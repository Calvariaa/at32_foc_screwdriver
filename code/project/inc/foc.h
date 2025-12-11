//
// Created by Calvaria on 2025/9/20.
//

#ifndef SIMPLEFOC_STM32F431_FOC_H
#define SIMPLEFOC_STM32F431_FOC_H

#include <stdint.h>

#include "at32m412_416_tmr.h"

#define BUS_VOLTAGE 15
#define COUNT_PERIOD 2000
#define FOC_FREQUENCY 90000

typedef struct {
        float a;
        float b;
        float c;
}motor_t;

typedef struct {
        float i_d;
        float i_q;
}turn_vector_t;

typedef struct {
        float alpha;
        float beta;
}static_vector_t;

typedef struct {
        tmr_type *htim;

        motor_t current;
        turn_vector_t turn_vector;
        static_vector_t i_park_vector;
        uint8_t sector;
        motor_t sector_voltage;
        static_vector_t svpwm_vector;
        motor_t svpwm_voltage;

        float set_angle;
        uint8_t pole_pairs;

        uint32_t expect_rotations;
}foc_t;

extern foc_t foc_motor;

void foc_init(foc_t *_foc, uint8_t pole_pairs, tmr_type *_htim);

void foc_control(foc_t *_foc, float i_q, float hall_data);

void mos_all_set(tmr_type *_htim, uint32_t _cmp_u, uint32_t _cmp_v, uint32_t _cmp_w);

void mos_all_close(tmr_type *_htim);

#endif //SIMPLEFOC_STM32F431_FOC_H
