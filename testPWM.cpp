#include <iostream>
#include <string>
#include <unistd.h>
#include "jetsonPWM.h"
using namespace std;
int main(int argc, char *argv[])
{

    cout << "Testing the PWM Pins" << endl;

    jetsonPWM PWM0 = 0;
    
    //PWM out
    PWMExport(PWM0);
    PWMSetPeriod(PWM0,1000000);
    PWMSetDuty(PWM0,500000);
    PWMEnable(PWM0);

    sleep(10);

    PWMDisable(PWM0);
    PWMUnexport(PWM0);

    return 0;
}
