# Line Following Car (Arduino)

This project is a basic line-following robot built using an Arduino and IR sensors for a EEE course of mine. It is capable of tracking a black line on a white surface using three sensors, and can make precise turns based on sensor input. The logic includes recovery U-turns and different motion profiles like sharp turns and curved paths.

---

## 🚗 Features

- Follows a black line using 3 IR sensors (left, middle, right)
- Detects line loss and performs U-turns based on last movement
- Executes hard and soft turns depending on pattern
- Forward, stop, and recovery logic implemented
- Simple analog motor control using `analogWrite`
- Serial monitor outputs sensor pattern in real time

---

## 📷 Hardware Requirements

- Arduino Uno (or compatible board)
- 3x IR sensors
- 2x DC motors with driver (L298N / L293D)
- Chassis, wheels, and power supply
- Jumper wires, breadboard (optional)

---

## 🧠 Sensor Logic (Pattern Recognition)

| Pattern | Meaning         | Action         |
|---------|-----------------|----------------|
| `010`   | Center on line  | Forward        |
| `011`   | Slight right    | Right Forward  |
| `001`   | Hard right      | Right Turn     |
| `110`   | Slight left     | Left Forward   |
| `100`   | Hard left       | Left Turn      |
| `000`   | Line lost       | U-Turn (based on last pattern) |
| `111`   | All sensors see line | Stop       |

---

## 🛠️ Installation & Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/line-following-car.git
   cd line-following-car
   ```

2. Open the `.ino` file in the Arduino IDE.

3. Connect your Arduino board and upload the code.

4. Assemble the car with sensors positioned on the front bottom side, and place it on a track with a black line on a white background.

---

## 🧾 File Structure

```
line-following-car/
│
├── line_following_car.ino   # Main Arduino sketch
├── README.md                # This file
```

---

## 🧠 Future Improvements

- PID control for smoother movement
- Bluetooth or Wi-Fi remote control
- Obstacle detection using ultrasonic sensors
- OLED/LCD display for live sensor values

---

## 📝 License

This project is licensed under the MIT License. See `LICENSE` file for more details.

---

## 👨‍💻 Author

**Imam**  
Computer Science & Engineering Student | Explorer | Builder  
[LinkedIn](https://www.linkedin.com/in/imam-ud-doula) • [GitHub](https://github.com/imamdoula004)

---

## 🤝 Contributions

Contributions are welcome! Fork the repo, create a branch, submit a pull request.
```
