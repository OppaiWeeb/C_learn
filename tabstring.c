// fichier tabstring.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char S1[]="Bonjour";
  char S2[]="et";
  char S3[]="bienvenue";

  char **tabs;
  tabs=malloc(3*sizeof(char*));
  tabs[0] = malloc((strlen(S1)+1)*sizeof(char));
  tabs[1] = malloc((strlen(S2)+1)*sizeof(char));
  tabs[2] = malloc((strlen(S3)+1)*sizeof(char));

  strcpy(tabs[0],S1);
  strcpy(tabs[1],S2);
  strcpy(tabs[2],S3);

  int i;
  printf("Test: ");
  for (i=0; i<3; i++)
    printf("%s ",tabs[i]);
  printf(" !!!\n");

  for (i=0; i<3; i++) free(tabs[i]);
  free(tabs);
  return 0;
}
