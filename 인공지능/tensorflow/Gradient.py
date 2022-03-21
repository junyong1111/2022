import matplotlib
import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

t1 = tf.Variable([1,2,3], dtype=tf.float32) # 고정형 tensor 선언
t2 = tf.Variable([10,20,30], dtype=tf.float32) # 변수형 tensor 선언

with tf.GradientTape() as tape: 
    t3 = t1 * t2  # 순방향 계산을 tape에 저장

gradients = tape.gradient(t3,[t1,t2]) # t3를 t1 ,t2로 편미분
print(type(gradients)) 

print("dt1:", gradients[0]) ## t3를 t1으로 편미분 즉 t2값만 있음
print("dt2:", gradients[1]) ## t3를 t2으로 편미분 즉 t1값만 있음

############################################################################

X_data = tf.random.normal(shape=(1000,), dtype= tf.float32)
Y_data = 3*X_data +1
w = tf.Variable(-1.)
b = tf.Variable(-1.)

Learning_late = 0.01
w_trace , b_trace = [],[]
EPOCH = 10
for epoch in range(EPOCH):
    for x, y in zip(X_data, Y_data):
        with tf.GradientTape() as tape:
            prediction = w*x + b
            loss = (prediction-y)**2
            
        gradients = tape.gradient(loss, [w,b])
        
        
        w_trace.append(w.numpy())
        b_trace.append(b.numpy())
        w = tf.Variable(w - Learning_late *gradients[0])
        b = tf.Variable(b - Learning_late * gradients[1])


fig , ax = plt.subplots(figsize=(20,10))

ax.plot(w_trace, label = 'weight')
ax.plot(b_trace, label = 'bias')

ax.tick_params(labelsize= 20)
ax.legend(fontsize = 30)

plt.show()