#include <stdio.h>
#include "tableau.h"

#define Table 4

int main(){
    int resul;
    int tab[Table] = {};
    int tab2[Table]= {};

    for(int i = 0; i<Table;i++ ){
        printf("enter the value of the tab %d ", i);
        scanf("%d", &tab[i]);
    }

    resul = Sum_Tab(tab, Table);
    printf("the sum of the tab is %d\n", resul);

    resul = Moy_Tab(tab, Table);
    printf("the moy of the tab is %d\n", resul);

    tab2[Table] = copie_tab(tab, tab2, Table);
    for(int i = 0; i<Table; i++){
        printf("The %d element of the tab1 is %d\nthe %d of the second is %d\n", i, tab[i], i, tab2[i]);
    }
}

int Sum_Tab(int tab[], int taille){
    int resul = 0;
    for(int i = 0; i < taille; i++){
        resul = tab[i]+resul;
    }
    return resul;
}


double Moy_Tab(int tab[], int taille){
    double resul = 0;
    for(int i = 0; i < taille; i++){
        resul = tab[i]+resul;
    }
    resul = resul / taille;
    return resul;
}

int copie_tab(int tab[], int tab2[], int taille){
    for(int i =0 ; i< taille; i++){
        tab2[i] = tab[i];
    }
    return tab2[Table];
}
