# _*_ coding: UTF-8 _*_
from dobot.srv  import *
import rospy
import time
if __name__=='__main__':
    rospy.init_node("test1")
    time.sleep(1)
    setptpcmd=rospy.wait_for_service("/DobotServer/SetPTPCmd")
    setptpcmd=rospy.ServiceProxy("/DobotServer/SetPTPCmd",SetPTPCmd)
    print("wait for server -> SetEndEffectorSuctionCup")
    rospy.wait_for_service("/DobotServer/SetEndEffectorSuctionCup")
    suck_client = rospy.ServiceProxy("/DobotServer/SetEndEffectorSuctionCup",SetEndEffectorSuctionCup)

    setptpcmd(0, -5.27437448502, 207.521438599, 51.4118499756, 91.455909729)
    time.sleep(6)
    setptpcmd(0, -11.07239151, -285.172119141, 92.5297546387, -92.2235031128)
    time.sleep(6)
    suck_client(1, 1, False)
    time.sleep(1)
    setptpcmd(0, 13.3574981689, 213.890075684, -29.8162994385, 86.4264984131) # to back
    time.sleep(6)
    # setptpcmd(0 , 125.452110291, -218.764968872, 68.9402694702, -60.1676177979) # to back
    time.sleep(6)
    suck_client(1, 0, False)
    print("catch success")