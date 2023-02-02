/************************************************ 
UART Serial communication Application header file
File Name: 
Author: 
License:  
************************************************/

#include "uart_drv.h"

#include <stdio.h>

/************************************************ 
    UART Serial Port Driver Application
************************************************/ 
/* Defaults */


/****************************************************************
**                                                                            
** Syntax           : void Uart_Init(void);                         
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  : void                                                    
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     : void                                             
**                                                                            
** Description      : Initialize the UART port                                 
**                                                                          
**
****************************************************************/
SerialPortErr_e Uart_Init(void);


/****************************************************************
**                                                                            
** Syntax           : void Uart_Send_Data(char *);                         
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  :  char*                                                   
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     :  void                                            
**                                                                            
** Description      : Send the data through the UART port                                 
**                                                                          
**
****************************************************************/
void Uart_Send_Data(uin32_t data);


/****************************************************************
**                                                                            
** Syntax           :  void Uart_Receive_Data(char *);                        
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  :   char*                                                  
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     :   void                                           
**                                                                            
** Description      :   Receive the data from the UART port and store in buffer                               
**                                                                          
**
****************************************************************/
void Uart_Receive_Data(uin32_t *);

/****************************************************************
**                                                                            
** Syntax           :  void Uart_Isr_Tx()                      
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  :   void                                                  
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     :   void                                           
**                                                                            
** Description      :   UART TX Interrupt function               
**                                                                          
**
****************************************************************/

void Uart_Isr_Tx();

/****************************************************************
**                                                                            
** Syntax           :  void Uart_Isr_Rx()                    
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  :  void                                                  
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     :  void                                           
**                                                                            
** Description      :  UART RX Interrupt function                                                    
**
****************************************************************/

void Uart_Isr_Rx();





