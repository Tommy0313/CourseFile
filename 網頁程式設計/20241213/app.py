from flask import Flask, render_template, request, redirect, url_for
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField, DateField, SelectField
from wtforms.validators import DataRequired
from flask import Flask, render_template, request, redirect, url_for
from flask_sqlalchemy import SQLAlchemy
app = Flask(__name__)
app.config['SECRET_KEY'] = 'YourSecretKey'
app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql://postgres:ee0313@localhost/my_hotel'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)
# Example room data (in a real application, this would come from a database)
rooms = [
    ('101', 'Single Room'),
    ('102', 'Double Room'),
    ('103', 'Deluxe Room')
]

class Guest(db.Model):
    guest_id = db.Column(db.Integer, primary_key=True)
    guest_name = db.Column(db.String(255), nullable=False)
    contact_info = db.Column(db.String(255))
class Room(db.Model):
    room_number = db.Column(db.String(10), primary_key=True)
    # other room fields...
class Booking(db.Model):
    booking_id = db.Column(db.Integer, primary_key=True)
    guest_id = db.Column(db.Integer, 
    db.ForeignKey('guest.guest_id'), nullable=False)
    room_number = db.Column(db.Integer, 
    db.ForeignKey('room.room_number'), nullable=False)
    check_in_date = db.Column(db.Date, nullable=False)
    check_out_date = db.Column(db.Date, nullable=False)
    # other booking fields...


class BookingForm(FlaskForm):
    guest_name = StringField('Guest Name', validators=[DataRequired()])
    room_number = SelectField('Room Number', choices=rooms, validators=[DataRequired()])
    check_in_date = DateField('Check-In Date', format='%Y-%m-%d', validators=[DataRequired()])
    check_out_date = DateField('Check-Out Date', format='%Y-%m-%d', validators=[DataRequired()])
    contact_info = StringField('Contact Information', validators=[DataRequired()])
    submit = SubmitField('Book Now')

@app.route('/')
def index():
    bookings = Booking.query.join(Guest).add_columns(
        Guest.guest_name, Booking.room_number, Booking.check_in_date, Booking.check_out_date
    ).all()
    return render_template('index.html', bookings=bookings)

@app.route('/booking', methods=['GET', 'POST'])
def booking():
    form = BookingForm()
    if form.validate_on_submit():
        # 檢查日期是否為空
        if not form.check_in_date.data or not form.check_out_date.data:
            error = "Check-in and check-out dates are required."
            return render_template('booking.html', form=form, error=error)
        
        # 檢查日期的邏輯
        if form.check_out_date.data <= form.check_in_date.data:
            error = "Check-out date must be later than check-in date."
            return render_template('booking.html', form=form, error=error)
        
        # 若無問題，處理預訂
        new_guest = Guest(guest_name=form.guest_name.data, contact_info=form.contact_info.data)
        db.session.add(new_guest)
        db.session.flush()  # 取得新加入的 guest_id
        
        new_booking = Booking(
            guest_id=new_guest.guest_id,
            room_number=form.room_number.data,
            check_in_date=form.check_in_date.data,
            check_out_date=form.check_out_date.data
        )
        db.session.add(new_booking)
        db.session.commit()
        
        return redirect(url_for('index'))
    
    return render_template('booking.html', form=form)

if __name__ == '__main__':
    app.run(debug=True)