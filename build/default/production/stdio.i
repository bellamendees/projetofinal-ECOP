# 1 "stdio.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "stdio.c" 2
# 1 "./lcd.h" 1
# 23 "./lcd.h"
 void lcdCommand(unsigned char cmd);
 void lcdData(unsigned char valor);
 void lcdInit(void);
    void lcdNumber(int value);
# 1 "stdio.c" 2



void printf(char texto[32]){
    int i;

    for(i=0; i<32; i++){
        if(texto[i] == '\0'){
            return;
        }
        if(texto[i] == '\n'){
            lcdCommand(0xC0);
            continue;
        }

        lcdData(texto[i]);
    }


}
