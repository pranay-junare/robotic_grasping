#! /usr/bin/env python
import sys
import rospy
import moveit_commander
import geometry_msgs.msg
import serial
import time

#ser = serial.Serial('/dev/ttyUSB0',9600)

moveit_commander.roscpp_initialize(sys.argv)
rospy.init_node('move_group_python_interface_tutorial', anonymous=True)
robot = moveit_commander.RobotCommander()
scene = moveit_commander.PlanningSceneInterface()

arm_group = moveit_commander.MoveGroupCommander("arm")

joint_values = []

# while 1:
#     group_variable_values = arm_group.get_current_joint_values()
#     for i in group_variable_values:
#         joint_values.append((i*180)/3.14)
#     print(joint_values)
#     time.sleep(1)

arduino = serial.Serial('/dev/ttyUSB2',4800)
arduino.timeout=1


def write_data(x):
    print(type(x))
    #print("This value will be sent: " ,bytearray(str(x),'utf8'))

    arduino.write(bytearray(str(x),'utf8'))

def read_data():
    #time.sleep(0.05)
    x = arduino.readline() 
    return x


arr = [110,180,3,4,5]


while True:
    group_variable_values = arm_group.get_current_joint_values()
    for i in group_variable_values:
        write_data(int((i*180)/3.14))
        print("Value : ", int((i*180)/3.14))
        write_data(' ')
    time.sleep(1)


# write_data(num2)
# write_data(num3)
print("Value from arduino:",read_data())


