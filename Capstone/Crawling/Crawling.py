from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Chrome("/Users/dak_kiwon/Jun/Git_dir/KMU-2022/Capstone/Crawling/chromedriver") 
driver.get("https://www.google.co.kr/imghp?hl=ko")

elem = driver.find_element_by_name("q")
### test commit