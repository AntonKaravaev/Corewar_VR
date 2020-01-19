#include "corewar.h"

unsigned int op_sub(t_val *val, t_game *game, t_carriage *car, t_op op)
{
    unsigned int	new_pc;
    int32_t			args[3];
	int32_t			sub;
    int				i;

//    ft_printf("SUB _ I was from here ----------------\n");
    if (check_targ(game->arena,car, op, &new_pc) == -1)
	{
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
    i = -1;
    while (++i < op.count_args)
    {
        args[i] = take_value_shift_pc(T_REG, game->arena, car, op);
        if (args[i] < 0 || args[i] > 15)
		{
			print_one_step(val, game, car, new_pc);
			return (new_pc);
		}
    }
    sub = car->reg[args[0]] - car->reg[args[1]];
    if (sub == 0)
        car->carry = 1;
    else
        car->carry = 0;
    car->reg[args[2]] = sub;
    //ft_print_op(car, op, args, val);
    if (val->value_param == 4 || val->value_param == 30)
        ft_printf("P %4d | sub r%d r%d r%d\n", car->numb, args[0] + 1, args[1] + 1, args[2] + 1);
	print_one_step(val, game, car, new_pc);
    return (new_pc);
}
