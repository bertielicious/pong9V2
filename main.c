/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 15 October 2019, 15:23
 */


#include <xc.h>
#include <stdio.h>
#include "config.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "set_usart.h"
#include "lcd_setup.h"
#include "lcdWrite.h"
#include "set_address.h"
#include "clearScreen.h"
#include "set_game_area.h"
#include "TMR0_setup.h"
#include "TMR1_setup.h"
#include "posnPaddle.h"
#include "renderPaddle.h"
#include "animate.h"
#include "splitDigits.h"
#include "showScore.h"
void main(void) 
{
config_osc();       // internal clock frequency = 8MHz
setup_ports();      
init_spi();
set_usart();
lcd_setup();        // configures the LCD
clearScreen();
set_game_area();
TMR0_setup();
TMR1_setup();
posnPaddle(0, buttonPress, 1);      // initial position of paddle is col = 0 & 1, row = buttonPress (24))
posnPaddle(1, buttonPress, 1);
printf("Pong !\n");
//set_address(10,0);
//lcdWrite(0xff,HIGH);
uchar g,a;
float col = 2;
float row = 32;
float colSpeed = 0.2;
float rowSpeed = 0.1;
splitDigits(leftScore); // split the score into units and tens
showScore(units, 16,1);

splitDigits(rightScore); // split the score into units and tens
showScore(units, 61,1);


while(1)
    {
start:    if(col > 1 && col < 3)
    {
    
        if((row > buttonPress - 4) && (row < (buttonPress + 8)))
        {
            colSpeed = 0.2;
            leftScore = leftScore + 1;  // as the paddle detected a collision with the ball, increment the left score
        for(g = 0; g < 8; g++)
        {
            gameplay_area[1][16+g] = 0x00;  // clear previous leftScore from LCD to avoid over writing updated score
            gameplay_area[1][10+g] = 0x00;
        } 
            splitDigits(leftScore); // split the score into units and tens
            showScore(units, 16,1); // show the units score at position col = 16, row = 1
            if(leftScore > 9)       // only show the tens digit of the score when units are greater than 9
            {
                showScore(tens, 8,1);   // show the tens score at position col = 8, row = 1;
            }
        }
        
    }    
        
        if(col > WIDTH - 3)
        {
            colSpeed = -0.2;
        }
        if(row > DEPTH)
            {
                rowSpeed = -0.1;
            }
            
        if (row <= 0)
            {
                rowSpeed = 0.1;
            }
    if(col < 2)
    {
        while(a < 10)
        {
            __delay_ms(100);
            a++;
        }
        a = 0;
        leftScore = 0;
        units = 0; 
        tens = 0;
       // col = 2;
        goto start;
    }
            
        col = col + colSpeed;
        row = row + rowSpeed;
        animate(col, row); 
    }
}

