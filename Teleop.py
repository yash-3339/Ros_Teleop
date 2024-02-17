import serial
import time

# Open serial connection to Arduino
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

def drive_forward(speed):
    # Send motor speeds to Arduino
    ser.write(bytes([speed, speed, speed, speed]))

def drive_backward(speed):
    # Send motor speeds to Arduino
    ser.write(bytes([-speed, -speed, -speed, -speed]))

def turn_left(speed):
    # Send motor speeds to Arduino
    ser.write(bytes([-speed, -speed, speed, speed]))

def turn_right(speed):
    # Send motor speeds to Arduino
    ser.write(bytes([speed, speed, -speed, -speed]))

def stop():
    # Send motor speeds to Arduino
    ser.write(bytes([0, 0, 0, 0]))

try:
    while True:
        print("Enter command:")
        print("1: Drive forward")
        print("2: Drive backward")
        print("3: Turn left")
        print("4: Turn right")
        print("5: Stop")
        print("0: Exit")
        command = input()

        if command == '1':
            speed = int(input("Enter speed (0-255): "))
            drive_forward(speed)
        elif command == '2':
            speed = int(input("Enter speed (0-255): "))
            drive_backward(speed)
        elif command == '3':
            speed = int(input("Enter speed (0-255): "))
            turn_left(speed)
        elif command == '4':
            speed = int(input("Enter speed (0-255): "))
            turn_right(speed)
        elif command == '5':
            stop()
        elif command == '0':
            break
        else:
            print("Invalid command!")

except KeyboardInterrupt:
    # Close serial connection
    ser.close()
