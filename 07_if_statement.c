#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int user_live = 1;
	printf("the user have %d live\n", user_live);
	printf("the user is touched by an enemy and may take 1 damage.\n");
	printf("did the user take the damage? [y/n]: ");	char yn;
	scanf("%c", &yn);

	if (yn == 'y'){
		printf("the user take the damage\n"); user_live = user_live - 1;}
	else if (yn == 'n'){
		printf("the user have a strong armor\n");}
	else{
		printf("the user take the damage\n"); user_live = user_live - 1;}

	//a simple statement check if a condition is correct or not and do somethings.
	if (user_live == 0 ) {
		printf("the user is not here anymore\n");}
	else{
		printf("the user survive\n");}

	return 0;
}