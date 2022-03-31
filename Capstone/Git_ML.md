ML
- **YOLOv3**
###### 사용한 **YOLO V3**모델은 **You Only Look Once**의 약자로써, 객체 탐지(Object detection)분야에서 많이 알려져 있으며 이미지를 한 번 보는 것으로 물체의 종류와 위치를 추측한다.
###### **YOLO v3**는 이전v2버전을 더욱 개량하여 정확도를 향상시켰다.


### 학습환경

- Google Colab  
(코랩에서 진행하는 이유)
    - ###### YOLO를 학습시키기 위해서는 Darknet을 사용해야하는데 설치 조건이 까다롭기 때문에 공통적인 환경을 위하여 
    - ###### Linux 환경
    - ###### GPU연산 가능  
##### #주의점 : Colab 무료버전은 최대 런타임 시간은 12시간이므로 구글 드라이브를 통한 데이터 백업 필요

### How to start

- ##### 최초 1회 실행시 구글 드라이브에 Darknet 환경 저장
- ##### 런타임 → 런타임 유형 변경 → 하드웨어 가속기(CPU) → 하드웨어 가속기(GPU)로 설정
```python
    from google.colab import drive
    drive.mount('/content/gdrive')
```







어떻게 시작하는지 
환경설정
파일구조 
코랩에서 






