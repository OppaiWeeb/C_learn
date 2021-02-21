#include <stdio.h>
#include <stdlib.h>

int i=0;

int main(int argc, char **argv)
{
  int terms[argc];
  int sum = 0;
  for(i=0;i<=argc;i++) {
    terms[i]=strtol(argv[i],0,0);
    sum = sum + terms[i];
    printf(sum);
    return 0;
  }
}
