/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: blink_led_simu_data.c
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

#include "blink_led_simu.h"

/* Block parameters (default storage) */
P_blink_led_simu_T blink_led_simu_P = {
  /* Expression: 65536
   * Referenced by: '<S2>/Constant'
   */
  65536.0,

  /* Expression: 3
   * Referenced by: '<S5>/Gain'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  10000.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  5000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Expression: 1250
   * Referenced by: '<S2>/Constant1'
   */
  1250.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
