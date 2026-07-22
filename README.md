# 🌐 TCP Port Scanner in C++

A console-based TCP Port Scanner developed in **C++** using the **Winsock API**. This project is designed to explore socket programming, TCP/IP networking, and cybersecurity fundamentals by scanning a target host for open TCP ports.

> **Status:** 🚧 In Development

---

## 📌 Project Overview

The goal of this project is to build a fast, reliable, and modular TCP port scanner while learning how network communication works at a low level.

The application will establish TCP connections to a target host and determine which ports are open, helping users understand networking concepts and basic security assessments.

---

## ✨ Planned Features

- Scan a target IP address
- Scan custom port ranges
- Detect open and closed TCP ports
- Display common service names (HTTP, SSH, FTP, etc.)
- Multithreaded scanning for improved performance
- Configurable connection timeout
- Export scan results to a text file
- Clean, menu-driven console interface

---

## 🛠 Technologies

- C++
- Winsock2 API
- TCP/IP Networking
- Socket Programming
- Standard Template Library (STL)
- Multithreading (Planned)

---

## 📂 Project Structure

```
cpp-port-scanner/
│
├── src/
│   ├── main.cpp
│   └── PortScanner.cpp
│
├── include/
│   └── PortScanner.h
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## 📚 Learning Objectives

This project is intended to strengthen practical knowledge of:

- TCP/IP Networking
- Client-Server Communication
- Socket Programming
- Port Scanning Techniques
- Network Services
- Multithreading
- Software Design in C++

---

## 🚀 Future Enhancements

- Banner grabbing
- Service version detection
- CIDR/network scanning
- IPv6 support
- CSV and JSON export
- Progress indicator
- Command-line arguments
- Cross-platform support (Linux & Windows)

---

## ▶️ Build

Compile using **g++**:

```bash
g++ src/main.cpp src/PortScanner.cpp -Iinclude -lws2_32 -o PortScanner
```

Run:

### Windows

```bash
PortScanner.exe
```

---

## ⚠️ Disclaimer

This project is intended for educational purposes and should only be used on systems and networks that you own or have explicit permission to test. Unauthorized network scanning may violate laws, regulations, or organizational policies.

---

## 📖 License

This project is licensed under the MIT License.

---

## 👨‍💻 Author

Developed as part of my journey in C++, networking, and cybersecurity.
