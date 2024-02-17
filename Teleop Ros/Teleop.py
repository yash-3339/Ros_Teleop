import rospy
from std_msgs.msg import Int32MultiArray
from geometry_msgs.msg import Twist

import serial
import time

# Open serial connection to Arduino
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

# Motor speed limits
MAX_SPEED = 255
MIN_SPEED = 0

def map_speed(value):
    return int((value - (-1.0)) / (1.0 - (-1.0)) * (MAX_SPEED - MIN_SPEED) + MIN_SPEED)

def cmd_vel_callback(data):
    # Extract linear and angular velocities
    linear_x = data.linear.x
    angular_z = data.angular.z

    # Calculate motor speeds based on linear and angular velocities
    left_speed = map_speed(linear_x - angular_z)
    right_speed = map_speed(linear_x + angular_z)

    # Send motor speeds to Arduino
    ser.write(bytes([left_speed, right_speed, left_speed, right_speed]))  # Adjust the order as needed

def read_encoder_values():
    # Read encoder values from Arduino
    serial_data = ser.readline().strip().decode('utf-8')
    encoder_values = list(map(int, serial_data.split(',')))
    return encoder_values

def publish_encoder_values():
    # Publish encoder values to ROS topic
    encoder_values_pub = rospy.Publisher('encoder_values', Int32MultiArray, queue_size=10)
    rospy.init_node('encoder_publisher', anonymous=True)
    rate = rospy.Rate(10)  # 10hz

    while not rospy.is_shutdown():
        # Read encoder values
        encoder_values = read_encoder_values()

        # Publish encoder values
        encoder_values_pub.publish(Int32MultiArray(data=encoder_values))
        rate.sleep()

if __name__ == '__main__':
    try:
        # Initialize ROS node
        rospy.init_node('motor_controller')

        # Subscribe to cmd_vel topic
        rospy.Subscriber('cmd_vel', Twist, cmd_vel_callback)

        # Publish encoder values
        publish_encoder_values()

    except rospy.ROSInterruptException:
        pass
