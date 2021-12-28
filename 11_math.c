#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_pow(double number, double power);

int main(void)
{
    double number = 2;
    double power = 2;
    calc_pow(number, power);
    return (0);
}

void calc_pow(double number, double power)
{
    printf("%f pow %f = %f", number, power, pow(number, power));
}
