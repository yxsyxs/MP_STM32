#include "sram.h"	  
#include "usart.h"	     
#include "stm32f4xx_hal.h"

#define Bank1_SRAM3_ADDR    ((uint32_t)(0x68000000))
#define SRAM_BANK_ADDR      ((uint32_t)0x68000000)

void FSMC_SRAM_Init(void)
{
      /*##-1- Configure the SRAM device ##########################################*/
  /* SRAM device configuration */ 
  SRAM_HandleTypeDef hsram;
  FSMC_NORSRAM_TimingTypeDef SRAM_Timing;	
	
  hsram.Instance  = FSMC_NORSRAM_DEVICE;
  hsram.Extended  = FSMC_NORSRAM_EXTENDED_DEVICE;
  
  SRAM_Timing.AddressSetupTime       = 2;
  SRAM_Timing.AddressHoldTime        = 1;
  SRAM_Timing.DataSetupTime          = 8;
  SRAM_Timing.BusTurnAroundDuration  = 1;
  SRAM_Timing.CLKDivision            = 2;
  SRAM_Timing.DataLatency            = 2;
  SRAM_Timing.AccessMode             = FSMC_ACCESS_MODE_A;
  
  hsram.Init.NSBank             = FSMC_NORSRAM_BANK3;
  hsram.Init.DataAddressMux     = FSMC_DATA_ADDRESS_MUX_DISABLE;
  hsram.Init.MemoryType         = FSMC_MEMORY_TYPE_SRAM;
  hsram.Init.MemoryDataWidth    = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
  hsram.Init.BurstAccessMode    = FSMC_BURST_ACCESS_MODE_DISABLE;
  hsram.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram.Init.WrapMode           = FSMC_WRAP_MODE_DISABLE;
  hsram.Init.WaitSignalActive   = FSMC_WAIT_TIMING_BEFORE_WS;
  hsram.Init.WriteOperation     = FSMC_WRITE_OPERATION_ENABLE;
  hsram.Init.WaitSignal         = FSMC_WAIT_SIGNAL_DISABLE;
  hsram.Init.ExtendedMode       = FSMC_EXTENDED_MODE_DISABLE;
  hsram.Init.AsynchronousWait   = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram.Init.WriteBurst         = FSMC_WRITE_BURST_DISABLE;

  if(HAL_SRAM_Init(&hsram, &SRAM_Timing, &SRAM_Timing) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler(); 
  }
}





//在指定地址(WriteAddr+Bank1_SRAM3_ADDR)开始,连续写入n个字节.
//pBuffer:字节指针
//WriteAddr:要写入的地址
//n:要写入的字节数
void FSMC_SRAM_WriteBuffer(uint8_t* pBuffer,uint32_t WriteAddr,uint32_t n)
{
	for(;n!=0;n--)  
	{										    
		*(uint8_t*)(Bank1_SRAM3_ADDR+WriteAddr)=*pBuffer;	  
		WriteAddr++;
		pBuffer++;
	}   
}																			    
//在指定地址((WriteAddr+Bank1_SRAM3_ADDR))开始,连续读出n个字节.
//pBuffer:字节指针
//ReadAddr:要读出的起始地址
//n:要写入的字节数
void FSMC_SRAM_ReadBuffer(uint8_t* pBuffer,uint32_t ReadAddr,uint32_t n)
{
	for(;n!=0;n--)  
	{											    
		*pBuffer++=*(uint8_t*)(Bank1_SRAM3_ADDR+ReadAddr);    
		ReadAddr++;
	}  
} 
 









