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
	int stop;
	char *str;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	//add if cant read
	i = 0;
	//read basic
	stop = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	while(i < stop && read(fd, &numb, 1) > 0)
	{
		printf("%.2x", numb);
		//if (i % 2 == 1)
		//	printf(" ");
		i++;
	}
	printf("\n");
	//str = 
	while(read(fd, &numb, 1) > 0)
	{
		printf("%.2x", numb);
		//if (i % 2 == 1)
		//	printf(" ");
		//i++;
	}
	//read code
}