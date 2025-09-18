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
        date_picker_div = driver.find_element(By.CSS_SELECTOR, "div.el-input__wrapper.has-value")
        
        # 直接修改 div 中的 data-pick 屬性
        driver.execute_script(f"arguments[0].setAttribute('data-pick', '民國{year}年{month}月')", date_picker_div)

        # 點擊查詢按鈕
        search_button = driver.find_element(By.CLASS_NAME, "el-button.el-button--primary.search-area-btn")
        search_button.click()

        time.sleep(2)  # 等待結果加載

        # 獲取結果頁面的HTML
        results_page = driver.page_source
        driver.quit()
        return results_page
    except Exception as e:
        print(f"錯誤: {e}")
        driver.quit()

# 用例：查詢2023年11月的彩券號碼
year = 112  # 這裡使用民國年
month = 12
lottery_results = fetch_history_lottery_results(year, month)
print(lottery_results)
