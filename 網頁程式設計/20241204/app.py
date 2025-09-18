from flask import Flask, render_template
import psycopg2

app = Flask(__name__)

# Database connection parameters

dbname = 'hotel'
user = 'postgres'
password = 'ee0313'
host = 'localhost'  # or your database host address
port = '5432'  # default PostgreSQL port

@app.route('/')
def index():
    conn = psycopg2.connect(
        dbname=dbname,
        user=user,
        password=password,
        host=host,
        port=port
    )
    cur = conn.cursor()
    cur.execute('''SELECT * FROM "BookOrder" WHERE check_in_date >= '2023-11-01';
                ''')
    rows = cur.fetchall()
    cur.close()
    conn.close()
    return render_template('index.html', data= rows)
if __name__ == '__main__':
    app.run(debug=True)
