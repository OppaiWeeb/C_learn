#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* x, char* y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char* a, int x, int y){
    int i;
    if (x == y)
        printf("%s\n", a);
    else {
        for (i = x; i <= y; i++) {
            swap((a + x), (a + i));
            permute(a, x + 1, y);
            swap((a + x), (a + i)); 
        }
    }
}

int main(int argc, char *argv[]){
	char str[1023];
    strcpy(str, argv[1]);
    int n = strlen(str);
    permute(str, 0, n - 1);
    return 0;
}
