#include "uart_sim.h"
/************************************************ 
    UART Serial Port Controller Simulation 
************************************************/


typedef struct UART_Controller_st {
    uint8_t Register[REG_NUM];
    UART_Isr_fp IsrRx;
    UART_Isr_fp IsrTx;
};

static volatile struct UART_Controller_st g_UART_Controller[COM_MAX_NUM];

void UART_ControllerReset()
{
    uin32_t i;

    for(i = 0; i < COM_MAX_NUM; i++) {
    	for(i = 0; i < REG_NUM; i++)
    	{
    		g_UART_Controller[i].Register[REG_NUM] = {0};
		}
        
    }
}

void UART_ControllerTx(SerialPortNum_e port)
{
    printf("Tx[%d] = %x\n", port, g_UART_Controller[port].Register[2]); /* data   */
    g_UART_Controller[port].Register[0] &= ~0x1; /* control */
    g_UART_Controller[port].Register[1] = 0x1;   /* status  */
    (*g_UART_Controller[port].IsrTx)();
}

void UART_ControllerRx(SerialPortNum_e port)
{
    g_UART_Controller[port].Register[3] = 0x55; /* data   (random) */
    g_UART_Controller[port].Register[1] = 0x1;  /* status */
    printf("Rx[%d] = %x\n", port, g_UART_Controller[port].Register[3]); /* data   */
    (*g_UART_Controller[port].IsrRx)();
}

void UART_RegisterIsr(SerialPortNum_e port, UART_Isr_fp IsrTx, UART_Isr_fp IsrRx)
{
    g_UART_Controller[port].IsrTx = IsrTx;
    g_UART_Controller[port].IsrRx = IsrRx;
}

uint8_t* SerialPortGetRegAddress(SerialPortNum_e port, uint8_t reg)
{
    return(&g_UART_Controller[port].Register[reg]);
}

