import numpy as np
import cv2

def order_points(pts): 
    rect = np.zeros((4, 2), dtype="float32")

    s = pts.sum(axis=1)
    rect[0] = pts[np.argmin(s)]
    rect[2] = pts[np.argmax(s)]

    diff = np.diff(pts, axis=1)
    rect[1] = pts[np.argmin(diff)]
    rect[3] = pts[np.argmax(diff)]

    return rect
    
def four_point_transform(image, pts):
    rect = order_points(pts)
    (tl, tr, br, bl) = rect

    widthA = np.sqrt(((br[0] - bl[0]) ** 2) + ((br[1] - bl[1]) ** 2))
    widthB = np.sqrt(((tr[0] - tl[0]) ** 2) + ((tr[1] - tl[1]) ** 2))
    maxWidth = max(int(widthA), int(widthB))

    heightA = np.sqrt(((tr[0] - br[0]) ** 2) + ((tr[1] - br[1]) ** 2))
    heightB = np.sqrt(((tl[0] - bl[0]) ** 2) + ((tl[1] - bl[1]) ** 2))
    maxHeight = max(int(heightA), int(heightB))

    dst = np.array([
        [0, 0],
        [maxWidth - 1, 0],
        [maxWidth - 1, maxHeight - 1],
        [0, maxHeight - 1]], dtype="float32")

    M = cv2.getPerspectiveTransform(rect, dst)
    warped = cv2.warpPerspective(image, M, (maxWidth, maxHeight))

    return warped

####### 이미지 읽기

img = cv2.imread('2.jpeg')
ratio = 500.0/img.shape[0]
dim = (int(img.shape[1] * ratio), 500)
img = cv2.resize(img, dim, interpolation= cv2.INTER_AREA)
og_img = img.copy()


GRAY = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
GRAY = cv2.GaussianBlur(GRAY, (3,3), 0)
edged = cv2.Canny(GRAY, 70,200)



cnts, _ = cv2.findContours(edged.copy(), cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
cnts = sorted(cnts, key =cv2.contourArea, reverse= True)[:5]
## 반환받은 cnt중 면적인 큰 순서대로 5번까지 반환 
check = False
for c in cnts:
    ## 순차적으로 탐색
    peri = cv2.arcLength(c, True)
    ## 컨투어의 길이를 반환
    approx = cv2.approxPolyDP(c, 0.02 * peri, True)
    ## 길이의 오차 2퍼센트로 도형을 근사화
    if len(approx) == 4:
        ## 근사화한 도형의 꼭지점이 4개라면 그것이 문서의 외곽
        screenCnt = approx
        check = True
        break
if check == False:
    cv2.imshow("IMG", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    
cv2.drawContours(img, [screenCnt], -1, (0,255,0), 2)
warped = four_point_transform(og_img, screenCnt.reshape(4, 2))

copy = warped.copy()

warped = cv2.cvtColor(warped, cv2.COLOR_BGR2GRAY)
result_with_blur = cv2.adaptiveThreshold(warped,255,cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 21,10)

cv2.imshow("IMG", img)
cv2.imshow("warped", copy)
# cv2.imshow("result_with_blur", result_with_blur)
cv2.waitKey(0)
cv2.destroyAllWindows()