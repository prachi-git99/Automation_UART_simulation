/************************************************ 
UART Serial communication driver
File Name: 
Author: 
License:  
************************************************/
#include "uart_reg.h"
#include "uart_drv.h"
#include "uart_sim.h"


/* UART Driver Local Functions */
static inline void UART_RegSetBits(UART_SerialPortHandler_st* pSerialPortHandler, 
                                   uint8_t reg, uint8_t mask, uint8_t shift, uint8_t val)
{
    uint8_t *addr;

    addr = SerialPortGetRegAddress(pSerialPortHandler->ePortId, reg);
    TARG_RegSetBits(addr, mask, shift, val);
}

static inline uint8_t UART_RegGetBits(UART_SerialPortHandler_st* pSerialPortHandler, 
                                  uint8_t reg, uint8_t mask, uint8_t shift, uin32_t *val)
{
    uint8_t *addr;

    addr = SerialPortGetRegAddress(pSerialPortHandler->ePortId, reg);
    TARG_RegSetBits(addr, mask, shift, val);
}

/* UART Driver Global Functions */
SerialPortErr_e UART_SerialPortInit(UART_SerialPortHandler_st* pSerialPortHandler)
{
    SerialPortErr_e eStatus = SUCCESS;
    
                                     
    UART_RegSetBits(pSerialPortHandler, SER_TX0_STATUS_REG_ADDR,
                                     SER_TX0_CTRL_MASK_BAUD, 
                                     SER_TX0_CTRL_SHIFT_BAUD, 
                                     pSerialPortHandler->eBaud);
                                     
    UART_RegSetBits(pSerialPortHandler, SER_TX0_STATUS_REG_ADDR,
                                     SER_TX0_CTRL_MASK_BITLEN, 
                                     SER_TX0_CTRL_SHIFT_BITLEN, 
                                     pSerialPortHandler->eBit);
                                     
    UART_RegSetBits(pSerialPortHandler, SER_TX0_STATUS_REG_ADDR,
                                     SER_TX0_CTRL_MASK_PARITY, 
                                     SER_TX0_CTRL_SHIFT_PARITY, 
                                     pSerialPortHandler->eParity);
                                     
    UART_RegSetBits(pSerialPortHandler, SER_TX0_STATUS_REG_ADDR,
                                     SER_TX0_CTRL_MASK_HWCTL, 
                                     SER_TX0_CTRL_SHIFT_HWCTL, 
                                     pSerialPortHandler->eHwControl);

    eStatus = SUCCESS;
	
    return(eStatus);
}


SerialPortErr_e UART_SerialPortWrite(UART_SerialPortHandler_st* pSerialPortHandler, uin32_t val)
{
    SerialPortErr_e eStatus = SUCCESS;
	uin32_t value = 0;
    UART_RegSetBits(pSerialPortHandler, SER_TX0_DATA_REG_ADDR,
                                        SER_TX0_DATA_MASK_VAL,
                                        SER_TX0_DATA_SHIFT_BIT,
					val);

    UART_RegSetBits(pSerialPortHandler, SER_TX0_CTRL_ADDR,
                                        SER_TX0_CTRL_MASK_START,
                                        SER_TX0_CTRL_SHIFT_START,
					0x01);
	
    //Check if tx is complete
    UART_RegGetBits(pSerialPortHandler, SER_TX0_STATUS_REG_ADDR, 
					SER_TX0_STATUS_MASK_TX_COMPLETEBIT,
                                        SER_TX0_STATUS_SHIFT_TX_COMPLETEBIT,
                                        &value);								   
										   
    return(eStatus);
}

SerialPortErr_e UART_SerialPortRead(UART_SerialPortHandler_st* pSerialPortHandler, uin32_t *val)
{
    SerialPortErr_e eStatus = SUCCESS;

    return(eStatus);
}

SerialPortErr_e UART_SerialPortDeInit(UART_SerialPortHandler_st* pSerialPortHandler)
{
    SerialPortErr_e eStatus = ERROR;

    return(eStatus);
}
