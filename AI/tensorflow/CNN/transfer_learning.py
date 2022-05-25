'''
해결하려는 문제에서 빠른 속도로 일정 수준의 베이스라인 성능을 얻고 싶을 때, 갖아 쉽고 빠른 방법인 전이 학습(transfer learning)이 있다.
전이 학습의 핵심은 사전학습도니 네트워크의 가중치를 사용하는 것이다. 전이 학습은 크게 세가지로 분류가 가능하다.
1. 모델을 변형하지 않고 사용
2. 모델의 분류기를 재학습하는 방법(일반적으로 가장 많이 사용)
3. 모델의 일부를 동결 해제하여 재학습
'''

import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPool2D, Dense, Flatten, BatchNormalization, Activation
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.applications import *
from tensorflow.keras.applications import VGG16
# 여러가지 모델 중 VGG16을 이용하여 전이학습을 진행

vgg16 = VGG16(weights = 'imagenet',
              input_shape = (32,32,3), include_top = False)

model = Sequential()
model.add(vgg16) 
### vgg16 추가 ###
model.add(Flatten())
model.add(Dense(256))
model.add(BatchNormalization())
model.add(Activation('relu'))
model.add(Dense(10, activation = 'softmax'))

mobilenet = MobileNet(weights = None, input_shape = None,
                      include_top = True)
resnet50 = ResNet50(weights = None, input_shape = None, include_top = True)
xceptiom = Xception(weights = None, input_shape = None, include_top = True)
## weights : ImageNet데이터를 학습시킨 가중치의 사용 여부를 결정하며 기본값은 None이며 사용하고 싶다면 imagenet을 전달
## input_shape : 입력 데이터의 형태를 전달
## include_top : 모델의 분류기층을 포함해서 구성할지를 결정하며 False를 전달할 경우, 위의 코드처럼 데이터셋에 적합한 분류기를 직접 정의


model.compile(optimizer = Adam(1e-4),
              loss = 'sparse_categorical_crossentropy',
              metrics = ['acc'])

def get_step(train_len, batch_size):
  if(train_len % batch_size > 0):
    return train_len // batch_size+1
  else:
    return train_len // batch_size

#### 
'''
from pickletools import optimize
import cv2
from cv2 import mean
import numpy as np
from sklearn import metrics
import tensorflow as tf
import matplotlib.pyplot as plt
from tensorflow.keras.datasets import cifar10
from tensorflow.keras.utils import to_categorical
from sklearn.model_selection import train_test_split
from tensorflow.keras.preprocessing.image import load_img, img_to_array, ImageDataGenerator

(x_train, y_train), (x_test, y_test) = cifar10.load_data()
train_datagen = ImageDataGenerator(
    horizontal_flip = True,
    zoom_range = 0.2,
    width_shift_range = 0.1,
    height_shift_range = 0.1,
    rotation_range = 30,
    fill_mode = 'nearest'
)
### 6장의 추가 이미지 생성
val_datagen = ImageDataGenerator()
batch_size = 16
## 배치 사이즈만큼의 크기만큼 생성

train_generator = train_datagen.flow(x_train,y_train, batch_size = batch_size)
val_generator = val_datagen.flow(x_test,y_test, batch_size = batch_size)
'''
### 위 코드와 합쳐서 사용
history = model.fit(train_generator,
                    epochs = 100,
                    steps_per_epoch = get_step(len(x_train), batch_size),
                    validation_data = val_generator,
                    validation_steps = get_step(len(x_test), batch_size)
)