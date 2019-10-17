#include "config.h"
#include "posnPaddle.h"
void paddleMove(void)
{
    if(PADDLEUP == LOW && PADDLEDWN == HIGH)    // paddleup button is pressed
    {
        if (buttonPress > 0)
        {
            posnPaddle(0, buttonPress, 0);  // paddle moves up with ever buttonPress
            posnPaddle(1, buttonPress, 0);  // 
            buttonPress--;
        }
    }
        else if(PADDLEUP == HIGH && PADDLEDWN == LOW)    // paddleup button is pressed
        {
            if (buttonPress <40)
            {
                posnPaddle(0, buttonPress, 1);  // paddle moves up with ever buttonPress
                posnPaddle(1, buttonPress, 1);  // 
                buttonPress++;
            }
        }
}
