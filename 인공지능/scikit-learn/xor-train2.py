import pandas as pd
from sklearn import svm, metrics

xor_input = [
    [0,0,0],
    [0,1,1],
    [1,0,1],
    [1,1,0]
]

xor_df = pd.DataFrame(xor_input)
xor_data = xor_df.loc[:,0:1] 
xor_label = xor_df.loc[:,2]

## 데이터 학습 
clf = svm.SVC()
clf.fit(xor_data, xor_label)

## 데이터 예측
pre = clf.predict(xor_data)

## 정답률 구하기
acc_score = metrics.accuracy_score(xor_label, pre)
print("정답률:", acc_score)