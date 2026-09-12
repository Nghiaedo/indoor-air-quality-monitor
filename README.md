# Indoor Air Quality Monitor

An Arduino-based indoor air quality monitoring system that measures **temperature, humidity, and air quality** using AHT20 and ENS160 sensors.

The system displays sensor data on a **16×2 I2C LCD** and uses three LEDs to indicate the current temperature level.

## Features

* Temperature measurement
* Relative humidity measurement
* Air quality monitoring
* AQI measurement
* TVOC measurement
* eCO₂ measurement
* 16×2 I2C LCD display
* Temperature status indicators

## Hardware

| Component                           |  Quantity |
| ----------------------------------- | --------: |
| Arduino                             |         1 |
| AHT20 Temperature & Humidity Sensor |         1 |
| ENS160 Air Quality Sensor           |         1 |
| 16×2 I2C LCD                        |         1 |
| Green LED                           |         1 |
| Yellow LED                          |         1 |
| Red LED                             |         1 |
| Resistor                            |         3 |
| Jumper wires                        | As needed |

## Circuit

### Pin Configuration

| Component  | Arduino Pin |
| ---------- | ----------- |
| Green LED  | D2          |
| Yellow LED | D7          |
| Red LED    | D12         |
| I2C SDA    | SDA         |
| I2C SCL    | SCL         |

The AHT20, ENS160, and LCD communicate with the Arduino through the **I2C interface**.

## Temperature Indicator

The three LEDs indicate the measured temperature:

| Temperature   | LED    |
| ------------- | -------|
| < 24°C        | Green  |
| 24°C – < 27°C | Yellow |
| ≥ 27°C        | Red    |

## Sensors

### AHT20

The AHT20 sensor provides:

* Temperature
* Relative humidity

### ENS160

The ENS160 air quality sensor provides:

* **AQI** — Air Quality Index
* **TVOC** — Total Volatile Organic Compounds
* **eCO₂** — Equivalent CO₂

## LCD Display

The LCD alternates between temperature/humidity information and air quality information.

### Temperature & Humidity

```text
Temp:25.3 C
Hum:60.2% rH
```

### Air Quality

```text
AQI:1 TVOC:20
eCO2:400ppm
```

## Required Libraries

Install the following libraries using the Arduino IDE Library Manager:

* `Adafruit AHTX0`
* `LiquidCrystal I2C`
* `ScioSense ENS160`

The `Wire` library is included with the Arduino framework.

## Installation

1. Clone or download this repository.

2. Open:

```text
indoor-air-quality-monitor.ino
```

in the Arduino IDE.

3. Install all required libraries.

4. Connect the hardware according to the circuit configuration.

5. Select your Arduino board and the correct serial port.

6. Upload the program.

7. The measurements will be displayed on the LCD.

## Project Structure

```text
indoor-air-quality-monitor/
│
├── indoor-air-quality-monitor.ino
├── README.md
├── LICENSE
├── .gitignore
│
└── images/
    ├── circuit.png
    └── prototype.jpg
```

## Future Improvements

Possible future improvements include:

* [ ] Add Wi-Fi connectivity
* [ ] Create a web-based monitoring dashboard
* [ ] Store historical sensor data
* [ ] Add real-time data visualization
* [ ] Implement air-quality warning alerts
* [ ] Add mobile notifications
* [ ] Improve LCD user interface
* [ ] Reduce blocking delays using a fully non-blocking timing system

## Project Status

**Status:** Completed prototype

**Platform:** Arduino

**Programming Language:** C++

**Communication:** I2C

**Sensors:** AHT20, ENS160

**Display:** 16×2 I2C LCD

## License

This project is licensed under the MIT License.
