// fichier readDB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  
  FILE *fichier;

  // verifie que deux arguments ont bien ete passes au programme
  if (argc != 2) {
    fprintf(stderr, "Erreur de syntaxe: readDB <fichier>\n");
    return 1;
  }

  // ouvre le fichier en lecture
  fichier = fopen(argv[1], "r");
  
  // test si tout s'est bien passe
  if (!fichier) {
    fprintf(stderr, "Impossible d'ouvrir le fichier %s en lecture\n", argv[1]);
    return 2;
  }
  
  //recupere les infos
  int age, i=0;
  char ligne[100] = "";
  char *nom="";
  char *prenom = "";
  char *sex="";
  char *perso[4]={0};

  while (fgets(ligne, 100, fichier) != NULL) {
    printf("%s, %d",ligne, i);
    i++;
  }

  for (int j = 0; j < i; j++)
  {
    perso[j]=fgets(ligne, 100, fichier);
  }
  
  printf("Nom: %s, Prenom: %s, Sexe: %c, Age %d", perso[0], perso[1], perso[2], perso[3] );
  
  
  
  // ferme le fichier ouvert
  fclose(fichier);
  printf("\n");
  return 0;
}
