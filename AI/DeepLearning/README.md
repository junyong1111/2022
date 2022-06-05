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



<!-- 
<details>
<summary>  </summary>
<div markdown="1">  


</div>
</details> -->