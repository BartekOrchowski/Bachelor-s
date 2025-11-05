/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: blink_led_simu.c
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
#include "blink_led_simu_types.h"
#include "rtwtypes.h"
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
static void blink_led_simu_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void blink_led_simu_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S2>/Encoder1' incorporates:
   *  MATLABSystem: '<Root>/Encoder'
   */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S2>/Encoder1' incorporates:
   *  MATLABSystem: '<Root>/Encoder'
   */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<S2>/Encoder1' incorporates:
   *  MATLABSystem: '<Root>/Encoder'
   */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S2>/Encoder1' incorporates:
     *  MATLABSystem: '<Root>/Encoder'
     */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void blink_led_simu_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator;
  int32_T c;

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

  /* MATLABSystem: '<S4>/Digital Port Write' */
  portNameLoc = GPIOB;
  c = (rtb_PulseGenerator != 0.0);
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 1U);

  /* MATLABSystem: '<S2>/Encoder1' */
  blink_led_simu_B.Encoder1_o1 = getTimerCounterValue
    (blink_led_simu_DW.obj_l.TimerHandle);

  /* MATLABSystem: '<S2>/Encoder1' */
  blink_led_simu_B.Encoder1_o2 = ouputDirectionOfCounter
    (blink_led_simu_DW.obj_l.TimerHandle);

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Sum: '<S2>/Minus'
   */
  if (blink_led_simu_B.Encoder1_o2) {
    rtb_PulseGenerator = (real_T)blink_led_simu_B.Encoder1_o1 -
      blink_led_simu_P.Constant_Value;
  } else {
    rtb_PulseGenerator = blink_led_simu_B.Encoder1_o1;
  }

  /* Outputs for Atomic SubSystem: '<S2>/Triggered Subsystem' */
  /* Gain: '<S5>/Gain' incorporates:
   *  Switch: '<S2>/Switch'
   */
  blink_led_simu_B.Gain = blink_led_simu_P.Gain_Gain * rtb_PulseGenerator;

  /* End of Outputs for SubSystem: '<S2>/Triggered Subsystem' */
  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  blink_led_simu_B.Divide = blink_led_simu_B.Gain /
    blink_led_simu_P.Constant1_Value;

  /* MATLABSystem: '<Root>/Encoder' */
  blink_led_simu_B.count = getTimerCounterValue
    (blink_led_simu_DW.obj.TimerHandle);

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
  blink_led_simu_M->Sizes.checksums[0] = (136901788U);
  blink_led_simu_M->Sizes.checksums[1] = (2699265801U);
  blink_led_simu_M->Sizes.checksums[2] = (1936744896U);
  blink_led_simu_M->Sizes.checksums[3] = (3520765107U);

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

  /* Start for MATLABSystem: '<S2>/Encoder1' */
  blink_led_simu_DW.obj_l.isInitialized = 0;
  blink_led_simu_DW.obj_l.matlabCodegenIsDeleted = false;
  blink_led_simu_SystemCore_setup(&blink_led_simu_DW.obj_l);

  /* Start for MATLABSystem: '<Root>/Encoder' */
  blink_led_simu_DW.obj.isInitialized = 0;
  blink_led_simu_DW.obj.matlabCodegenIsDeleted = false;
  blink_led_simu_SystemCore_setup(&blink_led_simu_DW.obj);
}

/* Model terminate function */
void blink_led_simu_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<S2>/Encoder1' */
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

  /* End of Terminate for MATLABSystem: '<S2>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!blink_led_simu_DW.obj.matlabCodegenIsDeleted) {
    blink_led_simu_DW.obj.matlabCodegenIsDeleted = true;
    if ((blink_led_simu_DW.obj.isInitialized == 1) &&
        blink_led_simu_DW.obj.isSetupComplete) {
      disableCounter(blink_led_simu_DW.obj.TimerHandle);
      disableTimerInterrupts(blink_led_simu_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(blink_led_simu_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(blink_led_simu_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
