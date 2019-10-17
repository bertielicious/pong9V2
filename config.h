/* 
 * File:   config.h
 * Author: Phil Glazzard
 *
 * Created on 25 August 2019, 18:31
 */

#ifndef CONFIG_H
#define	CONFIG_H


// PIC16F1459 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include<stdbool.h>                 
#define PADDLEUP PORTAbits.RA4      // PADDLEUP pin 3
#define PADDLEDWN PORTCbits.RC2      // PADDLEUP pin 14
#define _XTAL_FREQ 8000000         //8 MHz clock
#define SWIP PORTAbits.RA5          // Player selection ( 1 or 2 player)
#define RST PORTCbits.RC3           // RST reset - pin 7
#define CE PORTCbits.RC4            // CE chip enable - pin 6
#define SDO PORTCbits.RC7           // SDO serial data out - pin 9
#define DC PORTCbits.RC6            // DC data or command - pin 8
#define SCK PORTBbits.RB6           // SCK serial clock - pin 11
#define GREEN_LED PORTCbits.RC5     // debug LED - pin 5
/**************NOKIA 5110 LCD**************************/
#define FUNC_SET_EXTEND 0x21
//#define LCD_CONTRAST 0xb1
#define LCD_CONTRAST 0xb5
//#define LCD_CONTRAST 0xbe
#define LCD_TEMP_COEFF 0x04
#define LCD_BIAS 0x14
#define NORMAL_MODE 0x0c
#define BASIC_IS 0x20
#define ALL_PIX_ON 0x09
#define HORIZ_ADDR 0x20
#define VERT_ADDR 0x22
#define SET_Y 0x40
#define SET_X 0x80


/**************** Global variables*******************/
typedef unsigned char uchar;  

// Screen Size
const uchar WIDTH = 83;
const uchar DEPTH = 47;
bool run = 1;
uchar score = 0;
uchar units, tens = 0;
uchar leftScore = 0;
uchar rightScore = 0;


struct posnData         //vertical shift position data for ball
{
    uchar pageHigh;
    uchar pageLow;
    uchar dataHigh;
    uchar dataLow;
    uchar col;
    uchar row;
}; 

struct paddleData         //vertical shift position data for paddle
{
    uchar pageHigh;
    uchar pageLow;
    uchar dataHigh;
    uchar dataLow;
    uchar col;
    uchar row;
}; 
bool paddle[2] = {0xff, 0xff};
uchar yBall = 0;
uchar page = 3;
uchar x, y = 0;
char buttonPress = 24; // counts number of button presses up and down

bool paddlePosn[48][1];

/********************************/
                                  // HIGH is a constant of value 1
const bool P[8] = {0x41, 0x7f, 0x7f, 0x49, 0x09, 0x0f, 0x06, 0x00};
const bool O[8] = {0x1c, 0x3e, 0x63, 0x41, 0x63, 0x3e, 0x1c, 0x00};
const bool N[8] = {0x7f, 0x7f, 0x06, 0x0c, 0x18, 0x7f, 0x7f, 0x00};
const bool G[8] = {0x1c, 0x3e, 0x63, 0x41, 0x51, 0x73, 0x72, 0x00};
const bool EX[8] = {0x00, 0x06, 0x5f, 0x5f, 0x06, 0x00, 0x00, 0x00};
const bool BAT[8] = {0xff,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const bool TAB[8] = {0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff};
bool BALL[8] = {0x00,0xe0,0xe0,0xe0,0x00,0x00,0x00,0x00};
const bool TWO[8] = {0x62,0x73, 0x59, 0x49, 0x6f, 0x66, 0x00, 0x00};
const bool THREE[8] = {0x22,0x63, 0x49, 0x49, 0x7f, 0x36, 0x00, 0x00};
const bool r[8] = {0x44, 0x7c, 0x78, 0x4C, 0x04, 0x1c, 0x18, 0x00};
const bool e[8] = {0x38, 0x7c, 0x54, 0x54, 0x5c, 0x18, 0x00, 0x00};
const bool s[8] = {0x48, 0x5c, 0x54, 0x54, 0x74, 0x24, 0x00, 0x00};

const bool o[8] = {0x38, 0x7c, 0x44, 0x44, 0x7c, 0x38, 0x00, 0x00};
const bool n[8] = {0x7c, 0x7c, 0x04, 0x04, 0x7c, 0x78, 0x00, 0x00};
const bool c[8] = {0x38, 0x7c, 0x44, 0x44, 0x6c, 0x28, 0x00, 0x00};
const bool ee[8] = {0x38, 0x7c, 0x54, 0x54, 0x5c, 0x18, 0x00, 0x00};// aka e

const bool f[8] = {0x48, 0x7e, 0x7f, 0x49, 0x03, 0x02, 0x00, 0x00};
const bool one[8] = {0x40, 0x42, 0x7f, 0x7f, 0x40, 0x40, 0x00, 0x00};

const bool p[8] = {0x84, 0xfc, 0xf8, 0xa4, 0x24, 0x3c, 0x18, 0x00};
const bool l[8] = {0x00, 0x41, 0x7f, 0x7f, 0x40, 0x00, 0x00, 0x00};
const bool a[8] = {0x20, 0x74, 0x54, 0x54, 0x3c, 0x78, 0x40, 0x00};

const bool yy[8] = {0x9c, 0xbc, 0xa0, 0xa0, 0xfc, 0x7c, 0x00, 0x00};// aka y

const bool t[8] = {0x00, 0x04, 0x3e, 0x7f, 0x44, 0x24, 0x00, 0x00};
const bool w[8] = {0x3c, 0x7c, 0x70, 0x38, 0x70, 0x7c, 0x3c, 0x00};
const bool i[8] = {0x00, 0x44, 0x7d, 0x7d, 0x40, 0x00, 0x00, 0x00};
const bool cero[8] = {0x00, 0x3e, 0x61, 0x51,0x49,0x45,0x3e,0x00};
const bool uno[8] = {0x00, 0x44, 0x42, 0x7f, 0x40, 0x40, 0x00, 0x00};
const bool dos[8] = {0x00, 0x62, 0x51, 0x51, 0x49, 0x49, 0x66, 0x00};
const bool tres[8] = {0x00, 0x22, 0x41, 0x49, 0x49, 0x49, 0x36, 0x00}; 
const bool cuatro [8] = {0x10, 0x18, 0x14, 0x52, 0x7f, 0x50, 0x10, 0x00};
const bool cinco [8] = {0x00, 0x27, 0x45, 0x45, 0x45, 0x45, 0x39, 0x00};
const bool seis [8] = {0x00, 0x3c, 0x4a, 0x49, 0x49, 0x49, 0x30, 0x00};
const bool siete [8] = {0x00, 0x03, 0x01, 0x71, 0x09, 0x05, 0x03, 0x00};
const bool ocho [8] = {0x00, 0x36, 0x49, 0x49, 0x49, 0x49, 0x36, 0x00};
const bool nueve [8] = {0x00, 0x06, 0x49, 0x49, 0x49, 0x29, 0x1e, 0x00};


bool position[48][2] =     {{0,0},  // col 0 contains paddle position data
                            {0,0},  // col 1 contains ball position data
                            {0,0},  // to determine if there has been a paddle / ball collision
                            {0,0},  // depending on the position of the ball on the paddle
                            {0,0},  // varying angles / speeds of rebound occur.
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0},
                            {0,0},
                            {0,0},  
                            {0,0},
                            {0,0}};
uchar up[9] = {0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff};
uchar down[9] = {0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01,0x00};

enum {LOW, HIGH};                   // LOW is a constant of value 0
enum {UP, DOWN};

bool gameplay_area [6][84] = {{0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x031,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xff},
                              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x3c,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0xff},
                              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x3c,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0xff},
                              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x3c,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0xff},
                              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x3c,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0xff},
                              {0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xb0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xff}};

#endif	/* CONFIG_H */

