# 모두의 딥러닝


**강의 목표** 

- 머신러닝에 대한 기본적인 이해
    - Linear regression
    - Logistic regression
- Tensorflow 사용

**목차** 

1. Machine Learning Basics(머신러닝이란 무엇인가)
2. Linear Regression(선형 회귀)
3. Logistic Regression(로지스틱 회귀)
4. Multivariable linear/logistic regression(다중 선형/로지스틱 회귀)
5. Neural networks(뉴럴 네트워크)
6. Deep Learning(딥러닝)
    1. CNN
    2. RNN
    3. Bidirectional Neural networks



1. Machine Learning Basics(머신러닝이란 무엇인가)

1959년 Arthur Samel

- 개발자가 아닌 프로그램이 스스로 데이터를 학습하는 개념 제시

**머신러닝의 종류**

- **Supervised Learning(지도 학습)**
    - 데이터와 정답을 같이 학습한다(예측,분류)
- **Unsupervised Learning(비지도 학습)**
    - 데이터로만 학습하여 정답값을 스스로 유추한다(군집화)
- **Reinforsement Leaning(강화 학습)**
    - 맞췄을 때는 보상을 틀렸을 때는 패널티를 줘서 스스로 학습 (알파고)

일반적인 문제는 지도학습으로 해결이 가능하다.

- Image Labeling
- Email spam filter
- Predicting exam score

### Supervised Leaning(지도 학습)

지도학습은 크게 2가지 종류로 나눌 수 있다.

1. **Regression**
    1. 연속된 값을 **예측**
2. **Classificaion**
    1. 개와 고양이와 같이 이산적인 값을 **분류**할 때 사용
    - Binary Classification(2가지 분류)
    - Multi-label Classification(3가지 이상 분류)
1959년 Arthur Samel

- 개발자가 아닌 프로그램이 스스로 데이터를 학습하는 개념 제시

**머신러닝의 종류**

- **Supervised Learning(지도 학습)**
    - 데이터와 정답을 같이 학습한다(예측,분류)
- **Unsupervised Learning(비지도 학습)**
    - 데이터로만 학습하여 정답값을 스스로 유추한다(군집화)
- **Reinforsement Leaning(강화 학습)**
    - 맞췄을 때는 보상을 틀렸을 때는 패널티를 줘서 스스로 학습 (알파고)

일반적인 문제는 지도학습으로 해결이 가능하다.

- Image Labeling
- Email spam filter
- Predicting exam score

### Supervised Leaning(지도 학습)

지도학습은 크게 2가지 종류로 나눌 수 있다.

1. **Regression**
    1. 연속된 값을 **예측**
2. **Classificaion**
    1. 개와 고양이와 같이 이산적인 값을 **분류**할 때 사용
    - Binary Classification(2가지 분류)
    - Multi-label Classification(3가지 이상 분류)


