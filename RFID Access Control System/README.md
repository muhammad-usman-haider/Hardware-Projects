# RFID Access Control System

A comprehensive hardware-based access control solution using RFID technology with Arduino microcontroller integration. This system provides secure card-based authentication, real-time logging, and automated door lock control.

## 🎯 Project Overview

This RFID Access Control System implements a complete access management solution featuring:
- **Card-based Authentication**: Read and validate RFID card UIDs
- **Real-time Clock**: Track access timestamps with DS3231 RTC module
- **Automated Locking**: Servo motor-controlled door mechanism
- **Visual & Audio Feedback**: LED indicators and buzzer alerts
- **Data Logging**: Automatic logging to Excel spreadsheet with employee details

## ✨ Features

### Security Features
- **Multi-card Support**: Store and validate multiple authorized RFID cards
- **UID-based Authentication**: Unique identifier verification for each card
- **Access Logging**: Complete audit trail with timestamp, user ID, and employee details
- **Visual Confirmation**: Green LED for authorized access, red LED for denied access

### Hardware Integration
- **RFID Reader**: MFRC522 RFID module for card scanning
- **Servo Motor**: Automated door lock/unlock mechanism
- **Real-time Clock**: DS3231 RTC for accurate timestamping
- **Alerts**: Audible buzzer feedback (single beep for access granted, triple beep for denied)
- **LED Indicators**: 
  - Green LED: Authorized access
  - Red LED: Unauthorized access

### Data Management
- **Excel Integration**: Direct logging to Excel spreadsheet
- **Timestamp Recording**: Date, time, card UID, employee name, and ID
- **Organized Storage**: Automatic workbook saving with employee records

## 🔧 Hardware Requirements

| Component | Specification | Pin |
|-----------|---------------|-----|
| Arduino Uno/Mega | Microcontroller | - |
| MFRC522 | RFID Reader Module | SS: 10, RST: 9 |
| DS3231 | Real-time Clock Module | I2C (SDA, SCL) |
| Servo Motor | Door Lock Actuator | Pin 3 |
| Red LED | Access Denied Indicator | Pin 6 |
| Green LED | Access Granted Indicator | Pin 5 |
| Buzzer | Audio Alert | Pin 8 |
| 5V Power Supply | System Power | - |

### RFID Cards
- ISO/IEC 14443A compatible RFID cards
- 4-byte UID format
- 13.56 MHz frequency

## 📋 Software Requirements

### Arduino Libraries
```cpp
#include <SPI.h>           // Serial Peripheral Interface
#include <MFRC522.h>       // RFID Reader library
#include <Wire.h>          // I2C communication
#include <RTClib.h>        // Real-time Clock library
#include <Servo.h>         // Servo motor control
```

### Arduino IDE
- Version: 1.8.x or later
- Baud Rate: 9600 bps

## 🚀 Installation & Setup

### 1. Hardware Assembly
1. Connect MFRC522 RFID module to Arduino SPI pins
2. Connect DS3231 RTC module via I2C (SCL, SDA)
3. Attach servo motor to pin 3
4. Connect LEDs to pins 5 (Green) and 6 (Red)
5. Connect buzzer to pin 8
6. Power all components from 5V supply

### 2. Library Installation
```
Arduino IDE → Sketch → Include Library → Manage Libraries
Search and install:
- MFRC522 by GithubCommunity
- RTClib by Adafruit
```

### 3. Card Registration
Update authorized card UIDs in the code:
```cpp
byte Name1[4] = {0x63, 0xF0, 0x0A, 0x0E}; // First UID card
byte Name2[4] = {0xC3, 0x8F, 0x06, 0x10}; // Second UID card
```

### 4. Employee Data Configuration
```cpp
if (card_ID[i] == Name1[i]) {
    Name = "First Employee";
    Number = 123456;
} else if (card_ID[i] == Name2[i]) {
    Name = "Second Employee";
    Number = 789101;
}
```

### 5. Upload Code
1. Open `code.txt` in Arduino IDE
2. Configure correct board and COM port
3. Click Upload

## 📊 Operation Flow

```
Card Presented
    ↓
RFID Reader Detects Card
    ↓
Compare UID with Database
    ↓
    ├─→ Authorized (Match Found)
    │   ├→ Green LED ON
    │   ├→ Buzzer Beep (Single)
    │   ├→ Servo Unlock (90°)
    │   ├→ Log to Excel
    │   ├→ 5-second Door Open
    │   └→ Servo Lock (0°)
    │
    └─→ Unauthorized (No Match)
        ├→ Red LED ON
        ├→ Buzzer Alert (Triple Beep)
        └→ Access Denied
```

## 🔐 Access Control Logic

### Authorization Process
1. **Card Detection**: System detects new RFID card presence
2. **UID Reading**: Reads 4-byte unique identifier from card
3. **Database Matching**: Compares UID with stored authorized cards
4. **Decision**: Grants or denies access based on match
5. **Logging**: Records all access attempts with timestamp

### Timeout Settings
- **Door Unlock Duration**: 5 seconds (configurable)
- **LED/Buzzer Display**: 2 seconds after event
- **Card Read Debounce**: 1 second minimum between reads

## 📝 Data Logging Format

Excel spreadsheet entries are recorded in the following format:

| Date | Time | UID | Name | Number |
|------|------|-----|------|--------|
| 2025/05/26 | 14:30:45 | 63:F0:0A:0E | First Employee | 123456 |
| 2025/05/26 | 14:32:10 | C3:8F:06:10 | Second Employee | 789101 |

## 🔄 Customization Guide

### Adding New Cards
1. Scan new card to identify UID
2. Add UID to authorized array
3. Update employee name and ID
4. Recompile and upload

### Modifying Door Lock Duration
```cpp
delay(5000); // Change milliseconds (currently 5 seconds)
```

### Adjusting Servo Angles
```cpp
myServo.write(0);  // Locked position (0°)
myServo.write(90); // Unlocked position (90°)
```

### Changing Buzzer Pattern
Edit `beepBuzzer()` function for custom alert patterns

## 📂 Project Files

- **code.txt**: Main Arduino firmware
- **RFID Access Control System.pdf**: Technical documentation and schematics
- **rfid_excel_sheet.xlsm**: Excel template for logging
- **arduino file/**: Additional Arduino sketches and utilities

## 🐛 Troubleshooting

| Issue | Solution |
|-------|----------|
| RFID card not detected | Check SPI connections, verify SS and RST pins |
| RTC not initialized | Ensure DS3231 I2C connection, check library version |
| Servo not moving | Verify servo PWM pin (3), check power supply |
| Excel not updating | Verify serial communication, check baud rate (9600) |
| LEDs/Buzzer not responding | Check pin configuration, verify component connections |

## ⚙️ Technical Specifications

- **Operating Voltage**: 5V DC
- **Current Consumption**: ~500mA (typical)
- **RFID Read Range**: 2-5 cm (depends on card/module quality)
- **Response Time**: <500ms from card detection to door unlock
- **Data Logging**: Real-time to Excel via serial communication
- **Maximum Authorized Cards**: Expandable (limited by Arduino memory)

## 📚 References

- [MFRC522 RFID Module Documentation](http://www.micropic.ru/mfrc522_eng)
- [Arduino Servo Library Reference](https://www.arduino.cc/reference/en/libraries/servo/)
- [DS3231 RTC Module Guide](https://www.adafruit.com/product/3013)
- [Arduino SPI Communication](https://www.arduino.cc/en/Reference/SPI)

## 🔒 Security Considerations

- **Physical Security**: Store authorized card UIDs securely
- **Backup Power**: Consider UPS for continuous operation
- **Access Logs**: Regularly back up Excel logging files
- **Regular Audits**: Periodically review access records
- **Card Expiration**: Implement card validity date checks for future versions

## 🚦 Status Indicators

### LED Behavior
- **Green LED**: Lights up for 2 seconds when access is granted
- **Red LED**: Lights up for 2 seconds when access is denied
- **Both OFF**: System ready for next card

### Buzzer Alerts
- **Single Beep**: Authorized access granted
- **Triple Beep**: Unauthorized access attempted

## 📞 Support & Maintenance

For issues or improvements:
1. Review troubleshooting section
2. Check hardware connections
3. Verify Arduino IDE configuration
4. Consult technical documentation (PDF)

## 📄 License

This project is provided as-is for educational and commercial use.

## 👨‍💻 Author

**Muhammad Usman Haider**

---

**Last Updated**: May 2026

For detailed schematics and circuit diagrams, refer to the included PDF documentation.
