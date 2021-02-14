#include <stdio.h>

char * hello(){
	char * b = "hello";
	return b;
}

char * world(){
	char * a = "world";
	return a;
}

int main(){
	printf("%s, %s", hello(), world());
	return 0;
}
