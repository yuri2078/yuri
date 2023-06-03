#!/usr/bin/env python
 
import roslib
import sys
import rospy
import cv2
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
reload(sys)
sys.setdefaultencoding('utf8')
import json

from pyzbar.pyzbar import decode


class image_converter:
 
  def __init__(self):
    self.bridge = CvBridge()
    self.image_sub = rospy.Subscriber("/tag_detections_image",Image,self.callback)
 
  def callback(self,data):
    try:
      cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
    except CvBridgeError as e:
      print(e)
    cv2.imshow("Image window", cv_image)
    cv2.waitKey(3)
    try:

      decocdeQR = decode(cv_image)
      print(decocdeQR[0].data)
    except CvBridgeError as e:
      print(e)

 
def main(args):
  ic = image_converter()
  rospy.init_node('image_converter', anonymous=True)
  try:
    rospy.spin()
  except KeyboardInterrupt:
    print("Shutting down")
  cv2.destroyAllWindows()
 
if __name__ == '__main__':
    main(sys.argv)
