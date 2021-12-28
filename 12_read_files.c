#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int arcg, char **argv)
{
    if (arcg != 2) {
        printf("you dont have a file to read\n");
        return (1);
    }
    int stat = 0;
    int size_buff = 50;
    char *buff = malloc(sizeof(char) * size_buff);
    int fd = 0;

    if ((fd = open(argv[1], O_RDONLY)) == -1)
        return (1);

    for (;(stat = read(fd, buff, size_buff)) != 0;) {
        if (stat == -1)
            return (1);
        write(1, buff, size_buff);
    }
    printf("\n");
    free(buff);
    close(fd);
    return (0);
}
