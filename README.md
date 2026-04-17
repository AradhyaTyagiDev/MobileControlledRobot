# MobileControlledRobot
🤖 Mobile Controlled Robot (ESP32) without any sensors

This is my project where I built a small robot that can be controlled using mobile phone.

I made this project to learn:
- ESP32 programming
- Robot movement
- Real world problem solving
  
---

## 🚀 What this robot can do

- Move Forward ⬆️
- Move Backward ⬇️
- Turn Left ⬅️
- Turn Right ➡️
- Stop 🛑

---

## 🧠 Idea behind this

I wanted to build something which can:
- Move like a real robot
- Take commands from mobile
- Sense environment

Later I want to improve it so that:
- It can take decisions itself
- It becomes a smart robot (AI based)

---

## 🔧 Components Used

- **MCU**: ESP32 WROOM
- Motor Driver (L298N)
- DC Motors (2 or 4)
- Ultrasonic Sensor (HC-SR04)
- Battery
- Jumper wires
- Chassis
  
**Tool Used**: Ardino IDO + Visual Studio + PlatformIO

**Mobile App** Dabble (As Remote)

---

## ⚠️ Important Learning (Mistakes I did)

- ❌ Directly connected ECHO to ESP32 → **Wrong (5V issue)**
- ✅ Used voltage divider → **Correct (safe 3.3V)**

- ❌ Random delay → unstable readings  
- ✅ Fixed delay (50ms) → stable output

- ❌ Wires loose → robot not working properly  
- ✅ Tight connections → stable system

---

## 😅 Challenges I faced

- ESP32 pin confusion
- Sensor giving wrong values
- Voltage mismatch (5V vs 3.3V)
- Robot moving in wrong direction
- Wiring mess

---

## 🧪 What I improved

- Better structure (modular code)
- Clean sensor handling
- Stable readings
- Better motor control logic

---

## 📱 Mobile Control

Currently using:
- Bluetooth / WiFi based control (basic)

Future:
- App based UI
- Real-time control
- Voice control maybe 😄

---

## 🧑‍💻 Why I built this

I want to:
- Learn robotics deeply
- Build real products
- Eventually create smart systems

---

## ❤️ Final Thoughts

This is not perfect project.  
But I learned a lot while building it.

I believe:
> "Building small things leads to big innovations."

---

## 📸 Demo (Coming Soon)

▶️ [Watch Demo on LinkedIn](https://www.linkedin.com/posts/aradhya-tyagi-3162a73b7_robotics-esp32-iot-ugcPost-7449109218793775105-OZz9)

---

## 🤝 Contributions

This is my personal learning project, but suggestions are welcome.

---

## 📌 Author

Aradhya Tyagi
