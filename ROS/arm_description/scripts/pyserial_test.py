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

#while 1:
    #
    #print(group_variable_values)

arduino = serial.Serial('/dev/ttyUSB0',9600)
arduino.timeout=1


def write_data(x):
    print(type(x))
    print("This value will be sent: " ,bytearray(str(x),'utf8'))

    arduino.write(bytearray(str(x),'utf8'))

def read_data():
    #time.sleep(0.05)
    x = arduino.readline() 
    return x


arr = [110,180,3,4,5]

#while True:
# num1 = input("Enter the number 1: ")
# num2 = input("Enter the number 2: ")
# num3 = input("Enter the number 3: ")
while True:
    if(input("Enter 1: ") ):
        for i in arr:
            write_data(i)
            write_data(' ')

# write_data(num2)
# write_data(num3)
print("Value from arduino:",read_data())


