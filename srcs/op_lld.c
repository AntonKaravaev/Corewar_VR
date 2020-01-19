#include "corewar.h"

unsigned int	op_lld(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int32_t			args[3];
	unsigned int	new_pc;

//	ft_printf("LLD _ I was from here ----------------\n");
	if (check_targ(game->arena, car, op, &new_pc) != 0)
	{
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
	args[0] = take_value_shift_pc(car->targ[0], game->arena, car, op);
    args[1] = take_value_shift_pc(car->targ[1], game->arena, car, op);
	if (args[1] < 0 || args[1] > 15)
	{
		print_one_step(val, game, car, car->pc);
       	return (new_pc);
	}
	if (args[0] == 0)
		car->carry = 1;
	else
		car->carry = 0;
	car->reg[args[1]] = args[0]; // правильно записывает????
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | lld %d r%d\n", car->numb, args[0], args[1] + 1); // -car->reg[0]
	print_one_step(val, game, car, new_pc);
	return (new_pc);
}
