// Phan Le Son 17-Nov-2015
// jetsonPWM.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include "jetsonPWM.h"


//
// PWM Export
// Export the given pwm to userspace;
// Return: Success = 0 ; otherwise open file error
int PWMExport( jetsonPWM PWM )
{
    int fileDescriptor, length;
    char commandBuffer[MAX_BUF];

    fileDescriptor = open(SYSFS_PWM_DIR "/export", O_WRONLY);
    if (fileDescriptor < 0)
	{
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "PWMExport unable to open PWM%d",PWM) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

    length = snprintf(commandBuffer, sizeof(commandBuffer), "%d", PWM);
    if (write(fileDescriptor, commandBuffer, length) != length)
	{
        perror("PWMExport");
        return fileDescriptor ;

    }
    close(fileDescriptor);

    return 0;
}

// PWM Unexport
// Unexport the given pwm from userspace
// Return: Success = 0 ; otherwise open file error
int PWMUnexport ( jetsonPWM PWM )
{
    int fileDescriptor, length;
    char commandBuffer[MAX_BUF];

    fileDescriptor = open(SYSFS_PWM_DIR "/unexport", O_WRONLY);
    if (fileDescriptor < 0) 
	{
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "PWMUnexport is unable to open PWM%d",PWM) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

    length = snprintf(commandBuffer, sizeof(commandBuffer), "%d", PWM);
    if (write(fileDescriptor, commandBuffer, length) != length)
    {
        perror("PWMUnexport") ;
        return fileDescriptor ;
    }
    close(fileDescriptor);
    return 0;
}

// PWMSetPeriod
// Set the Period of the PWM pin 
// Return: Success = 0 ; otherwise open file error
int PWMSetPeriod ( jetsonPWM PWM, unsigned int tiPeriod )
{
    int fileDescriptor,length;
    char commandBuffer[MAX_BUF];

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_PWM_DIR  "/pwm%d/period", PWM);

    fileDescriptor = open(commandBuffer, O_WRONLY);
    if (fileDescriptor < 0) 
    {
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "PWMSetPeriod is unable to open pwm%d",PWM) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

	length = snprintf(commandBuffer, sizeof(commandBuffer), "%d", tiPeriod);
	
	if (write(fileDescriptor, commandBuffer, length) != length)
	{
        perror("PWMSetPeriod") ;
        return fileDescriptor ;
    }
    
    close(fileDescriptor);
    return 0;
}

// PWMSetDuty
// Set the Period of the PWM pin 
// Return: Success = 0 ; otherwise open file error
int PWMSetDuty ( jetsonPWM PWM, unsigned int tiDuty )
{
    int fileDescriptor,length;
    char commandBuffer[MAX_BUF];

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_PWM_DIR  "/pwm%d/duty", PWM);

    fileDescriptor = open(commandBuffer, O_WRONLY);
    if (fileDescriptor < 0) 
	{
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "PWMSetDuty is unable to open pwm%d",PWM) ;
        perror(errorBuffer);
        return fileDescriptor;
    }

	length = snprintf(commandBuffer, sizeof(commandBuffer), "%d", tiDuty);
	
	if (write(fileDescriptor, commandBuffer, length) != length)
	{
        perror("PWMSetDuty") ;
        return fileDescriptor ;
    }
    
    close(fileDescriptor);
    return 0;
}

// PWMEnable
// Open the given pin for reading
// Returns the file descriptor of the named pin
int PWMEnable(jetsonPWM PWM)
{
    int fileDescriptor;
    char commandBuffer[MAX_BUF];

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_PWM_DIR "/pwm%d/enable", PWM);

    fileDescriptor = open(commandBuffer, O_WRONLY);
    if (fileDescriptor < 0) 
	{
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "PWMEnable is unable to open pwm%d",PWM) ;
        perror(errorBuffer);
		
		return fileDescriptor;
    }
	
	if (write(fileDescriptor, "1", 2) != 2)
	{
		perror("PWMEnable") ;
		return fileDescriptor ;
	}
    return 0;
}

// PWMDisable
// Open the given pin for reading
// Returns the file descriptor of the named pin
int PWMDisable(jetsonPWM PWM)
{
    int fileDescriptor;
    char commandBuffer[MAX_BUF];

    snprintf(commandBuffer, sizeof(commandBuffer), SYSFS_PWM_DIR "/pwm%d/enable", PWM);

    fileDescriptor = open(commandBuffer, O_WRONLY );
    if (fileDescriptor < 0) 
	{
        char errorBuffer[128] ;
        snprintf(errorBuffer,sizeof(errorBuffer), "PWMDisable is unable to open pwm%d",PWM) ;
        perror(errorBuffer);
		
		return fileDescriptor;
    }
	
	if (write(fileDescriptor, "0", 2) != 2)
	{
		perror("PWMDisable") ;
		return fileDescriptor ;
	}
    return 0;
}



