# Definition of message used to efficiently get data from ROS to control pan tilt servos
# value of 0 is neutral (central) position of servo i.e. 1500uS pulse width
# value of SHRT_MIN is extreme negative position of servo i.e. 750uS pulse width
# value of SHRT_MAX is extreme positive position of servo i.e. 2250uS pulse width
# NB: most real servos have physical limit well short of the extreme positions.
int16 pan
int16 tilt
int16 zoom