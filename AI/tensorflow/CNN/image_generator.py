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
    vertical_flip = True,
    shear_range = 0.5,
    brightness_range = [0.5, 1.5],
    zoom_range = 0.2,
    width_shift_range = 0.1,
    height_shift_range = 0.1,
    rotation_range = 30,
    fill_mode = 'nearest'
)

test = img_to_array(load_img('TEST_IMG')).astype(np.uint8)
plt.figure()
plt.imshow(test)


test = test.reshape((1,) + test.shape)
test_generator = train_datagen.flow(test, batch_size= 10)
plt.figure(figsize = (5,5))
for i in range(9):
  data = next(test_generator)
  image = data[0]
  plt.subplot(3,3, i+1)
  plt.xticks([])
  plt.yticks([])
  plt.imshow(np.array(image, dtype = np.uint8), cmap = 'gray')
plt.show()
### 9개의 데이터 증폭 

