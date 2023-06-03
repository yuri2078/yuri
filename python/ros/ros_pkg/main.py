import catch
import time
import rospy
from geometry_msgs.msg import PoseStamped
from move_base_msgs.msg import MoveBaseActionResult
from geometry_msgs.msg import PoseWithCovarianceStamped
n = 1

def initPost(a,b,c,d,e,f,g):
    pose_msg = PoseWithCovarianceStamped()
    pose_msg.header.frame_id = 'map'
    pose_msg.pose.pose.position.x = a
    pose_msg.pose.pose.position.y = b
    pose_msg.pose.pose.position.z = c
    pose_msg.pose.pose.orientation.x = d
    pose_msg.pose.pose.orientation.y = e
    pose_msg.pose.pose.orientation.z = f
    pose_msg.pose.pose.orientation.w = g
    return pose_msg

def getPost(a,b,c,d,e,f,g):
    pose_msg = PoseStamped()
    pose_msg.header.frame_id = 'map'
    pose_msg.pose.position.x = a
    pose_msg.pose.position.y = b
    pose_msg.pose.position.z = c
    pose_msg.pose.orientation.x = d
    pose_msg.pose.orientation.y = e
    pose_msg.pose.orientation.z = f
    pose_msg.pose.orientation.w = g
    return pose_msg

pose_msg = getPost(0.560128881729 , 0.0145885251185 , 0.138, 0.0, 0.0, 0.0735568433658, 0.997291026127)
pose_msg_init = initPost(0.560128881729 , 0.0145885251185 , 0.138, 0.0, 0.0, 0.0735568433658, 0.997291026127)
pose_msg_2 = getPost(2.29184880819, -0.007800160734, 0.138, 0.0, 0.0, 0.756773483817, 0.653677209478)
pose_msg_2_init = initPost(2.29184880819, -0.007800160734, 0.138, 0.0, 0.0, 0.756773483817, 0.653677209478)
pose_msg_3 = getPost(2.22738262905, 0.382736776845, 0.138, 0.0, 0.0, 0.761119699313, 0.648611442481)
pose_msg_3_init = initPost(2.22738262905, 0.382736776845, 0.138, 0.0, 0.0, 0.761119699313, 0.648611442481)

def pose_callback(msg):
    global n
    global turtle_vel_pub
    global init_pos_pub
    if msg.status.status == 3: 
        print("Y")
        n = n + 1
        if n == 2 :
            init_pos_pub.publish(pose_msg_init)
            time.sleep(2)
            turtle_vel_pub.publish(pose_msg_2)
            pass
        
        if n == 3 :
            
            catch.catch()
            init_pos_pub.publish(pose_msg_2_init)
            time.sleep(2)
            turtle_vel_pub.publish(pose_msg_3)
            
        if n == 4 :
            catch.move()
            init_pos_pub.publish(pose_msg_3_init)
            time.sleep(2)
            turtle_vel_pub.publish(pose_msg)
        if n == 5 :
            init_pos_pub.publish(pose_msg_init)
            time.sleep(2)
            catch.diu()
            pass



if __name__ == '__main__':
    rospy.init_node("main_node")
    time.sleep(1)
    init_pos_pub = rospy.Publisher('/initialpose', PoseWithCovarianceStamped, queue_size=10)
    turtle_vel_pub = rospy.Publisher('move_base_simple/goal', PoseStamped, queue_size=1)
    turtle_vel_pub.publish(PoseStamped()) 
    time.sleep(1)
    catch.arm_init()
    rospy.Subscriber('/move_base/result', MoveBaseActionResult, pose_callback) 
    turtle_vel_pub.publish(pose_msg)
    
    rospy.spin()
    pass
    