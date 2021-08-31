// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xsuma.h"

extern XSuma_Config XSuma_ConfigTable[];

XSuma_Config *XSuma_LookupConfig(u16 DeviceId) {
	XSuma_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XSUMA_NUM_INSTANCES; Index++) {
		if (XSuma_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XSuma_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSuma_Initialize(XSuma *InstancePtr, u16 DeviceId) {
	XSuma_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSuma_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSuma_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

