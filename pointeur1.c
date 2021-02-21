// fichier pointeur1.c
#include <stdio.h>

int main()
{
  int i;
  int *pi;

  i=3;
  pi = &i;
  printf("(via la variable) Valeur=%d; adresse=%p\n",i,&i);
  printf("(via le pointeur) Valeur=%d; adresse=%p\n",*pi,pi);

  *pi = 4;
  printf("(via la variable) Valeur=%d; adresse=%p\n",i,&i);
  printf("(via le pointeur) Valeur=%d; adresse=%p\n",*pi,pi);

  return 0;
}
