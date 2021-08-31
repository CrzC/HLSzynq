// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xsuma.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XSuma_CfgInitialize(XSuma *InstancePtr, XSuma_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Bus_a_BaseAddress = ConfigPtr->Bus_a_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XSuma_Start(XSuma *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_AP_CTRL) & 0x80;
    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_AP_CTRL, Data | 0x01);
}

u32 XSuma_IsDone(XSuma *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XSuma_IsIdle(XSuma *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XSuma_IsReady(XSuma *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XSuma_EnableAutoRestart(XSuma *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_AP_CTRL, 0x80);
}

void XSuma_DisableAutoRestart(XSuma *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_AP_CTRL, 0);
}

void XSuma_Set_a(XSuma *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_A_DATA, Data);
}

u32 XSuma_Get_a(XSuma *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_A_DATA);
    return Data;
}

void XSuma_Set_b(XSuma *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_B_DATA, Data);
}

u32 XSuma_Get_b(XSuma *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_B_DATA);
    return Data;
}

void XSuma_Set_c_i(XSuma *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_C_I_DATA, Data);
}

u32 XSuma_Get_c_i(XSuma *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_C_I_DATA);
    return Data;
}

u32 XSuma_Get_c_o(XSuma *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_C_O_DATA);
    return Data;
}

u32 XSuma_Get_c_o_vld(XSuma *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_C_O_CTRL);
    return Data & 0x1;
}

void XSuma_InterruptGlobalEnable(XSuma *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_GIE, 1);
}

void XSuma_InterruptGlobalDisable(XSuma *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_GIE, 0);
}

void XSuma_InterruptEnable(XSuma *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_IER);
    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_IER, Register | Mask);
}

void XSuma_InterruptDisable(XSuma *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_IER);
    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_IER, Register & (~Mask));
}

void XSuma_InterruptClear(XSuma *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSuma_WriteReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_ISR, Mask);
}

u32 XSuma_InterruptGetEnabled(XSuma *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_IER);
}

u32 XSuma_InterruptGetStatus(XSuma *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSuma_ReadReg(InstancePtr->Bus_a_BaseAddress, XSUMA_BUS_A_ADDR_ISR);
}

