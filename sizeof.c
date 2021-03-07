#include <stdio.h>
#include <stdlib.h>

void main(){
    printf("char: %d octets\n", sizeof(char));
    printf("int: %d octets\n", sizeof(int));
    printf("long: %d octets\n", sizeof(long));
    printf("double: %d octets\n", sizeof(double));
    printf("float: %d octets\n", sizeof(float));
}