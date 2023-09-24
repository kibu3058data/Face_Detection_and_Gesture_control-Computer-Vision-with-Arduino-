import cv2
from cvzone.FaceDetectionModule import FaceDetector
cap=cv2.VideoCapture(0)

detector=FaceDetector(minDetectionCon=0.5)
while True:
    success, img=cap.read()

    img, bboxs= detector.findFaces(img)

    cv2.imshow("Image",img)

    cv2.waitKey(1)