import numpy as np
import cv2
import gdown
import os

if not os.path.exists('custom-train-yolo_final.weights'):
    url = 'https://drive.google.com/uc?id=1ol3yLt2zao2ZQB_t4DSbmOU-BWUag6LV&export=download'
    gdown.download(url, 'custom-train-yolo_final.weights', quiet = False)

min_confidence = 0.5
width = 800
height = 0
show_ratio = 1.0

path = "YOLO/"
Weights = 'custom-train-yolo_final.weights'
file_name = path + "images/test.jpg"
test_cfg = path + "cfg/custom-test-yolo.cfg"
net = cv2.dnn.readNetFromDarknet(test_cfg,Weights)


classes = ["문어","새송이버섯","블루베리","방울토마토","무", "배", "콩나물"
           ,"꽃게","양배추", "양파", "새우", "시금치", "깻잎", "애호박", "밥", "옥수수"
           ,"마늘", "바지락", "감자", "수박", "브로콜리", "오이", "멜론", "파", "오징어"
           ,"당근", "복숭아", "상추","계란", "파프리카", "사과", "고추", "돼지고기", "참외"
           ,"멸치", "고등어", "조기", "배추", "감", "딸기", "가지", "소고기", "고구마"
           ,"버터", "귤", "닭고기", "두부" ,"양송이버섯", "키위", "갈치"]

class_count = 50
anw = []

 
color_lists = np.random.uniform(0, 255, size= (len(classes), 3))
layer_names = net.getLayerNames()
output_layers = ['yolo_82', 'yolo_94', 'yolo_106']

img = cv2.imread(file_name)

h,w = img.shape[:2]
height = int(h * width / w)
blob = cv2.dnn.blobFromImage(img, 0.00392, (416,416), swapRB=True, crop=False
							 )

net.setInput(blob)
outs = net.forward(output_layers)

confidences = []
names = []
boxes = []
colors = []


for out in outs:
	for detection in out:
		scores = detection[5:]
		class_id = np.argmax(scores)
		confidence = scores[class_id]
		if confidence > min_confidence:
			#print(detection)
			# Object detected
			center_x = int(detection[0] * width)
			center_y = int(detection[1] * height)
			w = int(detection[2] * width)
			h = int(detection[3] * height)

			# Rectangle coordinates
			x = int(center_x - w /2)
			y = int(center_y - h / 2)

			boxes.append([x, y, w, h])
			confidences.append(float(confidence))
			names.append(classes[class_id])
			colors.append(color_lists[class_id])

indexes = cv2.dnn.NMSBoxes(boxes, confidences, min_confidence, 0.4)

print(set(names))