import pandas as pd
import matplotlib.pyplot as plt
import tensorflow.keras as keras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

### 데이터 로드 ###
### 데이터 다운로드 링크 ###
#https://www.kaggle.com/code/emilyjiminroh/cnn-sign-language-mnist-eng-kor/data#
train_df = pd.read_csv("/content/sign_mnist_train.csv") ## 해당 파일 경로
valid_df = pd.read_csv("/content/sign_mnist_valid.csv") ## 해당 파일 경로
print(train_df.head())
y_train = train_df['label']
y_valid = valid_df['label']
del train_df['label']
del valid_df['label']
x_train = train_df.values
x_valid = valid_df.values
print(x_train.shape)
print(y_train.shape)
print(x_valid.shape)
print(y_valid.shape)

### 이미지 확인 ### 
plt.figure(figsize=(40,40))

num_images = 20
for i in range(num_images):
    row = x_train[i]
    label = y_train[i]
    
    image = row.reshape(28,28)
    plt.subplot(1, num_images, i+1)
    plt.title(label, fontdict={'fontsize': 30})
    plt.axis('off')
    plt.imshow(image, cmap='gray')
    

### 데이터 정규화 및 모델 생성,학습 ### 
x_train = x_train / 255
x_valid = x_valid / 255
print(x_train.min())
print(x_train.max())

num_classes = 24
y_train = keras.utils.to_categorical(y_train, num_classes)
y_valid = keras.utils.to_categorical(y_valid, num_classes)

model = Sequential()
model.add(Dense(units = 512, activation='relu', input_shape=(784,)))
model.add(Dense(units = 512, activation='relu'))
model.add(Dense(units = num_classes, activation='softmax'))
model.summary()

model.compile(loss='categorical_crossentropy', metrics=['accuracy'])

model.fit(x_train, y_train, epochs=20, verbose=1, validation_data=(x_valid, y_valid))