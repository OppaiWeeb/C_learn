#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	//in some case we need to compare a variable to some "int" case and an if else statement may be long, complexe and useless instead of a switch case
	// it's used like that
	int option;
	printf("[1]: Die now in suffer\n[2]: Die now sufferless\nenter the option you want:");
	scanf("%d", &option);
	switch (option){
	case 1:
		printf("You die with suffer now\nhappy deathday.\n");
		break;
	
	case 2:
		printf("You die with no suffer now\nhappy deathday.\n");
		break;

	case 3:
		printf("You found the secret ending\nyou can survive\n");
		break;

	}
	return 0;
}