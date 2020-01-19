#include "corewar.h"

unsigned int	op_ld(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	unsigned int	new_pc;
	int32_t			args[3];

//	ft_printf("LD _ I was from here ----------------\n");
	if (check_targ(game->arena, car, op, &new_pc) == -1)
	{
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
	args[0] = take_value_shift_pc(car->targ[0], game->arena, car, op);
	args[1] = take_value_shift_pc(car->targ[1], game->arena, car, op);
	// printf("-->> %d \n",args[0]);
	// printf("-->> r%d \n",args[1]);
	// printf("new_pc =  %d \n",new_pc);
	// printf("car_step =  %d \n", car->step);
	if (args[1] < 0 || args[1] > 15)
	{
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
	if (args[0] == 0)
		car->carry = 1;
	else
		car->carry = 0;
	car->reg[args[1]] = args[0];
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | ld %d r%d\n", car->numb, args[0], args[1] + 1);
	print_one_step(val, game, car, new_pc);
	return (new_pc);
}
