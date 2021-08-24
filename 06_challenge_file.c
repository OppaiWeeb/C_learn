#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char ** argv){
	if(argc < 2){
		printf("Abort, missing argument.");
		return 1;
	}
	else if( argc > 2){
		printf("Abort, too much arguments.");
		return 1;
	}

	FILE *f;
	char * file_name = argv[1];

	if(access(file_name, F_OK)== 0){
		printf("Exist");
		f = fopen(file_name, "r");
		int count = 0;
		for(char c = getc(f); c != EOF; c = getc(f)){
			if(c == '\n'){
				count++;
			}
		}
		fclose(f);
		printf("there is %d line in the file %s\n", count, file_name);
	}
	else{
		printf("Doesn't exist");
	}
}
