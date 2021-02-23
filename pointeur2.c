#include <stdio.h>
#include <stdlib.h>

int changeValue(int *valueToChange);

int main(){
    int i = 5;
    int *Pi =&i;

    printf("the value of i is %d and his address is %p\n", i, &i);
    printf("The value of pointer P for i is %p and his value is %d\n", Pi, *Pi);

    changeValue(Pi);
    printf("Now the value of i is %d\n", i);
    printf("The new value of Pi is %p and the value is %d", Pi, *Pi);
    return 0;
}

int changeValue(int *valueToChange){
    *valueToChange = 10;
    return 0;
}