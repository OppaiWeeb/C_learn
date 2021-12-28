#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("You dont have give a file\n");
        return (1);
    }

    int fd;
    if ((fd = open(argv[1], O_RDWR) == -1))
        return (1);

    write(fd, "This is testing for insert text in a file\n", 43);
    close(fd);
    return (0);
}
