import numpy as np
from tensorflow import keras
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from tensorflow.keras.preprocessing import image as image_utils

### 저장된 모델 로드 ###
model = keras.models.load_model('asl_model')
model.summary()


### 이미지 확인을 위한 함수정의 ### 
def show_image(image_path):
    image = mpimg.imread(image_path)
    plt.imshow(image)

show_image('/content/b.png')

### 데이터 세트와 맞게 28x28의 GraySacle로 변환 ### 
def load_and_scale_image(image_path):
    image = image_utils.load_img(image_path, color_mode="grayscale", target_size=(28,28))
    return image

### 이미지 확인 ###
image = load_and_scale_image('/content/b.png')
plt.imshow(image, cmap='gray')

### 모델 재구성 ###
image = image_utils.img_to_array(image)
image = image.reshape(1,28,28,1) 
image = image / 255


### 예측값 저장 ### 
prediction = model.predict(image)
print(prediction)
np.argmax(prediction)
# Alphabet does not contain j or z because they require movement
alphabet = "abcdefghiklmnopqrstuvwxy"
dictionary = {}
for i in range(24):
    dictionary[i] = alphabet[i]
dictionary

dictionary[np.argmax(prediction)]

### 예측을 위한 함수 ### 
def predict_letter(file_path):
    show_image(file_path)
    image = load_and_scale_image(file_path)
    image = image_utils.img_to_array(image)
    image = image.reshape(1,28,28,1) 
    image = image/255
    prediction = model.predict(image)
    # convert prediction to letter
    predicted_letter = dictionary[np.argmax(prediction)]
    return predicted_letter

### 예측값 확인 ###
predict_letter("/content/a.png")