# Maze-Solving-Robot
The source code for a line follower and maze solving robot .

# Components
The robot use the following modules:

## Controller
- ESP 32 Wroom 32D development board (30 pin)
 
## Actuators
- 4 x N20 DC motors
- 2 x L293D motor driver IC
- 74HC04 NOT gate IC
 
## Sensors
- Qtr A8 IR array sensor
- TCS34725 color sensor
 
## Power
- 4 x LiPo 503450 3.7v 1000mAh battery
- 7805 linear voltage regulator IC
 
## Miscellaneous
- RGB Led 
- Buzzer

# Dependencies
Be sure to have the following libraries installed:
- Wire
- Adafruit TCS34725
- Adafruit BusIO
- SPI

# Usage
To use the robot, you'll need to upload the code to the ESP32 WROOM 32D development board using the Arduino IDE. Follow these steps:

1. Connect the ESP32 WROOM 32D development board to your computer using a USB cable.
2. Open the src/src.ino file in the Arduino IDE or your Compiler.
3. In the "Tools" menu, select the appropriate board ("ESP32 Dev Module") and the port.
4. Click the "Upload" button to upload the code to the development board.
5. Once the code is uploaded, disconnect the USB cable and power the robot using the 4 LiPo batteries.

To test the Rbobots component, you'll need to upload the coodes to the ESP32 WROOM 32D board . Follow these steps:
1. Connect the ESP32 WROOM 32D development board to your computer using a USB cable.
2. open the test file in the Arduino IDE or your compiler.
3. Upload different code of all the component in your Robot.


Any Quastion Contact me : anisyazid02@gmail.com
