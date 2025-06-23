# Bluetooth Controlled Car

## Description
This is a simple Arduino-based project that controls a robot car through any Bluetooth-enabled device.

## Components Used
- Arduino (Uno or similar)
- L298N Motor Driver Module
- HC-06 Bluetooth Module
- Car chassis with 2 DC motors (mechanical base)
- 2 × 18650 3.7V batteries
- Mini breadboard
- Jumper wires
- Switch

## Circuit Connection

### Power Connections
- Two 18650 batteries connected in series/parallel to provide the required voltage, with a **switch placed between the batteries and the Motor Driver Vin** for power control.
- Motor Driver Vin powered through the switch from the batteries
- Motor Driver Ground (GND) shared with Arduino and Bluetooth module
- Arduino Vin connected to Motor Driver 5V output
- Arduino GND connected to Motor Driver GND
- HC-06 VCC connected to Arduino 5V
- HC-06 GND connected to Motor Driver GND

### Arduino to Motor Driver Connections

| Arduino Pin | L298N Pin    | Description                  |
|-------------|--------------|------------------------------|
| 8           | IN1 (Pin1)   | Motor 1 direction control    |
| 9           | IN2 (Pin2)   | Motor 1 direction control    |
| 10          | ENA (Enable1)| Motor 1 speed control (PWM)  |
| 12          | IN3 (Pin3)   | Motor 2 direction control    |
| 13          | IN4 (Pin4)   | Motor 2 direction control    |
| 11          | ENB (Enable2)| Motor 2 speed control (PWM)  |

### Arduino to Bluetooth Module (HC-06)

| Arduino Pin | HC-06 Pin | Description                    |
|-------------|-----------|--------------------------------|
| 0 (RX)      | TX        | Arduino receives data from HC-06 TX |
| 1 (TX)      | RX        | Arduino transmits data to HC-06 RX  |

### Additional Notes
- Switch controls the power supply from the batteries to the motor driver
- Ensure all grounds (Arduino, Bluetooth, motor driver, battery) are connected together

## How to Use

1. **Upload the Code to Arduino**
   - Connect your Arduino to your PC via USB.
   - Open the Arduino IDE and load the provided project code.
   - Select the correct board and port, then upload the code to the Arduino.

2. **Wire the Components**
   - Connect all components exactly as described in the circuit diagram and wiring instructions.
   - Double-check all connections before powering the system to avoid damage.

3. **Power Up the Car**
   - Ensure the two 18650 batteries are fully charged.
   - Turn ON the switch to supply power from the batteries to the motor driver and Arduino.

4. **Pair the HC-06 Bluetooth Module**
   - On your smartphone or Bluetooth-enabled device, search for Bluetooth devices.
   - Find and select the device named `HC-06` (or your configured name).
   - If prompted, enter the default pairing code: `1234` or `0000`.

5. **Connect via Bluetooth Control App**
   - Open a Bluetooth serial terminal app (like “Bluetooth Terminal” on Android or “Serial Bluetooth Terminal” on iOS).
   - Connect to the HC-06 module.

6. **Control the Car**
   - Send commands from the app to control the car’s movement:
     - For example, send `F` to move forward.
     - Send `B` to move backward.
     - Send `L` to turn left.
     - Send `R` to turn right.
     - Send `S` to stop the car.

7. **Safety Tips**
   - Turn off the switch when you are done to disconnect power.
   - Avoid running the car on uneven or wet surfaces.
   - Keep the wiring insulated and secure.

---

Thank you for checking out this project! Happy coding and have fun controlling your Bluetooth car!
