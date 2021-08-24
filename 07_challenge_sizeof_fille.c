#include <stdio.h>
#include <stdlib.h>
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

	if(access(file_name, F_OK)==0){
		f =fopen(file_name, "r");
		long f_size;
		fseek(f, 0, SEEK_END);
		f_size = ftell(f);
		rewind(f);
		printf("%s: size = %ld\n", file_name, f_size);
	}
	else{
		printf("Fatal error\n exit"); 
		return 1;
	}
  return 0;
}
