#include "corewar.h"

unsigned int op_aff(t_val *val, t_game*game, t_carriage *car, t_op op)
{
    unsigned int	new_pc;
    int32_t			reg;

//ft_printf("             AFFFFFFF                 \n");
    if (check_targ(game->arena, car, op, &new_pc) == -1)
	{
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
    reg = take_value_shift_pc(car->targ[0], game->arena, car, op);
    if (reg < 0 || reg > 15)
	{
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
	if (val->flag_aff_flag == 1 || val->value_param == 30)
		ft_printf("Aff: %c\n", (char)((car->reg[reg]) % 256));
	print_one_step(val, game, car, new_pc);
    return (new_pc);
}
