#include <stdio.h>

int MinToHour(int *min, int *hour);

int main(){
    int min=0, hour=0;
    printf("How many min ?");
    scanf("%d", &min);
    MinToHour(&min, &hour);
    printf("%dh and %d min", hour, min);

}

int MinToHour(int *min, int *hour){
    *hour = *min / 60;
    *min = *min % 60;
    return 0;
}