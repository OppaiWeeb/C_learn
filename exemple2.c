#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)

{
    
    int a;
    if(argc!= 2) 

    {printf("usage:%s nombre\n",argv[0]);
    exit(1);
    
    }
    
a=atoi(argv[1]);
printf("\n");
bonjour(a);
revoir(--a);
return 0;

}