# NVIDIA 딥러닝 기초

### 목표
- 딥러닝 프로젝트를 처리할 수 있는 기반을 형성
- 딥러닝의 전반적인 기초 지식 제공
- 딥러닝에 관련 기사 ,튜토리얼 제공

<details>
<summary> 1. MNIST </summary>
<div markdown="1">  

Google의 Tensorflow를 이용하여 MNIST데이터를 다운받아서 실습진행

```python
import matplotlib.pyplot as plt
from tensorflow.keras.datasets import mnist
```
다운받은 MNIST 데이터를 각각 나눠준다 
- 학습 데이터
- 학습 정답데이터
- 검증 데이터
- 검증 정답데이터 

이렇게 총 4개의 데이터로 나눠 준 후 각각 확인해보면
학습 데이터의 크기는 총 6만장이며 28x28픽셀로 되어있고 검증 데이터의 크기는 1만장이며 마찬가지로 28x28픽셀이다 현재 unit8의 정수형 데이터 타입을 가지고있으며 각각의 이미지는 최소 0~ 최대 255의 값들이 저장되어있는걸 확인할 수 있다.  
첫번째 학습데이터의 정보를 출력해보면 5의 흑백 이미지를 확인 할 수 있다. 이 값이 5인지 확인하고 싶다면 학습데이터의 정답값이 들어있는 y_train을 출력함으로서 확인이 가능하다.


```python
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
```

2차원의 이미지 파일(28X28)을 784의 1차원 벡터로 평탄화 해준 이후에 각각의 픽셀값들을 0부터 1의 부동소수점으로 정규화해준뒤 다시 확인해보면 0~1의 사이에서 값들이 형성되어있는걸 볼 수 있다.

```python
x_train = x_train.reshape(60000, 784)
x_valid = x_valid.reshape(10000, 784)
x_train.shape
x_train[0]
x_train = x_train / 255
x_valid = x_valid / 255 
print(x_train.dtype)
print(x_train.min())
print(x_train.max())
```

0~부터 9까지의 숫자를 레이블해야하는데 이 때 케라스에서 제공해주는 함수를 이용하여 쉽게 범주를 레이블이 가능하다. 학습데이터와 검증데이터 모두 10개의 클래스로 레이블을 하고 값을 확인해보면 각각의 클래스에 맞게 자동으로 되어있다.

```python
import tensorflow.keras as keras
num_categories = 10

y_train = keras.utils.to_categorical(y_train, num_categories)
y_valid = keras.utils.to_categorical(y_valid, num_categories)
y_train[0:9]
```

모델생성을 하기위해서 케라스에서 제공해주는 함수를 이용한다. 현재 레이어의 값을 다음레이어에 영향을 주기위해서 Dense를 이용한다 최초 모델의 레이어를 생성할때는 모델의 Input값을 알려줘야 하므로 784을 인자로 넣어준다 활성화 함수로는 relu를 이용했다. relu는 일반적으로는 가장 효율이 좋다 그 이후 마지막 레이어에서는 10개의 클래스를 분류하므로  softmax함수를 이용하여 확률값으로 내보낸다. 이 때 model.summay()함수를 이용하여 현재 만든 모델에 대해 시각적으로 확인할 수 있다. 마지막으로 모델의 손실함수를 설정해준다 이때 분류모델에서 사용하는 크로스엔트로피를 사용하였다.

```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

model = Sequential()
model.add(Dense(units=512, activation='relu', input_shape=(784,)))
model.add(Dense(units = 512, activation='relu'))
model.add(Dense(units = 10, activation='softmax'))
model.summary()
model.compile(loss='categorical_crossentropy', metrics=['accuracy'])
```

### 결과 : 이제 현재 학습데이터와 라벨, 검증데이터와 라벨을 이용하여 총 5번의 epochs동안 학습을 진행 후 확인을 해보면 100퍼의 가까운 정확도에 모델이 나온것을 확인할 수 있다.

```python
history = model.fit(
    x_train, y_train, epochs=5, verbose=1, validation_data=(x_valid, y_valid)
)
```
</div>
</details>

<details>
<summary> 2. 미국 수화 데이터세트 이미지 분류 </summary>
<div markdown="1">  

캐글에서 제공해주는 미국 수화 데이터세트를 이용하여 모델을 트레이닝한다

csv파일을 로드하기위해서 pands 라이브러리를 이용한 후 각각의 데이터들의 값들을 확인해보면 각 label값  이미지의 픽셀값을 나타내고있다. 학습 데이터라벨과 검증 데이터 라벨의 값을 가져온 뒤 삭제해주고 학습 데이터와 검증 데이터의 값을 넣어준다. 이후 확인해보면  트레이닝을 위한 각각 784개 픽셀을 포함하는 27,455개의 이미지와 검증을 위해서는 7,172개의 이미지와 라벨이 있는걸 확인 할 수 있다.
[https://www.kaggle.com/code/emilyjiminroh/cnn-sign-language-mnist-eng-kor/data]

```python
import pandas as pd
train_df = pd.read_csv("/content/sign_mnist_train.csv")
valid_df = pd.read_csv("/content/sign_mnist_valid.csv")
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
```

현재 저장된 값들의 데이터를 한번 시각화를 하기 위해서 1차원 데이터를 다시 2차원의 28X28의로 reshape해준다 이 후 20개의 수화이미지를 확인해본 결과이다.

```python
import matplotlib.pyplot as plt
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
```

1번 MNIST 실습에서 했던거와 마찬가지로 데이터를 로드 이후 
1. 0 ~ 255의 값을 0 ~ 1의 부동소수점으로 정규화
2. 총 24개의 레이블로 범주 인코딩
3. 모델 생성 
- 활성화 함수로는 relu 사용 첫 레이어는 input값 지정
- 활성화 함수로 relu 사용 이후 자동으로 input값이 지정되어있음
- 분류를 위해서 softmax로 각각 클래스별로 확률값 반환
4. 모델 확인
5. 모델 컴파일 
- 분류모델의 손실함수 크로스엔트로피 사용
6. 모델 학습
- 총 20 eopchs만큼 학습

```python
import tensorflow.keras as keras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

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
```
### 결과 : 결과값을 확인해보면 학습데이터로는 높은 정확도가 나왔지만 실제 검증데이터의 정확도는 그에 비해 낮은편이다 예측결과는 높지만 실제 결과값의 정확도가 낮은 과적합의 문제가 발생한걸 확인해 볼 수 있었다.


</div>
</details>

<details>
<summary> 3.합성곱신경망 (Convolutional Neural Networks) </summary>
<div markdown="1">  

이미지 분류에 자주 사용되는 CNN모델에 대해 학습   
수화이미지에서 사용하였던 방법과 마찬가지이다.

1. pandas를 이용하여 데이터 로드
2. 라벨값 분류
3. 학습,검증 데이터값 분류
4. 24개의 범주 레이블
5. 0 ~ 1사이에 값으로 정규화

위 과정을 마치고 확인해보면 아까와 마찬가지로 학습데이터 27455장의 784 1차원 학습 데이터, 7172장의 784 1차원 검증데이터로 되어있다. 

```python
import tensorflow.keras as keras
import pandas as pd

# Load in our data from CSV files
train_df = pd.read_csv("/content/sign_mnist_train.csv")
valid_df = pd.read_csv("/content/sign_mnist_valid.csv")

# Separate out our target values
y_train = train_df['label']
y_valid = valid_df['label']
del train_df['label']
del valid_df['label']

# Separate out our image vectors
x_train = train_df.values
x_valid = valid_df.values

# Turn our scalar targets into binary categories
num_classes = 24
y_train = keras.utils.to_categorical(y_train, num_classes)
y_valid = keras.utils.to_categorical(y_valid, num_classes)

# Normalize our image data
x_train = x_train / 255
x_valid = x_valid / 255
x_train.shape, x_valid.shape
```

위 처럼 1차원의 데이터로 펼치면 서로 가까운 픽셀에대한 정보를 가지고 있지않다. 따라서 1차원의 데이터를 다시 3차원의 데이터로 변환해준다 이때 28x28x1인 이유는 Grapyscale이기 때문이다 또한 -1를 인자로 주게 되면 그 값은 자동으로 계산된다.  
이후 확인해보면 27455장의 3차원 학습데이터 , 7172장의 3차원 검증데이터로 reshape되어있는걸 확인할 수 있다.

```python
x_train = x_train.reshape(-1,28,28,1)
x_valid = x_valid.reshape(-1,28,28,1)
x_train.shape
x_valid.shape
x_train.shape, x_valid.shape
```

모델을 생성하는 단계이다.
1. Conv2D
- 2D 컨볼루션 레이어이며 작은 커널은 입력 이미지들을 훑으며, 분류에 중요한 특징들을 파악한다. 모델의 초기 컨볼루션은 선과 같은 간단한 특징을 탐지한다. 이후 컨볼루션은 점점 더 복잡한 특징을 탐지한다.  
- 75는 우리가 학습하게 될 필터(Filter)의 갯수를 의미하며  
- (3,3) 은 필터의 크기를 의미한다. 
- strides는 얼만큼의 보폭으로 움직일지
- padding은 입력 이미지와 결과 이미지의 크기를 맞추기 위해서 사용되며 제로패딩 또는 동일패딩을 사용한다.

2. BatchNormalization()
- 입력을 정규화하는 것과 마찬가지로, 배치정규화는 hidden layer들의 값을 scaling하여 학습을 개선한다.

3. MaxPool2D()
- 필터를 이용하여 계산된 값들 중 최대값만 가져온다 더 낮은 해상도로 축소하는 과정이며 이렇게 하면 모델이 약간의 변화에 더욱 견고하게 만들 수 있고, 모델의 학습 및 추론을 더욱 빠르게 할 수 있습니다.

4. Dropout()
- 위 수화예제에서 발생하였던 과적합을 방지하기 위한 방법 중 하나이며 무작위로 뉴런을 제외시키는 방식이다.

5. Flatten()
- 다차원입력을 1차원으로 바꿔주는 평탄화 작업을 해주며 분류를 위한 마지막 레이어로 들어간다.

6. Dense()
- 평탄화 작업한 feature vector를 입력으로 받아 어떤 feature가 분류에 기여하는지를 확인하며 마지막에는 분류를 위해 24개의 클래스 softmax를 이용한다.

위 과정을 거친 후 모델를 확인해보면 이전보다 파라메터 개수가 상당히 줄어든걸 확인 할 수 있으며 2번 실습과 같이 20epoch로 학습을 진행한다.

```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import (
    Dense,
    Conv2D,
    MaxPool2D,
    Flatten,
    Dropout,
    BatchNormalization,
)

model = Sequential()
model.add(Conv2D(75, (3, 3), strides=1, padding="same", activation="relu", 
                 input_shape=(28, 28, 1)))
model.add(BatchNormalization())
model.add(MaxPool2D((2, 2), strides=2, padding="same"))
model.add(Conv2D(50, (3, 3), strides=1, padding="same", activation="relu"))
model.add(Dropout(0.2))
model.add(BatchNormalization())
model.add(MaxPool2D((2, 2), strides=2, padding="same"))
model.add(Conv2D(25, (3, 3), strides=1, padding="same", activation="relu"))
model.add(BatchNormalization())
model.add(MaxPool2D((2, 2), strides=2, padding="same"))
model.add(Flatten())
model.add(Dense(units=512, activation="relu"))
model.add(Dropout(0.3))
model.add(Dense(units=num_classes, activation="softmax"))

model.summary()
model.compile(loss="categorical_crossentropy", metrics=["accuracy"])
model.fit(x_train, y_train, epochs=20, verbose=1, validation_data=(x_valid, y_valid))
```

### 결과 : 학습결과와 검증결과 둘 다 상당히 개선된 모습을 확인 할 수 있었다. 이와 같이 같은 데이터의 모델을 바꾸는 방법으로 아까의 과적합 문제를 해결할 수 있다. 


</div>
</details>


<details>
<summary> 4. 데이터 증강 </summary>
<div markdown="1">  

위 결과에서 과적합을 피하는 방법 중 하나로 모델의 아키텍쳐를 바꾸는 방법이 있었다. 뿐만 아니라 과적합을 피하는 방법 중 또다른 하나는 더 많은 데이터를 학습하는 방법이 있다. 기존에 있던 데이터를 증강하기 위하여 데이터 증강에 대한 방법에 대해 알아보자.

1. 데이터 로드
2. 데이터 ,라벨로 분류
3. 24개의 레이블 범주 인코딩
4. 0 ~ 1사이에 부동소수점으로 정규화
5. 3차원 데이터로 reshape

```python
import tensorflow.keras as keras
import pandas as pd

# Load in our data from CSV files
train_df = pd.read_csv("/content/sign_mnist_train.csv")
valid_df = pd.read_csv("/content/sign_mnist_valid.csv")

# Separate out our target values
y_train = train_df['label']
y_valid = valid_df['label']
del train_df['label']
del valid_df['label']

# Separate our our image vectors
x_train = train_df.values
x_valid = valid_df.values

# Turn our scalar targets into binary categories
num_classes = 24
y_train = keras.utils.to_categorical(y_train, num_classes)
y_valid = keras.utils.to_categorical(y_valid, num_classes)

# Normalize our image data
x_train = x_train / 255
x_valid = x_valid / 255

# Reshape the image data for the convolutional network
x_train = x_train.reshape(-1,28,28,1)
x_valid = x_valid.reshape(-1,28,28,1)
```

3번 실습에서 사용하였던 모델을 그대로 가져와서 사용

```python
## 20195298 박준용 ##

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import (
    Dense,
    Conv2D,
    MaxPool2D,
    Flatten,
    Dropout,
    BatchNormalization,
)

model = Sequential()
model.add(Conv2D(75, (3, 3), strides=1, padding="same", activation="relu", 
                 input_shape=(28, 28, 1)))
model.add(BatchNormalization())
model.add(MaxPool2D((2, 2), strides=2, padding="same"))
model.add(Conv2D(50, (3, 3), strides=1, padding="same", activation="relu"))
model.add(Dropout(0.2))
model.add(BatchNormalization())
model.add(MaxPool2D((2, 2), strides=2, padding="same"))
model.add(Conv2D(25, (3, 3), strides=1, padding="same", activation="relu"))
model.add(BatchNormalization())
model.add(MaxPool2D((2, 2), strides=2, padding="same"))
model.add(Flatten())
model.add(Dense(units=512, activation="relu"))
model.add(Dropout(0.3))
model.add(Dense(units=num_classes, activation="softmax"))
```

데이터 증강을 위하여 ImageDataGenerator 함수를 사용한다 
- 이미지 회전
- 이미지 확대
- 좌우 이동
- 상하 이동
- 수평 이동
- 수직 이동
위와 같은 방법을 통해 하나의 이미지를 여러장의 데이터로 증강하는게 가능하다 또한 무작위 샘플에대한 처리를 위해 자동으로 배치처리가 된다.

```python
from tensorflow.keras.preprocessing.image import ImageDataGenerator

datagen = ImageDataGenerator(
    rotation_range=10,  # randomly rotate images in the range (degrees, 0 to 180)
    zoom_range=0.1,  # Randomly zoom image
    width_shift_range=0.1,  # randomly shift images horizontally (fraction of total width)
    height_shift_range=0.1,  # randomly shift images vertically (fraction of total height)
    horizontal_flip=True,  # randomly flip images horizontally
    vertical_flip=False, # Don't randomly flip images vertically
)  

import matplotlib.pyplot as plt
import numpy as np
batch_size = 32
img_iter = datagen.flow(x_train, y_train, batch_size=batch_size)

x, y = img_iter.next()
fig, ax = plt.subplots(nrows=4, ncols=8)
for i in range(batch_size):
    image = x[i]
    ax.flatten()[i].imshow(np.squeeze(image))
plt.show()
```

증강된 데이터를 이용하여 모델학습을 시작한다 이 때 무한히 데이터를 생성하는걸 방지하기 위해 steps_per_epoch라는 인수를 사용하여 각 에포크가 얼마나 오랫동안 실행되어야 하는지를 명시적으로 설정하여야 한다. 여기서 사용할 일반적인 방식인 steps * batch_size = number_of_images_trained in an epoch는 단계 수를 증강되지 않은 데이터세트 크기를 batch_size(기본값 32)로 나눈 값과 동일하게 설정하는 것이기 때문이다.

```python
datagen.fit(x_train)
model.compile(loss='categorical_crossentropy', metrics=['accuracy'])
model.fit(img_iter,
          epochs=20,
          steps_per_epoch=len(x_train)/batch_size, # Run same number of steps we would if we were not using a generator.
          validation_data=(x_valid, y_valid))
```

### 결과 : 이전 모델보다 검증 정확도가 더 높고 일관적인 모습을 확인할 수 있다 위와 같은 방법으로 일반화가 개선되었고 새로운 데이터에 대한 예측도 개선된걸 확인 할 수 있었다. 

```python
### 다음 실습에 사용하기 위하여 현재 모델을 저장 ### 
model.save('asl_model')
```
</div>
</details>

<details>
<summary>5. 모델 배포 </summary>
<div markdown="1">  

위 학습에서 만들었던 모델을 배포한다.  
저장해두었던 모델을 로드한 후 모델에 대해 확인해본다.

```python
from tensorflow import keras

model = keras.models.load_model('asl_model')
model.summary()
```

현재 이미지 데이터는 학습에 사용했던 데이터와 크기와 RGB가 다르기때문에 해당 이미지를 학습에 사용했던 데이터와 맞추기 위하여 함수를 만들어 28X28의 흑백 이미지로 변환하다.

```python
### 이미지 확인을 위한 함수정의 ### 
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

def show_image(image_path):
    image = mpimg.imread(image_path)
    plt.imshow(image)

show_image('/content/b.png')
```

```python
### 데이터 세트와 맞게 28x28의 GraySacle로 변환 ### 
from tensorflow.keras.preprocessing import image as image_utils

def load_and_scale_image(image_path):
    image = image_utils.load_img(image_path, color_mode="grayscale", target_size=(28,28))
    return image

image = load_and_scale_image('/content/b.png')
plt.imshow(image, cmap='gray')
```

이제 예측을 위해 해당 이미지를 트레이닝된 데이터세트의 모양과 일치하도록 이미지를 재구성하는 과정이 이후 정규화과정까지 해준다.

```python
## 20195298 박준용 ##
image = image_utils.img_to_array(image)
image = image.reshape(1,28,28,1) 
image = image / 255
```

이제 해당 이미지를 통해 예측을 실행해본다 
출력값은 확률값이므로 그 중 가장 큰 확률값을 찾은 후 해당 알파벳에 해당하는 값을 반환하는 방식이다.

```python
prediction = model.predict(image)
print(prediction)
import numpy as np
np.argmax(prediction)
# Alphabet does not contain j or z because they require movement
alphabet = "abcdefghiklmnopqrstuvwxy"
dictionary = {}
for i in range(24):
    dictionary[i] = alphabet[i]
dictionary

dictionary[np.argmax(prediction)]
```

```python
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

predict_letter("/content/a.png")
```

### 결과 : 실제로 정확도가 높으며 샘플데이터를 예측하기 이전에 학습에 사용하였던 데이터와 같은 크기와 모양으로 재구성하는 과정이 꼭 필요하다.

</div>
</details>

<details>
<summary> 6. 사전 트레이닝된 모델 </summary>
<div markdown="1">  

딥러닝은 데이터 세트를 구하는데 어려움이 많다 이럴때 미리 트레이닝된 모델을 사용하여 이를 해결할 수 있다.  
오로지 개만 통과할 수 있는 자동문. 
일반적인 VGG16을 이용하여 학습진행

```python
from tensorflow.keras.applications import VGG16
  
# load the VGG16 network *pre-trained* on the ImageNet dataset
model = VGG16(weights="imagenet")
model.summary()
```

```python
### 이미지로드에 필요한 함수 ###
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

def show_image(image_path):
    image = mpimg.imread(image_path)
    print(image.shape)
    plt.imshow(image)

    ### 확인용 ###
show_image("/content/happy_dog.jpg")
```

다음으로는 모델에 보낼 수 있도록 이미지를 사전 처리이다. 지난 연습에서와 마찬가지이며 . 이 경우에는 이미지의 마지막 모양이 (1, 224, 224, 3)이 되어야 한다.

```python
from tensorflow.keras.preprocessing import image as image_utils
from tensorflow.keras.applications.vgg16 import preprocess_input

def load_and_process_image(image_path):
    # Print image's original shape, for reference
    print('Original image shape: ', mpimg.imread(image_path).shape)
    
    # Load in the image with a target size of 224, 224
    image = image_utils.load_img(image_path, target_size=(224, 224))
    # Convert the image from a PIL format to a numpy array
    image = image_utils.img_to_array(image)
    # Add a dimension for number of images, in our case 1
    image = image.reshape(1,224,224,3)
    # Preprocess image to align with original ImageNet dataset
    image = preprocess_input(image)
    # Print image's shape after processing
    print('Processed image shape: ', image.shape)
    return image

### 확인용 ###
processed_image = load_and_process_image("/content/brown_bear.jpg")  
```

다음은 모델 예측에 필요한 함수이며 총 3개의 이미지로 테스트를 진행해보았다.

```python
from tensorflow.keras.applications.vgg16 import decode_predictions

def readable_prediction(image_path):
    # Show image
    show_image(image_path)
    # Load and pre-process image
    image = load_and_process_image(image_path)
    # Make predictions
    predictions = model.predict(image)
    # Print predictions in readable form
    print('Predicted:', decode_predictions(predictions, top=3))

readable_prediction("/content/happy_dog.jpg")
readable_prediction("/content/brown_bear.jpg")
readable_prediction("/content/sleepy_cat.jpg")
```

위 3가지 케이스에 각각 강아지, 곰, 고양이를 잘 인식하였다. 이제 해당 모델을  사용하여 개만 출입을 허용하고 고양이는 내부에 있게 할 수 있습니다. 개는 범주 151 ~ 268이고, 고양이는 범주 281 ~ 285이다.

```python
import numpy as np

def doggy_door(image_path):
    show_image(image_path)
    image = load_and_process_image(image_path)
    preds = model.predict(image)
    if 151 <= np.argmax(preds) <= 268:
        print("Doggy come on in!")
    elif 281 <= np.argmax(preds) <= 285:
        print("Kitty stay inside!")
    else:
        print("You're not a dog! Stay outside!")

doggy_door("/content/happy_dog.jpg")
doggy_door("/content/brown_bear.jpg")
doggy_door("/content/sleepy_cat.jpg")
```

### 결과 : 사전에 학습된 모델을 이용하여 학습과정 없이 자신의 목적에 맞게 딥러닝을 이용할 수 있었다. 

</div>
</details>

<details>
<summary> 7.전이학습 </summary>
<div markdown="1">  

위 과정은 미리 학습된 데이터를 사용하기만 하는 과정이였다면 전이학습은 미리학습된 데이터를 가지고 다시 학습을하는 과정이다. 전이 학습은 크고 다양한 데이터세트가 없는 경우에 특히 강력한효과가 있다. 이런 경우에는 처음부터 트레이닝된 모델이 트레이닝 데이터를 빠르게 기억할 가능성이 높지만 새 데이터를 제대로 일반화할 수 없다. 전이 학습을 이용하면 소규모 데이터세트에 대해 정확하고 강력한 모델을 트레이닝할 수 있는 가능성을 높일 수 있다.  

- 특정한 개만 출입이 가능한 자동문
- 사전학습된 VGG16사용

```python
from tensorflow import keras

base_model = keras.applications.VGG16(
    weights='imagenet',  # Load weights pre-trained on ImageNet.
    input_shape=(224, 224, 3),
    include_top=False)


base_model.summary()
```

새 레이어를 사전 트레이닝된 모델에 추가하기 전에 수행해야 할 중요한 단계가 바로  모델의 사전 트레이닝된 레이어를 동결하는 것이다. 모델 동결은 트레이닝할 때 사전 트레이닝된 모델에서 기본 레이어는 업데이트하지 않고.  새로운 분류를 위해 우리가 끝에 추가하는 새 레이어만 업데이트하게 됩니다. 

기본 레이어를 동결하는 것은 모델에 대해 트레이닝 가능을 False로 설정하기만 하면 된다.

```python
base_model.trainable = False
```

새 레이어를 사전 트레이닝된 모델에 추가하는 과정이다.  새 레이어는 사전 트레이닝된 레이어의 피처를 취해 새 데이터세트에 대한 예측으로 변환한다. 
다음은  모델에 두 개의 레이어를 추가하는것이다. 
1.  이전의 CNN(Convolutional Neural Network)에서 봤던 풀링 레이어이다. 
2.  그런 다음에는 Bo인지 아닌지를 분류할 마지막 레이어를 추가해야 한다. 이는 한 개의 출력을 포함하는 밀접하게 연결된 레이어가 된다.

```python
inputs = keras.Input(shape=(224, 224, 3))
# Separately from setting trainable on the model, we set training to False 
x = base_model(inputs, training=False)
x = keras.layers.GlobalAveragePooling2D()(x)
# A Dense classifier with a single unit (binary classification)
outputs = keras.layers.Dense(1)(x)
model = keras.Model(inputs, outputs)

model.summary()
```

이전 연습에서 그랬던 것처럼 손실 및 지표 옵션으로 모델을 컴파일하는 과정이다. 여기서는 몇가지 다른 방법을 택한다 이전 분류 문제에 여러개의 레이블 범주가 있었다.  그래서 손실 계산을 위한 범주형 크로스 엔트로피를 선택했지만 이번에는 바이너리 분류 문제(Bo인지 아닌지 여부)만 있으므로 또한 기존 정확도 대신 바이너리 정확도를 사용하여 모델을 컴파일한다.

```python
# Important to use binary crossentropy and binary accuracy as we now have a binary classification problem
model.compile(loss=keras.losses.BinaryCrossentropy(from_logits=True), metrics=[keras.metrics.BinaryAccuracy()])
```

위에서 사용했던 데이터 증강을 사용하여 데이터를 늘린다

```python
from tensorflow.keras.preprocessing.image import ImageDataGenerator
# create a data generator
datagen = ImageDataGenerator(
        samplewise_center=True,  # set each sample mean to 0
        rotation_range=10,  # randomly rotate images in the range (degrees, 0 to 180)
        zoom_range = 0.1, # Randomly zoom image 
        width_shift_range=0.1,  # randomly shift images horizontally (fraction of total width)
        height_shift_range=0.1,  # randomly shift images vertically (fraction of total height)
        horizontal_flip=True,  # randomly flip images
        vertical_flip=False) # we don't expect Bo to be upside-down so we will not flip vertically
```

데이터 증강을 사용하여 모델 학습진행

```python
# load and iterate training dataset
train_it = datagen.flow_from_directory('data/presidential_doggy_door/train/', 
                                       target_size=(224, 224), 
                                       color_mode='rgb', 
                                       class_mode='binary', 
                                       batch_size=8)
# load and iterate validation dataset
valid_it = datagen.flow_from_directory('data/presidential_doggy_door/valid/', 
                                      target_size=(224, 224), 
                                      color_mode='rgb', 
                                      class_mode='binary', 
                                      batch_size=8)

model.fit(train_it, steps_per_epoch=12, validation_data=valid_it, validation_steps=4, epochs=20)
```

### 결과 : 전이학습을 통해 상당히 상당히 정확도가 높은 모델을 얻을 수 있었다. 


</div>
</details>


<details>
<summary> 7.파인튜닝 </summary>
<div markdown="1">  

이제 파인튜닝이라는 요령을 통해 모델을 개선할 수 있다. 파인튜닝을 학기위해서는 모델을 동결 이후 아주작은 학습률로 트레이닝 하여야 한다. 
이 단계는 동결된 레이어를 포함하는 모델이 완전히 트레이닝된 후에만 수행해야 한다. 

```python
### 예측을 위한 함수 ### 
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from tensorflow.keras.preprocessing import image as image_utils
from tensorflow.keras.applications.imagenet_utils import preprocess_input

def show_image(image_path):
    image = mpimg.imread(image_path)
    plt.imshow(image)

def make_predictions(image_path):
    show_image(image_path)
    image = image_utils.load_img(image_path, target_size=(224, 224))
    image = image_utils.img_to_array(image)
    image = image.reshape(1,224,224,3)
    image = preprocess_input(image)
    preds = model.predict(image)
    return preds


### Bo 분류를 위한 함수 ###

def presidential_doggy_door(image_path):
    preds = make_predictions(image_path)
    if preds[0] < 0:
        print("It's Bo! Let him in!")
    else:
        print("That's not Bo! Stay out!")
```

```python
# Unfreeze the base model
base_model.trainable = True

# It's important to recompile your model after you make any changes
# to the `trainable` attribute of any inner layer, so that your changes
# are taken into account
model.compile(optimizer=keras.optimizers.RMSprop(learning_rate = .00001),  # Very low learning rate
              loss=keras.losses.BinaryCrossentropy(from_logits=True),
              metrics=[keras.metrics.BinaryAccuracy()])


model.fit(train_it, steps_per_epoch=12, validation_data=valid_it, validation_steps=4, epochs=10)
```


```python
make_predictions('data/presidential_doggy_door/valid/bo/bo_20.jpg')
make_predictions('data/presidential_doggy_door/valid/bo/bo_20.jpg')
presidential_doggy_door('data/presidential_doggy_door/valid/not_bo/131.jpg')
presidential_doggy_door('data/presidential_doggy_door/valid/bo/bo_29.jpg')
```
### 결과 : 전이학습을 이용하면 작은데이터로도 좋은 성능의 모델을 만들 수 있다.

</div>
</details>

<details>
<summary>8.시퀀스 데이터 </summary>
<div markdown="1">  

시퀀스 데이터의 예시를 위해 텍스트 문장을 사용한다. 기본적으로 언어는 문자가 모여 단어를 이루고 단어가 모여 문장을 이루는 형식의 시퀀스 데이터로 구성된다. 시퀀스 데이터의 또 다른 예로는 시간에 따른 주가와 날씨 데이터가 있다. 

RNN 모델을 사용하기 위한 뉴욕타임즈의 헤드라인 데이터만을 로드
```python
import os 
import pandas as pd

nyt_dir = 'data/nyt_dataset/articles/'

all_headlines = []
for filename in os.listdir(nyt_dir):
    if 'Articles' in filename:
        # Read in all all the data from the CSV file
        headlines_df = pd.read_csv(nyt_dir + filename)
        # Add all of the headlines to our list
        all_headlines.extend(list(headlines_df.headline.values))
len(all_headlines)
```

컴퓨터가 이해할 수 있는방식으로 토큰화를 위해 필터링이후 토큰화진행


```python
# Remove all headlines with the value of "Unknown"
all_headlines = [h for h in all_headlines if h != "Unknown"]
len(all_headlines)

from tensorflow.keras.preprocessing.text import Tokenizer

# Tokenize the words in our headlines
tokenizer = Tokenizer()
tokenizer.fit_on_texts(all_headlines)
total_words = len(tokenizer.word_index) + 1
print('Total words: ', total_words)

# Print a subset of the word_index dictionary created by Tokenizer
subset_dict = {key: value for key, value in tokenizer.word_index.items() \
               if key in ['a','man','a','plan','a','canal','panama']}
print(subset_dict)

tokenizer.texts_to_sequences(['a','man','a','plan','a','canal','panama'])
```

토큰화 과정이 끝났으면 각 단어를 표현숫자로 변환한다. 
예를 들면 헤드라인 "nvidia launches ray tracing gpus"를 사용해 보면. 각 단어는 해당하는 숫자(예: nvidia - 5, launches - 22, ray - 94, tracing - 16, gpus - 102)로 대체되며 전체 시퀀스는 [5, 22, 94, 16, 102]가 된다.

```python
# Convert data to sequence of tokens 
input_sequences = []
for line in all_headlines:
    # Convert our headline into a sequence of tokens
    token_list = tokenizer.texts_to_sequences([line])[0]
    
    # Create a series of sequences for each headline
    for i in range(1, len(token_list)):
        partial_sequence = token_list[:i+1]
        input_sequences.append(partial_sequence)

print(tokenizer.sequences_to_texts(input_sequences[:5]))
input_sequences[:5]
```

모든 시퀀스의 길이를 맞추기 위해 패딩단계를 거친다.

```python
from tensorflow.keras.preprocessing.sequence import pad_sequences
import numpy as np

# Determine max sequence length
max_sequence_len = max([len(x) for x in input_sequences])

# Pad all sequences with zeros at the beginning to make them all max length
input_sequences = np.array(pad_sequences(input_sequences, maxlen=max_sequence_len, padding='pre'))
input_sequences[0]
```

예측변수및 타깃으로 분할한다

```python
# Predictors are every word except the last
predictors = input_sequences[:,:-1]
# Labels are the last word
labels = input_sequences[:,-1]
labels[:5]

from tensorflow.keras import utils

labels = utils.to_categorical(labels, num_classes=total_words)
```

이제 모델을 생성하는 과정이다. 
1. 임베딩
- 이 레이어는 토큰화된 시퀀스를 취하여 트레이닝 데이터세트의 모든 단어에 대한 임베딩을 학습하는 과정이며  개념상 임베딩의 목표는 피처의 일부나 전부의 차원 수를 줄이는 것이다.. 이 경우에는 각 단어를 벡터로 표현하며, 해당 벡터 내의 정보에 각 단어 간의 관계가 포함된다.

2. LSTM
- LSTM은 장기적인 정보를 학습하고 유지할 수 있는 특수한 유형의 순환 레이어이다.

```python
from tensorflow.keras.layers import Embedding, LSTM, Dense, Dropout
from tensorflow.keras.models import Sequential

# Input is max sequence length - 1, as we've removed the last word for the label
input_len = max_sequence_len - 1 

model = Sequential()

# Add input embedding layer
model.add(Embedding(total_words, 10, input_length=input_len))

# Add LSTM layer with 100 units
model.add(LSTM(100))
model.add(Dropout(0.1))

# Add output layer
model.add(Dense(total_words, activation='softmax'))

model.summary()
```

이제 모델을 컴파일 하는과정이다 이때 옵티마이저로 아담을 사용한다 아담은 일반적으로 가장 좋은 성능을 가지고있다.

```python
model.compile(loss='categorical_crossentropy', optimizer='adam')
model.fit(predictors, labels, epochs=30, verbose=1)
```

이제 다음과 같은 코드로 예측을 해보자

```python
def predict_next_token(seed_text):
    token_list = tokenizer.texts_to_sequences([seed_text])[0]
    token_list = pad_sequences([token_list], maxlen=max_sequence_len-1, padding='pre')
    prediction = model.predict_classes(token_list, verbose=0)
    return prediction

prediction = predict_next_token("today in new york")
prediction
```

```python
tokenizer.sequences_to_texts([prediction])

def generate_headline(seed_text, next_words=1):
    for _ in range(next_words):
        # Predict next token
        prediction = predict_next_token(seed_text)
        # Convert token to word
        next_word = tokenizer.sequences_to_texts([prediction])[0]
        # Add next word to the headline. This headline will be used in the next pass of the loop.
        seed_text += " " + next_word
    # Return headline as title-case
    return seed_text.title()
```

```python
seed_texts = [
    'washington dc is',
    'today in new york',
    'the school district has',
    'crime has become']
for seed in seed_texts:
    print(generate_headline(seed, next_words=5))
```

### 결과 : 30에포크의 트레이닝 후에는 결과가 약간 안좋디만 대부분의 헤드라인이 문법적으로는 어느 정도 이해가 되지만 맥락적으로도 잘 이해가 되는 것은 아닙니다. 더 많은 에포크로 트레이닝하는 방법으로 결과를 개선시킬 수 있다.

</div>
</details>


<details>
<summary>  9. 이미지개선 </summary>
<div markdown="1">  

```python
from tensorflow import keras

base_model = keras.applications.VGG16(
    weights='imagenet',
    input_shape=(224, 224, 3),
    include_top= False)

# Freeze base model
base_model.trainable = False
```

```python
# Create inputs with correct shape
inputs = keras.Input(shape=(224, 224, 3))

x = base_model(inputs, training=False)

# Add pooling layer or flatten layer
x = keras.layers.GlobalAveragePooling2D()(x)

# Add final dense layer
outputs = keras.layers.Dense(1, activation = 'softmax')(x)


# Combine inputs and outputs to create model
model = keras.Model(inputs, outputs)
```

```python
model.compile(loss='categorical_crossentropy', metrics=['accuracy'])
```

```python
from tensorflow.keras.preprocessing.image import ImageDataGenerator
# create a data generator
datagen = ImageDataGenerator(
        samplewise_center=True,  # set each sample mean to 0
        rotation_range=10,  # randomly rotate images in the range (degrees, 0 to 180)
        zoom_range = 0.1, # Randomly zoom image 
        width_shift_range=0.1,  # randomly shift images horizontally (fraction of total width)
        height_shift_range=0.1,  # randomly shift images vertically (fraction of total height)
        horizontal_flip=True,  # randomly flip images
        vertical_flip=False) # we don't expect Bo to be upside-down so we will not flip vertically
```

```python
## 20195298 박준용 ##

# load and iterate training dataset
train_it = datagen.flow_from_directory('data/fruits/train/', 
                                       target_size=(224, 224), 
                                       color_mode='rgb', 
                                       class_mode="categorical")
# load and iterate validation dataset
valid_it = datagen.flow_from_directory('data/fruits/valid/', 
                                      target_size=(224, 224), 
                                      color_mode='rgb', 
                                      class_mode="categorical")
```

```python
model.fit(train_it,
          validation_data=valid_it,
          steps_per_epoch=train_it.samples/train_it.batch_size,
          validation_steps=valid_it.samples/valid_it.batch_size,
          epochs=10)
```



</div>
</details>


<img width="803" alt="20195298_박준용" src="https://user-images.githubusercontent.com/79856225/172140056-2a099223-1118-4f85-8054-8308e8b7f6bd.png">


<!-- 
<details>
<summary>  </summary>
<div markdown="1">  


</div>
</details> -->
