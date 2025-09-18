from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
import time

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
        date_picker_div = driver.find_element(By.CSS_SELECTOR, "div.el-input__wrapper")
        
        # 直接修改 div 中的 data-pick 屬性
        driver.execute_script(f"arguments[0].setAttribute('data-pick', '民國{year}年{month}月')", date_picker_div)
        time.sleep(1)
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

# 用例：查詢2023年12月的彩券號碼
year = 112  # 這裡使用民國年
month = 11
lottery_results = fetch_history_lottery_results(year, month)

# 顯示結果
print(f"查詢日期: {lottery_results['日期']}")
print(f"一般號碼: {', '.join(lottery_results['一般號碼'])}")
print(f"特殊號碼: {', '.join(lottery_results['特殊號碼'])}")
