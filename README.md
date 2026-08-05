🎙️ ESP32 Voice Control Smart Room System



The ESP32 Voice Control Smart Room System is an IoT-based home automation project developed using an ESP32 Dev Module. The system uses the Arduino Bluetooth Control mobile application to receive voice commands through Bluetooth communication.

The ESP32 processes the received commands and controls a room light, a fan, and an automatic window system. A DHT11 sensor continuously monitors temperature and humidity, while a 16×2 I2C LCD displays sensor readings and the current status of each device in real time.

This project demonstrates Bluetooth communication, embedded systems, IoT automation, sensor integration, and real-time monitoring using ESP32.

---

✨ Features

- 🎤 Voice Control using Arduino Bluetooth Control App
- 🔵 Bluetooth Communication with ESP32
- 💡 Room Light ON/OFF
- 🌀 Fan ON/OFF
- 🪟 Automatic Window Open/Close using Servo Motor
- 🌡️ Temperature Monitoring
- 💧 Humidity Monitoring
- 📟 Real-Time LCD Status Display
- ⚡ External Power Supply using Buck Converter
- 🏠 Smart Home Automation Prototype

---

🛠 Hardware Components

Component| Quantity
ESP32 Dev Module| 1
Breadboard Power Supply (MB102)| 1
Buck Converter| 1
1-Channel Relay Module| 2
DC Fan| 1
LED / Room Light| 1
SG90 Servo Motor| 1
DHT11 Sensor| 1
16×2 I2C LCD Display| 1
Jumper Wires| As Required
External Power Supply| 1

---

🔌 ESP32 Pin Mapping

Component| GPIO
Fan Relay| GPIO 19
Light Relay| GPIO 23
Servo Motor| GPIO 13
DHT11| GPIO 4
LCD SDA| GPIO 21
LCD SCL| GPIO 22

---

⚡ Power Supply

- ESP32 powered by USB/Breadboard Power Supply
- Fan powered through Relay
- Servo powered from external 5V
- Buck Converter used to provide stable voltage
- All grounds are connected together (Common GND)

---

📱 Mobile Application

Application: Arduino Bluetooth Control

Communication Method:

Smartphone → Bluetooth → ESP32 → Relay / Servo → Devices

---

🎤 Voice Commands

Voice Command| Action| LCD Display
Fan On| Turn ON Fan| FAN ON
Fan Off| Turn OFF Fan| FAN OFF
Light On| Turn ON Room Light| ROOM LIGHT ON
Light Off| Turn OFF Room Light| ROOM LIGHT OFF
Open Window| Servo Opens Window| WINDOW OPEN
Close Window| Servo Closes Window| WINDOW CLOSED

---

📟 LCD Display

The LCD displays:

- Temperature
- Humidity
- Fan Status
- Light Status
- Window Status

Example:

Temp : 29°C
Hum  : 72%

Fan ON
Light OFF
Window OPEN

---

🔄 System Workflow

1. Open Arduino Bluetooth Control Application.
2. Connect to ESP32 via Bluetooth.
3. Speak a voice command.
4. The application converts the voice command into text.
5. ESP32 receives the Bluetooth command.
6. ESP32 controls the relay or servo motor.
7. LCD updates the current device status.
8. DHT11 continuously measures temperature and humidity.

---

📚 Required Arduino Libraries

- BluetoothSerial
- Wire
- LiquidCrystal_I2C
- ESP32Servo
- DHT Sensor Library
- Adafruit Unified Sensor

---

📂 Project Structure

Voice-Control-Smart-Room
│
├── README.md
├── Voice_Control_Smart_Room.ino
├── images/
│   ├── smart_room_system.png
│   ├── wiring_diagram.png
│   └── project_photo.jpg
├── circuit/
│   └── wiring.pdf
└── videos/
    └── demo.mp4

---

🎯 Applications

- Smart Home Automation
- IoT Learning
- University Projects
- Embedded Systems
- Voice-Controlled Devices
- Home Automation Research

---

🚀 Future Improvements

- Wi-Fi Control
- Blynk IoT Integration
- Google Assistant Integration
- Firebase Database
- Mobile Application Development
- AI Voice Recognition
- Energy Monitoring
- Security Features

---

👨‍💻 Developer

Sasidu Wishshanka

Faculty of Technology

Rajarata University of Sri Lanka

---

📜 License

This project is licensed under the MIT License.

---

⭐ If you like this project, don't forget to give it a Star on GitHub!
