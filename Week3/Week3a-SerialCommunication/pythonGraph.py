import serial
from time import sleep
import matplotlib.pyplot as plt

serial_port = "COM9"
baud_rate = 9600
dt = 0.05

# -- open the serial port
ser = serial.Serial(serial_port, baud_rate)
if ser.is_open:
    print(f"Serial port {ser.name} is open.")
    data = []
    N = 100  # number of data
    x_values = list(range(N))  # Create a list of x values
    y_values = []  # Create a list to store the y values

    for k in range(N):
        b = ser.readline()
        strn = b.decode()
        str1 = strn.rstrip()
        flt = float(str1)
        print(flt)
        data.append(flt)
        y_values.append(flt)



        sleep(dt)

    # -- close the serial port
    ser.close()
    if not ser.is_open:
        print(f"Serial port {ser.name} is closed.")

    # Plot the data
    plt.plot(x_values, y_values, 'b-')
    plt.draw()
    plt.pause(0.001)  # Small pause to allow the plot to update
    plt.show()  # Display the final plot

    # Set up a figure and axis for plotting
    plt.figure()
    plt.title("Potentiometer Reading Over Time")
    plt.xlabel("Time")
    plt.ylabel("Potentiometer Value")
