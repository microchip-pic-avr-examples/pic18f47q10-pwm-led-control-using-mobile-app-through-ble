/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F47Q10
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set BLE2_Conn aliases
#define BLE2_Conn_TRIS                 TRISAbits.TRISA1
#define BLE2_Conn_LAT                  LATAbits.LATA1
#define BLE2_Conn_PORT                 PORTAbits.RA1
#define BLE2_Conn_WPU                  WPUAbits.WPUA1
#define BLE2_Conn_OD                   ODCONAbits.ODCA1
#define BLE2_Conn_ANS                  ANSELAbits.ANSELA1
#define BLE2_Conn_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BLE2_Conn_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BLE2_Conn_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BLE2_Conn_GetValue()           PORTAbits.RA1
#define BLE2_Conn_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BLE2_Conn_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BLE2_Conn_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define BLE2_Conn_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define BLE2_Conn_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define BLE2_Conn_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define BLE2_Conn_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define BLE2_Conn_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set LED_D5 aliases
#define LED_D5_TRIS                 TRISAbits.TRISA7
#define LED_D5_LAT                  LATAbits.LATA7
#define LED_D5_PORT                 PORTAbits.RA7
#define LED_D5_WPU                  WPUAbits.WPUA7
#define LED_D5_OD                   ODCONAbits.ODCA7
#define LED_D5_ANS                  ANSELAbits.ANSELA7
#define LED_D5_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED_D5_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED_D5_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED_D5_GetValue()           PORTAbits.RA7
#define LED_D5_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED_D5_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define LED_D5_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define LED_D5_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define LED_D5_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define LED_D5_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define LED_D5_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define LED_D5_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set sensor_enable aliases
#define sensor_enable_TRIS                 TRISBbits.TRISB2
#define sensor_enable_LAT                  LATBbits.LATB2
#define sensor_enable_PORT                 PORTBbits.RB2
#define sensor_enable_WPU                  WPUBbits.WPUB2
#define sensor_enable_OD                   ODCONBbits.ODCB2
#define sensor_enable_ANS                  ANSELBbits.ANSELB2
#define sensor_enable_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define sensor_enable_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define sensor_enable_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define sensor_enable_GetValue()           PORTBbits.RB2
#define sensor_enable_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define sensor_enable_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define sensor_enable_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define sensor_enable_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define sensor_enable_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define sensor_enable_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define sensor_enable_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define sensor_enable_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISBbits.TRISB4
#define SW1_LAT                  LATBbits.LATB4
#define SW1_PORT                 PORTBbits.RB4
#define SW1_WPU                  WPUBbits.WPUB4
#define SW1_OD                   ODCONBbits.ODCB4
#define SW1_ANS                  ANSELBbits.ANSELB4
#define SW1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SW1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SW1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SW1_GetValue()           PORTBbits.RB4
#define SW1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SW1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set BLE2_Cmd_Mldp aliases
#define BLE2_Cmd_Mldp_TRIS                 TRISCbits.TRISC2
#define BLE2_Cmd_Mldp_LAT                  LATCbits.LATC2
#define BLE2_Cmd_Mldp_PORT                 PORTCbits.RC2
#define BLE2_Cmd_Mldp_WPU                  WPUCbits.WPUC2
#define BLE2_Cmd_Mldp_OD                   ODCONCbits.ODCC2
#define BLE2_Cmd_Mldp_ANS                  ANSELCbits.ANSELC2
#define BLE2_Cmd_Mldp_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define BLE2_Cmd_Mldp_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define BLE2_Cmd_Mldp_GetValue()           PORTCbits.RC2
#define BLE2_Cmd_Mldp_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define BLE2_Cmd_Mldp_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define BLE2_Cmd_Mldp_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define BLE2_Cmd_Mldp_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISCbits.TRISC5
#define SW2_LAT                  LATCbits.LATC5
#define SW2_PORT                 PORTCbits.RC5
#define SW2_WPU                  WPUCbits.WPUC5
#define SW2_OD                   ODCONCbits.ODCC5
#define SW2_ANS                  ANSELCbits.ANSELC5
#define SW2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SW2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SW2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SW2_GetValue()           PORTCbits.RC5
#define SW2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SW2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set BLE2_Wake aliases
#define BLE2_Wake_TRIS                 TRISDbits.TRISD0
#define BLE2_Wake_LAT                  LATDbits.LATD0
#define BLE2_Wake_PORT                 PORTDbits.RD0
#define BLE2_Wake_WPU                  WPUDbits.WPUD0
#define BLE2_Wake_OD                   ODCONDbits.ODCD0
#define BLE2_Wake_ANS                  ANSELDbits.ANSELD0
#define BLE2_Wake_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define BLE2_Wake_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define BLE2_Wake_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define BLE2_Wake_GetValue()           PORTDbits.RD0
#define BLE2_Wake_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define BLE2_Wake_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define BLE2_Wake_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define BLE2_Wake_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define BLE2_Wake_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define BLE2_Wake_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define BLE2_Wake_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define BLE2_Wake_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF4 pin functionality
 * @Example
    IOCBF4_ISR();
 */
void IOCBF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_InterruptHandler);

*/
extern void (*IOCBF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_DefaultInterruptHandler);

*/
void IOCBF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF5 pin functionality
 * @Example
    IOCCF5_ISR();
 */
void IOCCF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_InterruptHandler);

*/
extern void (*IOCCF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_DefaultInterruptHandler);

*/
void IOCCF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/