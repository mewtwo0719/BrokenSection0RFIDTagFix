# Fix Broken UID-Changeable MIFARE Cards

Program to fix UID-changeable MIFARE cards with a corrupted Sector 0.

> **Requirement:**  
> Install the MFRC522 library before using this program.  
> https://github.com/miguelbalboa/rfid

---

## Description

This sketch demonstrates how to repair UID-changeable MIFARE cards that become unusable due to a corrupted Sector 0, using an MFRC522 RFID reader.

---

## Typical Pin Layout

### MFRC522 to Arduino Wiring

| Signal | MFRC522 Pin | Arduino Uno / 101 | Arduino Mega | Arduino Nano v3 | Leonardo / Micro | Pro Micro |
|------|-------------|------------------|--------------|------------------|------------------|-----------|
| RST  | RST         | 9                | 5            | D9               | RESET / ICSP-5   | RST       |
| SS   | SDA (SS)    | 10               | 53           | D10              | 10               | 10        |
| MOSI | MOSI        | 11 / ICSP-4      | 51           | D11              | ICSP-4           | 16        |
| MISO | MISO        | 12 / ICSP-1      | 50           | D12              | ICSP-1           | 14        |
| SCK  | SCK         | 13 / ICSP-3      | 52           | D13              | ICSP-3           | 15        |

---

More pin layouts can be found here:  
https://github.com/miguelbalboa/rfid#pin-layout
