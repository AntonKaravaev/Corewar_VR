#include "corewar.h"

void	int_to_bytes(int numb, __uint8_t arena[], int pc, int size)
{
	// int i;
	void *p;
	// i = size;
	// while (--i > -1)
	// {
	// 	arena[(pc + i) % MEM_SIZE] = numb % 256;
	// 	numb = numb / 256;
	// }
	while (pc < 0)
        pc += MEM_SIZE;
    p = &numb;
	if (size == 4)
	{
		arena[pc % MEM_SIZE] = *(uint8_t*)(p + 3);
		arena[(pc + 1)% MEM_SIZE] = *(uint8_t*)(p + 2);
		arena[(pc + 2) % MEM_SIZE] = *(uint8_t*)(p + 1);
		arena[(pc + 3) % MEM_SIZE] = *(uint8_t*)(p);
	}
	else 
		ft_error("ERROR IN INT_TO_BYTE\n");

}

int		bytes_to_int(uint8_t arena[], int pc, int size)
{
	int			numb;
	void		*p;
	int16_t		double_byte;

	//pc = pc % MEM_SIZE;
	//ft_printf("bti %d %d %d %d\n", pc % MEM_SIZE, (pc + 1) % MEM_SIZE, (pc + 2) % MEM_SIZE, (pc + 3) % MEM_SIZE);
	numb = 0;
	if (size == 1)
		numb = arena[pc % MEM_SIZE];
	else if (size == 2)
	{
		p = &double_byte;
		*(int8_t*)(p  + 1) = arena[pc % MEM_SIZE];
		*(int8_t*)p = arena[(pc + 1) % MEM_SIZE];
		numb = double_byte;
	}
	else if (size == 4)
	{
		p = &numb;
		*(int8_t*)(p + 3) = arena[pc % MEM_SIZE];
		//ft_printf("%.x ", numb);
		*(int8_t*)(p + 2) = arena[(pc + 1) % MEM_SIZE];
		//ft_printf("%.x ", numb);
		*(int8_t*)(p + 1) = arena[(pc + 2) % MEM_SIZE];
		//ft_printf("%.x ", numb);
		*(int8_t*)(p) = arena[(pc + 3) % MEM_SIZE];
		//ft_printf("%.x \n", numb);
	}
	else
		ft_error("bad byte\n");
	//ft_printf("byte to int = %d\n", numb);
	return (numb);
}
