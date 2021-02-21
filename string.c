// fichier string.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char S[]="Bonjour";
  char *ps;
  int lenS,i;
  
  lenS = strlen(S);
  ps=malloc((lenS +1) * sizeof(char));

  for (i=0; i<lenS; i++)
    ps[i] = S[i];
  ps[lenS] = '\0';

  printf("Test: %s -> %s\n",S,ps);

  free(ps);
  return 0;
}
