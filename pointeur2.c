// fichier pointeur2.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  int *pi;

  pi = malloc(sizeof(int));

  *pi=3;
  i=*pi;
  printf("(via la variable) Valeur=%d; adresse=%p\n",i,&i);
  printf("(via le pointeur) Valeur=%d; adresse=%p\n",*pi,pi);

  *pi = 4;
  printf("(via la variable) Valeur=%d; adresse=%p\n",i,&i);
  printf("(via le pointeur) Valeur=%d; adresse=%p\n",*pi,pi);

  free(pi);
  return 0;
}
