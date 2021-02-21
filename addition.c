// fichier addition.c
#include <stdio.h>

int main(int argc, char **argv)
{
  int sum = 0;
  printf("Nom de l'executable: %s\n", argv[0]);
  if (argc == 1)
    printf("Aucun argument\n");
  else
    {
      int i;
      for (i=1; i<argc; i++) {
        if (strtol(argv[i],0,0) == 0) {
          printf("erreur à l'argument :%s\n",argv[i]);
          return 1;
        }
      }
      for (i=1; i<argc; i++) sum = sum + strtol(argv[i],0,0);
    }
  printf("résultat :%i\n",sum);
  return 0;
}
