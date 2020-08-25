/* --------0.Project information--------------------
 * SIM800A
 * Protocol communication: UART1
 * The system need built-in UART functions and include of STRING.h
      1. First the MCU need to initialize UART and define UART_ISR when data come in RX FIFO
      2. MCU flush RX receive string to make sure the new data coming
      3. MCU send command to SIM800A through UART
      3. MCU receive EVERY character in UART_ISR (should have delay after send to wait for SIM respond)
      4. Check the respond to see if it is appreciate or not
 * Author : TRAN MINH THUAN
---------------------------------------------------*/

/* ------------------------------1.System requirement-------------------------------
 * 1.Create a simple UART communication system send and receive 1 byte
 * 4.Create a protocol to send data through a Master NRF24L01 to NRF24L01 slave
     using Enhanced ShockBurst with IRQ pin Falling edge interrupt
*/
//Add libraries
#include "include.h"
//Define Variables

char SIM_data[50]={"THUAN QUA VIP"};       //Message send to SIM with CIPSEND


int main(void){
    // Clock configure at 80Mhz
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    UART_Init();
    IntMasterEnable();
    SIM_Init();
    //TEST SEND
    while (1)
    {
        SIM_TCPSend(SIM_data);
        SysCtlDelay(SysCtlClockGet()/1000);
    }
}






