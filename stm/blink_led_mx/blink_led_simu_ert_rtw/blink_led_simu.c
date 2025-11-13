/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: blink_led_simu.c
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

#include "blink_led_simu.h"
#include "blink_led_simu_types.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "blink_led_simu_private.h"

/* Block signals (default storage) */
B_blink_led_simu_T blink_led_simu_B;

/* Block states (default storage) */
DW_blink_led_simu_T blink_led_simu_DW;

/* Real-time model */
static RT_MODEL_blink_led_simu_T blink_led_simu_M_;
RT_MODEL_blink_led_simu_T *const blink_led_simu_M = &blink_led_simu_M_;

/* Forward declaration for local functions */
static void blink_led_simu_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void blink_led_s_SystemCore_setup_nm(stm32cube_blocks_PWMOutput_bl_T *obj);
static void blink_led_si_SystemCore_setup_n(stm32cube_blocks_EncoderBlock_T *obj);
static void blink_led_simu_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S6>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S6>/Analog to Digital Converter' */
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

static void blink_led_s_SystemCore_setup_nm(stm32cube_blocks_PWMOutput_bl_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S10>/PWM Output' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S10>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S10>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void blink_led_si_SystemCore_setup_n(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void blink_led_simu_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator;
  int32_T diff;
  uint32_T timerCounts;
  uint16_T data;

  /* MATLABSystem: '<S6>/Analog to Digital Converter' */
  regularReadADCNormal(blink_led_simu_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                       &data);

  /* MATLABSystem: '<S10>/PWM Output' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<S6>/Analog to Digital Converter'
   */
  setDutyCycleInPercentageChannel1(blink_led_simu_DW.obj_e.TimerHandle, (real_T)
    ((uint32_T)blink_led_simu_P.Gain_Gain * data) * 4.76837158203125E-7);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (blink_led_simu_DW.clockTickCounter <
                        blink_led_simu_P.PulseGenerator_Duty) &&
    (blink_led_simu_DW.clockTickCounter >= 0) ?
    blink_led_simu_P.PulseGenerator_Amp : 0.0;
  if (blink_led_simu_DW.clockTickCounter >=
      blink_led_simu_P.PulseGenerator_Period - 1.0) {
    blink_led_simu_DW.clockTickCounter = 0;
  } else {
    blink_led_simu_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S8>/Digital Port Write' */
  portNameLoc = GPIOB;
  diff = (rtb_PulseGenerator != 0.0);
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)diff);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)diff & 1U);

  /* MATLABSystem: '<Root>/Encoder' */
  timerCounts = getTimerCounterValue(blink_led_simu_DW.obj_l.TimerHandle);

  /* Gain: '<Root>/Gain1' incorporates:
   *  MATLABSystem: '<Root>/Encoder'
   */
  blink_led_simu_B.reps = (uint64_T)blink_led_simu_P.Gain1_Gain * timerCounts;

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (!blink_led_simu_DW.inited_not_empty) {
    blink_led_simu_DW.prevCnt = 0;
    blink_led_simu_DW.inited_not_empty = true;
    blink_led_simu_B.rpm = 0.0;
  } else {
    if (blink_led_simu_DW.prevCnt <= MIN_int32_T) {
      diff = MAX_int32_T;
    } else {
      diff = -blink_led_simu_DW.prevCnt;
    }

    if (diff > 32767) {
      diff -= 65536;
    } else if (diff < -32768) {
      diff += 65536;
    }

    blink_led_simu_DW.prevCnt = 0;
    blink_led_simu_B.rpm = (real_T)diff / 3200.0 / 0.001 * 60.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  blink_led_simu_M->Timing.taskTime0 =
    ((time_T)(++blink_led_simu_M->Timing.clockTick0)) *
    blink_led_simu_M->Timing.stepSize0;
}

/* Model initialize function */
void blink_led_simu_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(blink_led_simu_M, 60.0);
  blink_led_simu_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  blink_led_simu_M->Sizes.checksums[0] = (3627292058U);
  blink_led_simu_M->Sizes.checksums[1] = (2613575792U);
  blink_led_simu_M->Sizes.checksums[2] = (2291431759U);
  blink_led_simu_M->Sizes.checksums[3] = (1022985207U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    blink_led_simu_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(blink_led_simu_M->extModeInfo,
      &blink_led_simu_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(blink_led_simu_M->extModeInfo,
                        blink_led_simu_M->Sizes.checksums);
    rteiSetTPtr(blink_led_simu_M->extModeInfo, rtmGetTPtr(blink_led_simu_M));
  }

  /* Start for MATLABSystem: '<S6>/Analog to Digital Converter' */
  blink_led_simu_DW.obj.isInitialized = 0;
  blink_led_simu_DW.obj.matlabCodegenIsDeleted = false;
  blink_led_simu_SystemCore_setup(&blink_led_simu_DW.obj);

  /* Start for MATLABSystem: '<S10>/PWM Output' */
  blink_led_simu_DW.obj_e.isInitialized = 0;
  blink_led_simu_DW.obj_e.matlabCodegenIsDeleted = false;
  blink_led_s_SystemCore_setup_nm(&blink_led_simu_DW.obj_e);

  /* Start for MATLABSystem: '<Root>/Encoder' */
  blink_led_simu_DW.obj_l.isInitialized = 0;
  blink_led_simu_DW.obj_l.matlabCodegenIsDeleted = false;
  blink_led_si_SystemCore_setup_n(&blink_led_simu_DW.obj_l);
}

/* Model terminate function */
void blink_led_simu_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<S6>/Analog to Digital Converter' */
  if (!blink_led_simu_DW.obj.matlabCodegenIsDeleted) {
    blink_led_simu_DW.obj.matlabCodegenIsDeleted = true;
    if ((blink_led_simu_DW.obj.isInitialized == 1) &&
        blink_led_simu_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(blink_led_simu_DW.obj.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S10>/PWM Output' */
  if (!blink_led_simu_DW.obj_e.matlabCodegenIsDeleted) {
    blink_led_simu_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((blink_led_simu_DW.obj_e.isInitialized == 1) &&
        blink_led_simu_DW.obj_e.isSetupComplete) {
      disableCounter(blink_led_simu_DW.obj_e.TimerHandle);
      disableTimerInterrupts(blink_led_simu_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(blink_led_simu_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!blink_led_simu_DW.obj_l.matlabCodegenIsDeleted) {
    blink_led_simu_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((blink_led_simu_DW.obj_l.isInitialized == 1) &&
        blink_led_simu_DW.obj_l.isSetupComplete) {
      disableCounter(blink_led_simu_DW.obj_l.TimerHandle);
      disableTimerInterrupts(blink_led_simu_DW.obj_l.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(blink_led_simu_DW.obj_l.TimerHandle, ChannelInfo);
      disableTimerChannel2(blink_led_simu_DW.obj_l.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
