from datetime import datetime
from flask import Flask, render_template
from flask import jsonify, request
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SECRET_KEY'] = 'YourSecretKey'
app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql://postgres:ee0313@localhost/my_hotel'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

# Define the data models
class Booking(db.Model):
    __tablename__ = 'booking'
    booking_id = db.Column(db.Integer, primary_key=True)
    guest_id = db.Column(db.Integer, db.ForeignKey('guest.guest_id'))
    room_number = db.Column(db.String, db.ForeignKey('room.room_number'))
    check_in_date = db.Column(db.Date)
    check_out_date = db.Column(db.Date)
    total_price = db.Column(db.Float)
    booking_date = db.Column(db.Date)

    guest = db.relationship('Guest', backref='bookings')
    room = db.relationship('Room', backref='bookings')

class Guest(db.Model):
    __tablename__ = 'guest'
    guest_id = db.Column(db.Integer, primary_key=True)
    guest_name = db.Column(db.String)
    contact_info = db.Column(db.String)
  
  
class Room(db.Model):
    __tablename__ = 'room'
    room_number = db.Column(db.String, primary_key=True)
    room_type = db.Column(db.String)
    price_per_night = db.Column(db.Float)
    max_guests = db.Column(db.Integer)


# Route to show the booking list
@app.route('/')
def index():
    return render_template('index.html')
     
       
# Route to show the booking list
@app.route('/bookings')
def bookings():
    bookings = Booking.query.all()
    return render_template('bookings.html', bookings=bookings)

@app.route('/cancel_booking', methods=['POST'])
def cancel_booking():
    data = request.get_json()
    booking_id = data.get('booking_id')
    print(f"booking_id: {booking_id}")
     
    try:
        booking = Booking.query.get(booking_id)
        if booking:
            db.session.delete(booking)
            db.session.commit()
            return jsonify({"status": "success", "message": "Booking deleted"})
        else:
            return jsonify({"status": "error", "message": "Booking not found"}), 404
    except Exception as e:
        db.session.rollback()
        return jsonify({"status": "error", "message": str(e)}), 500

@app.route('/update_booking_date', methods=['POST'])
def update_booking_date():
    data = request.get_json()
    booking_id = data['booking_id']
    date_type = data['date_type']
    new_date = data['new_date']
    print(f"booking_id: {booking_id}, date_type: {date_type}, new_date: {new_date}")
    
    try:
        booking = Booking.query.get(booking_id)
        if booking:
            if date_type == 'check_in_date':
                booking.check_in_date = datetime.strptime(new_date, '%Y-%m-%d').date()
            elif date_type == 'check_out_date':
                booking.check_out_date = datetime.strptime(new_date, '%Y-%m-%d').date()
            db.session.commit()
            return jsonify({"status": "success", "message": "Booking date updated"})
        else:
            return jsonify({"status": "error", "message": "Booking not found"}), 404
    except Exception as e:
        db.session.rollback()
        return jsonify({"status": "error", "message": str(e)}), 500

@app.route('/admin/bookings', methods=['GET', 'POST'])
def admin_bookings():
    results = []
    error = None

    if request.method == 'POST':
        booking_id = request.form.get('booking_id')
        guest_name = request.form.get('guest_name')
        start_date = request.form.get('start_date')
        end_date = request.form.get('end_date')

        if booking_id and not booking_id.isdigit():
            error = "Booking ID must be numeric."
            return render_template('admin_bookings.html', bookings=results, error=error)


        # 若所有搜尋條件均為空
        if not booking_id and not guest_name and not (start_date and end_date):
            error = "Booking not found"
        else:
            query = Booking.query.join(Guest).join(Room)

            # 根據輸入條件添加查詢條件
            if booking_id:
                query = query.filter(Booking.booking_id == booking_id)
            if guest_name:
                query = query.filter(Guest.guest_name.ilike(f"%{guest_name}%"))
            if start_date and end_date:
                query = query.filter(Booking.check_in_date >= start_date, Booking.check_out_date <= end_date)

            results = query.all()

            # 若查詢結果為空
            if not results:
                error = "Booking not found"

    return render_template('admin_bookings.html', bookings=results, error=error)



@app.route('/check_booking', methods=['GET', 'POST'])
def check_booking():
    error = None
    booking = None

    if request.method == 'POST':
        booking_id = request.form.get('booking_id')

        if booking_id and not booking_id.isdigit():
            error = "Booking ID must be numeric."
            return render_template('check_booking.html', error=error)

        # 檢查是否輸入了 Booking ID
        if not booking_id:
            error = "Booking not found"
        else:
            booking = Booking.query.filter_by(booking_id=booking_id).first()
            if not booking:
                error = "Booking not found"

    
    return render_template('check_booking.html', booking=booking, error=error)


@app.route('/booking_details/<int:booking_id>')
def booking_details(booking_id):
    booking = Booking.query.get_or_404(booking_id)
    return render_template('booking_details.html', booking=booking)



if __name__ == '__main__':
    app.run(debug=True)



