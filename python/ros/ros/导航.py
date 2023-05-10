#_*_coding:UTF-8_*_
#! /usr/bin/env python

import rospy
import time
from geometry_msgs.msg import PoseStamped
from move_base_msgs.msg import MoveBaseActionResult
n=1
mypose=PoseStamped()
mypose.header.frame_id='map' #设置自己的目标
mypose.pose.position.x=0.4
mypose.pose.position.y=0.153
mypose.pose.position.z=0.138
mypose.pose.orientation.x=0
mypose.pose.orientation.y=0
mypose.pose.orientation.z=0.023
mypose.pose.orientation.w=0.999
    
mypose1=PoseStamped()
mypose1.header.frame_id='map' #设置自己的目标
mypose1.pose.position.x=0.972
mypose1.pose.position.y=0.202
mypose1.pose.position.z=0.138
mypose1.pose.orientation.x=0
mypose1.pose.orientation.y=0
mypose1.pose.orientation.z=-0.0268
mypose1.pose.orientation.w=0.999

mypose2=PoseStamped()
mypose2.header.frame_id='map' #设置自己的目标
mypose2.pose.position.x=1.6
mypose2.pose.position.y=0.2422
mypose2.pose.position.z=0.138
mypose2.pose.orientation.x=0
mypose2.pose.orientation.y=0
mypose2.pose.orientation.z=0.0114
mypose2.pose.orientation.w=0.999

def pose_callback(msg):
    global turtle_vel_pub
    global n
    if msg.status.status == 3: #成功到达目标点
        print("Y")
        n=n+1
        if n==2:
            turtle_vel_pub.publish(mypose1) #发送自己设置的目标点
            print("two")
            time.sleep(1)

        if n==3:
            turtle_vel_pub.publish(mypose2) #发送自己设置的目标点
            print("three")
            time.sleep(1)
        if n==4:
            turtle_vel_pub.publish(mypose) #发送自己设置的目标点
            print("four")
            time.sleep(1)

if __name__ == '__main__':
    rospy.init_node('pubpose')
    global turtle_vel_pub
    turtle_vel_pub = rospy.Publisher('move_base_simple/goal', PoseStamped, queue_size=1)

    myposee=PoseStamped()
    turtle_vel_pub.publish(myposee) 
    time.sleep(1)
    goal_status_sub = rospy.Subscriber('/move_base/result', MoveBaseActionResult, pose_callback) 

    turtle_vel_pub.publish(mypose)
    time.sleep(1)
    print("one")
    rospy.spin()
    n=n+1


