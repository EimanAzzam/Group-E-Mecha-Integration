from MPU6050 import MPU6050

mpu = MPU6050()

threshold = 3000  # Adjust this threshold as needed
previousGesture = -1

def setup():
    mpu.initialize()

def loop():
    gesture = detectGesture()

    if gesture != previousGesture:
        print("Detected Gesture:")
        if gesture == 1:
            print("The sign is up")
            # Perform an action for Gesture 1
        elif gesture == 2:
            print("The sign is down")
            # Perform an action for Gesture 2
        # Add more gesture cases as needed

        previousGesture = gesture

def detectGesture():
    ax, ay, az, gx, gy, gz = mpu.getMotion6()
    # Perform gesture recognition here based on sensor data
    # Define conditions to recognize specific gestures
    if ax > threshold and ay < threshold:
        return 1  # Gesture 1
    elif ax < -threshold and ay > threshold:
        return 2  # Gesture 2
    # Add more gesture conditions as needed
    return 0  # No gesture detected

if __name__ == '__main__':
    setup()
    while True:
        loop()
