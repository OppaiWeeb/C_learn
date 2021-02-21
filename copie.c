// fichier readDB
#include <stdio.h>

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
  int count,age;
  char ligne[100] = "";
  char *nom,*prenom = "";
  char *sex;
  while (fgets(ligne, 100, fichier) != NULL) {
    printf("%s\n",ligne);
    sscanf("%s %s %d %s",nom,prenom,&age,sex);
    printf("%s %s %d %s",nom,prenom,age,sex);
  }
  
  // ferme le fichier ouvert
  fclose(fichier);
  printf("\n");
  return 0;
}
