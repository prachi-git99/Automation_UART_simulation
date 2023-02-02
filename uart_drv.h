/************************************************ 
UART Serial communication driver header file
File Name: 
Author: 
License:  
************************************************/

/************************************************ 
  UART Serial Port Driver Definition 
************************************************/ 
#ifndef __UART_DRV_H__
#define __UART_DRV_H__

#define uin32_t unsigned int
#define uint8_t unsigned char


typedef enum{
    SUCCESS = 0,
    ERROR 
}SerialPortErr_e;

typedef enum{
    COM1 = 0,
    COM2,
    COM3,
    COM4
}SerialPortNum_e;

typedef enum{
    BAUD_1600=0,
    BAUD_4800,
    BAUD_9600,
    BAUD_19200,
}SerialPortBaudRate_e;

typedef enum{
    BITLEN_8 = 0,
    BITLEN_7
}SerialPortBitLen_e;

typedef enum{
    PARITY_ODD = 0,
    PARITY_EVEN
}SerialPortParity_e;

typedef enum{
    HWCTRL_YES = 0,
    HWCTRL_NO
}SerialPortHwControl_e;

typedef struct {
   // uint8_t                 *pBaseAddr;
    SerialPortNum_e         ePortId;
    SerialPortBaudRate_e    eBaud;
    SerialPortBitLen_e      eBit;
    SerialPortParity_e      eParity;
    SerialPortHwControl_e   eHwControl;
}UART_SerialPortHandler_st;

/************************************************ 
    UART Serial Port Driver Implementation 
************************************************/ 
/****************************************************************
**                                                                            
** Syntax           : static inline void UART_RegSetBits(UART_SerialPortHandler_st* pSerialPortHandler, 
                                 uint8_t reg,  uint8_t mask, uint8_t shift, uint8_t val);
                         
**                                                                            
**                                                                                                                                                  
** Parameters (in)  : UART_SerialPortHandler_st* pSerialPortHandler, 
                                uint8_t reg,   uint8_t mask, uint8_t shift, uint8_t val
                                                    
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     :  void                                          
**                                                                            
** Description      :  This API calls the driver API that used to set the bit in the register                               
**                                                                          
**
****************************************************************/
static inline void UART_RegSetBits(UART_SerialPortHandler_st* pSerialPortHandler, 
                                 uint8_t reg,  uint8_t mask, uint8_t shift, uint8_t val);

/****************************************************************
**                                                                            
** Syntax           : static inline uint8_t UART_RegGetBits(UART_SerialPortHandler_st* pSerialPortHandler, 
                                uint8_t reg,  uint8_t mask, uint8_t shift, uint8_t *val);                         
**                                                                            
**                                                                                                                                                  
** Parameters (in)  : UART_SerialPortHandler_st* pSerialPortHandler, 
                                uint8_t reg,  uint8_t mask, uint8_t shift, uint8_t *val                                                   
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     : uint8_t                                            
**                                                                            
** Description      : This API calls the driver API that used to get the bit in the register                                  
**                                                                          
**
****************************************************************/
static inline uint8_t UART_RegGetBits(UART_SerialPortHandler_st* pSerialPortHandler, 
                                uint8_t reg,  uint8_t mask, uint8_t shift, uin32_t *val);

/****************************************************************
**                                                                            
** Syntax           : SerialPortErr_e UART_SerialPortInit(UART_SerialPortHandler_st* pSerialPortHandler);                         
**                                                                            
**                                                                                                                                                  
** Parameters (in)  : UART_SerialPortHandler_st* pSerialPortHandler                                                    
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     :SerialPortErr_e                                    
**                                                                            
** Description      :Initializes the UART Port                                  
**                                                                          
**
****************************************************************/
SerialPortErr_e UART_SerialPortInit(UART_SerialPortHandler_st* pSerialPortHandler);



/****************************************************************
**                                                                            
** Syntax           : SerialPortErr_e UART_SerialPortWrite(UART_SerialPortHandler_st* pSerialPortHandler, uint32_t val);                         
**                                                                            
**                                                                                                                                                  
** Parameters (in)  : UART_SerialPortHandler_st* pSerialPortHandler, uint32_t val                                                    
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     : SerialPortErr_e                              
**                                                                            
** Description      : It writes the data to the UART port                                 
**                                                                          
**
****************************************************************/  
SerialPortErr_e UART_SerialPortWrite(UART_SerialPortHandler_st* pSerialPortHandler, uin32_t val);



/****************************************************************
**                                                                            
** Syntax           : SerialPortErr_e UART_SerialPortRead(UART_SerialPortHandler_st* pSerialPortHandler, uin32_t *val);
                         
**                                                                            
**                                                                                                                                                  
** Parameters (in)  : UART_SerialPortHandler_st* pSerialPortHandler, uin32_t *val
                                                    
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     :  SerialPortErr_e 
                                            
**                                                                            
** Description      :  Its read the data from the UART port                                
**                                                                          
**
****************************************************************/
SerialPortErr_e UART_SerialPortRead(UART_SerialPortHandler_st* pSerialPortHandler, uin32_t *val);



/****************************************************************
**                                                                            
** Syntax           : SerialPortErr_e UART_SerialPortDeInit(UART_SerialPortHandler_st* pSerialPortHandler);
                         
**                                                                            
**                                                                                                                                                  
** Parameters (in)  :UART_SerialPortHandler_st* pSerialPortHandler
                                                     
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     : SerialPortErr_e 
**                                                                            
** Description      : Deinitializes the UART ports                                
**                                                                          
**
****************************************************************/
SerialPortErr_e UART_SerialPortDeInit(UART_SerialPortHandler_st* pSerialPortHandler);

#endif /*__UART_DRV_H__*/
