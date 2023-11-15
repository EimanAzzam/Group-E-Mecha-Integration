import serial

# Define the COM port and baud rate
ser = serial.Serial('COM4', 9600)

try:
    while True:
        # Read data from the Arduino
        data = ser.readline().decode().strip()
        
        # Print the data to the console
        print(data)

except KeyboardInterrupt:
    # Close the serial connection when you press Ctrl+C
    ser.close()
