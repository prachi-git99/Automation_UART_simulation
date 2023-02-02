
/************************************************ 
UART Serial communication Application
File Name: 
Author: 
License:  
************************************************/

#include "uart_sim.h"
#include "Uart_app.h"


UART_SerialPortHandler_st  var;
UART_SerialPortHandler_st  *pSerialPortHandler=&var;

SerialPortErr_e Uart_Init(void)
{
	//Initialize the UART port here
	SerialPortErr_e eStatus = ERROR;
	
	pSerialPortHandler->ePortId = COM1;
	pSerialPortHandler->eBaud = BAUD_9600;
	pSerialPortHandler->eBit = BITLEN_8;
	pSerialPortHandler->eParity = PARITY_EVEN;
	pSerialPortHandler->eHwControl = HWCTRL_NO;
	
	eStatus = UART_SerialPortInit(pSerialPortHandler);
	
	if(eStatus == SUCCESS)
	{
		printf("UART Init Success\n");
	}
	else
	{
		printf("UART Init Failed\n");
	}
	return eStatus;	
}

void Uart_Receive_Data(uin32_t *buff)
{
	//need to receive the data here
	SerialPortErr_e eStatus = ERROR;
	
	eStatus = UART_SerialPortRead(pSerialPortHandler, buff);
	if(eStatus == SUCCESS)
	{
		printf("Data Received %d\n", *buff);
	}
	else
	{
		printf("Data Not Received\n");
	}
	
	
}

void Uart_Send_Data(uin32_t data)
{
	//need to send the data here
	
	SerialPortErr_e eStatus = ERROR;
	
	eStatus = UART_SerialPortWrite(pSerialPortHandler, data);
	
	if(eStatus == SUCCESS)
	{
		printf("Data Sent %x\n", data);
	}
	else
	{
		printf("Data Not Sent\n");
	}
}

void Uart_Isr_Tx()
{
	printf("UART TX Interrupt executed\n");
}

void Uart_Isr_Rx()
{
	printf("UART RX Interrupt executed\n");
}

int main()
{
	printf("UART Driver Implementation\n");
	uin32_t data = 0x21;
	uin32_t rx_data = 0x00;
	SerialPortErr_e eStatus = ERROR;
	
	UART_ControllerReset();
	
	//Init the UART port
	eStatus = Uart_Init();
	UART_RegisterIsr(COM1, Uart_Isr_Tx, Uart_Isr_Rx);
	//send and receive the data
	if(eStatus == SUCCESS)
	{
		Uart_Send_Data(data);
		UART_ControllerTx(COM1);
		Uart_Receive_Data(&rx_data);	
		UART_ControllerRx(COM1);
	}
	
	//ToDo: Need to implement the states to cintiniously send/receive the data
	
	return 0;
}

