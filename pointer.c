#include <stdio.h>

int MinToHour(int *min, int *hour);

int main(){
    int min=0, hour=0;
    printf("How many min ?");
    scanf("%d", &min);
    printf("%p\n", &min);
    MinToHour(&min, &hour);
    printf("%dh and %d min", hour, min);

}

int MinToHour(int *pointerm, int *pointerh){
    *pointerh = *pointerm / 60;
    *pointerm = *pointerm % 60;
    return 0;
}