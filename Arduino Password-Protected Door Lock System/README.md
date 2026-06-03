# Arduino Password-Protected Door Lock System

A sophisticated access control system built with Arduino that provides secure door locking/unlocking functionality through PIN-based authentication and emergency manual override capabilities.

## 🎯 Project Overview

This project implements a complete smart door lock system featuring:
- **Numeric keypad authentication** for password entry
- **Real-time LCD display** for user feedback
- **Servo motor control** for electromagnetic lock actuation
- **Visual indicators** (LED status lights)
- **Audio feedback** (buzzer alerts)
- **Emergency override button** for manual access
- **Automatic re-locking** after configurable duration

## 📋 Features

- ✅ 4x3 numeric keypad input
- ✅ 16x2 I2C LCD display
- ✅ Automatic door locking after 5-second window
- ✅ Wrong password indication with visual and audio alerts
- ✅ Real-time serial debugging output
- ✅ Emergency bypass button
- ✅ Red/Green LED status indicators
- ✅ Passive buzzer feedback system

## 🔧 Hardware Requirements

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno | 1 | Microcontroller |
| 4x3 Keypad | 1 | Numeric input (Membrane/Matrix type) |
| 16x2 LCD Display | 1 | I2C module (Address: 0x27) |
| Servo Motor | 1 | Door lock mechanism |
| Passive Buzzer | 1 | Audio feedback |
| Red LED | 1 | Status indicator (Locked state) |
| Green LED | 1 | Status indicator (Unlocked state) |
| Push Button | 1 | Emergency manual override |
| Resistors | 2 | 220Ω (for LEDs) |
| Connecting Wires | Multiple | Jumper wires |
| Power Supply | 5V | USB or external power |

## 📐 Pin Configuration

```
Keypad Rows:     Pins 5, 4, 3, 2
Keypad Columns:  Pins A3, A2, A1
LCD (I2C):       SDA (A4), SCL (A5)
Servo Motor:     Pin 6
Buzzer:          Pin 8
Green LED:       Pin 9
Red LED:         Pin 10
Push Button:     Pin 7 (Pull-up)
```

## 🔐 Default Credentials

- **Default Password:** `1234`
- **Entry Method:** Enter digits, then press `#` to submit

### Password Reset

To change the password, modify line 38 in the sketch:
```cpp
String password = "1234";  // Change this value
```

## 📖 How to Use

1. **Power on the system** - LCD displays "Enter Password:"
2. **Enter the 4-digit PIN** - Each digit displays as `*` on LCD
3. **Press `#` to submit:**
   - ✅ **Correct:** Door unlocks, green LED lights, "Access Granted" message displays
   - ❌ **Incorrect:** Buzzer sounds, "Wrong Password" message displays, red LED remains on
4. **Door auto-locks** after 5 seconds or press emergency button
5. **Press emergency button** (`*` key) at any time for manual override

## 💾 Dependencies

Install via Arduino IDE Library Manager:
- **Keypad** - by Mark Stanley & Alexander Brevig (v3.1.1+)
- **LiquidCrystal I2C** - by Frank de Brabander (v1.1.2+)

## 🚀 Installation Steps

1. Clone or download this repository
2. Open `Arduino Password-Protected Door Lock System.ino` in Arduino IDE
3. Install required libraries (Sketch → Include Library → Manage Libraries)
4. Configure pin assignments if using different Arduino board
5. Verify I2C LCD address (default: 0x27) using I2C scanner
6. Upload the sketch to your Arduino board
7. Monitor Serial output at 9600 baud for debugging

## 🔍 Serial Debugging

Open Serial Monitor (9600 baud) to view:
- Key presses
- Current input buffer
- System state changes
- Lock/unlock events

## ⚙️ Configuration Options

### Auto-lock Duration
Modify line 44 to change unlock duration:
```cpp
const unsigned long doorOpenDuration = 5000;  // milliseconds
```

### LCD I2C Address
If your LCD uses a different address, update line 21:
```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change 0x27 if needed
```

## 🛠️ Troubleshooting

| Issue | Solution |
|-------|----------|
| **LCD shows nothing** | Verify I2C address, check wiring, adjust contrast pot |
| **Keypad not responding** | Verify pin connections, test with keypad example sketch |
| **Servo doesn't move** | Check power supply (5V+), verify pin 6 connectivity |
| **Buzzer silent** | Verify buzzer polarity, check pin 8 output |
| **Button won't work** | Check INPUT_PULLUP configuration, verify pin 7 |

## 📚 Technical Specifications

- **Microcontroller:** ATmega328P (Arduino Uno)
- **Operating Voltage:** 5V
- **Password Length:** 4 digits (customizable)
- **LCD Resolution:** 16x2 characters
- **Keypad Matrix:** 4 rows × 3 columns
- **Servo Range:** 0° (locked) to 90° (unlocked)
- **Buzzer Frequency:** 1kHz (for wrong password)
- **Baud Rate:** 9600 bps

## 📄 Project Files

```
Arduino Password-Protected Door Lock System/
├── README.md                           (This file)
├── Arduino Password-Protected Door Lock System.pdf
├── Arduino Password-Protected Door Lock System.docx
└── arduino code/
    └── Arduino Password-Protected Door Lock System.ino
```

## 🔄 Future Enhancements

- [ ] RFID card integration
- [ ] Multiple user passwords with logging
- [ ] Wireless control (Bluetooth/WiFi)
- [ ] SD card logging of access events
- [ ] Mobile app control
- [ ] EEPROM password storage
- [ ] Time-based lock schedule

## 📝 License

This project is provided as-is for educational and personal use.

## 👨‍💻 Author

**Muhammad Usman Haider**

## 📧 Support

For issues, questions, or contributions, please refer to the project documentation or contact the author.

---

**Last Updated:** June 2026  
**Status:** ✅ Functional & Tested
