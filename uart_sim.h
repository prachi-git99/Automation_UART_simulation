
#include "uart_drv.h"
#include "Uart_app.h"

#ifndef __UART_SIM_H__
#define __UART_SIM_H__

#define REG_NUM 6
#define COM_MAX_NUM 4

typedef void (*UART_Isr_fp)(void );


/****************************************************************
**                                                                            
** Syntax           : void UART_ControllerReset();                         
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  : void                                                    
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     : void                                             
**                                                                            
** Description      : This API reset the UART registers before the UART INIT                                 
**                                                                          
**
****************************************************************/

void UART_ControllerReset();



/****************************************************************
**                                                                            
** Syntax           : void UART_ControllerTx(SerialPortNum_e port);                         
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  : SerialPortNum_e port                                               
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     : void                                             
**                                                                            
** Description      : API used to simulate the UART TX condition, also call TX interrupt handler                                 
**                                                                          
**
****************************************************************/

void UART_ControllerTx(SerialPortNum_e port);




/****************************************************************
**                                                                            
** Syntax           : void UART_ControllerRx(SerialPortNum_e port);                        
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  : SerialPortNum_e port                                                
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     : void                                             
**                                                                            
** Description      : API used to simulate the UART RX condition, also call RX interrupt handler                                 
**                                                                          
**
****************************************************************/

void UART_ControllerRx(SerialPortNum_e port);




/****************************************************************
**                                                                            
** Syntax           : void UART_RegisterIsr(SerialPortNum_e port, UART_Isr_fp IsrTx, UART_Isr_fp IsrRx);                       
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  : SerialPortNum_e port, UART_Isr_fp IsrTx, UART_Isr_fp IsrRx                                                   
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     : void                                             
**                                                                            
** Description      : Register the UART Inetrrupt handler in this API                               
**                                                                          
**
****************************************************************/

void UART_RegisterIsr(SerialPortNum_e port, UART_Isr_fp IsrTx, UART_Isr_fp IsrRx);




/****************************************************************
**                                                                            
** Syntax           : uint8_t* SerialPortGetRegAddress(SerialPortNum_e port, uint8_t reg);                        
**                                                                            
**                                                                            
**                                                                           
** Parameters (in)  : SerialPortNum_e port, uint8_t reg                                                  
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     : uint8_t*                                             
**                                                                            
** Description      : To get the address of requested register from the given port                                 
**                                                                          
**
****************************************************************/

uint8_t* SerialPortGetRegAddress(SerialPortNum_e port, uint8_t reg);



#endif /*__UART_SIM_H__*/
