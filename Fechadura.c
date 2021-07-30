#include <pic18f4520.h>
#include "config.h"
#include "lcd.h"
#include "stdio.h"
#include "bits.h"
#include "keypad.h"
#include "ssd.h"
#include "pwm.h"
#include "io.h"

int senha[5], flag1 = 0, flag2 = 0;

void teclado1(void) {
    int temp, i = -2, time;

    do {

        kpDebounce();
        ssdUpdate();
        for (time = 0; time < 100; time++);

        if (kpRead() != temp) {
            temp = kpRead();

            if (bitTst(kpRead(), 3) || bitTst(kpRead(), 2) || bitTst(kpRead(), 1) || bitTst(kpRead(), 4) || bitTst(kpRead(), 5) || bitTst(kpRead(), 6) || bitTst(kpRead(), 7) || bitTst(kpRead(), 9) || bitTst(kpRead(), 10) || bitTst(kpRead(), 11)) {
                i++;

            }


            if (bitTst(kpRead(), 3)) {

                ssdDigit(1, i);
            }
            if (bitTst(kpRead(), 2)) {

                ssdDigit(4, i);
            }
            if (bitTst(kpRead(), 1)) {

                ssdDigit(7, i);
            }
            if (bitTst(kpRead(), 4)) {

                ssdDigit(0, i);
            }
            if (bitTst(kpRead(), 5)) {

                ssdDigit(8, i);
            }
            if (bitTst(kpRead(), 6)) {

                ssdDigit(5, i);
            }
            if (bitTst(kpRead(), 7)) {

                ssdDigit(2, i);
            }
            if (bitTst(kpRead(), 9)) {

                ssdDigit(9, i);
            }
            if (bitTst(kpRead(), 10)) {

                ssdDigit(6, i);
            }
            if (bitTst(kpRead(), 11)) {

                ssdDigit(3, i);
            }
        }
    } while (i < 3);
}

void teclado2(void) {
    int temp, j = -2, time;

    do {
        kpDebounce();
        ssdUpdate();
        for (time = 0; time < 100; time++);
        if (kpRead() != temp) {
            temp = kpRead();

            if (bitTst(kpRead(), 3) || bitTst(kpRead(), 2) || bitTst(kpRead(), 1) || bitTst(kpRead(), 4) || bitTst(kpRead(), 5) || bitTst(kpRead(), 6) || bitTst(kpRead(), 7) || bitTst(kpRead(), 9) || bitTst(kpRead(), 10) || bitTst(kpRead(), 11)) {
                j++;

            }


            if (bitTst(kpRead(), 3)) {

                ssdDigit(1, j);

            }
            if (bitTst(kpRead(), 2)) {

                ssdDigit(4, j);

            }
            if (bitTst(kpRead(), 1)) {

                ssdDigit(7, j);

            }
            if (bitTst(kpRead(), 4)) {

                ssdDigit(0, j);

            }
            if (bitTst(kpRead(), 5)) {

                ssdDigit(8, j);

            }
            if (bitTst(kpRead(), 6)) {

                ssdDigit(5, j);

            }
            if (bitTst(kpRead(), 7)) {

                ssdDigit(2, j);

            }
            if (bitTst(kpRead(), 9)) {

                ssdDigit(9, j);

            }
            if (bitTst(kpRead(), 10)) {

                ssdDigit(6, j);

            }
            if (bitTst(kpRead(), 11)) {

                ssdDigit(3, j);
            }
        }
    } while (j < 3);
}

void acesso(void) {
    int time, i;


    ssdDigit(0, 0);
    ssdDigit(0, 1);
    ssdDigit(0, 2);
    ssdDigit(0, 3);

    lcdCommand(0x01);
    printf("Senha para destravar:");

    teclado1();

    for (i = 0; i < 4; i++) {
        if (bitTst(kpRead(), senha[i])) {
            flag1 += 1;
            lcdCommand(0x01);

            printf("DESTRAVADA \n Aguarde... ");
            pwmSet(50);
            for (time = 0; time < 30000; time++);
            pwmSet(0);

            lcdCommand(0x01);

            ssdDigit(0, 0);
            ssdDigit(0, 1);
            ssdDigit(0, 2);
            ssdDigit(0, 3);

            printf("#-TRAVAR\n*-Ver historico de senhas ");

            while (1) {
                ssdDigit(0, 0);
                ssdDigit(0, 1);
                ssdDigit(0, 2);
                ssdDigit(0, 3);
                if (bitTst(kpRead(), 8)) {

                    lcdCommand(0x01);
                    printf("Informe a senha para travar:");

                    teclado2();


                    for (i = 0; i < 4; i++) {
                        if (bitTst(kpRead(), senha[i])) {
                            flag2 += 1;

                            lcdCommand(0x01);
                            printf("TRAVADA\nAguarde...");
                            pwmSet(50);
                            for (i = 0; i < 30000; i++);
                            pwmSet(0);
                            return;
                        } else {
                            lcdCommand(0x01);
                            printf("TENTE NOVAMENTE\nAguarde...");
                            for (i = 0; i < 30000; i++);
                            lcdCommand(0x01);
                            printf("#-travar\n*-Ver historico  ");
                        }
                    }
                }


                if (bitTst(kpRead(), 0)) {

                    lcdCommand(0x01);
                    lcdCommand(0x80);
                    printf("DESTRAVADA:");
                    lcdNumber(flag1);
                    lcdCommand(0xC0);
                    printf("TRAVADA:");
                    lcdNumber(flag2);

                }
                kpDebounce();
            }

        }
    }
}

void defineSenha(void) {
    int i = -1, temp, time;
    ssdDigit(0, 0);
    ssdDigit(0, 1);
    ssdDigit(0, 2);
    ssdDigit(0, 3);

    printf("Primeiro passo \n Definir senha:");
    do {
        kpDebounce();
        ssdUpdate();
        for (time = 0; time < 100; time++);

        if (kpRead() != temp) {
            temp = kpRead();

            if (bitTst(kpRead(), 3) || bitTst(kpRead(), 2) || bitTst(kpRead(), 1) || bitTst(kpRead(), 4) 
                    || bitTst(kpRead(), 5) || bitTst(kpRead(), 6) || bitTst(kpRead(), 7) 
                    || bitTst(kpRead(), 9) || bitTst(kpRead(), 10) || bitTst(kpRead(), 11)) {
                i++;

            }
            if (bitTst(kpRead(), 3)) {

                ssdDigit(1, i);
                senha[i] = 3;

            }
            if (bitTst(kpRead(), 2)) {

                ssdDigit(4, i);
                senha[i] = 2;

            }
            if (bitTst(kpRead(), 1)) {

                ssdDigit(7, i);

                senha[i] = 1;
            }
            if (bitTst(kpRead(), 4)) {

                ssdDigit(0, i);

                senha[i] = 4;
            }
            if (bitTst(kpRead(), 5)) {

                ssdDigit(8, i);

                senha[i] = 5;
            }
            if (bitTst(kpRead(), 6)) {

                ssdDigit(5, i);

                senha[i] = 6;
            }
            if (bitTst(kpRead(), 7)) {

                ssdDigit(2, i);

                senha[i] = 7;
            }
            if (bitTst(kpRead(), 9)) {

                ssdDigit(9, i);

                senha[i] = 9;
            }
            if (bitTst(kpRead(), 10)) {

                ssdDigit(6, i);

                senha[i] = 10;
            }
            if (bitTst(kpRead(), 11)) {

                ssdDigit(3, i);

                senha[i] = 11;
            }
        }
    } while (i < 3);
}
