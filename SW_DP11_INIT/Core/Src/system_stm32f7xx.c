/**
  ******************************************************************************
  * @file    system_stm32f7xx.c
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M7 Device Peripheral Access Layer System Source File.
  *
  *   This file provides two functions and one global variable to be called from 
  *   user application:
  *      - SystemInit(): This function is called at startup just after reset and 
  *                      before branch to main program. This call is made inside
  *                      the "startup_stm32f7xx.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  *                                  by the user application to setup the SysTick 
  *                                  timer or configure other parameters.
  *                                     
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
  *
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f7xx_system
  * @{
  */  
  
/** @addtogroup STM32F7xx_System_Private_Includes
  * @{
  */

#include "stm32f7xx.h"


#if !defined  (HSE_VALUE) 
  #define HSE_VALUE    ((uint32_t)25000000) /*!< Default value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    ((uint32_t)16000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

/**
  * @}
  */

/** @addtogroup STM32F7xx_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F7xx_System_Private_Defines
  * @{
  */

/************************* Miscellaneous Configuration ************************/
/*!< Uncomment the following line if you need to use QSPI memory mounted
     on DK as data memory  */
#define DATA_IN_QSPI
/*!< Uncomment the following line if you need to relocate your vector Table in
     Internal SRAM. */
/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET  0x00 /*!< Vector Table base offset field. 
                                   This value must be a multiple of 0x200. */
/******************************************************************************/

/**
  * @}
  */

/** @addtogroup STM32F7xx_System_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F7xx_System_Private_Variables
  * @{
  */

  /* This variable is updated in three ways:
      1) by calling CMSIS function SystemCoreClockUpdate()
      2) by calling HAL API function HAL_RCC_GetHCLKFreq()
      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency 
         Note: If you use this function to configure the system clock; then there
               is no need to call the 2 first functions listed above, since SystemCoreClock
               variable is updated automatically.
  */
  uint32_t SystemCoreClock = 16000000;
  const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
  const uint8_t APBPrescTable[8] = {0, 0, 0, 0, 1, 2, 3, 4};

/**
  * @}
  */

/** @addtogroup STM32F7xx_System_Private_FunctionPrototypes
  * @{
  */
#if defined (DATA_IN_QSPI)
  //static void SetSysClk(void);
  static void SystemInit_ExtMemCtl(void); 
#endif /* DATA_IN_QSPI */
/**
  * @}
  */

/** @addtogroup STM32F7xx_System_Private_Functions
  * @{
  */

/**
  * @brief  Setup the microcontroller system
  *         Initialize the Embedded Flash Interface, the PLL and update the 
  *         SystemFrequency variable.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
  #endif
  /* Reset the RCC clock configuration to the default reset state ------------*/
  /* Set HSION bit */
  RCC->CR |= (uint32_t)0x00000001;

  /* Reset CFGR register */
  RCC->CFGR = 0x00000000;

  /* Reset HSEON, CSSON and PLLON bits */
  RCC->CR &= (uint32_t)0xFEF6FFFF;

  /* Reset PLLCFGR register */
  RCC->PLLCFGR = 0x24003010;

  /* Reset HSEBYP bit */
  RCC->CR &= (uint32_t)0xFFFBFFFF;

  /* Disable all interrupts */
  RCC->CIR = 0x00000000;
	
#if defined (DATA_IN_QSPI)
  // SetSysClk();
  SystemCoreClockUpdate();
  SystemInit_ExtMemCtl();
#endif /* DATA_IN_QSPI */


  /* Configure the Vector Table location add offset address ------------------*/
#ifdef VECT_TAB_SRAM
  SCB->VTOR = RAMDTCM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#else
  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
#endif
}

/**
   * @brief  Update SystemCoreClock variable according to Clock Register Values.
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  *           
  * @note   Each time the core clock (HCLK) changes, this function must be called
  *         to update SystemCoreClock variable value. Otherwise, any configuration
  *         based on this variable will be incorrect.         
  *     
  * @note   - The system frequency computed by this function is not the real 
  *           frequency in the chip. It is calculated based on the predefined 
  *           constant and the selected clock source:
  *             
  *           - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(*)
  *                                              
  *           - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(**)
  *                          
  *           - If SYSCLK source is PLL, SystemCoreClock will contain the HSE_VALUE(**) 
  *             or HSI_VALUE(*) multiplied/divided by the PLL factors.
  *         
  *         (*) HSI_VALUE is a constant defined in stm32f7xx_hal_conf.h file (default value
  *             16 MHz) but the real value may vary depending on the variations
  *             in voltage and temperature.   
  *    
  *         (**) HSE_VALUE is a constant defined in stm32f7xx_hal_conf.h file (default value
  *              25 MHz), user has to ensure that HSE_VALUE is same as the real
  *              frequency of the crystal used. Otherwise, this function may
  *              have wrong result.
  *                
  *         - The result of this function could be not correct when using fractional
  *           value for HSE crystal.
  *     
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate(void)
{
  uint32_t tmp = 0, pllvco = 0, pllp = 2, pllsource = 0, pllm = 2;
  
  /* Get SYSCLK source -------------------------------------------------------*/
  tmp = RCC->CFGR & RCC_CFGR_SWS;

  switch (tmp)
  {
    case 0x00:  /* HSI used as system clock source */
      SystemCoreClock = HSI_VALUE;
      break;
    case 0x04:  /* HSE used as system clock source */
      SystemCoreClock = HSE_VALUE;
      break;
    case 0x08:  /* PLL used as system clock source */

      /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N
         SYSCLK = PLL_VCO / PLL_P
         */    
      pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22;
      pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;
      
      if (pllsource != 0)
      {
        /* HSE used as PLL clock source */
        pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
      }
      else
      {
        /* HSI used as PLL clock source */
        pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);      
      }

      pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
      SystemCoreClock = pllvco/pllp;
      break;
    default:
      SystemCoreClock = HSI_VALUE;
      break;
  }
  /* Compute HCLK frequency --------------------------------------------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
  /* HCLK frequency */
  SystemCoreClock >>= tmp;
}

#if defined (DATA_IN_QSPI)

/**
  * @brief  Setup the external memory controller.
  *         Configures the GPIO and the QSPI in order to access the external 
  *         QSPI memory at the init.
  *         This function is called when the switch DATA_IN_QSPI is activated in 
  *         SystemInit() before jump to main.
  * @param  None
  * @retval None
  */
void SystemInit_ExtMemCtl(void)
{
  /****************************************************************************/
  /*                                                                          */
  /* Configuration of the IOs :                                               */
  /* --------------------------                                               */
  /* GPIOB2  : CLK                                                            */
  /* GPIOB6   : BK1_nCS                                                       */
  /* GPIOF8   : BK1_IO0/SO                                                    */
  /* GPIOF9   : BK1_IO1/SI                                                    */
  /* GPIOF7   : BK1_IO2                                                       */
  /* GPIOF6   : BK1_IO3                                                       */
  /*                                                                          */
  /* Configuration of the QSPI :                                              */
  /* ---------------------------                                              */
  /* - Instruction is on one single line                                      */
  /* - Address is 32-bits on four lines                                       */
  /* - No alternate bytes                                                     */
  /* - Ten dummy cycles                                                       */
  /* - Data is on four lines                                                  */
  /*                                                                          */
  /* If the clock is changed :                                                */
  /* -------------------------                                                */
  /* - Modify the prescaler in the control register                           */
  /* - Update the number of dummy cycles on the memory side and on            */
  /*   communication configuration register                                   */
  /*                                                                          */
  /* If the memory is changed :                                               */
  /* --------------------------                                               */
  /* - Update the device configuration register with the memory configuration */
  /* - Modify the instructions with the instruction set of the memory         */
  /* - Configure the number of dummy cycles as described in memory datasheet  */
  /* - Modify the data size and alternate bytes according memory datasheet    */
  /*                                                                          */
  /****************************************************************************/
  
  register uint32_t tmpreg = 0, datareg = 0,tmp = 0, timeout = 0xFFFF;
  
  /*--------------------------------------------------------------------------*/
  /*------------------ Activation of the peripheral clocks -------------------*/
  /*--------------------------------------------------------------------------*/      
  /* Enable GPIOB and GPIOF interface clock */ 
  /* Enable clock of the QSPI */
  RCC->AHB1ENR |= 0x00000022;
  //RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
  //RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
  
  /*--------------------------------------------------------------------------*/
  /*--------------------- Configuration of the I/O pins ----------------------*/
  /*--------------------------------------------------------------------------*/
  /* Configure alternate function selection for IO pins */
  GPIOF->AFR[0] = 0x99000000;
	GPIOF->AFR[1] = 0x000000AA;
	GPIOB->AFR[0] = 0x0A000900; 
  GPIOB->AFR[1] = 0x00000000;
  
  /* Configure alternate function mode for IO pins */
  GPIOF->MODER = 0x000AA000;
  GPIOB->MODER = 0x00002020;
  
  /* Configure output speed for IO pins */
  GPIOF->OSPEEDR = 0x000FF000;
  GPIOB->OSPEEDR = 0x00003030;
	
	/* Configure pins Output type to push-pull */
  GPIOF->OTYPER = 0x00000000;
  GPIOB->OTYPER = 0x00000000;
  
  /* Configure pull-up or pull-down for IO pins */
  GPIOB->PUPDR   = 0x00000000;
	GPIOF->PUPDR   = 0x00000000;
  
	/* Enable clock of the QSPI */
  RCC->AHB3ENR |= 0x0000002;
	
  /* Reset QSPI peripheral */
	RCC->AHB3RSTR |= (RCC_AHB3RSTR_QSPIRST); /* Reset */
	RCC->AHB3RSTR &= ~(RCC_AHB3RSTR_QSPIRST); /* Release reset */

  /* Enable Quad-SPI peripheral */
	QUADSPI->CR = 0x00000001;
	
	/* Send RESET ENABLE command (0x66) to allow memory registers reset*/
	QUADSPI->CCR = 0x00000166; 
	
	/* Send RESET command (0x99) to reset the memory registers*/
  QUADSPI->CCR = 0x00000199;
	
	/* Enable write cmd : 0x06. This to allow to write to enhanced volatile
	register to allow instructions to be writen in 4 lines*/
	while(QUADSPI->SR & 0x20); /* Wait for busy flag to be cleared */
	QUADSPI->CCR = 0x0106;
		
	/* Write to Enhanced Volatile Configuration Register of the external memory
  (MT25QL512): Enable quad I/O command input. Write to enhanced volatile
  configuration register cmd = 0x61, Configuration: 0x7F*/
  while(QUADSPI->SR & 0x20); /* Wait for busy flag to be cleared */
  QUADSPI->CCR = 0x01000161;

  while(!(QUADSPI->SR & 0x04)); /* Wait for FTF flag to be set */
  QUADSPI->DR = 0x7F;
  while(!(QUADSPI->SR & 0x02)); /* Wait for TCF flag to be set */

	/* Enable write cmd: 0x06. This is done to allow to write to volatile
	configuration register. For more details refer to MT25QL512 datasheet. */
  QUADSPI->CCR = ( 0x0106 | QUADSPI_CCR_IMODE );
	
	while(QUADSPI->SR & 0x20); /* Wait for busy flag to be cleared */
	/* Configure the Quad-SPI in 1-0-1 mode to write to VOLATILE CONFIGURATION
	REGISTER*/
	QUADSPI->CCR = (0x00000081 | QUADSPI_CCR_IMODE | QUADSPI_CCR_DMODE );

	while(!(QUADSPI->SR & 0x04)); /* Wait for FTF flag to be set */

//	/* Write 0x83 to volatile configuration register: bit 3 = 0 to enable XIP,
//	and bits [7:4] = 8 to set eight dummy cycles*/
//	QUADSPI->DR = ((MEM_DUMMY_CYCLE_XIP << 4) | 0x3 );
//	while(!(QUADSPI->SR & 0x02)); /* Wait for TCF flag to be set */
//	

//	#ifdef QSPI_DDRMODE
	QUADSPI->CR |= QSPI_CLOCK_MODE_0; /* SSHIFT = 0 delayed sample shifting
	disabled in DDR mode */
//	#else
//	QUADSPI->CR |= QSPI_CLK_PRESCALER | 0x10 ; /* 0x10: SSHIFT = 1 */
//	#endif
	QUADSPI->DCR = 0x00190000; /* Memory size: 512 Mb (64MB): 2^(26-1) ->
	2^(25) -> 2^(0x19)*/
// #endif
}
#endif /* DATA_IN_QSPI*/
/**
  * @}
  */

/**
  * @}
  */
  
/**
  * @}
  */    
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/