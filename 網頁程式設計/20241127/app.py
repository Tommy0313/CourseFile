from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    # 動態內容
    title = "Personal Web Page"
    education = [
        {"department": "Department of Intelligent Automation Engineering (associate degree)", "years": "2018~2023"},
        {"department": "Department of Computer Science & Information Engineering - GPA 4.0", "years": "2023~now"}
    ]
    technical_skills = [
        "Python, Tensorflow, Java, Firebase, Android APP, C, HTML, CSS, JavaScript - learned through university courses and reading related books.",
        "DBMS - learned through database system course.",
        "Python, C - learned through programming design and internship courses with project implementation.",
        "Tensorflow - learned through deep learning-Tensorflow course and artificial intelligence course with project implementation."
    ]
    return render_template('index2.html', title=title, education=education, technical_skills=technical_skills)

if __name__ == '__main__':
    app.run(debug=True)
