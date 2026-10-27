#ifndef HUB75_DRIVER_H
#define HUB75_DRIVER_H

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Configuration avancée DMA I2S pour ESP32
struct Hub75Config {
    uint8_t pin_r1, pin_g1, pin_b1;
    uint8_t pin_r2, pin_g2, pin_b2;
    uint8_t pin_a, pin_b, pin_c, pin_d, pin_e;
    uint8_t pin_lat, pin_oe, pin_clk;
    bool use_74hct245_shifter; // Flag pour l'adaptation matérielle des niveaux logiques 3.3V -> 5V
};

class Hub75Matrix {
public:
    Hub75Matrix(uint16_t width, uint16_t height);
    ~Hub75Matrix();

    bool begin(const Hub75Config& config);
    void clear();
    void setBrightness(uint8_t brightness);
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void swapBuffers(); // Double buffering pour un affichage sans scintillement

private:
    uint16_t _width;
    uint16_t _height;
    uint8_t _brightness;
    uint8_t* _dma_buffer;

    void allocateDMABuffer();
    void initI2S();
};

// Macro de conversion RGB888 vers RGB565
#define RGB(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3))

#endif // HUB75_DRIVER_H
