//
// Created by Calvaria on 2025/12/11.
//
#include "hall.h"
#include "at32m412_416_dma.h"
#include "wk_adc.h"
#include "dsp/fast_math_functions.h"

const int16_t min_sin = 600;
const int16_t min_cos = 570;
const int16_t amp_sin = (3468 - min_sin) / 2;
const int16_t amp_cos = (3550 - min_sin) / 2;

float hall_theta = 0;
void hall_init(void) {
  while (dma_flag_get(DMA1_FDT1_FLAG) == RESET) {
  }
  dma_flag_clear(DMA1_FDT1_FLAG);
}

void hall_update(void) {
  const float sin_val = (float)(adc_value[2] - min_sin - amp_sin) / (float)amp_sin;
  const float cos_val = (float)(adc_value[3] - min_cos - amp_cos) / (float)amp_cos;

  float theta;

  arm_atan2_f32(sin_val, cos_val, &theta);

  theta += PI * 0.22f;

  if (theta > PI * 2) {
    theta -= PI * 2;
  } else if (theta < 0) {
    theta += PI * 2;
  }

  hall_theta = theta;
}


float angle_prev = 0.0;
int64_t angle_rot_dat = 0;
int64_t get_magnet_angle_rot(float reval)
{
  float d_angle = reval - angle_prev;
  if (fabsf(d_angle) > (0.8f * (PI * 2))) angle_rot_dat += (d_angle > 0.f) ? -1 : 1;

  angle_prev = reval;
  return angle_rot_dat;
}

void reset_rotations(void)
{
  angle_rot_dat = 0;
}


// 归一化角度
float norm_angle(const float angle)
{
  float a = fmodf(angle, (PI * 2));
  return a >= 0 ? a : (a + (PI * 2));
}