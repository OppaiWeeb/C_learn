#include <stdlib.h>
#include <stdio.h>

void change_temp(float * temp, float * final_temp){
	*final_temp = *temp * 1.8 +32;
}

int main(int argc, char ** argv){
	float temp;
	float final_temp;
	printf("Enter a temperature value in °C:");
	scanf("%f", &temp);
	printf("the temp in °C is: %g\n", temp);

	printf("======================\n");
	change_temp(&temp, &final_temp);
	printf("The temp in °C is: %g\nThe temp in °F is: %g", temp, final_temp );
}