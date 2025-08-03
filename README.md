# TM4C123GH6PM I2C0 Initialization (PB2=SCL, PB3=SDA)

## 📘 Overview
This project demonstrates how to configure and use I2C Module 0 on the TM4C123GH6PM microcontroller using Port B pins (PB2 as SCL, PB3 as SDA). The system clock is set to 40 MHz, GPIOB and I2C0 are initialized, and a byte is transmitted to an I2C slave.

---

## 🛠️ Tools & Environment

- **Microcontroller**: TM4C123GH6PM (Tiva C Series)
- **IDE/Compiler**: Code Composer Studio / other ARM-compatible tools
- **Language**: C
- **Header Files**: `tm4c123gh6pm.h`, `clock.h`, `wait.h`

---

## 📌 Pin Configuration

| Pin | Function | Description     |
|-----|----------|-----------------|
| PB2 | I2C0SCL  | Clock line      |
| PB3 | I2C0SDA  | Data line       |

> ⚠️ Ensure external pull-up resistors (e.g., 4.7kΩ) are connected to SCL and SDA lines.


## 💻 Code Functionality

- Initializes system clock to 40 MHz
- Enables I2C0 and GPIO Port B
- Sets PB2 and PB3 to alternate I2C functions
- Configures I2C master with clock speed
- Sends byte `0x5A` to I2C slave at address `0x3B`
