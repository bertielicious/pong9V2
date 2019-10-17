#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"

void render(struct posnData s)      //render receives the entire struct containing pageHigh, pageLow, and col
{
         set_address( s.col, s.pageHigh);  
         lcdWrite(gameplay_area[s.pageHigh][s.col]|s.dataHigh, HIGH);  
       
         if(s.pageHigh != 5)
         {
            set_address( s.col, s.pageLow); 
            lcdWrite(gameplay_area[s.pageLow][s.col]|s.dataLow, HIGH);
         }  
     
}
