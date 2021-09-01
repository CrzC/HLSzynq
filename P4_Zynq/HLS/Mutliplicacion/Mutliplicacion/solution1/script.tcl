############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Mutliplicacion
set_top suma
add_files main_suma.cpp
add_files sumah.h
add_files -tb testmult.cpp
open_solution "solution1"
set_part {xc7z020-clg400-1} -tool vivado
create_clock -period 10 -name default
config_export -format ip_catalog -rtl vhdl -vendor crzc
#source "./Mutliplicacion/solution1/directives.tcl"
csim_design -clean
csynth_design
cosim_design -trace_level port -tool xsim
export_design -flow syn -rtl vhdl -format ip_catalog -vendor "crzc"
