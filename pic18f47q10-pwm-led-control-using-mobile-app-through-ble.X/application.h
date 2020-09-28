/* 
 * File:   application.h
 * Author: I16092
 *
 * Created on April 24, 2018, 8:04 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#ifdef	__cplusplus
extern "C" {
#endif

// include files
#include <string.h>
#include <stdlib.h>

#include "mcc_generated_files/BLE2_driver.h"
#include "mcc_generated_files/drivers/uart.h"
#include "mcc_generated_files/pwm3.h"
#include "mcc_generated_files/pwm4.h"
    
#define LED1  1
#define LED2  2
#define TIMEOUT  3

#define PWMMAXDUTY 0x3FF
#define SLEEP_TIMEOUT 60 // timeout period in seconds; wait SLEEP_TIMEOUT sec before going to sleep
#define LED1_OFF() PWM3_LoadDutyValue(0)
#define LED2_OFF() PWM4_LoadDutyValue(0)  
    
// global variables
volatile bool connection_status;

typedef struct {
    uint8_t LED_NUMBER;
    uint16_t LED_BRIGHTNESS_VALUE;
} LED_data;

typedef union
{
    uint8_t TicksBitMap;
    struct
    {
        unsigned mSecTick           : 1;
        unsigned mSecTenTick        : 1;
        unsigned mSecHundredTick    : 1;
        unsigned SecTick            : 1;
        unsigned MinTick            : 1;
        unsigned HourTick           : 1;
        unsigned HalfDayTick        : 1;
        unsigned DayTick            : 1;
    };
}appTimerHandlerBit_t;
volatile appTimerHandlerBit_t appTimer;

// function declarations
/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the BLE2 Click board and turn on the activity LED D5
 * @Example
    InitialSetup();
 */
void InitialSetup(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
     main application function being executed in while loop
 * @Example
    ApplicationTask();
 */
void ApplicationTask(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
     timer handler to generate tick every mS called by timer 1 ISR every mS
 * @Example
    appTMR_Tick();
 */
void appTMR_Tick(void);

/**
   @Param
    none 
   @Returns
    none
   @Description
    Increment mS Counter and Handle timer Tick Increments such as 10 mS, 100mS, 1S, 1min, 1Hr, Half day and day tick
   @Example
    appTMR_Handler( );
 */
void appTMR_Handler(void);
/**
   @Param
    none 
   @Returns
    none
   @Description
    Clear all bit fields/ticks of the appTimer
   @Example
    appTMR_ClearBitFlags( );
 */
void appTMR_ClearBitFlags(void);
/**
   @Param
    application timer structure 
   @Returns
    none
   @Description
    Execute various timely tasks. Frequency of task execution can be 1mS, 10mS, 100mS, 1S, 1min, 1H, half day or day
    100mS task: brightness of LED1 is changed every 100mS from 0% to 50% continuously.
    1sec task: time tracking of no command received from android app when connected 
               or simply sleep ticker increment when not connected
   @Example
    appTimerBasedTask( appTimer);
 */
void appTimerBasedTask(appTimerHandlerBit_t timerTask);
/**
   @Param
    none
   @Returns
    none
   @Description
    Enables watchdog timer, put RN4020 BLE module to deep sleep mode and controller enters Sleep state.
    When connected to mobile app on blue-tooth this function is called after no data received from the app for more than 1 minute.
    When not connected the function is called every 1 min. Sleep interval is 1 minute wake interval is 1 minute.   
   @Example
    curiousSleep();
 */
void curiousSleep(void);
/**
   @Param
    none
   @Returns
    none
   @Description
    wakes up BLE2 click from sleep mode by making WAKE_SW signal high
   @Example
    wakeUpBLE2Click();
 */
void wakeUpBLE2Click(void);

/**
   @Param
    none
   @Returns
    none
   @Description
    enables Deep sleep mode of BLE2 click by making WAKE_SW signal low
   @Example
    sleepBLE2Click();
 */
void sleepBLE2Click(void);

/**
   @Param
    none
   @Returns
    none
   @Description
    Clears the IOC flags for SW1 (RB4) and SW2 (RC5) if sleep mode is exited by IOC on falling edge of SW1 or SW2
   @Example
    handleIOC_SW1_SW2();
 */
void handleIOC_SW1_SW2(void);

/**
   @Param
    ASCII character
   @Returns
    hex value of character
   @Description
    returns the hex value of the character
   @Example
    ch = getHexValue('A');
 */
uint8_t getHexValue(char);

/**
   @Param
    none
   @Returns
    8 bit LedNumber
   @Description
    Returns LED number value received from mobile application over BLE
   @Example
    data.LED_NUMBER = getLedNumber();
 */
uint8_t getLedNumber(void);

/**
   @Param
    none
   @Returns
    8 bit Led Brightness value
   @Description
    Read and return LED brightness value received from mobile application over BLE
   @Example
    data.LED_BRIGHTNESS_VALUE = getBrightnessValue();
 */
uint16_t getBrightnessValue(void);

/**
   @Param
    none
   @Returns
    LED number and 8 bit Led Brightness value
   @Description
    Read and return LED number and LED brightness value received from mobile application
   @Example
    LED_data data = getLedCommand();
 */
LED_data getLedCommand(void);

/**
   @Param
   None
   @Returns
    None
   @Description
    Control the LEDs D2 and D3 and sleep mode according to commands received from mobile application
   @Example
    processLedCommand();
 */
void processLedCommand(void);


#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */

