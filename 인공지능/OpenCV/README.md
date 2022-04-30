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

![결과이미지](/assets/images/test.png)
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
