#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	// a while loop check a condition and run while the condition is true before quiting the loop
	int user_age;
	printf("enter your age: ");
	scanf("%d", &user_age);
	if (user_age < 18){
		printf("You are not majeur please wait\n"); // it can also be easly by printf("you are not majeur, please wait %d", 18 - user_age);
		int i=0;
		while (user_age < 18){
			i++;
			user_age++;
		}
		printf("you need to wait %d to reach 18", i);
	}
	else{
		printf("You are already majeur");
	}
	
	return 0;
}
