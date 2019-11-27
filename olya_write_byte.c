#include <stdint.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "op.h"

int main(int argc, char **argv)
{
    int fd;
    uint8_t numb;
    int i;

    if (argc != 2)
        return (-1);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (-1);
    //add if cant read
    i = 0;
    while(read(fd, &numb, 1) > 0)
    {
        printf("%.2x", numb);
        if (i % 2 == 1)
            printf(" ");
        i++;
    }
}