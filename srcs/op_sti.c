#include "corewar.h"

unsigned int op_sti(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int32_t			args[3];
	unsigned int	new_pc;
	int				i;

//	ft_printf("STI _ I was from here ----------------\n");
	if (check_targ(game->arena, car, op, &new_pc) == -1)
	{
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
	i = -1;
	while (++i < 3)
	{
		args[i] = take_value_shift_pc(car->targ[i], game->arena, car, op);
		if (car->targ[i] == T_REG)
        {
            if (args[i] < 0 || args[i] > 15)
			{
			//	ft_printf("111\n");
				print_one_step(val, game, car, new_pc);
				return (new_pc);
			}
		    if (i != 0)
				args[i] = car->reg[args[i]];
		}
	}
	int_to_bytes(car->reg[args[0]], game->arena, car->save_pc + idx_mod(args[1] + args[2]), REG_SIZE);
	if (val->value_param == 4 || val->value_param == 30)
	{
		ft_printf("P %4d | sti r%d %d %d\n", car->numb, args[0] + 1, args[1], args[2]);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", args[1], args[2], args[1] + args[2], (car->save_pc + idx_mod(args[1] + args[2])));
	}
	print_one_step(val, game, car, new_pc);
	return (new_pc);
}
