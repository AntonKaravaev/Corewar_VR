#include "corewar.h"

int				idx_mod(int pc)
{
	if (pc > 0)
		return (pc % IDX_MOD);
    while (pc < 0 && pc <= -IDX_MOD)
        pc += IDX_MOD;
    return (pc);
}

int				shift_arg(uint8_t t_array[], int size, int dir_size)
{
	int	shift;
	int	i;

	shift = 0;
	i = 0;
	while (i < size)
	{
		if (t_array[i] ==  T_REG)
			shift++;
		else if (t_array[i] == T_DIR)
			shift += dir_size;
		else if (t_array[i] == T_IND)
			shift += IND_SIZE;
		i++;
	}
	return (shift);
}
/*
int take_values(t_carriage *car, uint8_t arena[], t_op op)
{
	int				i;
	unsigned int	pc;

	pc = car->pc % MEM_SIZE;
	i = 0;
	while (i < op.count_args)
	{
		if (car->targ[i] == T_DIR)
		{
			car->args[i] = bytes_to_int(arena, pc, op.dir_size);
			pc = (pc + op.dir_size) % MEM_SIZE;
		}
		else if (car->targ[i] == T_REG)
		{
			car->args[i] = (int)arena[pc % MEM_SIZE] - 1;
			if (car->args[i] < 0 || car->args[i] > 15)
				return (-1);
			pc = (pc + 1) % MEM_SIZE;
		}
		else if (car->targ[i] == T_IND)
		{
			car->args[i] = bytes_to_int(arena, pc, IND_SIZE);
			pc = (pc + REG_SIZE) % MEM_SIZE;
		}
		else
			return (-1);
		i++;
	}
	return (0);
}
*/
int32_t				take_value_shift_pc(uint8_t type, uint8_t arena[], t_carriage *car, t_op op) //5 параметров!!!
{
	int		adr;
	int32_t	numb;

	if (type == T_DIR)
	{
		numb = bytes_to_int(arena, car->pc, op.dir_size);
		car->pc = (car->pc + op.dir_size) % MEM_SIZE;
	}
	else if (type == T_REG)
	{
		numb = (int)arena[(car->pc) % MEM_SIZE] - 1;
		car->pc = (car->pc + 1) % MEM_SIZE;
	}
	else if (type == T_IND)
	{
		if (op.idx_mod)
            adr = (car->save_pc + idx_mod(bytes_to_int(arena, car->pc, IND_SIZE))) % MEM_SIZE;
        else
            adr = (car->save_pc + bytes_to_int(arena, car->pc, IND_SIZE)) % MEM_SIZE;
		numb = bytes_to_int(arena, adr, REG_SIZE);
		car->pc = (car->pc + IND_SIZE) % MEM_SIZE;
	}
	else
		return (0);
	return (numb);
}

int					check_targ(uint8_t arena[], t_carriage *car, t_op op, unsigned int *new_pc)
{
    int i;

	car->step = 0;
    if (op.tcode)
    {
		car->pc = (car->pc + LEN_ARGS_CODE) % MEM_SIZE;
        take_targ(arena[car->pc], car->targ, op.count_args);
        car->pc = (car->pc + 1) % MEM_SIZE;
		car->step = shift_arg(car->targ, op.count_args, op.dir_size);
		// car->without_move = 0;
		// car->without_move = car->pc + car->step; // Перескок с конца арены в начало (Дурацкий)
		*new_pc = (car->pc + car->step) % MEM_SIZE;
		car->step += 1 + op.tcode;
        i = -1;
        while (++i < op.count_args)
        {
            if ((op.targ[i] & car->targ[i]) == 0)
                return (-1);
        }
    }
    else
    { //?
		*new_pc = (car->pc  + 1) % MEM_SIZE; //+1 ??
        i = -1;
        while (++i < op.count_args)
            car->targ[i] = op.targ[i];
		car->step = 1;
		//car->step = shift_arg(car->targ, op.count_args, op.dir_size);
    }

    return (0);
}

void				take_targ(uint8_t byte, uint8_t targ[], int size)
{
	int		i;
	uint8_t	type_code;

	i = 0;
	while (i < size)
	{
		type_code = (byte & 0xc0) >> 6;
		if (type_code == REG_CODE)
			targ[i] = T_REG;
		else if (type_code == DIR_CODE)
			targ[i] = T_DIR;
		else if (type_code == IND_CODE)
			targ[i] = T_IND;
		else
			targ[i] = T_LAB;
		byte = byte << 2;
		i++;
	}
}

/*
int main ()
{
	t_type array[3];
	uint8_t byts[] = {0x7b, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x07};

	int i;
	int pc;
	take_type(byts[0], array, 3);
	i = 0;
	pc = 1;
	while (i < 3)
	{
		if (array[i] ==  REG_CODE)
			printf("REG ");
		else if (array[i] ==  DIR_CODE)
			printf("DIR ");
		else if (array[i] == IND_CODE)
			printf("IND ");
		printf("val = %d \n", take_value_shift_pc(array[i], byts, &pc, 2));
		i++;
	}
	printf("\n");
	printf(" %d, %d, %d\n", array[0], array[1], array[2]);
	printf(" shift = %d\n", shift_arg(array, 0, 3, 2));
	return (0);
}
*/
