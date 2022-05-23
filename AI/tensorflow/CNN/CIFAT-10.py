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

(x_train, y_train), (x_test, y_test) = cifar10.load_data()
print(x_train.shape, y_train.shape)
print(x_test.shape, y_test.shape)

class_names = ['airplane', 'automobile', 'bird', 'cat',
               'deer', 'dog', 'frog', 'horse',
               'sheep', 'truck']
sample_size = 9
random_idx = np.random.randint(60000, size=sample_size)

plt.figure(figsize= (5,5))
for i, idx in enumerate(random_idx):
    plt.subplot(3,3, i+1)
    plt.xticks([])
    plt.yticks([])
    plt.imshow(x_train[i], cmap = 'gray')
    plt.xlabel(class_names[int(y_train[i])])
plt.show()

################################## 모델 다운로드 ###########################

x_mean = np.mean(x_train, axis= (0,1,2))
x_std = np.std(x_train, axis=(0,1,2))

x_train = (x_train - x_mean) / x_std
x_test = (x_test - x_mean) / x_std

x_train, x_val, y_train, y_val = train_test_split(x_train, y_train,
                                                  test_size= 0.3)

print(x_train.shape, len(y_train))
print(x_val.shape, len(y_val))
################################ 모델 데이터셋 전처리 ############################

model = tf.keras.models.Sequential()
model.add(tf.keras.layers.Conv2D(filters = 32, kernel_size = 3, padding = 'same',
                                 activation = 'relu', input_shape =(32,32,3)))
model.add(tf.keras.layers.Conv2D(filters = 32, kernel_size = 3, padding = 'same',
                                 activation = 'relu'))
model.add(tf.keras.layers.MaxPool2D(pool_size = (2,2), strides = 2, padding ='same'))

model.add(tf.keras.layers.Conv2D(filters = 64, kernel_size = 3, padding = 'same',
                                 activation = 'relu'))
model.add(tf.keras.layers.Conv2D(filters = 64, kernel_size = 3, padding = 'same',
                                 activation = 'relu'))
model.add(tf.keras.layers.MaxPool2D(pool_size = (2,2), strides = 2, padding ='same'))

model.add(tf.keras.layers.Conv2D(filters = 128, kernel_size = 3, padding = 'same',
                                 activation = 'relu'))
model.add(tf.keras.layers.Conv2D(filters = 128, kernel_size = 3, padding = 'same',
                                 activation = 'relu'))
model.add(tf.keras.layers.MaxPool2D(pool_size = (2,2), strides = 2, padding ='same'))
model.add(tf.keras.layers.Flatten())
model.add(tf.keras.layers.Dense(256, activation = 'relu'))
model.add(tf.keras.layers.Dense(10, activation = 'softmax'))

model.compile(optimizer = tf.keras.optimizers.Adam(1e-4),
              loss = 'sparse_categorical_crossentropy',
              metrics = ['Acc'])
############################# 모델 구성하기 #############################
### categorical_crossentropy -> 원핫인코딩
### sparse_categorical_crossentropy -> 0~9의 레이블 그대로 사용
model.summary()

history = model.fit(x_train, y_train,
                    epochs = 2,
                    batch_size = 32,
                    validation_data=(x_val,y_val))

############################ 모델학습하기 ################################

his_dict = history.history
loss = his_dict['loss']
val_loss = his_dict['val_loss']

epochs = range(1, len(loss) +1)
fig = plt.figure(figsize=(10,5))
ax1 = fig.add_subplot(1,2,1)
ax1.plot(epochs, loss, color= 'blue', label = 'train_loss')
ax1.plot(epochs, val_loss, color = 'orange', label = 'val_loss')
ax1.set_title('train and val loss')
ax1.set_xlabel('epochs')
ax1.set_ylabel('loss')
ax1.legend()

acc = his_dict['Acc']
val_acc = his_dict['val_Acc']

ax2 = fig.add_subplot(1,2,2)
ax2.plot(epochs, acc, color= 'blue', label = 'train_acc')
ax2.plot(epochs, val_acc, color= 'orange', label = 'val_acc')
ax2.set_title('train and val loss')
ax2.set_xlabel('epochs')
ax2.set_ylabel('acc')
ax2.legend()

plt.show()