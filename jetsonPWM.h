//Phan Le Son 17-Nov-2015
// jetsonPWM.h

#ifndef JETSONPWM_H_
#define JETSONPWM_H_

 /****************************************************************
 * Constants
 ****************************************************************/
 
#define SYSFS_PWM_DIR "/sys/class/pwm/pwmchip0"
#define POLL_TIMEOUT (3 * 1000) /* 3 seconds */
#define MAX_BUF 64

typedef unsigned int jetsonPWM ;
typedef unsigned int tiPeriod;
typedef unsigned int tiDuty;


int PWMExport( jetsonPWM PWM );
int PWMUnexport ( jetsonPWM PWM );
int PWMSetPeriod ( jetsonPWM PWM, unsigned int tiPeriod );
int PWMSetDuty ( jetsonPWM PWM, unsigned int tiDuty );
int PWMEnable(jetsonPWM PWM);
int PWMDisable (jetsonPWM PWM);

#endif 
