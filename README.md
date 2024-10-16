# Real-Time Voice Transfer and Human Speech Filter

## Project Overview
This project implements a real-time voice transfer system using two ESP32 boards. It captures and filters human speech to minimize background noise.

## Hardware Required
- 2 x ESP32 Boards
- 2 x INMP441 Microphones
- 1 x Speaker
- Jumper wires
- USB cables

## Software Required
- Arduino IDE
- BluetoothSerial and driver/i2s libraries

## Setup Instructions

### Hardware Setup
1. Connect the microphones to the first ESP32 (transmitter).
2. Connect the speaker to the second ESP32 (receiver).
3. Power both boards using USB.

### Software Setup
1. Install Arduino IDE.
2. Add ESP32 Board URL to Preferences.
3. Install necessary libraries.
4. Upload `transmitter.ino` to ESP32 1 and `receiver.ino` to ESP32 2.

## Running the Project
1. Start both ESP32 boards.
2. Monitor the serial output for any debugging information.
3. Speak into the transmitter and listen on the receiver.

## Libraries Used
- BluetoothSerial
- I2S
