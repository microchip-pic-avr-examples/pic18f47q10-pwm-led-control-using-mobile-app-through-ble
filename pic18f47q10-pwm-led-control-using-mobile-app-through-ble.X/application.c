// include files
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/BLE2_driver.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/pwm3.h"
#include "mcc_generated_files/pwm4.h"
#include "application.h"
#include "BLE2Click.h"

static uint16_t   timerMsTickCount = 0;
static uint16_t   timerMinTickCount = 0;
static uint16_t m100SecTicker = 0;
static uint8_t sleepTicker = 0;

bool goToSleep = false;
bool goToSleepNC = false;
bool menuTimeout = false;
bool led1on = false;
bool led2on = false;
bool justWakeUp = false;
bool inc = true;
bool dec = false;
        
uint8_t led2dutyh ;
uint8_t led2dutyl ;

// Initializes the BLE2 Click board and turn on the activity LED D5
void InitialSetup(void) {
    // setup BLE
    BLE2ClickSetup();  
    //turn on the activity LED
    LED_D5_SetHigh();
}

//main application function being executed in while loop
void ApplicationTask(void) {
    // local variables to handle various BLE operations
    bool connection_data = false;
    bool connection_end = false;  
    
    // check if any data is received on UART 
    if(uart[BLE2].DataReady()) {
        //clear the sleep timeout counter as data received from app
        sleepTicker = 0;
        // get the Response
        BLE2ClickGetstr();
        // if not connected , check if the received data is for new connection. If yes, update the status flag to connected
        if(!connection_status) {
            connection_status=strcmp(buf,resp_conn) ? 0 : 1;
        }
        // if device is connected, check for various response received by the BLE and process it 
        if(connection_status) {
            connection_end=strcmp(buf,resp_conn_end) ? 0 : 1;
            connection_data=strncmp(buf,resp_conn_data,2) ? 0 : 1;
            
            if(connection_end) { // received disconnect message, make the connection status flag as false
                connection_status=false;
                LED1_OFF();// turn off led1
                LED2_OFF();//turn off led2            
            }else if(connection_data){ // valid data received, process it
               processLedCommand();  
            }
        }  
    }
    
    // Get Timer Ticks
    if ( appTimer.mSecTick){
        // Clear Flags for next task
        appTMR_ClearBitFlags();
        //Increment mS Counter and Handle timer Tick Increments such as 10 mS, 100mS, 1S, 1min, 1Hr, Half day and day tick
        appTMR_Handler();
        // Execute timely Tasks 
        appTimerBasedTask(appTimer);
    } 

    if (goToSleep){
        curiousSleep();// activate Sleep mode
    }

    
}

//returns the hex value of the character
uint8_t getHexValue(char x) {
    uint8_t hexvalue;    
    switch(x){
        case '0':
            hexvalue = 0;
            break;
        case '1':
            hexvalue = 1;
            break;
        case '2':
            hexvalue = 2;
            break;
        case '3':
            hexvalue = 3;
            break; 
        case '4':
            hexvalue = 4;
            break;
        case '5':
            hexvalue = 5;
            break;
        case '6':
            hexvalue = 6;
            break;
        case '7':
            hexvalue = 7;
            break;   
        case '8':
            hexvalue = 8;
            break;
        case '9':
            hexvalue = 9;
            break;
        case 'A':
            hexvalue = 0xA;
            break;
        case 'B':
            hexvalue = 0xB;
            break; 
        case 'C':
            hexvalue = 0xC;
            break;
        case 'D':
            hexvalue = 0xD;
            break;
        case 'E':
            hexvalue = 0xE;
            break;
        case 'F':
            hexvalue = 0xF;
            break; 
        default:
            break;
    }

    return hexvalue;
}

//Returns LED number value received from mobile application over BLE
uint8_t getLedNumber(void) {
    
    uint8_t ch = (uint8_t)(getHexValue(buf[8]) << 4) | getHexValue(buf[9]);
    uint8_t num = (ch<='9') ? (ch-'0') : (ch-'A'+10) ;
    return num;
}

//Read and return LED brightness value received from mobile application over BLE
uint16_t getBrightnessValue(void) {
    
    uint8_t ch0 = (uint8_t)(getHexValue(buf[10]) << 4) | getHexValue(buf[11]);
    uint8_t ch1 = (uint8_t)(getHexValue(buf[12]) << 4) | getHexValue(buf[13]);
    uint8_t ch2 = (uint8_t)(getHexValue(buf[14]) << 4) | getHexValue(buf[15]);
    uint8_t num0 = (ch0<='9') ? (ch0-'0') : (ch0-'A'+10) ;
    uint8_t num1 = (uint8_t)(ch1<='9') ? (ch1-'0') : (ch1-'A'+10) ;
    uint8_t num2 = (ch2<='9') ? (ch2-'0') : (ch2-'A'+10) ;
    return (uint16_t)((num0 << 8) | (num1 << 4) | num2);
}

//Read and return LED number and LED brightness value received from mobile application
LED_data getLedCommand(void) {
    
    LED_data data;
    data.LED_NUMBER = getLedNumber();
    data.LED_BRIGHTNESS_VALUE = getBrightnessValue();
    return data;
}

//Control the LEDs D2 and D3 and sleep mode according to commands received from mobile application
void processLedCommand(void) {
    
LED_data data = getLedCommand();    

switch(data.LED_NUMBER) {
    case LED1:
        if (data.LED_BRIGHTNESS_VALUE){
           led1on= true;
        }            
        else{
            led1on= false;
            LED1_OFF();
        }     
        break;
    case LED2:
        if (data.LED_BRIGHTNESS_VALUE){
            led2on= true; 
            PWM4_LoadDutyValue(data.LED_BRIGHTNESS_VALUE);
        }
        else{
            led2on= false;
            LED2_OFF();
        }
        break;
    case TIMEOUT:
        if (data.LED_BRIGHTNESS_VALUE)
           menuTimeout = true; 
        else
           menuTimeout = false; 
        break;    
    }
}

//timer handler to generate tick every mS called by timer 1 ISR every mS
void appTMR_Tick(void)
{
    appTimer.mSecTick = true;       // Single Tick
}

//Clear all bit fields/ticks of the appTimer
void appTMR_ClearBitFlags(void)
{
    // Clear all bit Flags
    appTimer.TicksBitMap = 0x00;
}

//Increment mS Counter and Handle timer Tick Increments such as 10 mS, 100mS, 1S, 1min, 1Hr, Half day and day tick
void appTMR_Handler(void)
{
    // Increment Counter
    timerMsTickCount++;
    // Handle Tick Increments
    if ( (timerMsTickCount % 10) == 0){
        appTimer.mSecTenTick = true;
        if ( (timerMsTickCount % 100) == 0){
            appTimer.mSecHundredTick = true;
            if ( (timerMsTickCount % 1000) == 0){
                appTimer.SecTick = true;
                if ( (timerMsTickCount % 60000) == 0){
                    timerMinTickCount++;
                    appTimer.MinTick = true;
                    if ( (timerMinTickCount % 60) == 0){
                        appTimer.HourTick = true;
                        if ( (timerMinTickCount % 720) == 0){
                            appTimer.HalfDayTick = true;
                            if ( (timerMinTickCount % 1440) == 0){
                                appTimer.DayTick = true;
                                // Reset Counters
                                timerMsTickCount = 0;
                                timerMinTickCount = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

//Execute various timely tasks. Frequency of task execution can be 1mS, 10mS, 100mS, 1S, 1min, 1H, half day or day
//100mS task: brightness of LED1 is changed every 100mS from 0% to 100% to 0% continuously.
//1sec task: time tracking of idle period or if no command being received from android app when connected 
//or simply sleep ticker increment when not connected
void appTimerBasedTask(appTimerHandlerBit_t timerTask)
{
    // Excute 1mS task Regardless
    // --> 1mSec Task
    // Variable TimeLength Task
    if (timerTask.mSecTenTick){
        // --> 10mSec Task
    }
    if (timerTask.mSecHundredTick){
        // --> 100mSec Task
        if (led1on && connection_status){
            PWM3_LoadDutyValue(m100SecTicker);
            if(!m100SecTicker) m100SecTicker=1;
            if (inc){            
                m100SecTicker= m100SecTicker <<1;
                if (m100SecTicker>= PWMMAXDUTY){
                    m100SecTicker= PWMMAXDUTY;
                    dec = true;
                    inc= false;
                }
            }                
            else if (dec){
                m100SecTicker= m100SecTicker >>1;
                if (m100SecTicker<= 0){
                    m100SecTicker= 0;
                     inc = true;
                     dec= false;
                }
            }
        }        
      
        if (led2on && connection_status){// restore previous brightness value of LED 2
            if(justWakeUp){
                PWM4DCH=led2dutyh;
                PWM4DCL=led2dutyl;
                justWakeUp=false;
            }
        }
    }
    if (timerTask.SecTick)
    {
        // --> 1Sec Task
        LED_D5_Toggle();
        if (menuTimeout)
        {
            sleepTicker++;
            if (sleepTicker > SLEEP_TIMEOUT){
                goToSleep= true;
                sleepTicker=0;
            }          
        }         
    }
    if (timerTask.MinTick)
    {
        // --> 1Min Task
    }
    if (timerTask.HourTick){
        // --> 1Hour Task
    }
    if (timerTask.HalfDayTick){
        // --> 12Hour Task
    }
    if (timerTask.DayTick){
        // --> 1Day Task
    }
}

//Enables watchdog timer, put RN4020 BLE module to deep sleep mode and controller enters Sleep state.
//When connected to mobile app on blue-tooth this function is called after no data received from the app for more than 1 minute.
//When not connected the function is called every 1 min. Sleep interval is 1 minute wake interval is 1 minute.  
void curiousSleep(void)
{
    goToSleep = false;  
    timerMsTickCount=0;
    sleepTicker = 0;
    justWakeUp=false;
    
    if (led2on){// store current brightness level of LED2
        led2dutyh = PWM4DCH;
        led2dutyl = PWM4DCL;        
    } 
    LED1_OFF();
    LED2_OFF();
    //put BLE2 Click in deep sleep mode
    sleepBLE2Click();
    //turn off the activity LED
    LED_D5_SetLow();
    INTERRUPT_GlobalInterruptDisable();
    //Enable IOCI interrupt for IOC on SW1 and SW2
    PIE0bits.IOCIE = 1; 
    //Enable WDT  timeout 67 sec 
    WWDT_SoftEnable();
    SLEEP();
    NOP();
    //after wake-up Disable WDT  
    WWDT_SoftDisable();
    // Disable IOC interrupt
    PIE0bits.IOCIE = 0;
    handleIOC_SW1_SW2();
    INTERRUPT_GlobalInterruptEnable();
    //turn On the activity LED
    LED_D5_SetHigh();
    justWakeUp=true;
    //Wake-up BLE2 Click from deep sleep mode and advertise to check for connection attempt from mobile app
    wakeUpBLE2Click();    
}

//Clears the IOC flags for SW1 (RB4) and SW2 (RC5) if sleep mode is exited by IOC on falling edge of SW1 or SW2
void handleIOC_SW1_SW2(void)
{
    if(PIR0bits.IOCIF == 1)
    {
        PIR0bits.IOCIF = 0;
        // interrupt on change for pin IOCBF4
        if(IOCBFbits.IOCBF4 == 1)
        {
            IOCBFbits.IOCBF4 = 0; 
        }	
        // interrupt on change for pin IOCCF5
        if(IOCCFbits.IOCCF5 == 1)
        {
            IOCCFbits.IOCCF5 = 0; 
        }
    }    
}   

//enables Deep sleep mode of BLE2 click by making WAKE_SW signal low
void sleepBLE2Click(void)
{
    bool connection_end = false; 
    if (connection_status){
        //send K to RN4020 to disconnect from android app
        BLE2_SendString(cmd_sleep);
        BLE2ClickGetstr();//wait till connection end is received
        connection_end=strcmp(buf,resp_conn_end) ? 0 : 1;            
        // received disconnect message, make the connection status flag as false
        if(connection_end) { 
            connection_status=false;
        }        
    } 
    //send Y to RN4020 to stop advertising during deep sleep mode
    BLE2_SendString(cmd_stop_advertise);
    // make Wake_SW pin low to enter deep sleep mode of RN4020
    BLE2_DeepSleepModule();
    BLE2ClickGetstr();                             // Wait for "END" Response
}

//wakes up BLE2 click from sleep mode by making WAKE_SW signal high
void wakeUpBLE2Click(void)
{
    // make Wake_SW pin high to wake up from deep sleep mode 
    BLE2_WakeModule();
    BLE2ClickGetstr();                             // Wait for "CMD" Response
    //send A to RN4020 to start advertising
    BLE2_SendString(cmd_advertise);
    BLE2ClickGetstr();                             // Wait for "CMD" Response
    NOP();
}
        