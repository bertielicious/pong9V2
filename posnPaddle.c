#include "config.h"
#include "renderPaddle.h"
#include <stdio.h>
void posnPaddle(uchar col, uchar row, bool dir)
{
    struct paddleData retn;    // define a variable ret of type struct posnData
    if( row >=0 && row <8)
    {
        retn.pageHigh = 0;
        retn.pageLow = 1;
    }
    else if (row >=8 && row <16)
    {
        retn.pageHigh = 1;
        retn.pageLow = 2;
    }
    else if (row >=16 && row <24)
    {
        retn.pageHigh = 2;
        retn.pageLow = 3;
    }
    else if (row >=24 && row <32)
    {
        retn.pageHigh = 3;
        retn.pageLow = 4;
    }
    else if (row >=32 && row <40)
    {
        retn.pageHigh = 4;
        retn.pageLow = 5;
    }
    else if (row >=40 && row <48)
    {
        retn.pageHigh = 5;
       // retn.pageLow = 5;
    }
    switch(row%8)       // 0 to 9
    {
        case 0:
            if(dir == 1)
            {
                retn.dataHigh = 0xfe;       // paddle dir down (1)
                retn.dataLow = 0x01;
            }
            else
            {
                retn.dataHigh = 0xff;       // paddle dir up (0))
                retn.dataLow = 0x00;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;     
            
        case 1:
            if( dir == 1) 
            {
                retn.dataHigh = 0xfc;         // paddle dir down (1))    
                retn.dataLow = 0x03;
            }
            else
            {
                retn.dataHigh = 0xfe;       // paddle dir up (0))
                retn.dataLow = 0x01;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;   
            
        case 2:           
                   
            if( dir == 1) 
            {
                retn.dataHigh = 0xf8;         // paddle dir down (1))    
                retn.dataLow = 0x07;
            }
            else
            {
                retn.dataHigh = 0xfc;       // paddle dir up (0))
                retn.dataLow = 0x03;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;
            
        case 3:
                     
            if( dir == 1) 
            {
                retn.dataHigh = 0xf0;         // paddle dir down (1))    
                retn.dataLow = 0x0f;
            }
            else
            {
                retn.dataHigh = 0xf8;       // paddle dir up (0))
                retn.dataLow = 0x07;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;  
            
        case 4:
             
            if( dir == 1) 
            {
                retn.dataHigh = 0xe0;         // paddle dir down (1))    
                retn.dataLow = 0x1f;
            }
            else
            {
                retn.dataHigh = 0xf0;       // paddle dir up (0))
                retn.dataLow = 0x0f;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;    
            
        case 5:
            
            if( dir == 1) 
            {
                retn.dataHigh = 0xc0;         // paddle dir down (1))    
                retn.dataLow = 0x3f;
            }
            else
            {
                retn.dataHigh = 0xe0;       // paddle dir up (0))
                retn.dataLow = 0x1f;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;
            
            case 6:
            
            if( dir == 1) 
            {
                retn.dataHigh = 0x80;         // paddle dir down (1))    
                retn.dataLow = 0x7f;
            }
            else
            {
                retn.dataHigh = 0xc0;       // paddle dir up (0))
                retn.dataLow = 0x3f;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;
            
            case 7:
                      
            if( dir == 1) 
            {
                retn.dataHigh = 0x00;         // paddle dir down (1))    
                retn.dataLow = 0xff;
            }
            else
            {
                retn.dataHigh = 0x80;       // paddle dir up (0))
                retn.dataLow = 0x7f;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;
            
            case 8:

            if( dir == 1) 
            {
                retn.dataHigh = 0xf8;         // paddle dir down (1))    
                retn.dataLow = 0x01;
            }
            else
            {
                retn.dataHigh = 0x00;       // paddle dir up (0))
                retn.dataLow = 0xff;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;     
            
            
            case 9:

            if( dir == 1) 
            {
                retn.dataHigh = 0xfc;         // paddle dir down (1))    
                retn.dataLow = 0x03;
            }
            else
            {
                retn.dataHigh = 0xfe;       // paddle dir up (0))
                retn.dataLow = 0x01;
            }
            retn.col = col;
            retn.row = row;
            renderPaddle(retn);
            break;   
    }   
}

