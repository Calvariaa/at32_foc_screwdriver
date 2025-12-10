/* add user code begin Header */
/**
  **************************************************************************
  * @file     wk_tmr.c
  * @brief    work bench config program
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

/* Includes ------------------------------------------------------------------*/
#include "wk_tmr.h"

/* add user code begin 0 */

/* add user code end 0 */

/**
  * @brief  init tmr1 function.
  * @param  none
  * @retval none
  */
void wk_tmr1_init(void)
{
  /* add user code begin tmr1_init 0 */

  /* add user code end tmr1_init 0 */

  gpio_init_type gpio_init_struct;
  tmr_output_config_type tmr_output_struct;
  tmr_brkdt_config_type tmr_brkdt_struct;

  tmr_brk2_config_type tmr_brk2_struct;


  gpio_default_para_init(&gpio_init_struct);

  /* add user code begin tmr1_init 1 */

  /* add user code end tmr1_init 1 */

  /* configure the tmr1 CH1 pin */
  gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE0, GPIO_MUX_1);
  gpio_init_struct.gpio_pins = GPIO_PINS_0;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOF, &gpio_init_struct);

  /* configure the tmr1 CH1C pin */
  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE7, GPIO_MUX_1);
  gpio_init_struct.gpio_pins = GPIO_PINS_7;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOA, &gpio_init_struct);

  /* configure the tmr1 CH2 pin */
  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE9, GPIO_MUX_1);
  gpio_init_struct.gpio_pins = GPIO_PINS_9;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOA, &gpio_init_struct);

  /* configure the tmr1 CH2C pin */
  gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE1, GPIO_MUX_1);
  gpio_init_struct.gpio_pins = GPIO_PINS_1;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOF, &gpio_init_struct);

  /* configure the tmr1 CH3 pin */
  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE10, GPIO_MUX_1);
  gpio_init_struct.gpio_pins = GPIO_PINS_10;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOA, &gpio_init_struct);

  /* configure the tmr1 CH3C pin */
  gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE15, GPIO_MUX_1);
  gpio_init_struct.gpio_pins = GPIO_PINS_15;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOB, &gpio_init_struct);

  /* configure the tmr1 BRK pin */
  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE6, GPIO_MUX_1);
  gpio_init_struct.gpio_pins = GPIO_PINS_6;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOA, &gpio_init_struct);

  /* configure counter settings */
  tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR1, TMR_CLOCK_DIV1);
  tmr_repetition_counter_set(TMR1, 0);
  tmr_period_buffer_enable(TMR1, FALSE);
  tmr_base_init(TMR1, 65535, 0);

  /* configure primary mode settings */
  tmr_sub_sync_mode_set(TMR1, FALSE);
  tmr_primary_mode_select(TMR1, TMR_PRIMARY_SEL_RESET);
  tmr_primary_mode2_select(TMR1, TMR_PRIMARY_SEL_RESET);

  /* configure channel 1 output settings */
  tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_OFF;
  tmr_output_struct.oc_output_state = TRUE;
  tmr_output_struct.occ_output_state = TRUE;
  tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.oc_idle_state = FALSE;
  tmr_output_struct.occ_idle_state = FALSE;
  tmr_output_channel_config(TMR1, TMR_SELECT_CHANNEL_1, &tmr_output_struct);
  tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_1, 0);
  tmr_output_channel_buffer_enable(TMR1, TMR_SELECT_CHANNEL_1, FALSE);

  /* configure channel 2 output settings */
  tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_OFF;
  tmr_output_struct.oc_output_state = TRUE;
  tmr_output_struct.occ_output_state = TRUE;
  tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.oc_idle_state = FALSE;
  tmr_output_struct.occ_idle_state = FALSE;
  tmr_output_channel_config(TMR1, TMR_SELECT_CHANNEL_2, &tmr_output_struct);
  tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_2, 0);
  tmr_output_channel_buffer_enable(TMR1, TMR_SELECT_CHANNEL_2, FALSE);

  /* configure channel 3 output settings */
  tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_OFF;
  tmr_output_struct.oc_output_state = TRUE;
  tmr_output_struct.occ_output_state = TRUE;
  tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.oc_idle_state = FALSE;
  tmr_output_struct.occ_idle_state = FALSE;
  tmr_output_channel_config(TMR1, TMR_SELECT_CHANNEL_3, &tmr_output_struct);
  tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_3, 0);
  tmr_output_channel_buffer_enable(TMR1, TMR_SELECT_CHANNEL_3, FALSE);

  /* configure channel 4 output settings */
  tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_OFF;
  tmr_output_struct.oc_output_state = TRUE;
  tmr_output_struct.occ_output_state = FALSE;
  tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
  tmr_output_struct.oc_idle_state = FALSE;
  tmr_output_struct.occ_idle_state = FALSE;
  tmr_output_channel_config(TMR1, TMR_SELECT_CHANNEL_4, &tmr_output_struct);
  tmr_channel_value_set(TMR1, TMR_SELECT_CHANNEL_4, 0);
  tmr_output_channel_buffer_enable(TMR1, TMR_SELECT_CHANNEL_4, FALSE);

  /* configure break and dead-time settings */
  tmr_brkdt_struct.brk_enable = FALSE;
  tmr_brkdt_struct.auto_output_enable = FALSE;
  tmr_brkdt_struct.brk_polarity = TMR_BRK_INPUT_ACTIVE_LOW;
  tmr_brkdt_struct.fcsoen_state = FALSE;
  tmr_brkdt_struct.fcsodis_state = FALSE;
  tmr_brkdt_struct.wp_level = TMR_WP_OFF;
  tmr_brkdt_struct.deadtime = 0;
  tmr_brkdt_config(TMR1, &tmr_brkdt_struct);
  tmr_brk_filter_value_set(TMR1, 0);

  /* break 2 config */
  tmr_brk2_struct.brk2_enable = FALSE;
  tmr_brk2_struct.brk2_polarity = TMR_BRK_INPUT_ACTIVE_LOW;
  tmr_brk2_struct.brk2_filter = 0;
  tmr_brk2_config(TMR1, &tmr_brk2_struct);

  tmr_output_enable(TMR1, TRUE);

  tmr_counter_enable(TMR1, TRUE);

  /* add user code begin tmr1_init 2 */

  /* add user code end tmr1_init 2 */
}

/**
  * @brief  init tmr9 function.
  * @param  none
  * @retval none
  */
void wk_tmr9_init(void)
{
  /* add user code begin tmr9_init 0 */

  /* add user code end tmr9_init 0 */

  gpio_init_type gpio_init_struct;
  tmr_input_config_type  tmr_input_struct;

  gpio_default_para_init(&gpio_init_struct);

  /* add user code begin tmr9_init 1 */

  /* add user code end tmr9_init 1 */

  /* configure the tmr9 CH1 pin */
  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE2, GPIO_MUX_3);
  gpio_init_struct.gpio_pins = GPIO_PINS_2;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOA, &gpio_init_struct);

  /* configure the tmr9 CH2 pin */
  gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE3, GPIO_MUX_3);
  gpio_init_struct.gpio_pins = GPIO_PINS_3;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
  gpio_init(GPIOA, &gpio_init_struct);

  /* configure counter settings */
  tmr_cnt_dir_set(TMR9, TMR_COUNT_UP);
  tmr_clock_source_div_set(TMR9, TMR_CLOCK_DIV1);
  tmr_repetition_counter_set(TMR9, 0);
  tmr_period_buffer_enable(TMR9, FALSE);
  tmr_base_init(TMR9, 65535, 0);

  /* configure primary mode settings */
  tmr_sub_sync_mode_set(TMR9, FALSE);
  tmr_primary_mode_select(TMR9, TMR_PRIMARY_SEL_RESET);

  /* configure encoder mode */
  tmr_input_struct.input_channel_select = TMR_SELECT_CHANNEL_1;
  tmr_input_struct.input_mapped_select = TMR_CC_CHANNEL_MAPPED_DIRECT;
  tmr_input_struct.input_polarity_select = TMR_INPUT_RISING_EDGE;
  tmr_input_struct.input_filter_value = 0;
  tmr_input_channel_init(TMR9, &tmr_input_struct, TMR_CHANNEL_INPUT_DIV_1);

  tmr_input_struct.input_channel_select = TMR_SELECT_CHANNEL_2;
  tmr_input_struct.input_mapped_select = TMR_CC_CHANNEL_MAPPED_DIRECT;
  tmr_input_struct.input_polarity_select = TMR_INPUT_RISING_EDGE;
  tmr_input_struct.input_filter_value = 0;
  tmr_input_channel_init(TMR9, &tmr_input_struct, TMR_CHANNEL_INPUT_DIV_1);

  tmr_encoder_mode_config(TMR9, TMR_ENCODER_MODE_C, TMR_INPUT_RISING_EDGE, TMR_INPUT_RISING_EDGE);

  tmr_counter_enable(TMR9, TRUE);

  /* add user code begin tmr9_init 2 */
  
  /* add user code end tmr9_init 2 */
}

/* add user code begin 1 */

/* add user code end 1 */
