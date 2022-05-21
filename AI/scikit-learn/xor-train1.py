## XOR 연산 학습
from sklearn import svm
import matplotlib.pyplot as plt

xor_data = [
    [0,0,0],
    [0,1,1],
    [1,0,1],
    [1,1,0]
]

data = []
label = []
for row in xor_data:
    p = row[0]
    q = row[1]
    r = row[2]
    data.append([p,q])
    label.append(r)
    print("p:",p ," q:",q," r:",r," data:",data," label:",label)
    
## 데이터 학습
clf = svm.SVC()
clf.fit(data, label)

# 데이터 예측하기
pre = clf.predict(data)
print("예측결과:", pre)

# 결과 확인하기
ok =0; total =0
for idx, answer in enumerate(label):
    p = pre[idx]
    if p == answer: ok+=1
    total +=1
print("정답률:", ok, "/", total, "=", ok/total)





