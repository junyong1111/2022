from pickletools import optimize
import cv2
import numpy as np
import tensorflow 
import matplotlib.pyplot as plt
from tensorflow.keras.datasets import fashion_mnist
from tensorflow.keras.utils import to_categorical
from sklearn.model_selection import train_test_split


(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()
print(x_train.shape, y_train.shape)
print(x_test.shape, y_test.shape)
## fashion_mnist data download

np.random.seed(777)

calss_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']
class_num = 10

sampleSize = 9
random_idx = np.random.randint(60000,size=sampleSize)
## 랜덤으로 샘플 가져오기
x_train = np.reshape(x_train / 255, (-1,28,28,1))
x_test  = np.reshape(x_test / 255, (-1,28,28,1))
## 0~1범위로 만들기

y_train = to_categorical(y_train)
y_test = to_categorical(y_test)

x_train, x_val, y_train, y_val = train_test_split(x_train, y_train,
                                                  test_size = 0.3,
                                                  random_state = 777)
print('Fashion-MNIST ready~')
############################### 데이터 다운로드 단계 ###############################

model = tensorflow.keras.models.Sequential([
    tensorflow.keras.layers.Conv2D(filters = 16, kernel_size =3, padding = 'same',
                                   activation = 'relu', input_shape =(28,28,1)), ## 처음만 input_size를 지정
    tensorflow.keras.layers.MaxPool2D(pool_size =(2,2), strides = 2, padding = 'same'),
    tensorflow.keras.layers.Conv2D(filters = 32, kernel_size =3, padding = 'same',
                                   activation = 'relu'),
    tensorflow.keras.layers.MaxPool2D(pool_size =(2,2), strides = 2, padding = 'same'),
    tensorflow.keras.layers.Conv2D(filters = 64, kernel_size =3, padding = 'same',
                                   activation = 'relu'),
    tensorflow.keras.layers.MaxPool2D(pool_size =(2,2), strides = 2, padding = 'same'),
    tensorflow.keras.layers.Flatten(),
    tensorflow.keras.layers.Dense(64, activation = 'relu'),
    tensorflow.keras.layers.Dense(class_num, activation = 'softmax')    
])

############################### 모델 구성 단계 ###############################

model.compile(optimizer = 'adam',
              loss = 'categorical_crossentropy',
              metrics = ['acc'])
model.fit(x_train, y_train,
          epochs = 1,
          batch_size = 128,
          validation_data = (x_val,y_val))

############################### 모델 학습 단계 ###############################
model.summary()

