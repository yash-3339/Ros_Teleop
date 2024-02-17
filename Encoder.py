import serial
import time

# Open serial connection to Arduino
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

def read_encoder_values():
    # Read encoder values from Arduino
    serial_data = ser.readline().strip().decode('utf-8')
    encoder_values = list(map(int, serial_data.split(',')))
    return encoder_values

try:
    while True:
        # Read encoder values
        encoder_values = read_encoder_values()
        print("Encoder Values:", encoder_values)
        
        # Add your feedback control or other logic here

        time.sleep(1)

except KeyboardInterrupt:
    # Close serial connection
    ser.close()
