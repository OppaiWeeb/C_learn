#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int nbjeux = 0;
	char yn;
	int nbjoueur, Num, x;
	srand(time(NULL));
	printf("veux tu lancer un jeux ?\n y: oui\n n: non\n [?]: ");
	scanf("%c", &yn); 
	if(yn == 'y'){
		nbjeux++;
		printf("Combien de joueur jouent ?\n [?]: ");
		scanf("%d", &nbjoueur);

		if(nbjoueur != 1){
			int tour;
			printf("Entrer le nombre de tours max: "); 
    		scanf("%d", &tour); 

			printf("entrer le nombre a trouver en %d coups: ", tour);
			scanf("%d", &Num);

			printf("Nombre à trouver %d\n", Num);

			for(int j = 0; j < tour; j++){
				printf("guess the number : ");
				scanf("%d", &x);

				if(x > Num){
					printf("%d est plus grand que le chiffre a trouver\n", x);
				}

				else if (x < Num){
					printf("%d est plus petit que le chiffre a trouver\n", x);
				}

				else{
					printf("Le chiffre à ete trouver");
					break;
				}
			}
		}
		else{
			Num= rand() % 100; 
			printf("Nombre à trouver %d\n", Num);

			for(int j = 0; j < 10; j++){
				printf("guess the number : ");
				scanf("%d", &x);

				if(x > Num){
					printf("%d est plus grand que le chiffre a trouver\n", x);
				}

				else if(x < Num){
					printf("%d est plus petit que le chiffre a trouver\n", x);
				}

				else{
					printf("Le chiffre à ete trouver");
					break;
				}
			}
		}

	}
	
}
