// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XSUMA_H
#define XSUMA_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xsuma_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Bus_a_BaseAddress;
} XSuma_Config;
#endif

typedef struct {
    u32 Bus_a_BaseAddress;
    u32 IsReady;
} XSuma;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XSuma_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XSuma_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XSuma_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XSuma_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XSuma_Initialize(XSuma *InstancePtr, u16 DeviceId);
XSuma_Config* XSuma_LookupConfig(u16 DeviceId);
int XSuma_CfgInitialize(XSuma *InstancePtr, XSuma_Config *ConfigPtr);
#else
int XSuma_Initialize(XSuma *InstancePtr, const char* InstanceName);
int XSuma_Release(XSuma *InstancePtr);
#endif

void XSuma_Start(XSuma *InstancePtr);
u32 XSuma_IsDone(XSuma *InstancePtr);
u32 XSuma_IsIdle(XSuma *InstancePtr);
u32 XSuma_IsReady(XSuma *InstancePtr);
void XSuma_EnableAutoRestart(XSuma *InstancePtr);
void XSuma_DisableAutoRestart(XSuma *InstancePtr);

void XSuma_Set_a(XSuma *InstancePtr, u32 Data);
u32 XSuma_Get_a(XSuma *InstancePtr);
void XSuma_Set_b(XSuma *InstancePtr, u32 Data);
u32 XSuma_Get_b(XSuma *InstancePtr);
void XSuma_Set_c_i(XSuma *InstancePtr, u32 Data);
u32 XSuma_Get_c_i(XSuma *InstancePtr);
u32 XSuma_Get_c_o(XSuma *InstancePtr);
u32 XSuma_Get_c_o_vld(XSuma *InstancePtr);

void XSuma_InterruptGlobalEnable(XSuma *InstancePtr);
void XSuma_InterruptGlobalDisable(XSuma *InstancePtr);
void XSuma_InterruptEnable(XSuma *InstancePtr, u32 Mask);
void XSuma_InterruptDisable(XSuma *InstancePtr, u32 Mask);
void XSuma_InterruptClear(XSuma *InstancePtr, u32 Mask);
u32 XSuma_InterruptGetEnabled(XSuma *InstancePtr);
u32 XSuma_InterruptGetStatus(XSuma *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
