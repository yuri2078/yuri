# _*_ coding: UTF-8 _*_
from dobot.srv  import *
import rospy
import time
from sensor_msgs.msg import JointState
def arm_init() :
    rospy.loginfo("wait for service -> SetHOMECmd")
    rospy.wait_for_service("/DobotServer/SetHOMECmd")
    rospy.loginfo("start to client")
    client = rospy.ServiceProxy("/DobotServer/SetHOMECmd",SetHOMECmd)
    client()
    time.sleep(35)
    rospy.loginfo("setHome success!")
    rospy.loginfo("wait for service -> SetPTPCmd")
    rospy.wait_for_service("/DobotServer/SetPTPCmd")
    arm_client = rospy.ServiceProxy("/DobotServer/SetPTPCmd",SetPTPCmd)
    arm_client(0, -5.27437448502, 207.521438599, 51.4118499756, 91.455909729) # default pos
    time.sleep(5)


    arm_client.close()
    client.close()

def catch() :
    # start arm server
    rospy.loginfo("wait for service -> SetPTPCmd")
    rospy.wait_for_service("/DobotServer/SetPTPCmd")
    arm_client = rospy.ServiceProxy("/DobotServer/SetPTPCmd",SetPTPCmd)
    print("wait for server -> SetEndEffectorSuctionCup")
    rospy.wait_for_service("/DobotServer/SetEndEffectorSuctionCup")
    suck_client = rospy.ServiceProxy("/DobotServer/SetEndEffectorSuctionCup",SetEndEffectorSuctionCup)

    #start to catch
    arm_client(0, -21.9793758392 , -266.671203613 , 126.494918823 , -94.7117385864) # search package
    time.sleep(5) 
    arm_client(0, -22.0892620087, -265.013031006, 89.8041992188, -94.7646789551) # search package
    time.sleep(5)
    suck_client(1, 1, False) # open suck
    time.sleep(2)


    suck_client.close()
    arm_client.close()

def move() :
    rospy.loginfo("wait for service -> SetPTPCmd")
    rospy.wait_for_service("/DobotServer/SetPTPCmd")
    arm_client = rospy.ServiceProxy("/DobotServer/SetPTPCmd",SetPTPCmd)
    print("wait for server -> SetEndEffectorSuctionCup")
    rospy.wait_for_service("/DobotServer/SetEndEffectorSuctionCup")
    suck_client = rospy.ServiceProxy("/DobotServer/SetEndEffectorSuctionCup",SetEndEffectorSuctionCup)

    arm_client(0, 13.3574981689, 213.890075684, -29.8162994385, 86.4264984131) # to back
    time.sleep(5)

    suck_client(1, 0, False)
    print("catch success")

    suck_client.close()
    arm_client.close()


def diu() :
    print("start to diu")
    rospy.loginfo("wait for service -> SetPTPCmd")
    rospy.wait_for_service("/DobotServer/SetPTPCmd")
    arm_client = rospy.ServiceProxy("/DobotServer/SetPTPCmd",SetPTPCmd)

    print("wait for server -> SetEndEffectorSuctionCup")
    rospy.wait_for_service("/DobotServer/SetEndEffectorSuctionCup")
    suck_client = rospy.ServiceProxy("/DobotServer/SetEndEffectorSuctionCup",SetEndEffectorSuctionCup)

    #start to catch
    arm_client(0, 13.3574981689, 213.890075684, -30.4162994385, 86.4264984131) # search package
    time.sleep(5)

    suck_client(1, 1, False) # open suck
    time.sleep(2)
    arm_client(0, 47.7871589661, -279.134216309, 43.0585365295, -80.2852630615) # to back
    time.sleep(5)

    suck_client(1, 0, False)
    print("diu success")


    arm_client(0, -5.27437448502, 207.521438599, 51.4118499756, 91.455909729) # default pos
    time.sleep(5)
    suck_client.close()
    arm_client.close()

if __name__=='__main__':
    rospy.init_node("catch_node")
    arm_init()
    catch()
    diu()