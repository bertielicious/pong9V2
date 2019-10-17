#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
void renderPaddle(struct paddleData t)
{
    set_address( t.col, t.pageHigh);  
    lcdWrite(gameplay_area[t.pageHigh][t.col]|t.dataHigh, HIGH);  
       
    if(t.pageHigh != 5)
    {
       set_address( t.col, t.pageLow); 
       lcdWrite(gameplay_area[t.pageLow][t.col]|t.dataLow, HIGH);
    }  
}
