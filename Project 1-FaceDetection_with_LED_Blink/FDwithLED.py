import cv2
from cvzone.FaceDetectionModule import FaceDetector
from cvzone.SerialModule import SerialObject
import pyttsx3
import Voicemsg

cap=cv2.VideoCapture(0)
detector=FaceDetector(minDetectionCon=0.7)
c=0
arduino=SerialObject('COM5')
while True:
    success, img=cap.read()
    engine = pyttsx3.init()

    img, bboxs= detector.findFaces(img)
    # If Face is Detected , then LED is ON.
    if bboxs:
        c=c+1
        arduino.sendData([1])
        if c == 1 :
            Voicemsg.speech()
    else:
        arduino.sendData([0])
        c=0


    cv2.imshow("Image",img)

    cv2.waitKey(1)