from pytesseract import Output
import pytesseract
from PIL import Image
import numpy as np
import jellyfish
import imutils
import cv2
import os
import re


image_name = "/content/OCR/test.jpg" ## 이미지 경로
min_conf = 0

image = cv2.imread(image_name)
GRAY = cv2.cvtColor(image , cv2.COLOR_BGR2GRAY)
height, width = GRAY.shape
cv2.GaussianBlur(GRAY, (5, 5), 0)

GRAY_enlarge = cv2.resize(GRAY, (2*width, 2*height), interpolation=cv2.INTER_LINEAR)
####################### Enlarge 2x

denoised = cv2.fastNlMeansDenoising(GRAY_enlarge, h=10, searchWindowSize=21, templateWindowSize=7)
###################### Denoising ######################

results = pytesseract.image_to_string(denoised ,lang='kor') ### /usr/share/tesseract-ocr/4.00/tessdata/kor.traineddata 원하는 데이터를 넣어줘야 함
# results = re.compile('[|가-힣|+').sub('', results)
print(results)

classes = ["가지","감자", "깻잎", "버터", "당근",
           "대파","마늘", "무","배추","브로콜리",
           "상추","새송이버섯","시금치","애호박",
           "양배추", "양송이버섯","양파","오이",
           "고추","고구마", "콩나물", "귤","감",
           "딸기", "멜론", "참외", "배", "복숭아",
           "블루베리", "사과", "수박", "파프리카",
           "키위","방울토마토", "소고기","돼지고기",
           "닭고기", "달걀", "조기", "갈치","고등어",
           "문어", "꽃게", "새우", "오징어","바지락",
           "멸치", "두부", "옥수수","밥"]

           
min_confidence = 0.6
string = results

list = []
for i in string :
    if i.isalpha() :
        list.append(i)
    elif i == "\n" :
        list.append("\n")
    

string = "".join(list)
result = string


result = result.replace("\n", " ")
result = result.split(" ")
recipe = []
for i in result :
  if i != '' :
    recipe.append(i)
print(recipe)


for i in recipe:
  for j in classes:
    if j in i:
      print("인식된 재료는 : ", j)

