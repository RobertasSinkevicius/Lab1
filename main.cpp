// comment on why this has occoured!! 
//Error : Mutex: 0x20000160, Not allowed in ISR context
#include "mbed.h"

// main() runs in its own thread in the OS
InterruptIn bttn(PC_13);

void bttn_interrupt(){
    printf("Buttn pressed \r\n");
}

int main()
{
    bttn.fall(&bttn_interrupt);
    while (true) {

    }
}