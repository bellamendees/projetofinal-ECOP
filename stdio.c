#include "lcd.h"


void printf(char texto[32]){ //função para imprimir uma mensagem no lcd
    int i;
 
    for(i=0; i<32; i++){
        if(texto[i] == '\0'){ 
            return;
        }
        if(texto[i] == '\n'){
            lcdCommand(0xC0); //muda para a segunda linha
            continue;
        }
        
        lcdData(texto[i]);
    }
 
    
}





