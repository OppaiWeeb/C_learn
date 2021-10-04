#include <stdio.h>
#include <stdlib.h>

//The prototype is set as a preproc compiler instruction.
// type of the function function name(argument); <== note that semi-colon is essential.
void saymyname(char *name);

int main(int argc, char const *argv[]){
	printf("This C file is a file to show how prototype work\n");
	//If we call a function, without telling to the compiler how the function work, the compiler 'ill show some error
	// So we need to tell how the function work and wich argument the function take.
	saymyname("heisenberg");
	return 0;
}

void saymyname(char *name){
	printf("My name is %s\n", name);
}
