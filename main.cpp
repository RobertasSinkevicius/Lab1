// comment on why this has occoured!! 
//Error : Mutex: 0x20000160, Not allowed in ISR context
//interrupt handlers are expected to set interrupt flags to appropriate values as part of their core functionality. Set up flags and values;
#include "mbed.h"

// main() runs in its own thread in the OS
InterruptIn bttn(PC_13);
char flag0=0;  // initial button value
void fall_int(){
flag0=1;      // button is pressed
}
void rise_int(){ // button is released
flag0=0;
}

int main()
{
     bttn.fall(&fall_int);
     bttn.rise(&rise_int);
    while (true) {
        if(flag0==1){  // button is pressed - print function activated
             printf("Buttn pressed \r\n");
             flag0=0;  // button is released - No print function 
        }
        ThisThread::sleep_for(50);


    }
}