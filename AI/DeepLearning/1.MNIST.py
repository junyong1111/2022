import matplotlib.pyplot as plt
import cv2
from tensorflow.keras.datasets import mnist
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

### 데이터 로드 ###
(x_train, y_train), (x_valid, y_valid) = mnist.load_data()
print(x_train.shape)
print(x_valid.shape)
print(x_train.dtype)
print(x_train.min())
print(x_train.max())
print(x_train[0])

image = x_train[0]
plt.imshow(image, cmap='gray')
y_train[0]

### 데이터 재구성 ###
x_train = x_train.reshape(60000, 784)
x_valid = x_valid.reshape(10000, 784)
x_train.shape
x_train[0]
x_train = x_train / 255
x_valid = x_valid / 255 
print(x_train.dtype)
print(x_train.min())
print(x_train.max())

### 데이터별 범주 인코딩 ###
num_categories = 10

y_train = keras.utils.to_categorical(y_train, num_categories)
y_valid = keras.utils.to_categorical(y_valid, num_categories)
y_train[0:9]

### 모델 구성 ### 
model = Sequential()
model.add(Dense(units=512, activation='relu', input_shape=(784,)))
model.add(Dense(units = 512, activation='relu'))
model.add(Dense(units = 10, activation='softmax'))
model.summary()
model.compile(loss='categorical_crossentropy', metrics=['accuracy'])
### 여러개의 항목을 분류하므로 위와같은 손실함수를 사용 ###

### 학습 시작 ###
history = model.fit(
    x_train, y_train, epochs=5, verbose=1, validation_data=(x_valid, y_valid)
)