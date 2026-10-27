#include <Arduino.h>
#include "Hub75Driver.h"

// Initialisation de la matrice (64x32 standard)
Hub75Matrix matrix(64, 32);

void setup() {
    Serial.begin(115200);
    Serial.println("Initialisation du driver ESP32 HUB75 DMA...");

    Hub75Config cfg = {
        .pin_r1 = 25, .pin_g1 = 26, .pin_b1 = 27,
        .pin_r2 = 14, .pin_g2 = 12, .pin_b2 = 13,
        .pin_a = 23, .pin_b = 22, .pin_c = 5, .pin_d = 17, .pin_e = 255, // 255 = non utilisé
        .pin_lat = 4, .pin_oe = 15, .pin_clk = 16,
        .use_74hct245_shifter = true // Sécurise les signaux haute fréquence vers la dalle
    };

    if (!matrix.begin(cfg)) {
        Serial.println("Erreur : Impossible d'allouer la mémoire DMA !");
        while (true) {
            for (volatile uint32_t i = 0; i < 1000000; i++); // Boucle d'attente
        }
    }

    matrix.setBrightness(120);
    matrix.clear();
    Serial.println("Matrice prête. Lancement de la démonstration...");
}

void loop() {
    // Démonstration simple de balayage de couleurs
    for (uint8_t r = 0; r < 255; r++) {
        matrix.drawPixel(32, 16, RGB(r, 0, (255 - r)));
        matrix.swapBuffers();
        
        // Temporisation logicielle précise sans bloquer les interruptions
        for (volatile uint32_t i = 0; i < 50000; i++); 
    }
}
