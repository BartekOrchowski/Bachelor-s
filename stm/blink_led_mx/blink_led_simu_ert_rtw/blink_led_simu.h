/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: blink_led_simu.h
 *
 * Code generated for Simulink model 'blink_led_simu'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Nov 12 16:15:48 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_blink_led_simu_h_
#define RTW_HEADER_blink_led_simu_h_
#ifndef blink_led_simu_COMMON_INCLUDES_
#define blink_led_simu_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "main.h"
#endif                                 /* blink_led_simu_COMMON_INCLUDES_ */

#include "blink_led_simu_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  uint64_T reps;                       /* '<Root>/Gain1' */
  real_T rpm;                          /* '<Root>/MATLAB Function' */
} B_blink_led_simu_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S6>/Analog to Digital Converter' */
  stm32cube_blocks_EncoderBlock_T obj_l;/* '<Root>/Encoder' */
  stm32cube_blocks_PWMOutput_bl_T obj_e;/* '<S10>/PWM Output' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int32_T prevCnt;                     /* '<Root>/MATLAB Function' */
  uint8_T is_active_c2_blink_led_simu; /* '<Root>/MATLAB Function' */
  boolean_T inited_not_empty;          /* '<Root>/MATLAB Function' */
} DW_blink_led_simu_T;

/* Parameters (default storage) */
struct P_blink_led_simu_T_ {
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  uint32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_blink_led_simu_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_blink_led_simu_T blink_led_simu_P;

/* Block signals (default storage) */
extern B_blink_led_simu_T blink_led_simu_B;

/* Block states (default storage) */
extern DW_blink_led_simu_T blink_led_simu_DW;

/* Model entry point functions */
extern void blink_led_simu_initialize(void);
extern void blink_led_simu_step(void);
extern void blink_led_simu_terminate(void);

/* Real-time Model object */
extern RT_MODEL_blink_led_simu_T *const blink_led_simu_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'blink_led_simu'
 * '<S1>'   : 'blink_led_simu/Analog to Digital Converter'
 * '<S2>'   : 'blink_led_simu/Digital Port Write'
 * '<S3>'   : 'blink_led_simu/MATLAB Function'
 * '<S4>'   : 'blink_led_simu/PWM Output'
 * '<S5>'   : 'blink_led_simu/Analog to Digital Converter/ECSoC'
 * '<S6>'   : 'blink_led_simu/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S7>'   : 'blink_led_simu/Digital Port Write/ECSoC'
 * '<S8>'   : 'blink_led_simu/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S9>'   : 'blink_led_simu/PWM Output/ECSoC'
 * '<S10>'  : 'blink_led_simu/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* RTW_HEADER_blink_led_simu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
