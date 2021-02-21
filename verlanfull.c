#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv) {
    int i=0;
    int j=0;
    for(i=argc-1;i>0;i--) {                     //pour i allant du dernier argument au 1er
        for(j=strlen(argv[i]);j>=0;j--) {       //pour j allant de la derniere lettre de l'argument a la premiere lettre de l'argument
            printf("%c",argv[i][j]);            //affiche le caractere correspondant
        }
        if(i!=1) {
            printf(" ");                        //met un espace entre les arguments
        }
    }
    printf("\n");                               //retour chariot
    return 0;
}