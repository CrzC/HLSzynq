#include <stdio.h>
#include "platform.h"
#include "xgpio.h"
#include "xparameters.h"
#include "xil_printf.h"//la función menu se utiliza unicamente para desplegar las opciones para controlar al mux
//cabe mencionar que el orden de las funciones puede ser arbitrario y tambien lo que se pide
//para seleccionar cada operacion en este caso se utilziaron numeros,pueden ser letras tambien
//pero se tendrian que hacer cambios en otras partes del codigo.
void menu(){
	 print("Practica 1: ZYNQ + Modulo RTL \n\r");
	 print("Elija la compuerta logica a realizar \n\r");
	 print("	1 AND	\n\r");
	 print("	2 OR	\n\r");
	 print("	3 XOR	\n\r");
	 print("	4 NOR	\n\r");
}
//la funcion validacion unicamente corrobora que lo ingresado sea una opcion existente
unsigned char validacion (){
	unsigned char A,AA; // varaible que se obtendra del puerto serial (temporal y la que se regresa)
	int u;// variable para la condición de while
	u=2;
	while(u!=1){
		A=XUartPs_RecvByte(XPAR_PS7_UART_0_BASEADDR);
		if ((A=='1')||(A=='2')||(A=='3')||(A=='4')){
			u=1;// como se ingreso una oopcion valida se termina el ciclo haciendo u==1

			AA=A;;
		}else{
			print("Ingrese una opcion valida \n\r");// mensaje para el usuario
			u=2;// se mantiene el ciclo while
		}
	}
	return AA;
}
//igual es una funcion para validar sin embargo aca unicamente se toma en cuenta cuando
//se ingresa el numero 5
unsigned char validacion2 (){
	unsigned char b,bb; // varaible que se obtendra del puerto serial

		b=XUartPs_RecvByte(XPAR_PS7_UART_0_BASEADDR);
		if ((b=='5')||(b=' ')){
			bb=b;;
	}
	return bb;
}
//main es la función principal

int main()
{
    init_platform();//inicializar la plataforma.
    int o=1;//variable que se utilizara en un ciclo while
    XGpio seleccion,salida;//creacion de las isntancias seleccion y salida

    unsigned char sel,sel2;// variables donde se almacenaran las variables que retornan
    // de las funciones de validación
    int resultado; //variable donde se guarda lo que se lee de la salida del mux
    //inicilizacion de las entradas-salidas de proposito general
    //el GPIO_X debe coincidir con la numeracion del diagrama,es decir si la IP
    // axi_gpio_0 esta conectada con el selector del mux se le asigna la variable seleccion
    // para cambiar el nombre de la variable es en la seccion XGio linea 52
    XGpio_Initialize(&salida,XPAR_AXI_GPIO_0_DEVICE_ID);
    XGpio_Initialize(&seleccion,XPAR_AXI_GPIO_1_DEVICE_ID);//

    XGpio_SetDataDirection(&seleccion,1,0);  // instancia - canal - registro de direccion de datos (1 para entradas / 0 para salidas)
    XGpio_SetDataDirection(&salida,1,1);

    print("ya paso la inicializacion\n\r");


    while(1)
    {
    	menu();//llamar a la funcion menu
    	sel=validacion();//llamar a la funcion validacion y guardarla en la variable sel
    	o=1;//volver a crear el bucle de la funcion while(o==1)
    	//lo que se escribe en cada opcion depende del codigo en vhdl del mux
        switch (sel){
      	case '1':
      		XGpio_DiscreteWrite(&seleccion,1,0);// instancia - canal - dato
      	    break;
      	case '2':
      		     XGpio_DiscreteWrite(&seleccion,1,1);
      		break;
      	case '3':
      		XGpio_DiscreteWrite(&seleccion,1,2);
      		break;
      	case '4':
      		XGpio_DiscreteWrite(&seleccion,1,3);
      		break;

      	}
        print("5 para regresar al menu	\n\r");
        print("Ingrese cualquier caracter para que se imprima el resultado	\n\r");

    	while(o==1)//ciclo para imprimir el resultado
        {

    	    resultado=XGpio_DiscreteRead(&salida,1);//leer la salida y guardarla en resultado
    		xil_printf("Resultado : %d \n\r",resultado);//imprimir el resultado
    		sel2=validacion2();//llamar la segunda validacion
    		if (sel2=='5')
    		{
    			o=2;//romper el ciclo while
    		}
    	    }

    }
    cleanup_platform();
    return 0;
}

