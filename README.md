# ESP32 HUB75 Matrix Driver 🚀

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Downloads](https://img.shields.io/badge/downloads-12k%2B-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Version](https://img.shields.io/badge/version-v2.4.1-orange)

A highly optimized, lightweight C/C++ framework for driving HUB75 RGB LED matrices using the ESP32 (WROOM, S3, C3). 

This project was built to address the lack of well-documented, DMA-optimized libraries that handle hardware level-shifting properly. It is widely used by makers, in technical high schools for educational purposes, and for commercial smart signage.

## ✨ Key Features
* **High Refresh Rate:** DMA-based I2S output for flicker-free rendering.
* **Hardware Adaptation Guide:** Comprehensive schematics for using 74HCT245 octal bus transceivers for safe 3.3V to 5V logic level shifting.
* **Low Memory Footprint:** Optimized framebuffers compared to existing alternatives.
* **Multi-Panel Chaining:** Support for chaining multiple 64x32 or 64x64 panels seamlessly.

## 🛠️ Hardware Requirements
* **Microcontroller:** ESP32 (Standard, S3, or C3 Super Mini)
* **Panel:** Standard HUB75 / HUB75E RGB LED Matrix (e.g., P3, P4, P5)
* **Level Shifter:** 74HCT245 (Crucial for stable signals at high frequencies)

## 📦 Quick Start

Include the library in your PlatformIO or Arduino IDE environment:

```cpp
#include "Hub75Driver.h"

// Define your ESP32 pins
#define R1_PIN 25
#define G1_PIN 26
#define B1_PIN 27
// ... other pins configured

Hub75Matrix matrix(64, 32); // Panel dimensions

void setup() {
    matrix.begin();
    matrix.setBrightness(100);
    matrix.drawPixel(10, 10, RGB(255, 0, 0)); // Draw a red pixel
}

void loop() {
    // Animation logic
}
