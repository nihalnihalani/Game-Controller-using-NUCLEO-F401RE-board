# 🎮 IoT Game Controller using NUCLEO-F401RE

Control *Angry Gran Runner* with Real-World Motion!

![Platform](https://img.shields.io/badge/Platform-NUCLEO--F401RE-blue)
![Language](https://img.shields.io/badge/Language-C++%20%7C%20Python-yellow)
![Status](https://img.shields.io/badge/Status-Prototype-green)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

---

## 🧠 Abstract

This project turns a NUCLEO-F401RE development board with an X-NUCLEO-IKS01A2 sensor into a real-world motion-based game controller! When the board is physically lifted, it triggers a simulated "Up Arrow" keypress on your PC — letting you jump over obstacles in games like **Angry Gran Runner** or Chrome's **T-Rex Runner**.

---

## 🎯 Goal

Simulate keyboard input using motion sensors to create a fun and interactive physical game controller for online games.

---

## 🧩 System Overview

![System Architecture](https://via.placeholder.com/800x400?text=System+Architecture+Diagram+Here)

-   **Hardware:** NUCLEO-F401RE + X-NUCLEO-IKS01A2
-   **Software:** MBED C++ firmware + Python (PySerial, PyAutoGUI)
-   **Communication:** USB serial connection
-   **Action:** Y-axis motion → "u" → simulated `↑` key

---

## 🔧 Hardware Requirements

-   NUCLEO-F401RE board
-   X-NUCLEO-IKS01A2 MEMS motion sensor
-   Micro USB cable
-   A PC with Python 3.x

---

## 📦 Software Requirements

-   [MBED Online Compiler](https://os.mbed.com/)
-   Python 3.x
-   Required Python packages:

    ```bash
    pip install pyserial pyautogui
    ```

## 🚀 Setup Instructions

1.  **Connect Hardware**

    Stack the MEMS sensor board on the NUCLEO-F401RE.

    Connect the board to your PC via USB.

2.  **Upload Firmware**

    Import the provided .cpp code into MBED Compiler.

    Compile the project to generate a .bin file.

    Drag and drop the .bin file onto the mounted NUCLEO drive.

3.  **Run Python Script**

    Open `Python_WakeUp.py` in IDLE or your preferred IDE.

    Click `Run` > `Run Module`.

4.  **Test the Motion**

    Gently lift the board to simulate a Y-axis wake-up event.

    The sensor sends "u" via serial, triggering a virtual ↑ key press.

    Test the functionality using Angry Gran Run or the Chrome T-Rex game.

---


## 🧪 Challenges Faced

* **Latency Handling:** A `wait(0.1s)` was added after detecting the "u" input to ensure smooth and stable input detection from the serial port.

---

## 📚 References

* Wake-Up Detection Code – MBED
* Angry Gran Runner Game

---

## 🧠 Ideas for Future Work

* Map additional gestures (tilt left/right) to more game actions
* Make it wireless with BLE or Wi-Fi support
* Generalize the script to support multiple games via custom mapping
* Add vibration feedback using motor module

---

## 🙌 Contributors

| Name  | Role                 |
| :---- | :------------------- |
| Nihal | Developer, Researcher |

---

## 📄 License

This project is licensed under the MIT License.

Feel free to use, modify, and share with attribution.

Made with ❤️ for fun, learning, and sensors!
