/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: blink_led_simu_types.h
 *
 * Code generated for Simulink model 'blink_led_simu'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Nov  5 13:59:16 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_blink_led_simu_types_h_
#define RTW_HEADER_blink_led_simu_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_S5MMpcz8vT0FlmhmEl4q5C
#define struct_tag_S5MMpcz8vT0FlmhmEl4q5C

struct tag_S5MMpcz8vT0FlmhmEl4q5C
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_S5MMpcz8vT0FlmhmEl4q5C */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_S5MMpcz8vT0FlmhmEl4q5C stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

/* Custom Type definition for MATLABSystem: '<Root>/Encoder' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_c6vUyHR5f8xkCafg9uVRGF
#define struct_tag_c6vUyHR5f8xkCafg9uVRGF

struct tag_c6vUyHR5f8xkCafg9uVRGF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_c6vUyHR5f8xkCafg9uVRGF */

#ifndef typedef_stm32cube_blocks_EncoderBlock_T
#define typedef_stm32cube_blocks_EncoderBlock_T

typedef struct tag_c6vUyHR5f8xkCafg9uVRGF stm32cube_blocks_EncoderBlock_T;

#endif                             /* typedef_stm32cube_blocks_EncoderBlock_T */

/* Parameters (default storage) */
typedef struct P_blink_led_simu_T_ P_blink_led_simu_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_blink_led_simu_T RT_MODEL_blink_led_simu_T;

#endif                                 /* RTW_HEADER_blink_led_simu_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
