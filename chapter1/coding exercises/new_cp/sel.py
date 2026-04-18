from selenium import webdriver as wd 
from selenium.webdriver.common.by import By  ##by XPATH
from selenium.webdriver.support.ui import WebDriverWait as wdt 
from selenium.webdriver.support import expected_conditions as ec
from selenium.webdriver.chrome.options import Options 
from selenium.webdriver.common.action_chains import ActionChains
from selenium.common.exceptions import UnexpectedAlertPresentException as excp
import time

"""adding the options of chrome to make it maximized,detach the window from the program and adding eager load"""
options = Options()
options.add_argument("--start-maximized")
"""use this or alert one to accept all the alert"""
# options.set_capability("unhandledPromptBehavior", "accept")
options.add_experimental_option("detach", True)
prefs= {
    "profile.managed_default_content_settings.images": 2
}

options.add_experimental_option("prefs",prefs)
options.page_load_strategy = 'eager'  # or 'none'
driver = wd.Chrome(options=options)

# perfroming mutliactions using ActionChains
actions = ActionChains(driver)

username = "krish2@gmail.com"
passwords = 123456987

driver.get("https://booogle.onrender.com/html/login.html")
username_field=driver.find_element(By.XPATH, "//input[@id='loginEmail']")
password_field = driver.find_element(By.XPATH, "//input[@id='loginPassword']")


username_field.send_keys(username)
password_field.send_keys(passwords)
submit_button=driver.find_element(By.XPATH, "//input[@type='submit']")
submit_button.click()

wdt(driver, 10).until(ec.alert_is_present())
alert = driver.switch_to.alert
print(alert.text)
alert.accept()

# driver.execute_script("window.open('https://booogle.onrender.com/html/cart.html');")
driver.switch_to.new_window('tab')
driver.get("https://booogle.onrender.com/html/leture.html")   


tab_array = driver.window_handles
driver.switch_to.window(tab_array[0])
driver.close()
driver.switch_to.window(tab_array[1])
time.sleep(4)
search = wdt(driver,10).until(ec.presence_of_all_elements_located((By.XPATH, "//input[@id='searchBox']")))
#there can be list of input box but i want first one from there or you can do this ec.presence_of_element_located((By.XPATH, "//....... 
search[0].send_keys("nidhi parshar")
img = driver.find_element(By.XPATH, "//img[@src='https://i.ytimg.com/vi/MGvtT2PAy7Y/hqdefault.jpg']")
img.click()
time.sleep(10)
# from selenium.webdriver.chrome.service import Service 
# from selenium.webdriver.chrome.options import Options
# from selenium.common.exceptions import NoSuchElementException
# import time

# # --- Setup Chrome WebDriver ---
# service = Service()  # Uses default ChromeDriver in PATH

# driver = webdriver.Chrome(service=service, options=chrome_options)

# try:
