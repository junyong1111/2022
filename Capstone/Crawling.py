from selenium.webdriver.common.keys import Keys
import time
import urllib.request
from selenium.webdriver.common.by import By
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

def set_chrome_driver():
    chrome_options = webdriver.ChromeOptions()
    driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=chrome_options)
    return driver           #크롬 드라이버 자동 업데이트 코드

set_chrome_driver()

#구글페이지의 기본적인 이미지 수는 약 50장

keyword = input("검색어를 입력하시오 : ")
count = 1

driver = webdriver.Chrome("/Users/byeon/PycharmProjects/Kobot/Chrome_Driver/chromedriver")
driver.get("https://www.google.co.kr/imghp?hl=ko&ogbl ")

# elem = driver.find_element_by_name("q") #검색창 불러오기 ###selenium 3 version###
elem = driver.find_element(by = By.NAME, value = "q") #검색창 불러오기

elem.send_keys(keyword) #검색창에 검색어 입력
elem.send_keys(Keys.RETURN) #Enter입력

# driver.find_elements_by_css_selector(".rg_i.Q4LuWd")[0].click() ###selenium 3 version###
images = driver.find_elements(by = By.CSS_SELECTOR, value = ".rg_i.Q4LuWd" ) #먼저 작은 이미지의 특정요소 가져오기

for image in images :
    try : 
        image.click()
        time.sleep(2) #시간지연을 위한 코드, 여기선 2초마다 imgae 저장
        # imgURL = driver.find_element_by_css_selector(".n3VNCb") ###selenium 3 version###
        # imgURL = driver.find_element(by = By.CSS_SELECTOR, value = ".n3VNCb").get_attribute("src") #src추출
        # 위의 css 추출은 중복된 class name이 많아서 부정확 할 수 있다.
        imgURL = driver.find_element(by=By.XPATH, value='/html/body/div[2]/c-wiz/div[3]/div[2]/div[3]/div/div/div[3]/div[2]/c-wiz/div/div[1]/div[1]/div[2]/div/a/img').get_attribute("src")
        # css추출의 대안으로 정확한 fullXPATH를 이용한다.
        urllib.request.urlretrieve(imgURL, keyword + str(count) + ".jpg")
        count += 1
    except :
        pass

driver.close()