# 🛠️ Autonomous Line-Following and Obstacle-Avoiding Robot

This project is an autonomous robot built using an Arduino. It can detect and avoid obstacles using an ultrasonic sensor and follow a line using two infrared (IR) sensors.

## 🔧 Hardware Components

- **Arduino Uno** (or compatible board)
- 2 DC motors with an H-Bridge motor driver (e.g., L298N)
- 2 IR sensors (for line tracking, mounted left and right)
- 1 Ultrasonic sensor (HC-SR04)
- Jumper wires
- Robot chassis with wheels
- External power source (e.g., battery pack)

## ⚙️ Arduino Pin Connections

| Function              | Arduino Pin |
|----------------------|-------------|
| Left motor forward    | 11          |
| Left motor backward   | 12          |
| Right motor forward   | 9           |
| Right motor backward  | 10          |
| Left motor speed (PWM)| 6           |
| Right motor speed (PWM)| 5          |
| Ultrasonic trigger     | 8           |
| Ultrasonic echo        | 7           |
| Left IR sensor         | A1          |
| Right IR sensor        | A0          |

## 🧠 Functionality

- **Obstacle Avoidance**: If an object is detected within `50 cm`, the robot stops.
- **Line Following**:
  - Both sensors detect the line → move forward
  - Only the left sensor detects the line → turn right
  - Only the right sensor detects the line → turn left
  - Neither sensor detects the line → stop

## 📦 Code Overview

Main functions in the Arduino sketch:

- `mergiInainte(time, left_speed, right_speed)` – move forward
- `mergiInapoi(time, left_speed, right_speed)` – move backward
- `mergiStanga(time, left_speed, right_speed)` – turn left
- `mergiDreapta(time, left_speed, right_speed)` – turn right
- `opreste(time)` – stop movement

## 🛠️ How to Use

1. Wire all sensors and motors according to the table above.
2. Upload the provided Arduino sketch to the board.
3. Open the Serial Monitor (9600 baud) to view distance readings.
4. Place the robot on a surface with a contrasting line and an obstacle to test.

## ❗ Notes

- The line should be black on a white background (or the reverse). Make sure the IR sensors are properly positioned and calibrated.
- Adjust the `distantaPrag` value to change obstacle detection sensitivity.
- More detalied info found in the pdf