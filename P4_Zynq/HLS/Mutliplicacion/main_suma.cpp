
#include "sumah.h"

void suma (dtype *a,dtype *b,dtype *c)
{
#pragma HLS INTERFACE s_axilite port=a bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=b bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=c bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=return bundle=BUS_A

	*c = *a + *b;

}
