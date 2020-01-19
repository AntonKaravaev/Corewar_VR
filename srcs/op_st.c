#include "corewar.h"

unsigned int op_st(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	unsigned int    new_pc;
	int32_t      	args[3];
	int32_t      	adr;

	// (void)val;
	// car->save_pc = car->pc; // Это Антон затирал!
//	ft_printf("ST _ I was from here ----------------\n");
	if (check_targ(game->arena, car, op, &new_pc) == -1)
	{
		print_one_step(val, game, car, new_pc);  // НАЙТИ ОШИБКУ В МЕСТЕ С ОЛЕЙ!
		return (new_pc);
	}
	args[0] = take_value_shift_pc(car->targ[0], game->arena, car, op);
	if (args[0] < 0 || args[0] > 15)
	{
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
	if (car->targ[1] == T_REG)
	{
		args[1] = take_value_shift_pc(T_REG, game->arena, car, op);
		if (args[1] < 0 || args[1] > 15)
		{
			print_one_step(val, game, car, new_pc);
			return (new_pc);
		} // change car->reg[0] на car->numb
		car->reg[args[1]] = car->reg[args[0]];
		if (val->value_param == 4 || val->value_param == 30)
			ft_printf("P %4d | st r%d %d\n", car->numb, args[0] + 1, args[1] + 1);
		print_one_step(val, game, car, new_pc);
		return (new_pc);
	}
	adr = bytes_to_int(game->arena, car->pc, IND_SIZE);
	int_to_bytes(car->reg[args[0]], game->arena, (car->save_pc + adr % IDX_MOD), REG_SIZE);
	if (val->value_param == 4 || val->value_param == 30)
	{
		if (car->targ[1] == T_REG)
			ft_printf("P %4d | st r%d %d\n", car->numb, args[0] + 1, args[1]); // change car->reg[0] на car->numb
		else
			ft_printf("P %4d | st r%d %d\n", car->numb, args[0] + 1, adr);
	}
	print_one_step(val, game, car, new_pc);
	return (new_pc);
}
/*
unsigned int op_st(t_game *game, t_carriage *car, t_op op)
{
	unsigned int    new_pc;
	unsigned int	save_pc;

	save_pc = car->pc;
	if (check_targ(game->arena, car, op, &new_pc) == -1)
		return (new_pc);
	if (take_values(car, game->arena, op) == -1)
		return (new_pc);

}
*/