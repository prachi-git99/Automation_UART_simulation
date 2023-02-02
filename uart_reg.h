/************************************************ 
UART Serial communication driver header file
File Name: 
Author: 
License:  
************************************************/

#ifndef __UART_REG_H__
#define __UART_REG_H__

#include "uartdrv.h"

/* Control Register */
#define SER_TX0_CTRL_ADDR           (0x00)
#define SER_TX0_CTRL_SHIFT_START    (0)
#define SER_TX0_CTRL_MASK_START     (0x01)

#define SER_TX0_CTRL_SHIFT_BAUD     (1)
#define SER_TX0_CTRL_MASK_BAUD      (0x0E)

#define SER_TX0_CTRL_SHIFT_BITLEN   (4)
#define SER_TX0_CTRL_MASK_BITLEN    (0x10)

#define SER_TX0_CTRL_SHIFT_PARITY   (5)
#define SER_TX0_CTRL_MASK_PARITY    (0x20)

#define SER_TX0_CTRL_SHIFT_HWCTL    (6)
#define SER_TX0_CTRL_MASK_HWCTL     (0x40)

#define SER_TX0_CTRL_SHIFT_STOPBIT  (7)
#define SER_TX0_CTRL_MASK_STOPBIT   (0x80)

/* Status Register */
#define SER_TX0_STATUS_REG_ADDR            (0x1)
#define SER_TX0_STATUS_SHIFT_TX_COMPLETEBIT   (0)
#define SER_TX0_STATUS_MASK_TX_COMPLETEBIT    (0x01)

#define SER_TX0_STATUS_MASK_TX_FAILURE     (0x02)
#define SER_TX0_STATUS_SHIFT_TX_FAILURE    (1)

/* Tx Data Register */
#define SER_TX0_DATA_REG_ADDR    (0x2)
#define SER_TX0_DATA_SHIFT_BIT       (0x0)
#define SER_TX0_DATA_MASK_VAL        (0xFF)

/* Rx Data Register */
#define SER_RX0_DATA_REG_ADDR    (0x3)
#define SER_RX0_DATA_SHIFT_BIT       (0)
#define SER_RX0_DATA_MASK_VAL        (0xFF)

/****************************************************************
**                                                                            
** Syntax           :   inline void TARG_RegSetBits(uint8_t *addr, uint8_t mask,\
	   						 uint8_t shift, uint8_t val);                         
**                                                                            
** Parameters (in)  :   uint8_t *addr, uint8_t mask,uint8_t shift, uint8_t val                                                  
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     :    void                                          
**                                                                            
** Description      :   It sets the bits of the registers with the value given                               
**                                                                          
****************************************************************/
inline void TARG_RegSetBits(uint8_t *addr, uint8_t mask, uint8_t shift, uint8_t val)
{ 	
	*addr = ((*addr ) & ~mask) | (val<<shift);
}

/****************************************************************
**                                                                            
** Syntax           : inline uint8_t TARG_RegGetBits(uint8_t *addr, uint8_t mask,
   					   uint8_t shift, uint8_t *val);                         
**                                                                            
** Parameters (in)  :  uint8_t *addr, uint8_t mask, uint8_t shift, uint8_t *val                                                  
**                                                                           
** Parameters (out) :                                                   
**                                                                            
** Return value     :  uint8_t                                            
**                                                                            
** Description      :  It get the bits of the registers with the value given                                       
**                                                                          
****************************************************************/
inline uint8_t TARG_RegGetBits(uint8_t *addr, uint8_t mask, uint8_t shift, uin32_t *val)
{
	*val = (*addr) & mask;
}

#endif /*__UART_REG_H__*/
