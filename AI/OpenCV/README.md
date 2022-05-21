### OpenCV ??  
OpenCV : 다양한 이미지/영상 처리를 위한 Python 오픈소스 라이브러리이며 뿐만 아니라 BSD(Berkeley Software Distribution) 라이센서를 따르기 때문에 상업적으로 사용이 가능하다! 참고로 OpenCV는 RGB 순서가 아니라 BGR순서이다.

# Step1. OpenCV라이브러리 설치

다음 명령어를 사용하여 OpenCV 라이브러리 설치
```python
pip install opencv-python
```
OpenCV라이브러리가 설치되었으면 이제 python 파일 하나를 생성 후 확인

```python
import cv2 ## OpenCV 라이브러리 
print(cv2.__version__) ## 버전확인
```
```python
4.5.5
```
# Step2. 이미지/영상 출력

* ### OpenCV를 이용하여 이미지를 화면에 출력
[무료_이미지_사이트](https://pixabay.com/ko/)


```python
import cv2
image = 'test.jpg' # 출력하고싶은 이미지 경로   
image = cv2.imread(image) # imread()함수로 이미지 읽어오기
image.shape #이미지의 세로 가로
image = cv2.imshow('보여지는 이름', image)  # imshow()함수를 이용하여 새로운 창에서 이미지를 출력
cv2.waitKey() # 아무키나 입력받을때까지 대기
cv2.destroyAllWindows()# 모든 창 닫기
```
결과  

![test](https://user-images.githubusercontent.com/79856225/166098760-f251f92d-0bb6-46f6-82ce-c2595a480e66.jpg)

아무키나 눌러서 종료


뿐만 아니라 다양한 함수로 이미지의 색상등을 변경 가능
```python
image = cv2.imread(image, cv2.IMREAD_COLOR)
##일반 cv2.imread(image)랑같다
Gray = cv2.imread(image, cv2.IMREAD_GRAYSCALE)
## 흑백으로 변경
Unchanged = cv2.imread(image, cv2.IMREAD_UNCHANGED)
## 투명영역 포함

cv2.imshow("Normal", image) ## 일반 출력
cv2.imshow("GRAY", Gray) ## 흑백 출력
cv2.imshow("Unchanged", Unchanged) ## 투명 포함 출력
cv2.waitKet()
cv2.destroyAllWindows()
```

* ### OpenCV를 이용하여 동영상을 화면에 출력

이번에는 동영상파일 읽어오기  
[무료_동영상_사이트](https://www.pexels.com/ko-kr/videos/)  
 해당 사이트에서 마음에드는 동영상 저장 후 다음 실습코드 사용


```python
import cv2

Video = cv2.VideoCapture("test.mp4")## 동영상 경로
## 동영상은 이미지의 연속이므로 반복문을 이용하여 출력

while Video.isOpened():
    ret , frame = Video.read() 
    ## ret -> 결과값이 있는지 없는지(성공여부)
    ## frame -> 영상에서 읽어 온 이미지
    
    if not ret : # 더 읽을 영상이 없다면
        print("동영상 종료")
        break
    
    cv2.imshow("Video", frame)
    
    if cv2.waitKey(25) == ord('q'): ##만약 q를 입력하면 종료 숫자를 조절해서 재생속도 컨트롤 가능
        print("동영상 재생 종료.")
        break

Video.release() ## Video 자원 종료
cv2.destroyAllWindows()
```

# Step3. OpenCV 도형그리기
- OpenCV를 이용하여 도형그리기

### 빈 스케치북 만들기

```python
import cv2
import numpy as np
### 세로 480 X 가로 640,3채널
img = np.zeros((480,640,3),dtype=np.uint8)
img [:] = (255,255,255)
## 전체 공간을 흰색으로
print(img)
cv2.imshow("img",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 특정 영역 색칠

```python
import cv2
import numpy as np
img = np.zeros((480,640,3),dtype=np.uint8)
img [100:200, 200:300] = (255,255,255) 
## 세로 : 100~200
## 가로 : 200~300 
## 정해진 공간을 흰색으로 
cv2.imshow("img", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 직선
- 직선의 종류  
cv2.LINE_4 : 상하좌우 4 방향으로 연결된 선  
cv2.LINE_8 : 대각선을 포함한 8방향으로 연결된 선(기본값)  
cv2.LINE_AA : 부드러운 선  

```python
import cv2
import numpy as np
img = np.zeros((480,640,3),dtype=np.uint8)

COLOR = (0,255,255)
## BGR : Yellow
THICKNESS = 3 
## 두께

cv2.line(img. (50,100),(400,50),COLOR, THICKNESS, cv2.LINE_8)
## X1,Y1 -> X2,X2 직선

cv2.line(img. (50,200),(400,150),COLOR, THICKNESS, cv2.LINE_8)
## Line_4

cv2.line(img. (50,300),(400,250),COLOR, THICKNESS, cv2.LINE_8)
## Line_AA

cv2.imshow("img", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 원

```python
import cv2
import numpy as np
img = np.zeros((480,640,3),dtype=np.uint8)

COLOR = (255,255,0)
## BGR : 옥색
THICKNESS = 10
## 두께

RADIUS = 50 
## 원은 반지름이 필요

cv2.circle(img, (200,100), RADIUS, COLOR, THICKNESS, cv2.LINE_AA)
## 속이 빈 원

cv2.circle(img, (200,100), RADIUS, COLOR, cv2.FILLED, cv2.LINE_AA)
## 두께인자를 cv2.FILLED 또는 -1을 입력  -> 속이 꽉 찬 원

cv2.imshow("img", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```


### 사각형
```python
import cv2
import numpy as np
img = np.zeros((480,640,3),dtype=np.uint8)

COLOR = (0,255,0)
## BGR : 녹색
THICKNESS = 3
## 두께

cv2.rectangle(img,(100,100),(200,200), COLOR,THICKNESS)
## 속이 빈 사각형

cv2.rectangle(img,(300,100),(400,300), COLOR,-1)
## 속이 꽉 찬 사각형

cv2.imshow("img", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 다각형

```python
import cv2
import numpy as np
img = np.zeros((480,640,3),dtype=np.uint8)

COLOR = (0,0,255) 
## BGR : RED
THICKNESS = 3
## 두께

point1 = np.array([[100,100], [200,100], [100,200]])

point2 = np.array([[200,100],[300,100],[300,200]])

point3 = np.array( [[[100,300],[200,300],[100,400]], [[200,300],[300,300],[300,400]]] ) 

cv2.polylines(img, [point1], True, COLOR, THICKNESS, cv2.LINE_AA)
## 닫힘 여부 = True 시작과 끝을 연결

cv2.polylines(img, [point2], False, COLOR, THICKNESS, cv2.LINE_AA)
## 닫힘 여부 = False 시작과 끝을 연결하지 않음

cv2.fillPoly(img,point3,COLOR,cv2.LINE_AA)
## 꽉 찬 다각형

cv2.imshow("img", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

# Step4. 텍스트 

### OpenCV 기본 텍스트
1. cv2.FONT_HERSHEY_SIMPLEX : 보통 크기의 sans-serif 글꼴
2. cv2.FONT_HERSHEY_PLAIN : 작은 크기의 sans-serif 글꼴
3. cv2.FONT_HERSHEY_SCRIPT_SIMPLEX : 필기체 스타일 글꼴
4. cv2.FONT_HERSHEY_SCRIPT_TRIPLEX : 보통 크기의 serif 글꼴
5. cv2.FONT_ITALIC : 기울임(이탤릭체) 다른 폰트와 같이 씀

```python
import numpy as np
import cv2

img = np.zeros((480,640,3), dtype =np.uint8)

SCALE = 1
COLOR  = (255,255,255)
THICKESS = 2


cv2.putText(img, "Hello Wolrd.", (20,50), cv2.FONT_HERSHEY_SIMPLEX, SCALE, COLOR, THICKESS)


cv2.putText(img, "Hello Wolrd.", (20,150),FONT_HERSHEY_SIMPLEX | cv2.FONT_ITALIC, SCALE, COLOR, THICKESS)

cv2.imsho("img", img)
cv2.waitKey(0)
cv2.destroyALLWindow()
```

### 한글 입력  
OpenCV에서는 한글을 제공하지 않기 때문에 우회하는 방법이 필요 PIL라이브러리 필요

```python
import numpy as np
import cv2
from PIL import ImageFont, ImageDraw, Image

def HangulText(src, text, pos, font_sz, font_color):
  img = Image.fromarray(src)
  draw = ImageDraw.Draw(img)
  font = ImageFont.truetype('fonts/gulim.ttc', font_sz)
  draw.text(pos, text, font = font, fill=font_color)
  return np.array(img)

img = np.zeros((480,640,3), dtype =np.uint8)

font_sz = 30
COLOR  = (255,255,255)


img = HangulText(img, "안녕", (20,50),font_sz, COLOR)


cv2.imsho("img", img)
cv2.waitKey(0)
cv2.destroyALLWindow()
```

# Step5. 이미지/동영상 저장

### 이미지 저장
```python
import cv2
img = 'test.jpg' # 출력하고싶은 이미지 경로   
image = cv2.imread(img, cv2.IMREAD_GRAYSCALE) #
save = cv2.imwrite('img_save.jpg', img)
## 원하는 파일명.확장자를 입력 
```

### 동영상 저장
```python
import cv2
Video = cv2.VideoCapture("test.mp4")## 동영상 경로

### 코텍 정의
fourcc = cv2.VideoWriter_fourcc(*'DIVX') ## *를 붙이면 각 글자들이 띄어쓰기가 된다.
width = round(Video.get(cv2.CAP_PROP_FRAME_WIDTH))
height = round(Video.get(cv2.CAP_PROP_FRAME_HEIGHT))
## 불러온 동영상과 같은 크기로 지정
fps = Video.get(cv2.CAP_PROP_FPS)
## 불러온 동영상과 같은 FPS(영상속도)로 지정
out = cv2.VideoWriter('test.avi',fourcc, fps, (width, height))


while Video.isOpened():
    ret , frame = Video.read() 
    if not ret : 
        print("동영상 종료")
        break
    cv2.imshow("Video", frame)
    cv2.write(frame) ## 영상 데이터만 저장 가능 소리X
    if cv2.waitKey(25) == ord('q'):
        print("동영상 재생 종료.")
        break
out.release() 
## 자원해제        
Video.release() 
cv2.destroyAllWindows()
```

## Step6. 크기 조정

### 이미지
1. 사용자 지정크기로 조정
```python
import cv2
img = 'test.jpg' # 출력하고싶은 이미지 경로
img = cv2.resize(img, (400,500))
## 가로 400 X 세로 500 크기로 조정

cv2.imsho("img", img)
cv2.waitKey(0)
cv2.destroyALLWindow()
```
2. 비율로 조정

```python
import cv2
img = 'test.jpg' # 출력하고싶은 이미지 경로
img = cv2.resize(img, None, fx = 0.5, fy= 0.5)
## 가로 0.5 세로 0.5 비율로 조정

cv2.imsho("img", img)
cv2.waitKey(0)
cv2.destroyALLWindow()
```

### 보간법 사용
이미지를 조정할 때 보다 자연스럽게 처리하기 위해 사용 
1. cv2.INTER_AREA : 크기를 줄일 때
2. cv2.INTER_CUBIC :크기를 늘릴 때(속도가 느리지만 퀄리티가 높음)
3. cv2.INTER_LINEAR : 크기를 늘릴 때 (기본값)


```python
import cv2
img = 'test.jpg' # 출력하고싶은 이미지 경로
img = cv2.resize(img, None, fx = 3, fy= 3, interpolation = cv2.INTER_CUBIC)
## 가로 3배 세로 3배 비율로 조정

cv2.imsho("img", img)
cv2.waitKey(0)
cv2.destroyALLWindow()
```

### 동영상
1. 고정크기 변환
```python
import cv2
Video = cv2.VideoCapture("test.mp4")## 동영상 경로

while Video.isOpened():
  ret,frame = Video.read()
  if not ret:
    break
  fram = cv2.resize(fram, (400,500))
  cv2.imshow('Video', frame)
  if cv2.waitKey(1) == ord('q'):
    break

Video.release()
cv2.destroyAllWindows()
```
2. 비율로 변환
```python
import cv2
Video = cv2.VideoCapture("test.mp4")## 동영상 경로

while Video.isOpened():
  ret,frame = Video.read()
  if not ret:
    break
  fram = cv2.resize(fram, None, fx=1.5, fy=1.5, interpolation = cv2.INTER_CUBIC)
  cv2.imshow('Video', frame)
  if cv2.waitKey(1) == ord('q'):
    break

Video.release()
cv2.destroyAllWindows()
```



# Step 1 이미지 변형

## 이진화
원하는 값만을 걸러내기 위하여 
이미지를 오로지 흑과 백으로만 표현하는 것


### 임계값(threshold)

```python
import cv2

img = 'test.jpeg'
img = cv2.imread(img)
GRAY = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

ret, binary = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)
### 127보다 크면 흰색으로 처리
```
### 1. Trackbar

```python
img = cv2.imread('Test.jpg', cv2.IMREAD_GRAYSCALE) ## 바로 그레이스케일로 읽음

def empty(pos):
    print(pos)
    pass 
## 임계값을 프린트해주는 함수

name = 'Tracbar'
cv2.namedWindow(name) 

cv2.createTrackbar('Threshold', name, 127,255, empty)
## bar 이름 , 창 이름, 초기값, 최대값, 이벤트 처리

while True:
    thresh = cv2.getTrackbarPos('Threshold', name)
    ret, binary = cv2.threshold(img, thresh, 255, cv2.THRESH_BINARY) ## 임계값을 읽어와서 
    if not ret: ## 리턴값이 없으면 종료 
        break
    cv2.imshow(name, binary) ## 있다면 출력 
    if cv2.waitKey(1) == ord('q'): ## q가 입력된다면 종료
        break
cv2.destroyAllWindows()
```

### 2. Adaptive
이미지 전체가 아니라 영역을 세분화해서 임계치를 적용한다 일정하지 않은 이미지에 사용
```python
import cv2

def empty(pos):
    print(pos)
    pass

img = cv2.imread('Test.jpeg', cv2.IMREAD_GRAYSCALE)
name = 'Tracbar'
cv2.namedWindow(name)

## bar 이름 , 창 이름, 초기값, 최대값, 이벤트 처리
cv2.createTrackbar('block_size', name, 25, 100, empty)
## 영역을 세분화하기 위한 block size를 정의하고 홀수만 가능하며 1보다는 커야 한다.
cv2.createTrackbar('c', name, 3, 10, empty)
## c->일반저긍로 양수의 값을 사용

while True:
    block_size = cv2.getTrackbarPos('block_size', name)
    c = cv2.getTrackbarPos('c', name)
    
    if block_size <=1: ## 1이하면 가장 낮은 홀수인 3으로 변경
        block_size = 3
    if block_size %2 ==0: ## 짝수 -> 홀수로
        block_size += 1
    binary = cv2.adaptiveThreshold(img, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, block_size, c)
    # binary = cv2.adaptiveThreshold(img, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, block_size, c) ## 가우시안 

    ### 임계값이 넘어간다면 흰색으로 MEAN_C가 아닌 가우시안도 사용가능
    
    cv2.imshow(name, binary)
    if cv2.waitKey(1) == ord('q'):
        break
cv2.destroyAllWindows()
```

### 3. 오츠 알고리즘
가장 최적의 임계치값을 자동으로 찾는 알고리즘 Bimodal image에 사용하기 적합하다

```python
import cv2

img = cv2.imread('Test.jpeg', cv2.IMREAD_GRAYSCALE)
ret, binary = cv2.threshold(img, 127,255, cv2.THRESH_BINARY)
## 기본 임계치
ret, otsu = cv2.threshold(img, -1,255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
## 오츠 알고리즘 임계치
print('Otsu Threshold', ret)

cv2.imshow("Img", img)
cv2.imshow("Binary", binary)
cv2.imshow("Otsu", otsu)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

# Step 2 이미지 변환

### 1.팽창(Dilation)
이미지를 확장하여 작은 구멍을 채우는 것 흰색 영역의 외곽 픽셀 주변에 흰색을 추가
```python
import cv2
import numpy as np

kernel = np.ones((3,3), dtype= np.uint8) 
### 커널 필요

img = cv2.imread('Test.jpeg', cv2.IMREAD_GRAYSCALE)
dilate1 = cv2.dilate(img, kernel, iterations=1)
## 이미지 ,커널 , 반복횟수
dilate2 = cv2.dilate(img, kernel, iterations=2)
dilate3 = cv2.dilate(img, kernel, iterations=3)

cv2.imshow("IMG", img)
cv2.imshow("dilate1", dilate1)
cv2.imshow("dilate2", dilate2)
cv2.imshow("dilate3", dilate3)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 2.침식(Erosion)
이미지를 깍아서 노이즈를 제거해준다 흰색 영역의 외곽 픽셀을 검은색으로 변경!
```python
import cv2
import numpy as np

kernel = np.ones((3,3), dtype= np.uint8) 
### 커널 필요

img = cv2.imread('Test.jpeg', cv2.IMREAD_GRAYSCALE)
erode1 = cv2.erode(img, kernel, iterations=1)
erode2 = cv2.erode(img, kernel, iterations=2)
erode3 = cv2.erode(img, kernel, iterations=3)

cv2.imshow("IMG", img)
cv2.imshow("erode1", erode1)
cv2.imshow("erode2", erode2)
cv2.imshow("erode3", erode3)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 3.열림&닫힘
열림과 닫힘은 노이즈를 제거 후 원상태로 복구할 때 사용한다  

열림(Opening) : 침식 후 팽창, 깍아서 노이즈 제거 후 살 찌움
dilate(erode(img))
```python
import cv2
import numpy as np

kernel = np.ones((3,3), dtype= np.uint8) 
### 커널 필요

img = cv2.imread('Test.jpeg', cv2.IMREAD_GRAYSCALE)
erode = cv2.erode(img, kernel, iterations=3)
dilate = cv2.dilate(erode, kernel, iterations=3)


cv2.imshow("IMG", img)
cv2.imshow("erode", erode)
cv2.imshow("dilate", dilate)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 3.열림&닫힘
닫힘(Closing) : 팽창 후 침식, 구멍을 메운 후 다시 깍음
erode(dilate(img)

```python
import cv2
import numpy as np

kernel = np.ones((3,3), dtype= np.uint8) 
### 커널 필요

img = cv2.imread('Test.jpeg', cv2.IMREAD_GRAYSCALE)
dilate = cv2.dilate(img, kernel, iterations=3)
erode = cv2.erode(dilate, kernel, iterations=3)

cv2.imshow("IMG", img)
cv2.imshow("erode", erode)
cv2.imshow("dilate", dilate)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

## Step 3 이미지 검출
### 1. 경계선(Canny Edge Detection)
```python
import cv2
from cv2 import threshold
from numpy import empty

def empty(pos):
    pass

img = cv2.imread('Test.jpeg', cv2.IMREAD_GRAYSCALE)
# canny = cv2.Canny(img, 150, 200)
## 이미지 , minVal(하위임계값), maxVal(상위임계값)

name = "Trackbar"
cv2.namedWindow(name)
cv2.createTrackbar('threshold1', name, 0, 255,empty) ## minVal
cv2.createTrackbar('threshold2', name, 0, 255,empty) ## maxVal

while True:
    threshold1 = cv2.getTrackbarPos('threshold1', name)
    threshold1 = cv2.getTrackbarPos('threshold2', name)
    
    canny = cv2.Canny(img, threshold1, threshold1)

    cv2.imshow("IMG", canny)
    if cv2.waitKey(1) == ord('q'):
        break
cv2.destroyAllWindows()

```
### 2. 윤곽선(Contour)
경계선을 연결한 선

```python
import cv2

img = cv2.imread('ocr.jpeg')
copy_img = img.copy() ## Contour는 원본이미지를 건들기 때문에 미리 복사

GRAY = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret,otsu = cv2.threshold(GRAY, -1, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
contours, hierarchy = cv2.findContours(otsu, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)
## cv2.CHAIN_APPROX_NONE - > CHAIN_APPROX_SIMPLE(꼭지점만)
## 윤곽선 정보, 구조
## 이미지, 윤곽선 찾는 모드(mode) , 윤곽선 찾을때 사용하는 근사치 방법
COLOR = (0,200,0) ### 녹색
cv2.drawContours(copy_img, contours, -1, COLOR, 2)## 윤곽선 그리기
## 대상이미지 , 윤고ㅓ가선 정보, 인덱스(-1이면 전체) , 색깔, 두께 


cv2.imshow('IMG', copy_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 2. 윤곽선(Contour) 찾기 모드
1. cv2.RETR_EXTERNAL : 가장 외곽의 윤곽선만 찾음
2. cv2.RETR_LIST : 모든 윤곽선을 찾음(계층정보(족보)가 없음)
3. cv2.RETR_TREE : 모든 윤곽선을 찾음 (계층정보(족보)가 트리모양)

```python
import cv2

img = cv2.imread('ocr.jpeg')
copy_img = img.copy() ## Contour는 원본이미지를 건들기 때문에 미리 복사

GRAY = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret,otsu = cv2.threshold(GRAY, -1, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
contours, hierarchy = cv2.findContours(otsu, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
## 윤곽선 정보, 구조
## 이미지, 윤곽선 찾는 모드(mode) , 윤곽선 찾을때 사용하는 근사치 방법


COLOR = (0,200,0) ### 녹색
cv2.drawContours(copy_img, contours, -1, COLOR, 2)## 윤곽선 그리기
cv2.imshow('IMG', copy_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 3. 윤곽선(Contour) 경계 사각형
윤곽선의 경계면을 둘러싸는 사각형 
 
boundingRect()
```python
import cv2

img = cv2.imread('ocr.jpeg')
copy_img = img.copy() ## Contour는 원본이미지를 건들기 때문에 미리 복사

GRAY = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret,otsu = cv2.threshold(GRAY, -1, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
contours, hierarchy = cv2.findContours(otsu, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)
## 윤곽선 정보, 구조
## 이미지, 윤곽선 찾는 모드(mode) , 윤곽선 찾을때 사용하는 근사치 방법

COLOR = (0,200,0) ### 녹색

for cnt in contours:
    x,y,w,h = cv2.boundingRect(cnt) ## cnt에 있는 윤곽선 정보로 사각형을 그리기
    cv2.rectangle(copy_img, (x,w),(y+w, y+h), COLOR, 2)
cv2.imshow('IMG', copy_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 4. 윤곽선(Contour) 면적
cv2.contourArea()를 이용하여 면적을 계산가능
```python
import cv2

img = cv2.imread('ocr.jpeg')
copy_img = img.copy() ## Contour는 원본이미지를 건들기 때문에 미리 복사

GRAY = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret,otsu = cv2.threshold(GRAY, -1, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
contours, hierarchy = cv2.findContours(otsu, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)
## 윤곽선 정보, 구조
## 이미지, 윤곽선 찾는 모드(mode) , 윤곽선 찾을때 사용하는 근사치 방법


COLOR = (0,200,0) ### 녹색

for cnt in contours:
    if cv2.contourArea(cnt)>100000: ### 사각형의 면적이 25000보다 크다면 그려주기
        x,y,w,h = cv2.boundingRect(cnt)
        cv2.rectangle(copy_img, (x,w),(y+w, y+h), COLOR, 2)
cv2.imshow('IMG', copy_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
```
