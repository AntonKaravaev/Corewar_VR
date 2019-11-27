#include "corewar.h"

void ft_take_int(int fd, int *n)
{
	int i;
	uint8_t byte;

	*n = 0;
	i = 0;
	while (i < 4)
	{
		if (read(fd, &byte, 1) <= 0)
			ft_error("Short file\n");
		*n = *n * 16 * 16 + byte;
		i++;
	}
}

void init_champ(int fd, t_champ *champ)
{
	unsigned int tmp;
	uint8_t numb;
	int i;

	if (read(fd, &tmp, 4) <= 0)
		ft_error("Short file\n");
	if (tmp != 0xf383ea00) //why reverse
		ft_error("Missing magic header\n");
	if (read(fd, champ->name, PROG_NAME_LENGTH) < 0)
		ft_error("Short file\n");
	if (read(fd, &tmp, 4) < 0)
		ft_error("Short file\n");
	if (tmp != 0x00000000)
		ft_error("Missing NULL after name\n");
	ft_take_int(fd, &(champ->exec_code_size));
	if (champ->exec_code_size > CHAMP_MAX_SIZE)
		ft_error("Exec_size code too big\n");
	if (read(fd, champ->comment, COMMENT_LENGTH) < 0)
		ft_error("Short file\n"); //reverse ?
	if (read(fd, &tmp, 4) < 0)
		ft_error("Short file\n");
	if (tmp != 0x00000000)
		ft_error("Missing NULL after comment\n");
	i = 0;
	while (read(fd, &numb, 1) > 0)
	{
		champ->exec_code[i] = numb;
		i++;
	}
	ft_printf("size = %d, reading_byte = %d\n", champ->exec_code_size, i);
	if (i != champ->exec_code_size)
		ft_error("Wrong exec_code_size\n");
	//ft_printf("size = %d, i = %d\n", champ->exec_code_size, i);
}