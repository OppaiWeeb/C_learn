#include <stdio.h>
#include <stdlib.h>

void hello_world(char *word);

void hello_world(char *word){
	printf("%s", word);
}

int main(int argc, char const *argv[]){
	char  str[128];
	fgets(str, sizeof(str), stdin);
	hello_world(str);
	return 0;
}
