#include "corewar.h"

unsigned int	op_add(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	unsigned int	new_pc;
	int				i;
	int32_t			args[3];
	int32_t			sum;

	//ft_printf("ADD _ I was from here ----------------\n");
	if (check_targ(game->arena, car, op, &new_pc) == -1)
	{
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
	i = -1;
	while (++i < op.count_args)
	{
		args[i] = take_value_shift_pc(T_REG, game->arena, car, op);
		if (args < 0 || args[i] > 15)
		{
			print_one_step(val, game, car, new_pc);
			return (new_pc);
		}
	}
	sum = car->reg[args[0]] + car->reg[args[1]];
	if (sum == 0)
	    car->carry = 1;
	else
		car->carry = 0;
	car->reg[args[2]] = sum;
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | add r%d r%d r%d\n", car->numb, args[0] + 1, args[1] + 1, args[2] + 1);
	print_one_step(val, game, car, new_pc);
	return (new_pc);
}
