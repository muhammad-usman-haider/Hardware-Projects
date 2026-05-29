# Smart Traffic Control System

## Overview

The **Smart Traffic Control System** is an intelligent embedded systems project that optimizes traffic flow at intersections using IR sensors for real-time traffic density detection and RFID technology for emergency vehicle priority. This system automatically adjusts signal timing based on traffic congestion levels while supporting emergency override capabilities.

## Features

✨ **Intelligent Traffic Management**
- Real-time traffic density detection using dual IR sensors
- Adaptive green light duration based on congestion levels
- Standard traffic light state machine (Red → Green → Yellow → Red)

🚨 **Emergency Vehicle Priority**
- RFID-based emergency vehicle detection
- Automatic priority mode activation for emergency vehicles
- Extended green light duration in emergency mode

📊 **Dynamic Signal Timing**
- **Low Traffic**: 10 seconds green light
- **Medium Traffic**: 20 seconds green light  
- **High Traffic**: 40 seconds green light
- **Emergency Mode**: 30 seconds green light with automatic bypass

🔧 **System States**
- **RED**: Stop state (10 seconds)
- **GREEN**: Go state (variable: 10-40 seconds based on density)
- **YELLOW**: Caution state (3 seconds)
- **RFID_MODE**: Emergency priority mode (30 seconds)

## Hardware Requirements

### Components
- **Microcontroller**: Arduino (UNO/Mega)
- **Traffic Lights**: 3× LED modules (Red, Yellow, Green)
- **IR Sensors**: 2× Infrared sensors (for traffic density detection)
- **RFID Module**: MFRC522 RFID reader
- **RFID Card/Tag**: Emergency vehicle tag
- **SPI Interface**: For MFRC522 communication

### Pin Configuration
| Component | Pin | Description |
|-----------|-----|-------------|
| Red LED | 8 | Stop signal |
| Yellow LED | 9 | Caution signal |
| Green LED | 10 | Go signal |
| IR Sensor 1 | 2 | Traffic detection lane 1 |
| IR Sensor 2 | 3 | Traffic detection lane 2 |
| RFID Chip Select (SS) | 7 | SPI slave select |
| RFID Reset (RST) | 6 | RFID module reset |

## Software Architecture

### Traffic Density Logic
The system reads two IR sensors to determine traffic density:

| IR1 | IR2 | Result | Duration |
|-----|-----|--------|----------|
| HIGH | HIGH | None | 10s |
| HIGH | LOW | Low | 20s |
| LOW | HIGH | Low | 20s |
| LOW | LOW | High | 40s |

### State Machine
```
RED (10s)
    ↓
[Check Traffic Density]
    ↓
GREEN (10-40s based on density)
    ↓
YELLOW (3s)
    ↓
RED
```

**Emergency Override**: At any state, if RFID emergency vehicle detected → Immediate GREEN (30s)

### Libraries Used
- **SPI.h**: Serial Peripheral Interface communication
- **MFRC522.h**: RFID module communication

## Installation

### 1. Hardware Setup
1. Connect LEDs to pins 8, 9, and 10 with appropriate current-limiting resistors (330Ω)
2. Connect IR sensors to pins 2 and 3 (INPUT mode)
3. Connect MFRC522 RFID module via SPI:
   - MOSI → Arduino MOSI
   - MISO → Arduino MISO
   - SCK → Arduino SCK
   - SS → Pin 7
   - RST → Pin 6
4. Connect power and ground appropriately

### 2. Software Setup
1. Clone or download this repository
2. Open the `SMART_TRAFIC_SYSTEM.ino` file in Arduino IDE
3. Install required libraries:
   - MFRC522 library (Search in Arduino Library Manager)
4. **Configure Emergency RFID UID** (Line 39):
   ```cpp
   byte emergencyUID[4] = {0x63, 0xF0, 0x0A, 0x0E};  // Replace with your card UID
   ```
5. Select your Arduino board and COM port
6. Upload the sketch

### 3. Get Your Emergency RFID Card UID
1. Use an RFID scanning sketch to read your card UID
2. Update the `emergencyUID` array in the code with the actual UID

## Configuration

### Timing Parameters (in milliseconds)
```cpp
#define YELLOW_TIME   3000    // Yellow light duration
#define RED_TIME      10000   // Red light duration
#define RFID_GREEN    30000   // Emergency mode green light
#define GREEN_LOW     10000   // Low traffic green duration
#define GREEN_MEDIUM  20000   // Medium traffic green duration
#define GREEN_HIGH    40000   // High traffic green duration
```

Modify these values in the code to adjust system timing according to your requirements.

## Operation

1. **Power on** the system
2. **Normal Operation**: System cycles through traffic lights based on detected traffic density
3. **Emergency Mode**: Present emergency RFID card to the reader for immediate green light
4. **Serial Monitor**: Connect to serial port (9600 baud) to view system status and debug information

### Serial Output Examples
```
Smart Traffic System Initialized
Traffic: LOW
Traffic: HIGH
RFID PRIORITY MODE
RFID MODE ENDED
```

## Advantages

- ✅ **Reduces Congestion**: Adaptive timing reduces wait times
- ✅ **Emergency Support**: Emergency vehicles get priority access
- ✅ **Energy Efficient**: Optimized LED control and sensor usage
- ✅ **Scalable**: Can be extended to multi-intersection systems
- ✅ **Cost-Effective**: Uses readily available Arduino and components

## Future Enhancements

- 📡 IoT integration for centralized traffic management
- 🗺️ GPS-based emergency vehicle routing
- 📊 Traffic analytics and reporting
- 🌐 Multi-intersection coordination
- 📱 Mobile app for real-time traffic updates
- 🚗 Vehicle counting and statistical analysis

## Troubleshooting

| Issue | Solution |
|-------|----------|
| LEDs not lighting | Check pin connections and LED polarity |
| RFID not detecting cards | Verify MFRC522 connections; check card UID in code |
| IR sensors not responding | Clean sensors; verify pin connections and sensor calibration |
| Erratic behavior | Check power supply voltage; verify Arduino COM port settings |
| Serial output shows no data | Check baud rate (9600); verify USB driver installation |

## License

This project is open-source and available under the MIT License. Feel free to use, modify, and distribute as needed.

## Author

**Muhammad Usman Haider**  
Hardware Projects Repository

## Support

For issues, questions, or contributions, please open an issue on the GitHub repository.

---

**Last Updated**: 2026-05-29  
**Version**: 1.0  
**Status**: Active Development
