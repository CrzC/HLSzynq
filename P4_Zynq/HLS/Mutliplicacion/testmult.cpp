

#include <stdio.h>
#include "sumah.h"


int main()
{
    dtype a,b,c;
    a=1.125;
    b=6.5;
    c = 0;
    for (int i = 0; i<3;i++){
    	a=a+i;
    	b=b+i;
    	suma (&a,&b,&c);
    	printf (" %f  +  %f  = %f",a,b,c);
    	printf("\n");

    }

return 0;
}
