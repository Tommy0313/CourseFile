from flask import Flask, render_template
app = Flask(__name__)
@app.route('/')
def home():
    # Variables to pass to the HTML template
    title = "Welcome to My Flask App"
    description = "This is a simple dynamic web page using Flask."
    items = ["Python", "Flask", "HTML", "CSS"]
    # Render the template and pass the variables
    return render_template('index.html', title=title,description=description, items=items)

if __name__ == '__main__':
    app.run(debug=True)