# HLSzynq
Este trabajo fue generado durante mis prácticas Profesionales en la Facultad de Físico Matemáticas de la BUAP
## Sobre el trabajo:
Todas las practicas se realizaron en la tarjeta  [PYNQ-Z2](https://www.tul.com.tw/productspynq-z2.html) y se centran en el uso de:
1. la Sintesis de Alto Nivel (HLS,por sus siglas en ingles)
2. Integración de IP's con el PS (Zynq)
3. Uso del framework [PYNQ](http://www.pynq.io/home.html)

## Practicas 
1. Zynq con Módulo RTL
2.  Primer boot en la tarjeta PYNQ -Z2 
3.  Crear un Overlay
4.  Crear IP con Vitis HLS
5.  Overlay con IP's de HLS
6.  Suma de Matrices
7.  Multiplicación de matrices
8.  Uso del Axi Timer

## Estructura de las carpetas

Las practicas estan en carpetas que tienen la siguiente estrucutra:

```bash
Nombre de la practica
    ├── SDK/         # Codigo en c o C++ 
    ├── PYNQ/                     # archivos .bit y .hwh y codigo en python
    └── vivado/          # archivos referente a vivado
        ├── hdl/      # archivos en vhdl o verilog
        ├── ip_repo/  #  ips 
        ├── constraints/ # archivo xdc
        ├── practica.tcl  
      
```

## Glosario
1. RTL: Register Transfer Level,es un nivel de abstracción relativamente bajo que permite la descripción de un circuito digital específico. RTL también se puede usar para referirse a un lenguaje de descripción de hardware (VHDL, Verilog, SystemC), donde el código "RTL" es un nivel de abstracción más bajo que el código de "Nivel de comportamiento".
2. Overlay: Los Overlay, o bibliotecas de hardware, son diseños de FPGA programables / configurables que amplían la aplicación del usuario desde el sistema de procesamiento (PS) Zynq a la lógica programable (PL).
3.  IP: Una unidad reutilizable de diseño de disposición lógica. Los núcleos IP se pueden utilizar como bloques de construcción dentro de una FPGA.
