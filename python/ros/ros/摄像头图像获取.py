# -*- coding: utf-8 -*-
import rospy
from sensor_msgs.msg import Image
import sys
import cv2
from cv_bridge import CvBridge, CvBridgeError

# 初始化一个cv_bridge对象
bridge = CvBridge()

# 定义一个listener类
class listener:

    def __init__(self):
        # 初始化ros节点
        rospy.init_node('listener', anonymous=True)
        self.num=0000

        # 订阅"/obstacel_images"话题，回调函数为self.callback，队列长度为1
        image_sub = rospy.Subscriber("/obstacel_images",Image, self.callback,queue_size=1)

        # 循环等待话题消息
        rospy.spin()
        
    def callback(self,data): 
        try:
            # 将ROS的图像消息转换为OpenCV格式
            cv_image = bridge.imgmsg_to_cv2(data, "bgr8")
            frame = cv_image

            # 将图像保存到指定路径下
            cv2.imwrite("/home/eaibot/yuri/" + str(self.num)+ '.jpg',frame)
            self.num += 1
            # 在图像窗口中显示图像
            cv2.namedWindow("detect")
            cv2.imshow("detect", cv_image) 
            cv2.waitKey(1)  

        except CvBridgeError as e:
            print(e)    
 
# 程序入口函数
if __name__ == '__main__':
    listener()
