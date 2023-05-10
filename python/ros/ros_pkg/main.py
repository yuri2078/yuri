import catch
import time
import rospy
from geometry_msgs.msg import PoseStamped
from move_base_msgs.msg import MoveBaseActionResult

n = 1
pose_msg = PoseStamped()
pose_msg.header.frame_id = 'map'
pose_msg.pose.position.x = -0.00823353123267
pose_msg.pose.position.y = 0.0360173331432
pose_msg.pose.position.z = 0.138
pose_msg.pose.orientation.x = 0.0
pose_msg.pose.orientation.y = 0.0
pose_msg.pose.orientation.z = -0.0797150339956
pose_msg.pose.orientation.w = 0.996817693139

pose_msg_2 = PoseStamped()
pose_msg_2.header.frame_id = 'map'
pose_msg_2.pose.position.x = 3.37150863972
pose_msg_2.pose.position.y = 1.22533640662
pose_msg_2.pose.position.z = 0.138
pose_msg_2.pose.orientation.x = 0.0
pose_msg_2.pose.orientation.y = 0.0
pose_msg_2.pose.orientation.z = 0.999999154242
pose_msg_2.pose.orientation.w = 0.0013005826089

pose_msg_3 = PoseStamped()
pose_msg_3.header.frame_id = 'map'
pose_msg_3.pose.position.x = 3.0150863972
pose_msg_3.pose.position.y = 1.22533640662
pose_msg_3.pose.position.z = 0.138
pose_msg_3.pose.orientation.x = 0.0
pose_msg_3.pose.orientation.y = 0.0
pose_msg_3.pose.orientation.z = 0.999999154242
pose_msg_3.pose.orientation.w = 0.0013005826089


def pose_callback(msg):
    global n
    global turtle_vel_pub
    if msg.status.status == 3: 
        print("Y")
        n = n + 1
        if n == 2 :
            catch.catch()
            turtle_vel_pub.publish(pose_msg_3)
            pass
        
        if n == 3 :
            catch.move()
            turtle_vel_pub.publish(pose_msg)
        if n == 4 :
            catch.diu()
            pass



if __name__ == '__main__':
    rospy.init_node("main_node")
    time.sleep(1)
    turtle_vel_pub = rospy.Publisher('move_base_simple/goal', PoseStamped, queue_size=1)
    turtle_vel_pub.publish(PoseStamped()) 
    time.sleep(1)
    catch.arm_init()
    rospy.Subscriber('/move_base/result', MoveBaseActionResult, pose_callback) 
    turtle_vel_pub.publish(pose_msg_2)
    rospy.spin()
    pass
    