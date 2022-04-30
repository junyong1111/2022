### 이미지 출력 기본코드 ###
import cv2

image = '/test_img/test.jpg' # 출력하고싶은 이미지 경로   
image = cv2.imread(image) # imread()함수로 이미지 읽어오기
image.shape #이미지의 세로 가로
image = cv2.imshow('보여지는 이름', image)  # imshow()함수를 이용하여 새로운 창에서 이미지를 출력

cv2.waitKey() # 아무키나 입력받을때까지 대기
cv2.destroyAllWindows()# 모든 창 닫기



### 동영상 출력 기본코드 ####
# import cv2

# Video = cv2.VideoCapture("test.mp4")## 동영상 경로
# ## 동영상은 이미지의 연속이므로 반복문을 이용하여 출력

# while Video.isOpened():
#     ret , frame = Video.read() 
#     ## ret -> 결과값이 있는지 없는지(성공여부)
#     ## frame -> 영상에서 읽어 온 이미지
    
#     if not ret : # 더 읽을 영상이 없다면
#         print("동영상 종료")
#         break
    
#     cv2.imshow("Video", frame)
    
#     if cv2.waitKey(1) == ord('q'): ##만약 q를 입력하면 종료 숫자를 조절해서 재생속도 컨트롤 가능
#         print("동영상 재생 종료.")
#         break

# Video.release() ## Video 자원 종료
# cv2.destroyAllWindows()

