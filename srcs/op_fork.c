#include "corewar.h"

unsigned int	op_fork(t_val *val, t_game *game, t_carriage *car,t_op op)
{
	uint32_t	t_dir;
	t_carriage	new_car;
	t_list		*new;

//	ft_printf("OP_FORK _ I was from here ----------------\n");
	car->pc = (car->pc + 1) % MEM_SIZE;
	t_dir = take_value_shift_pc(T_DIR, game->arena, car, op);
	new_car = copy_carriage(car, game);
	new_car.pc = (car->save_pc + idx_mod(t_dir) % MEM_SIZE);
	//new_car.numb??
	if (!(new = ft_lstnew((void*)&new_car, sizeof(t_carriage))))
		ft_error("memor :(");
	ft_lstadd(&(game->carriages), new);
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | fork %d (%d)\n", car->numb, t_dir, car->save_pc + idx_mod(t_dir));
	print_one_step_fork(val, game, car, (car->pc) % MEM_SIZE);
	return ((car->pc) % MEM_SIZE);
}
