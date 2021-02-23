#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "devin.h"

#define NombreCoup 10
#define min 0

int main(){
    int jouer = min, YN = min, xp_total=min, i=min;
    srand(time(NULL));
    while (i < NombreCoup){
        printf("Do you want to play ? (1 yes autre non) \n");
        scanf("%d", &YN);
        if (YN == 1){
            devin(&xp_total);
        }
        else
        {
            return 1;
        }
        i++;
    }
    printf("you have play %d game please stop\n",i+1);
}

int randomInt(int max, int *Psecret){
    int randInt = min;
    randInt = (rand() % (max - min + 1)) + min;
    *Psecret = randInt;
}

int jeux(int rand){
    int user=min, i=min;
    while(i<NombreCoup){
        printf("c'est le %d tour.\n",i+1);
        printf("Entre un chiffre: ");
        scanf("%d", &user);
        if (user > rand ){
            printf("le chiffre est plus petit.\n");
        }
        else if (user < rand){
            printf("le chiffre est plus grand.\n");
        }
        else
        {
            printf("le chiffre a ete trouve.\n");
            return 3;
            break;
        }
        i++;
    }
    printf("the number was %d\n", rand);
    return 0;
}

int xp(int victoire, int *xp_total){
    if(victoire == 3){
        printf("victoire\n");
        *xp_total = *xp_total + 10;
    }
    else{
        printf("echec\n");
        *xp_total = *xp_total;
    }
    return min;
}

int devin(int *xp_total){
    int max=min, secret=min, victoire=min;
    printf("select max number");
    scanf("%d", &max);
    randomInt(max, &secret);
    //printf("the number to find is %d\n", secret);
    victoire = jeux(secret);
    xp(victoire, xp_total);
    printf("you have %d XP\n", *xp_total);
}
