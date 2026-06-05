# Temperature and Humidity Monitoring System

## 📋 Overview

A comprehensive Arduino-based environmental monitoring system that measures and logs temperature and humidity data in real-time. This project demonstrates the integration of sensor technologies, data acquisition, and persistent storage for environmental monitoring applications.

## ✨ Features

- **Dual Temperature Measurement**: Reads temperature in both Celsius and Fahrenheit
- **Humidity Monitoring**: Real-time humidity level detection
- **Data Logging**: Automatic data storage to SD card for historical analysis
- **Serial Communication**: Real-time data display via USB serial connection
- **Error Handling**: Built-in sensor failure detection and error reporting
- **Configurable Sampling**: Easily adjustable measurement intervals

## 🔧 Hardware Requirements

- **Microcontroller**: Arduino (tested with Arduino Uno and compatible boards)
- **Temperature & Humidity Sensor**: DHT22 (or DHT11 with code modification)
- **SD Card Module**: SD card reader/writer module with SPI interface
- **SD Card**: microSD card (formatted as FAT32, minimum 4GB)
- **Additional Components**:
  - USB cable for power and serial communication
  - Jumper wires for connections
  - Optional: Breadboard for prototyping

### Pinout Configuration

| Component | Arduino Pin |
|-----------|-------------|
| DHT22 Data | A5 |
| SD Card CS | 4 (Chip Select) |
| SPI MOSI | 11 |
| SPI MISO | 12 |
| SPI SCK | 13 |
| GND | GND |
| 5V Power | 5V |

## 📦 Software Requirements

- Arduino IDE 1.8.0 or higher
- **Libraries**:
  - SPI (built-in)
  - SD (built-in)
  - DHT Sensor Library (install via Arduino Library Manager)

### Installation Steps

1. **Install Arduino IDE**: Download from [arduino.cc](https://www.arduino.cc/en/software)

2. **Install DHT Library**:
   - Open Arduino IDE
   - Navigate to Sketch → Include Library → Manage Libraries
   - Search for "DHT" and install "DHT sensor library" by Adafruit

3. **Upload Code**:
   - Clone or download this repository
   - Open `Temperature and Humidity Monitoring System.ino` in Arduino IDE
   - Select your board type (Tools → Board)
   - Select the correct COM port (Tools → Port)
   - Click Upload (Ctrl+U)

## 🚀 Usage

### Running the System

1. **Power On**: Connect Arduino via USB to your computer or power source
2. **Monitor Data**: Open Serial Monitor (Tools → Serial Monitor) at 9600 baud
3. **Data Logging**: System automatically logs readings to `dataLog.txt` on the SD card

### Serial Output Example

```
Initializing SD card...
Initialization done.
Humidity: 45.30%, Temperature: 72.50°F, 22.50°C, Timestamp: 2580
Data written to SD card.
Humidity: 45.35%, Temperature: 72.45°F, 22.47°C, Timestamp: 12580
Data written to SD card.
```

### SD Card Data Format

Logged data is stored in plain text format:

```
Humidity: 45.30%, Temperature: 72.50°F, 22.50°C, Timestamp: 2580
Humidity: 45.35%, Temperature: 72.45°F, 22.47°C, Timestamp: 12580
Humidity: 45.40%, Temperature: 72.48°F, 22.49°C, Timestamp: 22580
```

## 🔧 Customization

### Changing Sensor Type

To use DHT11 instead of DHT22, modify line 6:

```cpp
#define DHTTYPE DHT11  // Change from DHT22 to DHT11
```

### Adjusting Sampling Interval

Modify the delay at line 60 (currently 10 seconds):

```cpp
delay(10000);  // Change value in milliseconds (10000 = 10 seconds)
```

### Changing SD Card Chip Select Pin

Modify line 7 if using a different CS pin:

```cpp
#define CSPIN 4  // Change to your desired pin
```

## 📊 Data Analysis

The logged data can be:
- Transferred to a computer for analysis
- Imported into spreadsheet applications (Excel, Google Sheets)
- Processed with Python or other analysis tools
- Visualized using graphing software

### Sample Python Script for Data Processing

```python
import pandas as pd

# Read the data log
data = pd.read_csv('dataLog.txt', delim_whitespace=True)

# Calculate statistics
print(data.describe())

# Export to CSV for Excel
data.to_csv('temperature_humidity.csv', index=False)
```

## ⚠️ Troubleshooting

| Issue | Solution |
|-------|----------|
| "Initialization failed!" | Check SD card connection, ensure card is formatted as FAT32 |
| "Failed to read from DHT sensor!" | Verify DHT sensor wiring, try replacing sensor |
| No serial output | Check USB connection, verify baud rate is 9600 |
| SD card not detected | Ensure CS pin is correct, verify SPI wiring |
| File not created on SD card | Check SD card has free space and is not write-protected |

## 📈 Applications

- Environmental monitoring in laboratories
- Smart home climate control systems
- Weather station data collection
- Greenhouse automation
- Cold chain monitoring
- HVAC system optimization
- Educational IoT projects

## 🔐 Safety Considerations

- Ensure proper power supply voltage (5V or 3.3V depending on Arduino variant)
- Handle SD cards with care to prevent data corruption
- Keep sensors away from moisture (unless waterproofed)
- Use appropriate enclosures for environmental protection

## 📄 Documentation

Additional technical documentation including circuit diagrams and component specifications can be found in:
- `Temperature and Humidity Monitoring System.pdf` - Complete project documentation

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Suggest improvements or optimizations
- Report bugs or issues
- Add new features (e.g., WiFi logging, cloud sync)
- Improve documentation

## 📝 License

This project is provided as-is for educational and personal use.

## 👨‍💻 Author

**Muhammad Usman Haider**

## 📞 Support & Questions

For questions or issues, please open an issue in this repository or refer to the project documentation.

---

**Last Updated**: June 2026

**Status**: ✅ Active & Maintained

**Hardware Compatibility**: Arduino Uno, Arduino Mega, Arduino Nano, and compatible boards
