#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){

	//When we play with array, we need to imagine that the first element of the array is not the first it's the zero and the last one is not the last it's the last -1
	//also we init an array like that
	int array[4] = {0, 2, 4, 5};

	//and guess what else is an array, yep a string is an array
	char strin[4] = "test";

	// we show element of an array by it index 
	printf("array first position is %d\n", array[0]);
	printf("the third letter of the string strin is %c\n", strin[2]);
	return 0;
}
