/* add user code begin Header */
/**
  **************************************************************************
  * @file     at32m412_416_int.c
  * @brief    main interrupt service routines.
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */
/* add user code end Header */

/* includes ------------------------------------------------------------------*/
#include "at32m412_416_int.h"
/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include "at32m412_416_wk_config.h"
#include "foc.h"
#include "hall.h"
#include "ssd1306.h"

/* add user code end private includes */

/* private typedef -----------------------------------------------------------*/
/* add user code begin private typedef */

/* add user code end private typedef */

/* private define ------------------------------------------------------------*/
/* add user code begin private define */

/* add user code end private define */

/* private macro -------------------------------------------------------------*/
/* add user code begin private macro */

/* add user code end private macro */

/* private variables ---------------------------------------------------------*/
/* add user code begin private variables */

/* add user code end private variables */

/* private function prototypes --------------------------------------------*/
/* add user code begin function prototypes */

/* add user code end function prototypes */

/* private user code ---------------------------------------------------------*/
/* add user code begin 0 */

/* add user code end 0 */

/* external variables ---------------------------------------------------------*/
/* add user code begin external variables */
int32_t encoder_pulse_data = 0;
int32_t encoder_position = 0;
/* add user code end external variables */

/**
  * @brief  this function handles nmi exception.
  * @param  none
  * @retval none
  */
void NMI_Handler(void)
{
  /* add user code begin NonMaskableInt_IRQ 0 */

  /* add user code end NonMaskableInt_IRQ 0 */

  /* add user code begin NonMaskableInt_IRQ 1 */

  /* add user code end NonMaskableInt_IRQ 1 */
}

/**
  * @brief  this function handles hard fault exception.
  * @param  none
  * @retval none
  */
void HardFault_Handler(void)
{
  /* add user code begin HardFault_IRQ 0 */

  /* add user code end HardFault_IRQ 0 */
  /* go to infinite loop when hard fault exception occurs */
  while (1)
  {
    /* add user code begin W1_HardFault_IRQ 0 */

    /* add user code end W1_HardFault_IRQ 0 */
  }
}

/**
  * @brief  this function handles memory manage exception.
  * @param  none
  * @retval none
  */
void MemManage_Handler(void)
{
  /* add user code begin MemoryManagement_IRQ 0 */

  /* add user code end MemoryManagement_IRQ 0 */
  /* go to infinite loop when memory manage exception occurs */
  while (1)
  {
    /* add user code begin W1_MemoryManagement_IRQ 0 */

    /* add user code end W1_MemoryManagement_IRQ 0 */
  }
}

/**
  * @brief  this function handles bus fault exception.
  * @param  none
  * @retval none
  */
void BusFault_Handler(void)
{
  /* add user code begin BusFault_IRQ 0 */

  /* add user code end BusFault_IRQ 0 */
  /* go to infinite loop when bus fault exception occurs */
  while (1)
  {
    /* add user code begin W1_BusFault_IRQ 0 */

    /* add user code end W1_BusFault_IRQ 0 */
  }
}

/**
  * @brief  this function handles usage fault exception.
  * @param  none
  * @retval none
  */
void UsageFault_Handler(void)
{
  /* add user code begin UsageFault_IRQ 0 */

  /* add user code end UsageFault_IRQ 0 */
  /* go to infinite loop when usage fault exception occurs */
  while (1)
  {
    /* add user code begin W1_UsageFault_IRQ 0 */

    /* add user code end W1_UsageFault_IRQ 0 */
  }
}

/**
  * @brief  this function handles svcall exception.
  * @param  none
  * @retval none
  */
void SVC_Handler(void)
{
  /* add user code begin SVCall_IRQ 0 */

  /* add user code end SVCall_IRQ 0 */
  /* add user code begin SVCall_IRQ 1 */

  /* add user code end SVCall_IRQ 1 */
}

/**
  * @brief  this function handles debug monitor exception.
  * @param  none
  * @retval none
  */
void DebugMon_Handler(void)
{
  /* add user code begin DebugMonitor_IRQ 0 */

  /* add user code end DebugMonitor_IRQ 0 */
  /* add user code begin DebugMonitor_IRQ 1 */

  /* add user code end DebugMonitor_IRQ 1 */
}

/**
  * @brief  this function handles pendsv_handler exception.
  * @param  none
  * @retval none
  */
void PendSV_Handler(void)
{
  /* add user code begin PendSV_IRQ 0 */

  /* add user code end PendSV_IRQ 0 */
  /* add user code begin PendSV_IRQ 1 */

  /* add user code end PendSV_IRQ 1 */
}

/**
  * @brief  this function handles systick handler.
  * @param  none
  * @retval none
  */
void SysTick_Handler(void)
{
  /* add user code begin SysTick_IRQ 0 */

  /* add user code end SysTick_IRQ 0 */

  /* add user code begin SysTick_IRQ 1 */

  /* add user code end SysTick_IRQ 1 */
}

/**
  * @brief  this function handles EXINT Line 2 handler.
  * @param  none
  * @retval none
  */
void EXINT2_IRQHandler(void)
{
  /* add user code begin EXINT2_IRQ 0 */

  /* add user code end EXINT2_IRQ 0 */

  if(exint_interrupt_flag_get(EXINT_LINE_2) != RESET)
  {
    /* add user code begin EXINT_LINE_2 */
    if (gpio_input_data_bit_read(ENC_A_GPIO_PORT, ENC_A_PIN) == SET) {
      if (gpio_input_data_bit_read(ENC_B_GPIO_PORT, ENC_B_PIN) == RESET) {
        encoder_pulse_data++;
      }
      else {
        encoder_pulse_data--;
      }
    }
    else {
      if (gpio_input_data_bit_read(ENC_B_GPIO_PORT, ENC_B_PIN) == SET) {
        encoder_pulse_data++;
      }
      else {
        encoder_pulse_data--;
      }
    }
    /* clear flag */
    exint_flag_clear(EXINT_LINE_2);
    /* add user code end EXINT_LINE_2 */ 
  }

  /* add user code begin EXINT2_IRQ 1 */

  /* add user code end EXINT2_IRQ 1 */
}

/**
  * @brief  this function handles EXINT Line 3 handler.
  * @param  none
  * @retval none
  */
void EXINT3_IRQHandler(void)
{
  /* add user code begin EXINT3_IRQ 0 */

  /* add user code end EXINT3_IRQ 0 */

  if(exint_interrupt_flag_get(EXINT_LINE_3) != RESET)
  {
    /* add user code begin EXINT_LINE_3 */
    if (gpio_input_data_bit_read(ENC_B_GPIO_PORT, ENC_B_PIN) == SET) {
      if (gpio_input_data_bit_read(ENC_A_GPIO_PORT, ENC_A_PIN) == SET) {
        encoder_pulse_data++;
      }
      else {
        encoder_pulse_data--;
      }
    }
    else {
      if (gpio_input_data_bit_read(ENC_A_GPIO_PORT, ENC_A_PIN) == RESET) {
        encoder_pulse_data++;
      }
      else {
        encoder_pulse_data--;
      }
    }
    /* clear flag */
    exint_flag_clear(EXINT_LINE_3);
    /* add user code end EXINT_LINE_3 */ 
  }

  /* add user code begin EXINT3_IRQ 1 */

  /* add user code end EXINT3_IRQ 1 */
}

/**
  * @brief  this function handles DMA1 Channel 1 handler.
  * @param  none
  * @retval none
  */
void DMA1_Channel1_IRQHandler(void)
{
  /* add user code begin DMA1_Channel1_IRQ 0 */

  /* add user code end DMA1_Channel1_IRQ 0 */

  if(dma_interrupt_flag_get(DMA1_FDT1_FLAG) != RESET)
  {   
    /* add user code begin DMA1_FDT1_FLAG */
    hall_update();

    encoder_position = (encoder_pulse_data) / 4;

    foc_control(&foc_motor, (float)encoder_position / 10.f, hall_theta);

    gpio_bits_toggle(LED0_GPIO_PORT,LED0_PIN);
    
    /* handle full data transfer and clear flag */
    dma_flag_clear(DMA1_FDT1_FLAG);
    /* add user code end DMA1_FDT1_FLAG */ 
  }

  /* add user code begin DMA1_Channel1_IRQ 1 */

  /* add user code end DMA1_Channel1_IRQ 1 */
}

/**
  * @brief  this function handles DMA1 Channel 2 handler.
  * @param  none
  * @retval none
  */
void DMA1_Channel2_IRQHandler(void)
{
  /* add user code begin DMA1_Channel2_IRQ 0 */

  /* add user code end DMA1_Channel2_IRQ 0 */

  if(dma_interrupt_flag_get(DMA1_FDT2_FLAG) != RESET)
  {   
    /* add user code begin DMA1_FDT2_FLAG */
    /* handle full data transfer and clear flag */
    dma_flag_clear(DMA1_FDT2_FLAG);
    /* add user code end DMA1_FDT2_FLAG */ 
  }

  /* add user code begin DMA1_Channel2_IRQ 1 */

  /* add user code end DMA1_Channel2_IRQ 1 */
}

/**
  * @brief  this function handles TMR1 Overflow and TMR10 handler.
  * @param  none
  * @retval none
  */
void TMR1_OVF_TMR10_IRQHandler(void)
{
  /* add user code begin TMR1_OVF_TMR10_IRQ 0 */

  /* add user code end TMR1_OVF_TMR10_IRQ 0 */

  /* add user code begin TMR1_OVF_TMR10_IRQ 1 */

  /* add user code end TMR1_OVF_TMR10_IRQ 1 */
}

/**
  * @brief  this function handles TMR1 Trigger and hall and TMR11 handler.
  * @param  none
  * @retval none
  */
void TMR1_TRG_HALL_TMR11_IRQHandler(void)
{
  /* add user code begin TMR1_TRG_HALL_TMR11_IRQ 0 */

  /* add user code end TMR1_TRG_HALL_TMR11_IRQ 0 */

  /* add user code begin TMR1_TRG_HALL_TMR11_IRQ 1 */

  /* add user code end TMR1_TRG_HALL_TMR11_IRQ 1 */
}

/**
  * @brief  this function handles TMR1 Channel handler.
  * @param  none
  * @retval none
  */
void TMR1_CH_IRQHandler(void)
{
  /* add user code begin TMR1_CH_IRQ 0 */

  /* add user code end TMR1_CH_IRQ 0 */

  /* channel4 interrupt management */
  if(tmr_interrupt_flag_get(TMR1, TMR_C4_FLAG) != RESET)
  {
    /* add user code begin TMR1_TMR_C4_FLAG */

    adc_ordinary_software_trigger_enable(ADC2, TRUE);

    /* clear flag */
    tmr_flag_clear(TMR1, TMR_C4_FLAG);
    /* add user code end TMR1_TMR_C4_FLAG */
  }

  /* add user code begin TMR1_CH_IRQ 1 */

  /* add user code end TMR1_CH_IRQ 1 */
}

/**
  * @brief  this function handles I2C1 Event handler.
  * @param  none
  * @retval none
  */
void I2C1_EVT_IRQHandler(void)
{
  /* add user code begin I2C1_EVT_IRQ 0 */
  /* add user code end I2C1_EVT_IRQ 0 */

  if(i2c_interrupt_flag_get(I2C1, I2C_TDC_FLAG) != RESET)
  {
    /* add user code begin I2C1_TDC_FLAG */

    /* add user code end I2C1_TDC_FLAG */ 
  }

  /* add user code begin I2C1_EVT_IRQ 1 */

  /* add user code end I2C1_EVT_IRQ 1 */
}

/* add user code begin 1 */

/* add user code end 1 */
