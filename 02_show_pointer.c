#include <stdio.h>
#include <stdlib.h>

int i=10;
int *P_i = &i;

int main(){
	printf("The value of the variable is %d\nand his adress value is %d",i, &i);
	printf("\n\n");
	printf("the address of the pointer is %d\nand his value is %d",P_i, *P_i);
	return 0;
}