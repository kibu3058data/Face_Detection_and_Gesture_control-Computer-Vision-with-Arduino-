from cvzone.SerialModule import SerialObject
import cv2
arduino=SerialObject('COM5')

imgLedOn=cv2.imread('../Resources/LedOn.jpg')
imgLedOff=cv2.imread('../Resources/LedOff.jpg')

while True:
    arduino.sendData([1])
    cv2.imshow("Image",imgLedOn)
    cv2.waitKey(1000)
    arduino.sendData([0])
    cv2.imshow("Image",imgLedOff)
    cv2.waitKey(1000)