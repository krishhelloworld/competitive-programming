from selenium import webdriver as wbd
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options 
from selenium.webdriver.support.ui import WebDriverWait as wbt 
from selenium.webdriver.support import expected_conditions as ec
from selenium.common.exceptions import UnexpectedAlertPresentException as excp
options = Options()
options.page_load_stratergy = 'eager'
options.add_argument("--start-maximized")
options.add_experimental_option("useAutomationExtension",False)

options.add_experimental_option("detach",True)
prefs= {
    'profile.default_content_setting_values.image': 2
}
options.add_experimental_option("prefs",prefs)
driver = wbd.Chrome(options=options)
driver.get("https://chatgpt.com")
#textarea class="wcDTda_fallbackTextarea" name="prompt-textarea" autofocus="" placeholder="Ask anything" aria-label="Chat with ChatGPT" data-virtualkeyboard="true"
textarea= wbt(driver,10).until(ec.presence_of_element_located((By.XPATH, "//textarea[@name='prompt-textarea']")))
textarea.send_keys("hey how are you")
driver.get("https://google.com")

#https://chatgpt.com/?prompt=hello+to+me+world -> you have to press submit after this
#https://www.google.com/search?q=%22{new+world}%22&sca_esv=11e50d49d5e228fb&sxsrf=ANbL-n46BoqwqsghcUFuy8QmOTzoyF09qg%3A1767930043464&udm=50->to change with the bracket {new+world}->hello+to+my+world
# from selenium import webdriver
# from selenium.webdriver.chrome.options import Options 
# from selenium.webdriver.common.by import By
# from selenium.webdriver.support.ui import Select, WebDriverWait
# from selenium.webdriver.support import expected_conditions as EC
# import pandas as pd
# import time

# driver = webdriver.Chrome()
# driver.get("https://erp.aktu.ac.in/WebPages/KYC/Index.aspx")

# time.sleep(5)

# data = []

# # get all options
# options = driver.find_elements(By.XPATH, "//select[@id='ddlCityLocation']/option")

# for i in range(3, len(options)):  # skip junk options
#     value = options[i].get_attribute("value")
#     location = options[i].text.strip()

#     if not location:
#         continue

#     print(f"Processing: {location}")

#     # 🔥 set value using JS (bypasses UI)
#     driver.execute_script(f"""
#         document.getElementById('ddlCityLocation').value = '{value}';
#         document.getElementById('ddlCityLocation').dispatchEvent(new Event('change'));
#     """)

#     time.sleep(3)

#     rows = driver.find_elements(By.XPATH, "//table//tr")

#     for row in rows[1:]:
#         cols = row.find_elements(By.TAG_NAME, "td")

#         if len(cols) > 1:
#             college = cols[1].text.strip()
#             if college:
#                 data.append([college, location])

# df = pd.DataFrame(data, columns=["College", "Location"])
# df.to_excel("email.xlsx", index=False)

# driver.quit()