# LED Control with Voice Commands

A sophisticated Arduino-based embedded systems project that demonstrates voice command recognition and real-time LED control through serial communication. This project bridges hardware control with intuitive voice-based interaction, making it ideal for IoT applications and smart home automation systems.

## Overview

This project enables wireless control of multiple LEDs using voice commands transmitted via serial communication. By leveraging Arduino microcontroller capabilities and intelligent command parsing, users can dynamically control three colored LEDs (Green, Orange, Red) with simple voice instructions.

## Features

- **Multi-LED Control**: Simultaneous management of three independent LED circuits
- **Voice Command Recognition**: Serial-based voice input processing with case-insensitive command matching
- **Real-Time Feedback**: Immediate LED response to voice commands
- **Modular Design**: Clean, well-organized Arduino code with straightforward logic
- **Extensible Architecture**: Easy to expand with additional LEDs and commands
- **Serial Communication**: Robust 9600 baud rate serial interface for reliable command transmission

## Hardware Requirements

### Components
- **Microcontroller**: Arduino (UNO, Mega, or compatible board)
- **LEDs**: 3x High-Brightness LEDs (Green, Orange, Red)
- **Resistors**: 3x 220Ω Current-Limiting Resistors
- **Power Supply**: 5V DC power source (USB or external)
- **Breadboard**: For prototyping and circuit assembly
- **Jumper Wires**: For circuit connections
- **Voice Module** (Optional): Bluetooth HC-05 or similar for wireless voice input

### Pin Configuration
```
Green LED   → Arduino Pin 3
Orange LED  → Arduino Pin 4
Red LED     → Arduino Pin 5
GND         → Common ground with all LEDs
```

## Software Requirements

- Arduino IDE (version 1.8.0 or higher)
- Compatible USB drivers for your Arduino board
- Serial communication application or voice-to-text module

## Installation & Setup

### Hardware Assembly
1. Connect the three LEDs to Arduino pins 3, 4, and 5 through 220Ω resistors
2. Connect all LED cathodes to the common ground
3. Power the Arduino via USB or external power supply
4. Ensure proper connections before uploading code

### Software Installation
1. Download the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
2. Clone or download this repository
3. Open `LED Control with Voice Commands.ino` in the Arduino IDE
4. Select your Arduino board type: **Tools → Board → [Your Arduino Model]**
5. Select the appropriate COM port: **Tools → Port → COM[X]**
6. Click **Upload** to flash the firmware to your Arduino

## Usage

### Supported Commands

| Command | Action |
|---------|--------|
| `green` | Turn on the Green LED |
| `green off` | Turn off the Green LED |
| `orange` | Turn on the Orange LED |
| `orange off` | Turn off the Orange LED |
| `red` | Turn on the Red LED |
| `red off` | Turn off the Red LED |

### Operation

1. Open the Serial Monitor: **Tools → Serial Monitor**
2. Set baud rate to **9600**
3. Enter commands in the input field (e.g., "green", "orange off", "red")
4. Press Enter to transmit the command
5. The Arduino processes the command and controls the respective LED
6. Serial feedback displays the received command

**Example Interaction**:
```
> green
green
> orange off
orange off
> red
red
```

## Code Architecture

### Main Components

**Pin Definitions**
```cpp
int Green = 3;    // Green LED on Pin 3
int Orange = 4;   // Orange LED on Pin 4
int Red = 5;      // Red LED on Pin 5
```

**Initialization**
```cpp
void setup() {
  Serial.begin(9600);           // Initialize serial communication
  pinMode(Green, OUTPUT);       // Configure pins as outputs
  pinMode(Orange, OUTPUT);
  pinMode(Red, OUTPUT);
}
```

**Command Processing**
```cpp
void loop() {
  if (Serial.available() > 0) {
    voice = Serial.readString();
    voice.trim();               // Remove whitespace
    
    // Case-insensitive command matching
    if (voice.equalsIgnoreCase("green")) {
      digitalWrite(Green, HIGH);
    }
    // Additional commands...
  }
}
```

## Technical Specifications

- **Microcontroller**: 8-bit AVR (ATmega328P)
- **Operating Voltage**: 5V DC
- **Serial Baud Rate**: 9600 bps
- **Output Current per Pin**: 40mA (max)
- **Processing Speed**: 16 MHz

## Extended Applications

This project can be easily extended to support:
- **Bluetooth Integration**: Wireless voice command transmission via HC-05 module
- **Voice Recognition**: Integration with voice recognition modules (EEPROM-based)
- **Automation Sequences**: Timed LED patterns and sequences
- **Mobile App Control**: Serial communication via mobile application
- **IoT Integration**: Connection to cloud platforms for remote control
- **Status Reporting**: Real-time LED status feedback

## Troubleshooting

| Issue | Solution |
|-------|----------|
| LEDs not responding | Verify pin connections and breadboard assembly |
| Serial communication errors | Check baud rate matches (9600) and select correct COM port |
| Inconsistent command recognition | Ensure whitespace is trimmed; use exact command syntax |
| Upload fails | Verify Arduino board type and drivers are correctly installed |
| LEDs too dim | Check resistor values and LED polarity |

## Future Enhancements

- [ ] Add PWM-based brightness control
- [ ] Implement pattern sequences
- [ ] Integrate wireless Bluetooth module
- [ ] Add voice recognition capability
- [ ] Develop web-based control dashboard
- [ ] Implement MQTT protocol for IoT connectivity

## Documentation

For detailed hardware schematics and assembly instructions, refer to the included PDF documentation:
- **LED Control with Voice Commands.pdf** - Complete project documentation with circuit diagrams

## License

This project is licensed under the MIT License. See the [LICENSE](../../LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit pull requests or raise issues for bug fixes and feature enhancements.

## Author

**Muhammad Usman Haider**
- GitHub: [@muhammad-usman-haider](https://github.com/muhammad-usman-haider)

## Support

For questions or technical support, please open an issue in the repository or contact the project maintainer.

---

**Last Updated**: June 2026
