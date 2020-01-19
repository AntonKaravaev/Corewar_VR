#include "corewar.h"

unsigned int	op_ldi(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int32_t			args[3];
	unsigned int	new_pc;
	int				i;

//	ft_printf("LDI _ I was from here ----------------\n");
	if (check_targ(game->arena, car, op, &new_pc) != 0)
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
				print_one_step(val, game, car, new_pc);
				return (new_pc);
			}
		    else if (i != 2)
				args[i] = car->reg[args[i]];
		}
	}
	car->reg[args[2]] = bytes_to_int(game->arena, (car->save_pc + idx_mod(args[0] + args[1])) % MEM_SIZE, REG_SIZE);
	//("value = %d\n", car->reg[args[2]]);
	//ft_printf("add = %d\n", (car->save_pc + idx_mod(args[0] + args[1]))%MEM_SIZE);
	if (val->value_param == 4 || val->value_param == 30)
	{
		ft_printf("P %4d | ldi %d %d r%d\n", car->numb, args[0], args[1], args[2] + 1);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n", args[0], args[1], args[0] + args[1], car->save_pc + idx_mod(args[0] + args[1]));
	}
	print_one_step(val, game, car, new_pc);
	return (new_pc);
}
