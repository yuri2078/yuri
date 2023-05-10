import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

class ImageSubscriber:
    def __init__(self):
        self.bridge = CvBridge()
        self.image_sub = rospy.Subscriber("/camera/image_raw", Image, self.callback)

    def callback(self, data):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            print(e)
        cv2.imwrite("./image.jpg", cv_image)

if __name__ == '__main__':
    rospy.init_node('image_subscriber')
    ImageSubscriber()
    rospy.spin()


# rosrun map_server map_server ~/my_workspace/maps/my_map.yaml