# Robotics Control System Repository

This repository contains the code for implementing motor control and encoder functionality on both Arduino and Raspberry Pi platforms.

## Arduino Code

The Arduino code is responsible for controlling motors using L298N drivers and reading encoder values from the motor shafts. The code is located in the `Arduino_Code` directory.

### Instructions

1. Upload the Arduino code to your Arduino Mega board.
2. Make sure to connect the motor drivers and encoders properly to the Arduino Mega.

## Raspberry Pi Code

The Raspberry Pi code acts as a ROS node to receive motor control commands and encoder values from the Arduino, and it publishes them to ROS topics. The code is located in the `RaspberryPi_Code` directory.

### Instructions

1. Install ROS on your Raspberry Pi.
2. Run the ROS node using the provided Python script.
3. Make sure to adjust the serial port (`/dev/ttyACM0`) in the Python code if your Arduino is connected to a different port.
4. Adjust the publishing rate (`rate`) as needed.
5. Adjust the mapping of velocities to motor speeds according to your specific robot configuration.

## Additional Information

If you need any additional information or assistance, feel free to contact me.
