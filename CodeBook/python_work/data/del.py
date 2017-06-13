from cv2 import *
cam = VideoCapture(0)
# 抓拍十张小图片
for x in range(0, 9):
    s, img = cam.read()
    if s:
        imwrite("img-"+str(x)+".jpg", img)