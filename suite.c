#include <stdio.h>


int main(){
	int lign = 0;
	printf("how many ligne do you want to fill ?\nMaximum 10\n");
	scanf("%d", &lign);
	for(int i=1; i<lign+1;i++){
		printf("\n");
		for(int j = 1; j<i+1; j++){
			printf("%d", i);
		}
	}
}

