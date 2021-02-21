#include <stdio.h>
#include "personne.h"

#define start_money 100

void main(){
    int nbplayer;
    printf("How many player is there ?");
    scanf("%d", &nbplayer);
    if(nbplayer>9){
        printf("the king exile your team on a desert island, You are dead\n");
        end();
    }
    else{
        create_player(nbplayer);
        printf("The story begin in a country with a tyranic king\nThe king called you to defeat the dragon\n");
        printf("the dragon eat you and your friend before destroy the city\n");
        end();
    }
    
}  

int create_player(int nbplayer){
    personne joueur[nbplayer];
    for(int i =0; i<nbplayer;i++){
        printf("\nplayer %d\n", i+1);
        printf("What is your user name ? ");
        scanf("%s", &joueur[i].username);
        joueur[i].money = start_money;
        printf("What is your sexe ? (0:male, or 1:female)");
        scanf("%d", &joueur[i].gender);
        printf("%s I gave you %f money\n", joueur[i].username, joueur[i].money);
    }
    return 0;
}

int end(){
    return 1;
}