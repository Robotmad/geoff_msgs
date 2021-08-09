# Definition of message used to efficiently get data from ROS to control 4 wheel steered drive
# value of 0 is neutral (central) position of servo i.e. 1500uS pulse width
# value of SHRT_MIN is extreme negative position of servo i.e. 750uS pulse width
# value of SHRT_MAX is extreme positive position of servo i.e. 2250uS pulse width
# NB: most real servos have physical limit well short of the extreme positions.

# Wheel drive commands (velocity m/s as per cmd_vel)
float32[4] wheel_speeds

# Steering servo commands (position in radians)
float32[4] steer_angles