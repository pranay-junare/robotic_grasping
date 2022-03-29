Below are the ROS packages:
1) ur5
This is the Working code for UR5 with parallel plate gripper.
You have to specify joint values in order to move the robot.
No IK available.

2) grasp_ros
Package for kinect v2 interface
	a) $ roslaunch grasp_ros visualise_kinectdata.launch 
	   will launch the RViz to visualise the kinect data
	b) $ rosrun grasp_ros kinect_data.py 
	   will run a kinect_data node to convert RGB to RGD
	c) $ roslaunch kinect2_bridge kinect2_bridge
