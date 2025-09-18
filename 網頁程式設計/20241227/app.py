from flask import Flask, render_template
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
import time
from flask import request

app = Flask(__name__)

def fetch_lottery_results():
    # 設定 Selenium 與 Chrome
    chrome_options = Options()
    chrome_options.add_argument("--headless")
    service = Service(ChromeDriverManager().install())
    driver = webdriver.Chrome(service=service, options=chrome_options)
    driver.get('https://www.taiwanlottery.com/')
    time.sleep(2)  # 等待 JavaScript 加載
    soup = BeautifulSoup(driver.page_source, 'html.parser')
    driver.quit()

    # 彩種資料
    lottery_types = {
        "賓果": {"index": 0, "super_class": "ball color-super", "normal_class": "ball"},
        "威力彩": {"index": 1, "super_class": "ball color-super secondary-area", "normal_class": "ball"},
        "大樂透": {"index": 2, "super_class": "ball color-super special-number", "normal_class": "ball"},
        "49樂合彩": {"index": 3, "super_class": None, "normal_class": "ball"},
        "今彩539": {"index": 4, "super_class": None, "normal_class": "ball"},
        "39樂合彩": {"index": 5, "super_class": None, "normal_class": "ball"},
        "三星彩": {"index": 0, "class": "result-balls justify-center", "normal_class": "ball"},
        "四星彩": {"index": 1, "class": "result-balls justify-center", "normal_class": "ball"}
    }

    results = {}
    for name, info in lottery_types.items():
        if "class" in info:  # 三星彩與四星彩特殊邏輯
            result_ball = soup.find_all('div', class_=info["class"])[info["index"]]
        else:
            result_ball = soup.find_all('div', class_='result-balls')[info["index"]]
        normal_balls = [ball.text for ball in result_ball.find_all('div', class_=info["normal_class"])]
        super_ball = None
        if "super_class" in info and info["super_class"]:
            super_ball = result_ball.find('div', class_=info["super_class"])
            super_ball = super_ball.text if super_ball else None
            normal_balls.remove(super_ball)
        results[name] = {"一般獎號": normal_balls, "特別號": super_ball}

    return results

@app.route('/')
def home():
    results = fetch_lottery_results()
    return render_template('index.html', results=results)

def fetch_history_lottery_results(year, month):
    # 設定 Selenium 與 Chrome
    chrome_options = Options()
    chrome_options.add_argument("--headless")
    service = Service(ChromeDriverManager().install())
    driver = webdriver.Chrome(service=service, options=chrome_options)

    # 訪問歷史查詢頁面
    url = "https://www.taiwanlottery.com/lotto/history/history_result/"
    driver.get(url)
    time.sleep(2)

    try:
        # 定位到日期選擇的 div
        date_picker_div = driver.find_element(By.CSS_SELECTOR, "div.el-input__wrapper.has-value")
        
        # 直接修改 div 中的 data-pick 屬性
        driver.execute_script(f"arguments[0].setAttribute('data-pick', '民國{year}年{month}月')", date_picker_div)
        time.sleep(2)
        # 點擊查詢按鈕
        search_button = driver.find_element(By.CLASS_NAME, "el-button.el-button--primary.search-area-btn")
        search_button.click()

        time.sleep(2)  # 等待結果加載

        # 提取結果頁面的彩券號碼
        results = {}

        # 獲取指定日期的彩券結果（class="period-date"）
        period_date = driver.find_element(By.CLASS_NAME, "period-date").text
        results["日期"] = period_date

        # 提取號碼
        winner_number_container = driver.find_element(By.CLASS_NAME, "winner-number-other-container")
        
        # 一般號碼（class="ball secondary-area"）
        normal_numbers = [ball.text for ball in winner_number_container.find_elements(By.CLASS_NAME, "ball.secondary-area")]
        
        # 特殊號碼（class="ball color-super secondary-area"）
        special_numbers = [ball.text for ball in winner_number_container.find_elements(By.CLASS_NAME, "ball.color-super.secondary-area")]
        results["一般號碼"] = normal_numbers[:-1]  # 移除最後一個號碼
        results["特殊號碼"] = special_numbers

        driver.quit()
        return results
    except Exception as e:
        print(f"錯誤: {e}")
        driver.quit()
        return None

@app.route('/history', methods=['GET', 'POST'])
def history():
    if request.method == 'POST':
        year = request.form['year']
        month = request.form['month']
        lottery_results = fetch_history_lottery_results(int(year), (month))
        if lottery_results:
            return render_template('history.html', results=lottery_results)
        else:
            return render_template('history.html', error="查詢失敗，請重試！")
    return render_template('history.html')

if __name__ == '__main__':
    app.run(debug=True)

