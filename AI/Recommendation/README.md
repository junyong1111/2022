## 추천 시스템 기술

#### 유트브와 넷플릭스와 같은 머신 러닝 알고리즘을 이용하여 추천 시스템 구현

- 선수 지식

  - Tensorflow
  - DSSTNE(Amazon)
  - Sagemaker
  - Apach Spark

- 맛보기 단계
  - python3를 위한 가상환경 (아나콘다)
  - http://media.sundog-soft.com/RecSys/RecSys-Materials.zip 다운로드 후 압축해제
  - http://media.sundog-soft.com/RecSys/ml-latest-small.zip 10만개에 개의 영화 평점 데이터 셋
  - 위 데이터 폴더를 Materials 폴더로 이동 후
  - RecSys-Materials/GettingStarted.py 파일 실행
    - 특이값 분해 SVD를 이용하여 나랑 비슷한 취향의 영화 추천 (임의의 85번 유저에 데이터를 기반)
