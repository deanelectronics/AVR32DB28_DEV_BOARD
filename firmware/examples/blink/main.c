#include <avr/io.h>
#include <util/delay.h>

#define LED_PORT PORTA
#define LED_MASK 0xFE  /* PA1-PA7, skip PA0 (UPDI) */

static void delay_ms(uint16_t ms) {
    while (ms--) _delay_ms(1);
}

int main(void) {
    LED_PORT.DIR = LED_MASK;

    while (1) {
        /* Chase pattern across PA1-PA7 */
        for (uint8_t bit = 1; bit <= 7; bit++) {
            LED_PORT.OUT = (1 << bit);
            delay_ms(100);
        }
        /* All on, then all off */
        LED_PORT.OUT = LED_MASK;
        delay_ms(300);
        LED_PORT.OUT = 0;
        delay_ms(300);
    }
}
