/**
  ******************************************************************************
  * @file    stm32f7xx_quadspi.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the QUADSPI  
  *          firmware library.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __stm32f7XX_QUADSPI_H
#define __stm32f7XX_QUADSPI_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx.h"
#include "stm32f7xx_rcc.h"
/** @addtogroup stm32f7xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup QUADSPI
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** 
  * @brief  QUADSPI Communication Configuration Init structure definition  
  */

typedef struct
{
  
  uint32_t QUADSPI_ComConfig_FMode;            /* Specifies the Functional Mode
                                          This parameter can be a value of @ref QUADSPI_ComConfig_Functional_Mode*/  
	
  uint32_t QUADSPI_ComConfig_DDRMode;          /* Specifies the Double Data Rate Mode
                                          This parameter can be a value of @ref QUADSPI_ComConfig_DoubleDataRateMode*/
	
  uint32_t QUADSPI_ComConfig_DHHC;            /* Specifies the Delay Half Hclk Cycle
                                          This parameter can be a value of @ref QUADSPI_ComConfig_DelayHalfHclkCycle*/
  
  uint32_t QUADSPI_ComConfig_SIOOMode;         /* Specifies the Send Instruction Only Once Mode
                                          This parameter can be a value of @ref QUADSPI_ComConfig_SendInstructionOnlyOnceMode*/
  
  uint32_t QUADSPI_ComConfig_DMode;            /* Specifies the Data Mode
                                          This parameter can be a value of @ref QUADSPI_ComConfig_DataMode*/
  
  uint32_t QUADSPI_ComConfig_DummyCycles;      /* Specifies the Number of Dummy Cycles.
                                           This parameter can be a number between 0x00 and 0x1F */             

  uint32_t QUADSPI_ComConfig_ABSize;           /* Specifies the Alternate Bytes Size
                                          This parameter can be a value of @ref QUADSPI_ComConfig_AlternateBytesSize*/ 

  uint32_t QUADSPI_ComConfig_ABMode;           /* Specifies the Alternate Bytes Mode
                                          This parameter can be a value of @ref QUADSPI_ComConfig_AlternateBytesMode*/     
 
  uint32_t QUADSPI_ComConfig_ADSize;           /* Specifies the Address Size
                                          This parameter can be a value of @ref QUADSPI_ComConfig_AddressSize*/

  uint32_t QUADSPI_ComConfig_ADMode;           /* Specifies the Address Mode
                                          This parameter can be a value of @ref QUADSPI_ComConfig_AddressMode*/
  
  uint32_t QUADSPI_ComConfig_IMode;            /* Specifies the Instruction Mode
                                          This parameter can be a value of @ref QUADSPI_ComConfig_InstructionMode*/

  uint32_t QUADSPI_ComConfig_Ins;      /* Specifies the Instruction Mode
                                          This parameter can be a value of @ref QUADSPI_ComConfig_Instruction*/
  
}QUADSPI_ComConfig_InitTypeDef;

/** 
  * @brief  QUADSPI Init structure definition  
  */

typedef struct
{
  uint32_t QUADSPI_SShift;    /* Specifies the Sample Shift
                              This parameter can be a value of @ref QUADSPI_Sample_Shift*/

  uint32_t QUADSPI_Prescaler; /* Specifies the prescaler value used to divide the QUADSPI clock.
                              This parameter can be a number between 0x00 and 0xFF */ 

  uint32_t QUADSPI_CKMode;    /* Specifies the Clock Mode
                              This parameter can be a value of @ref QUADSPI_Clock_Mode*/

  uint32_t QUADSPI_CSHTime;   /* Specifies the Chip Select High Time
                              This parameter can be a value of @ref QUADSPI_ChipSelectHighTime*/   
 
  uint32_t QUADSPI_FSize;     /* Specifies the Flash Size.
                               QUADSPI_FSize+1 is effectively the number of address bits required to address the flash memory.
                               The flash capacity can be up to 4GB (addressed using 32 bits) in indirect mode, but the
                               addressable space in memory-mapped mode is limited to 512MB
                               This parameter can be a number between 0x00 and 0x1F */
  uint32_t QUADSPI_FSelect;   /* Specifies the Flash which will be used,
                                 This parameter can be a value of @ref QUADSPI_Fash_Select*/
  uint32_t QUADSPI_DFlash;   /* Specifies the Dual Flash Mode State
                                 This parameter can be a value of @ref QUADSPI_Dual_Flash*/
}QUADSPI_InitTypeDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup QUADSPI_Exported_Constants
  * @{
  */

/** @defgroup QUADSPI_Sample_Shift 
  * @{
  */

#define QUADSPI_SShift_NoShift                        ((uint32_t)0x00000000)
#define QUADSPI_SShift_HalfCycleShift                 ((uint32_t)QUADSPI_CR_SSHIFT_0)
#define QUADSPI_SShift_OneCycleShift                  ((uint32_t)QUADSPI_CR_SSHIFT_1)
#define QUADSPI_SShift_OneAndHalfCycleShift           ((uint32_t)QUADSPI_CR_SSHIFT)
#define IS_QUADSPI_SSHIFT(SSHIFT)      (((SSHIFT) == QUADSPI_SShift_NoShift) || \
                                        ((SSHIFT) == QUADSPI_SShift_HalfCycleShift) || \
                                        ((SSHIFT) == QUADSPI_SShift_OneCycleShift) || \
                                        ((SSHIFT) == QUADSPI_SShift_OneAndHalfCycleShift))

/**
  * @}
  */
  
/** @defgroup QUADSPI_Prescaler 
  * @{
  */

#define IS_QUADSPI_PRESCALER(PRESCALER) (((PRESCALER) <= 0xFF))

/**
  * @}
  */

/** @defgroup QUADSPI_Clock_Mode 
  * @{
  */

#define QUADSPI_CKMode_Mode0           ((uint32_t)0x00000000)
#define QUADSPI_CKMode_Mode3           ((uint32_t)QUADSPI_DCR_CKMODE)
#define IS_QUADSPI_CKMODE(CKMode) (((CKMode) == QUADSPI_CKMode_Mode0) || \
                                   ((CKMode) == QUADSPI_CKMode_Mode3))
/**
  * @}
  */
  
/** @defgroup QUADSPI_ChipSelectHighTime 
  * @{
  */

#define QUADSPI_CSHTime_1Cycle           ((uint32_t)0x00000000)
#define QUADSPI_CSHTime_2Cycle           ((uint32_t)QUADSPI_DCR_CSHT_0)
#define QUADSPI_CSHTime_3Cycle           ((uint32_t)QUADSPI_DCR_CSHT_1)
#define QUADSPI_CSHTime_4Cycle           ((uint32_t)QUADSPI_DCR_CSHT_0 | QUADSPI_DCR_CSHT_1)
#define QUADSPI_CSHTime_5Cycle           ((uint32_t)QUADSPI_DCR_CSHT_2)
#define QUADSPI_CSHTime_6Cycle           ((uint32_t)QUADSPI_DCR_CSHT_2 | QUADSPI_DCR_CSHT_0)
#define QUADSPI_CSHTime_7Cycle           ((uint32_t)QUADSPI_DCR_CSHT_2 | QUADSPI_DCR_CSHT_1)
#define QUADSPI_CSHTime_8Cycle           ((uint32_t)QUADSPI_DCR_CSHT)
#define IS_QUADSPI_CSHTIME(CSHTIME)    (((CSHTIME) == QUADSPI_CSHTime_1Cycle) || \
                                        ((CSHTIME) == QUADSPI_CSHTime_2Cycle) || \
                                        ((CSHTIME) == QUADSPI_CSHTime_3Cycle) || \
                                        ((CSHTIME) == QUADSPI_CSHTime_4Cycle) || \
                                        ((CSHTIME) == QUADSPI_CSHTime_5Cycle) || \
                                        ((CSHTIME) == QUADSPI_CSHTime_6Cycle) || \
                                        ((CSHTIME) == QUADSPI_CSHTime_7Cycle) || \
                                        ((CSHTIME) == QUADSPI_CSHTime_8Cycle))
/**
  * @}
  */
  
/** @defgroup QUADSPI_Flash_Size 
  * @{
  */

#define IS_QUADSPI_FSIZE(FSIZE)         (((FSIZE) <= 0x1F))

/**
  * @}
  */
	
/** @defgroup QUADSPI_Fash_Select 
  * @{
  */

#define QUADSPI_FSelect_1           ((uint32_t)0x00000000)
#define QUADSPI_FSelect_2           ((uint32_t)QUADSPI_CR_FSEL)
#define IS_QUADSPI_FSEL(FLA)      (((FLA) == QUADSPI_FSelect_1) || \
                                   ((FLA) == QUADSPI_FSelect_2))
/**
  * @}
  */
	
/** @defgroup QUADSPI_Dual_Flash 
  * @{
  */

#define QUADSPI_DFlash_Disable           ((uint32_t)0x00000000)
#define QUADSPI_DFlash_Enable            ((uint32_t)QUADSPI_CR_DFM)
#define IS_QUADSPI_DFM(FLA)       (((FLA) == QUADSPI_DFlash_Enable) || \
                                   ((FLA) == QUADSPI_DFlash_Disable))
/**
  * @}
  */

/** @defgroup QUADSPI_ComConfig_Functional_Mode 
  * @{
  */
  
#define QUADSPI_ComConfig_FMode_Indirect_Write     ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_FMode_Indirect_Read      ((uint32_t)QUADSPI_CCR_FMODE_0)
#define QUADSPI_ComConfig_FMode_Auto_Polling       ((uint32_t)QUADSPI_CCR_FMODE_1)
#define QUADSPI_ComConfig_FMode_Memory_Mapped      ((uint32_t)QUADSPI_CCR_FMODE)
#define IS_QUADSPI_FMODE(FMODE)                  (((FMODE) == QUADSPI_ComConfig_FMode_Indirect_Write) || \
                                                  ((FMODE) == QUADSPI_ComConfig_FMode_Indirect_Read) || \
                                                  ((FMODE) == QUADSPI_ComConfig_FMode_Auto_Polling) || \
                                                  ((FMODE) == QUADSPI_ComConfig_FMode_Memory_Mapped))
/**
  * @}
  */
	
/** @defgroup QUADSPI_ComConfig_DoubleDataRateMode 
  * @{
  */

#define QUADSPI_ComConfig_DDRMode_Disable           ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_DDRMode_Enable            ((uint32_t)QUADSPI_CCR_DDRM)
#define IS_QUADSPI_DDRMODE(DDRMODE)    (((DDRMODE) == QUADSPI_ComConfig_DDRMode_Disable) || \
                                        ((DDRMODE) == QUADSPI_ComConfig_DDRMode_Enable))
/**
  * @}
  */
	
/** @defgroup QUADSPI_ComConfig_DoubleDataRateMode 
  * @{
  */

#define QUADSPI_ComConfig_DHHC_Disable           ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_DHHC_Enable            ((uint32_t)QUADSPI_CCR_DHHC)
#define IS_QUADSPI_DHHC(DHHC)          (((DHHC) == QUADSPI_ComConfig_DHHC_Disable) || \
                                        ((DHHC) == QUADSPI_ComConfig_DHHC_Enable))
/**
  * @}
  */
  
/** @defgroup QUADSPI_ComConfig_SendInstructionOnlyOnceMode 
  * @{
  */

#define QUADSPI_ComConfig_SIOOMode_Disable           ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_SIOOMode_Enable            ((uint32_t)QUADSPI_CCR_SIOO)
#define IS_QUADSPI_SIOOMODE(SIOOMODE)    (((SIOOMODE) == QUADSPI_ComConfig_SIOOMode_Disable) || \
                                          ((SIOOMODE) == QUADSPI_ComConfig_SIOOMode_Enable))
/**
  * @}
  */  

/** @defgroup QUADSPI_ComConfig_DataMode 
  * @{
  */

#define QUADSPI_ComConfig_DMode_NoData          ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_DMode_1Line           ((uint32_t)QUADSPI_CCR_DMODE_0)
#define QUADSPI_ComConfig_DMode_2Line           ((uint32_t)QUADSPI_CCR_DMODE_1)
#define QUADSPI_ComConfig_DMode_4Line           ((uint32_t)QUADSPI_CCR_DMODE)
#define IS_QUADSPI_DMODE(DMODE)        (((DMODE) == QUADSPI_ComConfig_DMode_NoData) || \
                                        ((DMODE) == QUADSPI_ComConfig_DMode_1Line) || \
                                        ((DMODE) == QUADSPI_ComConfig_DMode_2Line) || \
                                        ((DMODE) == QUADSPI_ComConfig_DMode_4Line))
/**
  * @}
  */
  
/** @defgroup QUADSPI_ComConfig_AlternateBytesSize 
  * @{
  */

#define QUADSPI_ComConfig_ABSize_8bit            ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_ABSize_16bit           ((uint32_t)QUADSPI_CCR_ABSIZE_0)
#define QUADSPI_ComConfig_ABSize_24bit           ((uint32_t)QUADSPI_CCR_ABSIZE_1)
#define QUADSPI_ComConfig_ABSize_32bit           ((uint32_t)QUADSPI_CCR_ABSIZE)
#define IS_QUADSPI_ABSIZE(ABSIZE)      (((ABSIZE) == QUADSPI_ComConfig_ABSize_8bit) || \
                                        ((ABSIZE) == QUADSPI_ComConfig_ABSize_16bit) || \
                                        ((ABSIZE) == QUADSPI_ComConfig_ABSize_24bit) || \
                                        ((ABSIZE) == QUADSPI_ComConfig_ABSize_32bit))
/**
  * @}
  */
  
/** @defgroup QUADSPI_ComConfig_AlternateBytesMode 
* @{
*/

#define QUADSPI_ComConfig_ABMode_NoAlternateByte          ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_ABMode_1Line                    ((uint32_t)QUADSPI_CCR_ABMODE_0)
#define QUADSPI_ComConfig_ABMode_2Line                    ((uint32_t)QUADSPI_CCR_ABMODE_1)
#define QUADSPI_ComConfig_ABMode_4Line                    ((uint32_t)QUADSPI_CCR_ABMODE)
#define IS_QUADSPI_ABMODE(ABMODE)      (((ABMODE) == QUADSPI_ComConfig_ABMode_NoAlternateByte) || \
                                        ((ABMODE) == QUADSPI_ComConfig_ABMode_1Line) || \
                                        ((ABMODE) == QUADSPI_ComConfig_ABMode_2Line) || \
                                        ((ABMODE) == QUADSPI_ComConfig_ABMode_4Line))
/**
  * @}
  */
  
/** @defgroup QUADSPI_ComConfig_AddressSize 
  * @{
  */

#define QUADSPI_ComConfig_ADSize_8bit            ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_ADSize_16bit           ((uint32_t)QUADSPI_CCR_ADSIZE_0)
#define QUADSPI_ComConfig_ADSize_24bit           ((uint32_t)QUADSPI_CCR_ADSIZE_1)
#define QUADSPI_ComConfig_ADSize_32bit           ((uint32_t)QUADSPI_CCR_ADSIZE)
#define IS_QUADSPI_ADSIZE(ADSIZE)      (((ADSIZE) == QUADSPI_ComConfig_ADSize_8bit) || \
                                        ((ADSIZE) == QUADSPI_ComConfig_ADSize_16bit) || \
                                        ((ADSIZE) == QUADSPI_ComConfig_ADSize_24bit) || \
                                        ((ADSIZE) == QUADSPI_ComConfig_ADSize_32bit))
/**
  * @}
  */
  
/** @defgroup QUADSPI_ComConfig_AddressMode 
* @{
*/

#define QUADSPI_ComConfig_ADMode_NoAddress          ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_ADMode_1Line              ((uint32_t)QUADSPI_CCR_ADMODE_0)
#define QUADSPI_ComConfig_ADMode_2Line              ((uint32_t)QUADSPI_CCR_ADMODE_1)
#define QUADSPI_ComConfig_ADMode_4Line              ((uint32_t)QUADSPI_CCR_ADMODE)
#define IS_QUADSPI_ADMODE(ADMODE)        (((ADMODE) == QUADSPI_ComConfig_ADMode_NoAddress) || \
                                          ((ADMODE) == QUADSPI_ComConfig_ADMode_1Line) || \
                                          ((ADMODE) == QUADSPI_ComConfig_ADMode_2Line) || \
                                          ((ADMODE) == QUADSPI_ComConfig_ADMode_4Line))
/**
  * @}
  */  
  
/** @defgroup QUADSPI_ComConfig_InstructionMode 
* @{
*/

#define QUADSPI_ComConfig_IMode_NoInstruction          ((uint32_t)0x00000000)
#define QUADSPI_ComConfig_IMode_1Line                  ((uint32_t)QUADSPI_CCR_IMODE_0)
#define QUADSPI_ComConfig_IMode_2Line                  ((uint32_t)QUADSPI_CCR_IMODE_1)
#define QUADSPI_ComConfig_IMode_4Line                  ((uint32_t)QUADSPI_CCR_IMODE)
#define IS_QUADSPI_IMODE(IMODE)        (((IMODE) == QUADSPI_ComConfig_IMode_NoInstruction) || \
                                        ((IMODE) == QUADSPI_ComConfig_IMode_1Line) || \
                                        ((IMODE) == QUADSPI_ComConfig_IMode_2Line) || \
                                        ((IMODE) == QUADSPI_ComConfig_IMode_4Line))
/**
  * @}
  */

/** @defgroup QUADSPI_ComConfig_Instruction 
  * @{
  */

#define IS_QUADSPI_INSTRUCTION(INSTRUCTION)           ((INSTRUCTION) <= 0xFF) 
/**
  * @}
  */ 

/** @defgroup QUADSPI_InterruptsDefinition 
  * @{
  */

#define QUADSPI_IT_TO                  QUADSPI_CR_TOIE
#define QUADSPI_IT_SM                  QUADSPI_CR_SMIE
#define QUADSPI_IT_FT                  QUADSPI_CR_FTIE
#define QUADSPI_IT_TC                  QUADSPI_CR_TCIE
#define QUADSPI_IT_TE                  QUADSPI_CR_TEIE

#define IS_QUADSPI_CONFIG_IT(IT) ((((IT) & 0xFFE0FFFF) == 0) && ((IT) != 0 ))

#define IS_QUADSPI_GET_IT(IT)    (((IT) == QUADSPI_IT_TO) || \
                                  ((IT) == QUADSPI_IT_SM) || \
                                  ((IT) == QUADSPI_IT_FT) || \
                                  ((IT) == QUADSPI_IT_TC) || \
                                  ((IT) == QUADSPI_IT_TE))

/**
  * @}
  */
  
/** @defgroup QUADSPI_FlagsDefinition 
  * @{
  */

#define QUADSPI_FLAG_TO                  QUADSPI_SR_TOF
#define QUADSPI_FLAG_SM                  QUADSPI_SR_SMF
#define QUADSPI_FLAG_FT                  QUADSPI_SR_FTF
#define QUADSPI_FLAG_TC                  QUADSPI_SR_TCF
#define QUADSPI_FLAG_TE                  QUADSPI_SR_TEF
#define QUADSPI_FLAG_BUSY                QUADSPI_SR_BUSY

#define IS_QUADSPI_GET_FLAG(FLAG)     (((FLAG) == QUADSPI_FLAG_TO) || \
                                       ((FLAG) == QUADSPI_FLAG_SM) || \
                                       ((FLAG) == QUADSPI_FLAG_FT) || \
                                       ((FLAG) == QUADSPI_FLAG_TC) || \
                                       ((FLAG) == QUADSPI_FLAG_TE) || \
                                       ((FLAG) == QUADSPI_FLAG_BUSY))
/**
  * @}
  */
  
/** @defgroup QUADSPI_FlagClearDefinition 
  * @{
  */

#define QUADSPI_FCLEAR_TO                  QUADSPI_FCR_CTOF
#define QUADSPI_FCLEAR_SM                  QUADSPI_FCR_CSMF
#define QUADSPI_FCLEAR_TC                  QUADSPI_FCR_CTCF
#define QUADSPI_FCLEAR_TE                  QUADSPI_FCR_CTEF

#define IS_QUADSPI_CLEAR_FLAG(FLAG)      ((((FLAG) & 0xFFFFFFE4) == 0) && ((FLAG) != 0))  

/**
  * @}
  */
  
/** @defgroup QUADSPI_Polling_Match_Mode 
  * @{
  */

#define QUADSPI_PMM_AND                 ((uint32_t)0x00000000)
#define QUADSPI_PMM_OR                  ((uint32_t)QUADSPI_CR_PMM)

#define IS_QUADSPI_PMM(PMM)              (((PMM) == QUADSPI_PMM_AND) || \
                                          ((PMM) == QUADSPI_PMM_OR)) 
/**
  * @}
  */
  
/** @defgroup QUADSPI_Polling_Interval 
  * @{
  */

#define IS_QUADSPI_PIR(PIR)                 ((PIR) <= QUADSPI_PIR_INTERVAL) 
/**
  * @}
  */
  
/** @defgroup QUADSPI_Timeout 
  * @{
  */

#define IS_QUADSPI_TIMEOUT(TIMEOUT)         ((TIMEOUT) <= QUADSPI_LPTR_TIMEOUT) 
/**
  * @}
  */
  
/** @defgroup QUADSPI_DummyCycle 
  * @{
  */

#define IS_QUADSPI_DCY(DCY)                       ((DCY) <= 0x1F) 
/**
  * @}
  */
  
/** @defgroup QUADSPI_FIFOThreshold 
  * @{
  */

#define IS_QUADSPI_FIFOTHRESHOLD(FIFOTHRESHOLD)        ((FIFOTHRESHOLD) <= 0x0F) 
/**
  * @}
  */  

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Initialization and Configuration functions *********************************/
void QUADSPI_DeInit(void);
void QUADSPI_Init(QUADSPI_InitTypeDef* QUADSPI_InitStruct);
void QUADSPI_StructInit(QUADSPI_InitTypeDef* QUADSPI_InitStruct);
void QUADSPI_ComConfig_Init(QUADSPI_ComConfig_InitTypeDef* QUADSPI_ComConfig_InitStruct);
void QUADSPI_ComConfig_StructInit(QUADSPI_ComConfig_InitTypeDef* QUADSPI_ComConfig_InitStruct);
void QUADSPI_Cmd(FunctionalState NewState);
void QUADSPI_AutoPollingMode_Config(uint32_t QUADSPI_Match, uint32_t QUADSPI_Mask , uint32_t QUADSPI_Match_Mode);
void QUADSPI_AutoPollingMode_SetInterval(uint32_t QUADSPI_Interval);
void QUADSPI_MemoryMappedMode_SetTimeout(uint32_t QUADSPI_Timeout);
void QUADSPI_SetAddress(uint32_t QUADSPI_Address);
void QUADSPI_SetAlternateByte(uint32_t QUADSPI_AlternateByte);
void QUADSPI_SetFIFOThreshold(uint32_t QUADSPI_FIFOThreshold);
void QUADSPI_SetDataLength(uint32_t QUADSPI_DataLength);
void QUADSPI_TimeoutCounterCmd(FunctionalState NewState);
void QUADSPI_AutoPollingModeStopCmd(FunctionalState NewState);
void QUADSPI_AbortRequest(void);
void QUADSPI_DualFlashMode_Cmd(FunctionalState NewState);

/* Data transfers functions ***************************************************/
void     QUADSPI_SendData8(uint8_t Data);
void     QUADSPI_SendData16(uint16_t Data);
void     QUADSPI_SendData32(uint32_t Data);
uint8_t  QUADSPI_ReceiveData8(void);
uint16_t QUADSPI_ReceiveData16(void);
uint32_t QUADSPI_ReceiveData32(void);

/* DMA transfers management functions *****************************************/
void QUADSPI_DMACmd(FunctionalState NewState);

/* Interrupts and flags management functions **********************************/
void       QUADSPI_ITConfig(uint32_t QUADSPI_IT, FunctionalState NewState);
uint32_t   QUADSPI_GetFIFOLevel(void);
FlagStatus QUADSPI_GetFlagStatus(uint32_t QUADSPI_FLAG);
void       QUADSPI_ClearFlag(uint32_t QUADSPI_FLAG);
ITStatus   QUADSPI_GetITStatus(uint32_t QUADSPI_IT);
void       QUADSPI_ClearITPendingBit(uint32_t QUADSPI_IT);
uint32_t   QUADSPI_GetFMode(void);

#ifdef __cplusplus
}
#endif

#endif /*__STM32f7XX_QUADSPI_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
