#include <pic18f4520.h>
#include "config.h"
#include "lcd.h"
#include "stdio.h"
#include "bits.h"
#include "keypad.h"
#include "ssd.h"
#include "pwm.h"
#include "io.h"
#include "Fechadura.h"


void main(void) {
    
           int k;

    pwmInit();    
    pwmFrequency(2000);
    lcdInit();
    kpInit();
      ssdInit();
    defineSenha();

    lcdCommand(0x01);
    
        printf("A senha foi salva \nAguarde...");
            for (k = 0; k < 30000; k++);
    lcdCommand(0x01);
        printf("Acesso bloqueado \nAguarde...");
            for (k = 0; k < 30000; k++);
    lcdCommand(0x01);

    while (1) {
        acesso();
    }

}

