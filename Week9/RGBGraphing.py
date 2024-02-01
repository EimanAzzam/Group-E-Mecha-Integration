import matplotlib.pyplot as plt
import numpy as np
import serial

# Establish serial connection with Arduino
arduino_port = 'COM3'  # Change this to the correct port for your system
baud_rate = 9600
ser = serial.Serial(arduino_port, baud_rate)

def read_color_from_arduino():
    # Read color values from Arduino
    line = ser.readline().decode('utf-8').rstrip()
    r, g, b = map(int, line.split(','))
    return r, g, b

def create_channel(color_val):
    return np.ones((10, 10, 3)) * color_val

def display_color(r, g, b):
    color = [r / 255, g / 255, b / 255]  # Normalize RGB values
    # Create a block for each channel with linear gradients
    r1 = create_channel([r / 255, 0, 0])
    g1 = create_channel([0, g / 255, 0])
    b1 = create_channel([0, 0, b / 255])
    rgbchannel = [r1, g1, b1]
    # Combine the color channel horizontally
    # channels_combined = np.hstack(rgbchannel)
    # Create the final RGB values for the specified color
    true_color = np.ones((10, 30, 3)) * color
    # Combine all vertically
    # final_display = np.vstack([channels_combined, true_color])
    final_display = np.vstack([np.hstack(rgbchannel), true_color])
    # Display the final block
    plt.imshow(final_display)
    plt.axis('off')
    plt.show()

if __name__ == "__main__":
    try:
        while True:
            r, g, b = read_color_from_arduino()
            display_color(r, g, b)

    except KeyboardInterrupt:
        ser.close()