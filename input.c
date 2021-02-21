// fichier input.c
#include <stdio.h>

int main()
{
   char c;
   int i;
   float f;
   char s[10];
   int ret;
   ret=scanf("Un char %c, un entier %d, un reel %f, une chaine %s et c'est tout.", &c, &i, &f, s);
   printf("Resultat (%d): %c // %d // %f // %s //\n", ret, c, i, f, s);
   return 0;
}
