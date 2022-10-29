# Computer Vision

컴퓨터 비전은 이미지에서 시작한다.

### **컴퓨터가 이미지를 이해하는 과정**

- 샘플링
    - 2차원 영상 공간을 M*N(해상도)으로 샘플링
- 양자화
    - 처리속도와 해상도 사이에 트레이드오프가 존재
    

### **과학적 접근과 공학적 접근**

**목표 1.** 사람의 시각에 맞먹는 인공 시각을 만든다.

**목표 2.** 한정된 범위에서 특정한 임무를 달성하는 인공 시각을 만든다.

- 과학적 접근(강 인공지능)
    - **목표 1을 달성하려는 노력**
    - 사람 시각의 원리를 밝혀낸 다음 컴퓨터로 모방
    - 인공 지능이 필수
- 과학적 접근이 어려운 점
    - 역 문제
        - 3차원 →2차원으로 변환시 3차원에 대한 정보 손실 발생
    - 불량 문제(ill - posed problem : 정답이 없는 문제)
    - 다양한 변형 발생
- 공학적 접근(약 인공지능)
    - **목표 2를 달성하려는 노력**
        - 강 인공지능은 상당히 어렵기 때문에 특정한 목적을 위한 인공 시각을 만든다.
    - 한정된 범위에서 특정한 임무를 달성하는 인공 시각을 만든다.
        - 많은 응용 현장에서 사용 중이며 사람보다 뛰어난 경우 존재

### 계층적 처리

- 전처리
    - 영상처리(노이즈 등 잡음 제거 작업)
- 특징 추출
    - 특징 등을 검출하고 특징 벡터 추출
- 해석
    - 응용에 따라 다양한 형태
    
    영상 ⇒ 전처리 ⇒ 특징 추출(저급 비전) ⇒ 해석(고급 비전)⇒ 고급 묘사

### 시스템 설계

<aside>
🪜 문제 ⇒ 데이터베이스 수집 ⇒ 알고리즘 설계와 구현 ⇒ 성능 평가

</aside>

1. **문제 이해**
- 주어진 문제에 대한 직관적이고 철저한 이해 중요
    - 합리적 제약 조건 수립 필요
    - ex) 얼굴 인식기
        - 크기가 일정한 정면 얼굴 vs 자연 영상 속 얼굴
        - 전자는 제작이 쉽지만 응용 분야가 한정된다.
            - 보안 장치 O
            - 응용 적용 불가능
2. **데이터베이스 수집**
- 질적으로 양적으로 우수해야 고성능 시스템 제작 가능
- 데이터베이스 = 학습 집합 + 테스트 집합
- 수집 방법
    - 직접 수집(많은 비용을 부담해야 하지만 개발자에게는 자산이 된다)
    - 인터넷에서 다운로드(고품질의 데이터베이스 풍부함)

3. **알고리즘 설계와 구현**

- 알고리즘 선택의 중요성과 어려움
    - 새로운 알고리즘 개발 또는 기존 알고리즘 중에서 주어진 문제에 적합한 것 선택
    - ex) 손 동작 인식기 제작
        - 엣지, 영역, 지역 특징 중에 어떤 것을 사용?
            - 영역을 사용한다면 어떤 영상 분할 알고리즘?
            - 어떤 추적 알고리즘?
- 선택 방법
    - 데이터베이스를 이용하여 성능 실험(설계자의 경험과 직관이 중요)
    - **성능 비교 분석 논문을 참조**
- 프로그래밍
    - OpenCV(부록 A)
    - Matlab이 제공하는 IPT(Image Processing Toolbox)
    - 오픈소스
1. **성능 평가**
    
    
    | True Positive(TP) | 실제 True인 정답을 True라고 예측 (정답) |
    | --- | --- |
    | True Negative(TN) | 실제 False인 정답을 True라고 예측(정답) |
    | False Positive(FP) | 실제 False인 정답을 True라고 예측(오답) |
    | False Negative(FN) | 실제 True인 정답을 False라고 예측(오답) |
    
    Positive ⇒ 정답으로 예측
    
    Negative ⇒ 오답으로 예측
    
    True ⇒ 정답
    
    False ⇒ 오답
    
    ex) 
    
    - False Positive
        - 잘못된것을 정답이라고 예측
    
    1. Precision(정밀도)
        - 모델이 True(정답)라고 분류한 것 중에서 실제 True(정답)인 것의 비율
        
        Precision = $TP / TP+FP$
        
    
    b.  Recall(재현율)
    
    - 실제 True(정답)인것 중에서 모델이 True(정답)라고 에측한 것의 비율
    
    Recall =  $TP/ TP + FN$

    ## Basic operation

### 영상 처리

- 주어진 목적을 달성하기 위해 원래 영상을 새로운 영상으로 변환
- 컴퓨터 비전의 전처리 과정

### 히스토그램

용도 : 영상의 특성 파악

- [0,L-1] 사이의 명암값 각각이 **영상에 몇 번 나타나는지 표시**
- 히스토그램 h와 정규화 히스토그램

**히스토그램 용도**

- 히스토그램 평활화
    - 히스토그램을 **평평하게** 만들어 주는 연산
    - 명암의 **동적 범위를 확장**하여 **영상의 품질을 향상**
    - 누적 히스토그램 c(.)를 매핑 함수로 사용
    
    → 영상처리 연산은 분별력을 가지고 활용 여부를 결정
    
    **(무조건 품질이 향상되는 것은 아님)**
    

### 이진화(Binaryization, Binary Image)

**이진화**

- 명암 영상을 **흑과 백**만 가진 이진 영상으로 변환

**임계값(threshold) 방법**

- 두 봉우리 사이의 계곡을 임계값 T로 결정
- 자연 영상에서는 계곡 지점 결정이 어려움

### 영상 처리의 세 가지 기본 연산

1. 점 연산
    - 오직 자신의 명암값에 따라 새로운 값을 결정
    - 선형 연산
        - K=1인경우
    - 비선형 연산
        - 감마 수정(모니터나 프린터 색상 조절에 사용)
    - 디졸브
        - K=2인경우
2. 영역 연산(Filter 처리관련)
    - 이웃 화소의 명암값에 따라 새로운 값 결정
    - 상관(correlation)
        - 원시적인 매칭 연산(물체를 **윈도우 형태로 표현**하고 물체를 검출)
    - 컨볼루션
        - 윈도우를 뒤집은 후 상관 적용
        - 선형 연산
        - 임펄스 반응
        - 예제
            - 박스와 가우시안은 스무딩 효과
            - 샤프닝은 명암 대비 강조 효과
            - 수평 에지와 수직 에지는 에지 검출 효과
        - 비선형 연산
            - 메디안 필터
                - 솔트페퍼 잡음에 효과적임
                - **메디안은 가우시안 비해 에지 보존 효과 뛰어남**
        
        ![스크린샷 2022-10-25 오후 10.00.37.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f32d3172-8dfc-4946-9f08-174a2d0fe943/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-10-25_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_10.00.37.png)
        
    
    여기서는 상관, 컨볼루션 둘을 구분하지 않고 컨볼루션이라는 용어를 사용

여기서는 상관, 컨볼루션 둘을 구분하지 않고 컨볼루션이라는 용어를 사용

3. 기하 연산
    - 일정한 기하 연산으로 결정된 화소의 명암값에 따라 새로운 값 결정
    - 동차 좌표(Homogeneous coordinate)와 동차 행렬
    
    동차 좌표 사용 이유
    
    ⇒ 복합 변환을 이용한 계산 효율
    
    ex) 이동 후 회전은 두 번의 행렬  곱셈, 하지만 복합 변환을 이용하면 한 번의 곱셈
    
    ### Gaussian Filtering
    
    블러한 이미지를 얻을 수 있음
    
    ![스크린샷 2022-10-25 오후 10.54.04.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2f74ace7-5510-47ef-bcaf-20cabaad89b3/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-10-25_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_10.54.04.png)
    
    분산 값 ⇒ 필터의 사이즈 
    
    → **분산 값이 커지면 이미지가 더 흐려진다**
    
    ### Edges
    
    - 물체 내부나 배경은 변화가 없거나 작음
    - **물체 경계는 변화가 큼**
    
    → 명암,컬러  또는 텍스처의 변화량을 측정하여 **변화량이 큰 곳을 Edge로 검출**
    
    **Edge를 사용하는 이유**
    
    - 물체의 경계를 표시해 줌
        
        → 물체를 구별할 수 있음
        
    - 매칭에 용이한 선분이나 곡선으로 변환 가능
    
    **Edge의 한계**
    
    - 실종된 Edge(거짓 부정). 거짓 Edge(거짓 긍정)발생
    - 이들 오류를 어떻게 최소화?
    
    **Detection edges**
    
    - What’s an edge?
        - intensity discontinuity ⇒ **rapid change**
    - **How** can we **find large changes** in intensity?
        - **gradient operator** seems like the right solution
    
    **Image gradient**
    
    - How can we differentiate a digital image F[x,y]?
        - Option 1 : reconstruct a continuous image, f, then take gradient
        - **Option 2 : take discrete derivative (finite difference)**
        
        ![스크린샷 2022-09-19 오후 12.31.31.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e5886def-c262-4444-8c4c-cfa4a8c76e16/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-09-19_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_12.31.31.png)
        
    
    **디지털 영상의 미분**
    
    - |X-1 | X | X+1|
        - ex) 1차 미분에 해당하는 마스크
            - f’(x) → f(x+1) - f(x)
                - △x = 1
                
                ![스크린샷 2022-09-19 오후 12.45.42.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5018835a-24e2-41a1-a683-278525f21d05/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-09-19_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_12.45.42.png)
                
        - ex) 2차 미분에 해당하는 마스크
            - f’’(x) →f’(x) - f’(x-1)
            - △x = 1
            
            → f’(x) = f(x+1) - f(x)
            
            → f’(x-1) = f(x) - f(x-1) 
            
            → f(x-1) - 2f(x) + f(x+1)
            
            ![스크린샷 2022-09-19 오후 12.48.36.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0841925e-23f0-4708-a3d4-0648b59b9e67/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-09-19_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_12.48.36.png)
            
    
    **Edge 검출 과정**
    
    - **1차 미분에서 봉우리**
    - **2차 미분에서 영교차를 찾음**
    
    **현실에서는 잡음 때문에 스무딩이 필요 (가우시안 필터 사용)**
    
    - △x = 2 로 설정
    - 이에 해당하는 2차미분 마스크
    
    ![스크린샷 2022-09-19 오후 12.56.13.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5ea874ab-4319-48b7-992f-91c7e183515a/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-09-19_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_12.56.13.png)
    
    **2차원 정방형으로 확장하여 스무딩 효과**
    
    ![스크린샷 2022-09-19 오후 1.02.08.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c8c7f8c5-09b1-42e3-b92a-487c99713254/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-09-19_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_1.02.08.png)
    
    **Edge 검출 연산**
    
    - **엣지의 방향은 그래디언트와 수직**이다.
    - 잡음이 심한 경우 1차미분과 2차미분은 잡음을 증폭시킴
        
        **→ 가우시안을 사용**해야 하는 이유
        
    1. 이미지(f) → 가우시안 필터를 적용 (잡음 제거)
    2. 엣지 찾기 필터 적용(1차 미분)
    
    **총 2번의 필터 연산을 사용**
    
    미분+가우시안(DOG?) 필터가 있다고 가정하면 1번의 연산으로 엣지를 찾을 수 있음
    
    가우시안을 미분 → 이미지 곱하기
    
    **LOG 필터**
    
    - LOG 필터 : (가우시안+ 2차미분)
    
    가우시안 → 2차미분 → 이미지 컨볼루션 → 영교차 검출
    
    ![스크린샷 2022-09-21 오후 12.38.28.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/99747be9-8f09-4940-914d-f7d86c9b943a/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-09-21_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_12.38.28.png)
    
    라플라시안:  2차미분 필터
    
    **가우시안과 scale**
    
    - 이미지를 줄여주는 것 → 가우시안 블러 ↑
    - 블러↑,   이미지 축소 → 스케일이 커짐
    - 이미지의 Size와는 관계가 없고 관찰자 입장에서 이미지를 넓게 본다는 의미
    
    ![스크린샷 2022-09-21 오후 12.54.04.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/45982ceb-f190-4514-b742-32babdf7dd7d/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-09-21_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_12.54.04.png)
    
    ### Supervised Learning
    
    **회귀(Regression)**
    
    - **Regression : 정답값이 실수 real-valued**
        - ex) 몸무게, 키
    
    **분류(Classification)**
    
    - **Classification : 정답값이 명확함 categorical**
        - ex) 고양이, 강아지
    
    ### Unsupervised Learning
    
    **군집화(Clustring)**
    
    - 군집화 : 유사한 특징 벡터들을 끼리끼리 모음(K-means, SOM 신경망, 민시프 등..)
    
    ### Reinforcement Learning
    
    - 강화학습
    
    ### 일반화 능력
    
    - 학습 과정에서 사용하지 않은 테스트 집합으로 학습이 완료된 분류기 성능 평가
    - 학습 집합과 테스트 집합에 대한 성능이 비슷하면 일반화 능력이 뛰어남
    - **과적합** 하면 일반화능력이 떨어짐
        - 과적합 : 주어진 데이터셋은 잘 맞추지만 새로운 데이터셋은 맞추지 못함
    
    ### **Regression**
    
    **Linear Regression Problem**
    
    - Input : Dataset Z = {(x1, y1), …. (xn, yn)}
    - Output : A linear function
    
    **Lost function (Cost Function)**
    
    손실함수 : 학습에 대한 기준
    
    ![스크린샷 2022-09-26 오후 12.38.25.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/82337a3c-281c-44df-88b1-0d0dc880b6f0/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-09-26_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_12.38.25.png)
    
    cost funtion + linear regression ⇒ 무조건 convex
    
    **Underfitting(High Bias)**
    
    - 학습데이터와 테스트데이터 모두 예측 못함
    - 학습데이터가 충분하지 않았을 때 발생
        - 학습데이터를 증가시켜줘야 함
    
    **Overfitting(High Variance)**
    
    - 학습데이터는 잘 예측하지만 테스트데이터는 예측 못함
    - capacity 가 들어날수록 표현력이 높아지지만 과적합에 빠지기 쉬워진다.
    - 규제를 이용하여 방지할 수 있음
        - 주어진 데이터 Z를 Traing data 와 Test data로 나누어서 학습 진행
    
    ### Classification
    
    - Binary Classification
        - 2개 값을 예측
    - Multiclass Classification
        - 3개 이상의 값을 예측
    
    Linear 모델로는 분류 Task를 해결하기 어려웠다(XOR)문제를 해결하기 힘들다.
    
    **→ Logistic Regression 을 이용하여 이를 해결**
    
    연속된 값 (input) → 연속된 값(output) ⇒ Linear Regression
    
    연속된 값 (input) → 이산된 값(output) ⇒ Logistic Regression
    
    분류와 같은 이산적인 값을 예측하는 Task에서는 Gradient Descent(Linear Regrssion)을 이용하여 해결하기 힘들다. 이 때 Sigmoid 이용하면 해결이 가능하다
    
    ![스크린샷 2022-10-25 오후 11.54.06.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7fd68e9b-eeb6-4112-88bc-6b7021e4078e/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-10-25_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_11.54.06.png)
    
    활성화 함수 ⇒ Cross-entropy loss를 
    
    ⇒ entropy는 모든 정보를 알아야 함
    
    ⇒ 애매한 값에서는 값이 커짐 즉, 맞거나 틀리거나로 학습
    
    ![스크린샷 2022-10-25 오후 11.52.35.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b12f8c81-e57f-48df-a4aa-b72618438ef2/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2022-10-25_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_11.52.35.png)
    
    **Multi Classification에서는** **SoftMax(활성함수)를 사용하여 확률값으로 바꿔준다.**
    
    Binary Classifiaction → Logistic Sigmoid(활성함수) →  Cross-entropy loss 
    
    Multi Classifiaction → SoftMax활성함수) →  Cross-entropy loss 
    
    ### Gradient Descent
    
    → 항상 글로벌 미니멈에 빠지는건 아님
    
    확률론적 경사 하강법(SGD)
    
    샘플 한 개만을 랜덤으로 뽑아서 업데이트(속도가 빠름)
    
    → 이상한 샘플이 끼면 노이즈가 심할 수 있음
    
    → 모든 데이터를 이용하는게 아닌 배치 사이즈를 이용
    
    **unbised estimate**
    
    모든 데이터를 사용 ⇒ Gradient Descent
    
    1개의 데이터만을 사용 ⇒Sthochastic Gradient Descent
    
    위 2개의 장점만을 사용 ⇒ mini-batch Sthochastic Gradient Descent
    
    ⇒ 전체 데이터가 아닌 특정 사이즈의 미니 배치 사이즈의 데이터만을 사용