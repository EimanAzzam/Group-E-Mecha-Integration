import serial
import time
import sys
import keyboard

# Define the serial port and baud rate
# Adjust the port as per your Arduino
ser = serial.Serial('COM7', 9600)

try:
    while True:
        if ser.in_waiting > 0:
            # Read the serial data from the Arduino
            angle = ser.readline().decode().strip()
            print(f"Current servo angle: {angle} degrees")
        
        if keyboard.is_pressed('q'):  # check if 'q' is pressed
            print("You pressed 'q'. Exiting...")
            break

except KeyboardInterrupt:
    pass  # Handle keyboard interrupt

finally:
    ser.close()  # Close the serial connection

print("Serial connection closed.")