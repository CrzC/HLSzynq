
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <xsuma.h>

XSuma doSum;
XSuma_Config *doSumCfg;

void iniciar_Suma(){
	int status=0;
	doSumCfg = XSuma_LookupConfig(XPAR_SUMA_0_DEVICE_ID);
	if (doSumCfg){
		status = XSuma_CfgInitialize(&doSum,doSumCfg);
		if (status != XST_SUCCESS){
			printf("Ha ocurrido un error al iniciar la IP  :( \n");
		}
	}
}
unsigned int float_a_u32(float val){
	unsigned int resultado;
	union float_bytes{
		float v;unsigned char bytes[4];
	}data;
	data.v = val;
	resultado = (data.bytes[3] << 24) + (data.bytes[2] << 16) + (data.bytes[1] << 8) + (data.bytes[0]);
	return resultado;
}

float u32_a_float(unsigned int val){
	union{
		float val_float;
		unsigned char bytes[4];
	}data;
	data.bytes[3] = (val >> (8*3)) & 0xff;
	data.bytes[2] = (val >> (8*2)) & 0xff;
	data.bytes[1] = (val >> (8*1)) & 0xff;
	data.bytes[0] = (val >> (8*0)) & 0xff;
	return data.val_float;
}
int main()
{
	float a;
	float b;
	float c = 0;
    init_platform();
    iniciar_Suma();
    while(1){
    printf("----------Programa para utilizar la IP - Suma \n");
    printf("         C = A + B \n");
    printf("Donde C, A y B son datos tipo float \n");
    printf("Ingrese valor de A : \n");
    scanf("%f",&a);
    printf("Ingrese valor de B : \n");
    scanf("%f",&b);
    printf("Enviando valores a la IP\n");
    XSuma_Set_a(&doSum,float_a_u32(a));
    XSuma_Set_b(&doSum,float_a_u32(b));
    c = u32_a_float(XSuma_Get_c_o(&doSum));
    printf("C = %f \n",c);
    XSuma_Start(&doSum);
    while(!XSuma_IsDone(&doSum));
    c = u32_a_float(XSuma_Get_c_o(&doSum));
    printf(" A + B = C \n ");
    printf(" %f + %f = %f \n ",a,b,c);
    }
    cleanup_platform();
    return 0;
}

