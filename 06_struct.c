#include <stdio.h>
#include <stdlib.h>

// we can define the struct as a preproc instruction or in the function who need the struct.
struct user{
		int live;
		char *name[];
} user;

int main(int argc, char const *argv[])
{
	// a struct is a variable that contain other variable
	user.live = 3;
	printf("enter user name: ");
	scanf("%s", user.name);

	printf("the user is named %s, and get %d live\n",user.name, user.live);


	return 0;
}
