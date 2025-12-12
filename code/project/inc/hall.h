//
// Created by Calvaria on 2025/12/11.
//

#ifndef AT32M416EBP7_WORKBENCH_HALL_H
#define AT32M416EBP7_WORKBENCH_HALL_H
#include <stdint.h>

extern float hall_theta;

void hall_init(void);

void hall_update(void);

int64_t get_magnet_angle_rot(float reval);

void reset_rotations(void);

float norm_angle(float angle);

#endif //AT32M416EBP7_WORKBENCH_HALL_H