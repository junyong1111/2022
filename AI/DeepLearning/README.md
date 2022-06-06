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




<img width="803" alt="20195298_박준용" src="https://user-images.githubusercontent.com/79856225/172140056-2a099223-1118-4f85-8054-8308e8b7f6bd.png">



<!-- 
<details>
<summary>  </summary>
<div markdown="1">  


</div>
</details> -->