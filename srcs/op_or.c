#include "corewar.h"

unsigned int op_or(t_val *val, t_game *game, t_carriage *car, t_op op)
{
    unsigned int    new_pc;
    int32_t         args[3];
    int32_t         or;
    int             i;

//    ft_printf("OR _ I was from here ----------------\n");
    if (check_targ(game->arena, car, op, &new_pc) == -1)
    {
        print_one_step(val, game, car, new_pc);
        return (new_pc); // а в некоторых (-1) Почему??? Вопрос Антона
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
    or = args[0] | args[1];
    if (or == 0)
        car->carry = 1;
    else
        car->carry = 0;
    car->reg[args[2]] = or;
    if (val->value_param == 4 || val->value_param == 30)
        ft_printf("P %4d | or %d %d r%d\n", car->numb, args[0], args[1], args[2] + 1);
	print_one_step(val, game, car, new_pc);
    return (new_pc);
}