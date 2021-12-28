#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    for (int i = 0; i != argc; i++)
        printf("argument %d is %s", i, argv[i]);
    return (0);
}
