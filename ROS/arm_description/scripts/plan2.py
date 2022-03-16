#! /usr/bin/env python
import sys
import rospy
import moveit_commander

import geometry_msgs.msg

# # put the arm at the 2nd grasping position
# pose_target.position.z = 0.1125
# arm_group.set_pose_target(pose_target)
# #plan1 = arm_group.plan()
# plan1 = arm_group.go()

# # close the gripper
# hand_group.set_named_target("close")
# plan2 = hand_group.go()

# # put the arm at the 3rd grasping position
# pose_target.position.z = 0.1
# arm_group.set_pose_target(pose_target)
# #plan1 = arm_group.plan()
# plan1 = arm_group.go()

# rospy.sleep(5)
# current_pose = arm_group.get_current_pose()
# rospy.loginfo(current_pose)

# moveit_commander.roscpp_shutdown()


print("")
print("----------------------------------------------------------")
print("Welcome to the MoveIt MoveGroup Python Interface Tutorial")
print("----------------------------------------------------------")
print("Press Ctrl-D to exit at any time")
print("")

moveit_commander.roscpp_initialize(sys.argv)
rospy.init_node('move_group_python_interface_tutorial', anonymous=True)
robot = moveit_commander.RobotCommander()
scene = moveit_commander.PlanningSceneInterface()

arm_group = moveit_commander.MoveGroupCommander("arm")

# Put the arm in the start position
# arm_group.set_named_target("pick")
# plan1 = arm_group.go()

# # Open the gripper
# hand_group.set_named_target("open")
# plan2 = hand_group.go()

# arm_group.set_named_target("pick")
# plan2 = arm_group.go()

# put the arm at the 1st grasping position
pose_target = geometry_msgs.msg.Pose()

pose_target.position.x = 0.19099261001467255
pose_target.position.y = -6.665336304699893e-06
pose_target.position.z = 0.14900598524181596
pose_target.orientation.x = -9.261859355487332e-06
pose_target.orientation.y = 0.7070801299313123
pose_target.orientation.z = 9.25930116420452e-06
pose_target.orientation.w = 0.7071334313160438
arm_group.set_pose_target(pose_target)
plan = arm_group.go()

pose_target.position.x = 0.12

arm_group.set_pose_target(pose_target)
plan3 = arm_group.go()

group_variable_values = arm_group.get_current_joint_values()
print(group_variable_values)



