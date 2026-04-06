# BLE Heart Rate & Temperature Sensor (blehrv5)

An ESP32-based BLE (Bluetooth Low Energy) sensor application that simulates a heart rate monitor and temperature sensor using the NimBLE stack.

## Features

- **Heart Rate Service** (UUID: 0x180D)
  - Simulates heart rate measurements (90-160 BPM)
  - Notifications sent every 1 second when enabled
  - Standard Heart Rate Measurement characteristic (UUID: 0x2A37)
  - Body Sensor Location characteristic (UUID: 0x2A38)

- **Health Thermometer Service** (UUID: 0x1809)
  - Simulates temperature measurements (~36.50°C)
  - Notifications sent every 200ms when enabled
  - Standard Temperature Measurement characteristic (UUID: 0x2A1C)
  - IEEE 11073-20601 format (3-byte mantissa + exponent)

- **Device Information Service** (UUID: 0x180A)
  - Manufacturer Name
  - Model Number

## Supported Targets

| ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C5 | ESP32-C6 | ESP32-C61 | ESP32-H2 | ESP32-S3 |
| ----- | -------- | -------- | -------- | -------- | --------- | -------- | -------- |

## Prerequisites

- ESP-IDF v5.x or later
- ESP32 development board
- BLE client device (smartphone/tablet with BLE scanner app)

## Setup & Build

### 1. Set Target Chip

```bash
idf.py set-target <chip_name>
```

Replace `<chip_name>` with your target (e.g., `esp32`, `esp32c3`, `esp32s3`).

### 2. Build the Project

```bash
idf.py build
```

### 3. Flash & Monitor

```bash
idf.py -p PORT flash monitor
```

Replace `PORT` with your serial port (e.g., `/dev/ttyUSB0` or `COM3`).

**Exit serial monitor:** Press `Ctrl-]`

## Usage

1. Flash the firmware to your ESP32 board
2. Open serial monitor to view logs
3. Use a BLE scanner app (e.g., nRF Connect, LightBlue) to scan for devices
4. Connect to `blehr_sensor_1.0`
5. Enable notifications for:
   - **Heart Rate Measurement** characteristic
   - **Temperature Measurement** characteristic
6. Observe real-time sensor data in your BLE client app

## Example Output

```
I (91) BTDM_INIT: BT controller compile version [fe7ced0]
I (421) NimBLE_BLE_HeartRate: BLE Host Task Started
GAP procedure initiated: stop advertising.
Device Address: xx:xx:xx:xx:xx:xx
connection established; status=0
subscribe event; cur_notify=1
 value handle; val_handle=3
Temperature subscription enabled
GATT procedure initiated: notify; att_handle=3
GATT procedure initiated: notify; att_handle=3
```

## Project Structure

```
blehrv5/
├── main/
│   ├── main.c           # Main application entry & BLE event handling
│   ├── gatt_svr.c       # GATT server & service definitions
│   ├── blehr_sens.h     # BLE service UUIDs & configuration
│   └── CMakeLists.txt   # Component build configuration
├── CMakeLists.txt       # Project build configuration
├── sdkconfig            # ESP-IDF project configuration
└── README.md            # This file
```

## Architecture

- **NimBLE Stack**: Lightweight BLE host stack
- **FreeRTOS Tasks**: 
  - Heart rate notification timer (1-second intervals)
  - Temperature notification task (200ms intervals)
- **GATT Server**: Custom service registration with callback handling
- **NVS Flash**: Stores PHY calibration data

## Configuration

Key parameters in the code:
- Device name: `blehr_sensor_1.0`
- Heart rate range: 90-160 BPM
- Temperature: ~36.50°C with slight variation
- Notification intervals: 1s (HR), 200ms (Temp)

## Troubleshooting

### Common Issues

**Build fails:**
- Ensure ESP-IDF environment is sourced: `. $IDF_PATH/export.sh`
- Run `idf.py set-target <chip>` first

**BLE not advertising:**
- Check serial monitor for initialization errors
- Verify NVS flash is properly initialized

**Cannot connect:**
- Ensure BLE client is within range
- Check if device name `blehr_sensor_1.0` appears in scanner

**No notifications:**
- Enable notifications in your BLE client app
- Check subscription events in serial monitor

## License

This project is based on the Apache 2.0 licensed ESP-IDF examples.

## Resources

- [ESP-IDF Programming Guide](https://idf.espressif.com/)
- [NimBLE Documentation](https://mynewt.apache.org/latest/network/index.html)
- [BLE Heart Rate Profile](https://www.bluetooth.com/specifications/specs/heart-rate-profile-1-0/)
- [BLE Health Thermometer Profile](https://www.bluetooth.com/specifications/specs/health-thermometer-profile-1-0/)
