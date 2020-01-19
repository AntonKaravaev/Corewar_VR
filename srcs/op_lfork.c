#include "corewar.h"

unsigned int	op_lfork(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int32_t		t_dir;
	t_carriage	new_car;
	t_list		*new;

//	ft_printf("OP_LFORK _ I was from here ----------------\n");
	car->pc = (car->pc + 1) % MEM_SIZE;
 	t_dir = take_value_shift_pc(T_DIR, game->arena, car, op);
	new_car = copy_carriage(car, game);
	new_car.pc = (t_dir + car->save_pc) % MEM_SIZE;
	
	//new_car.numb??
	if (!(new = ft_lstnew((void*)&new_car, sizeof(t_carriage))))
			ft_error("memor :(");
	ft_lstadd(&(game->carriages), new);
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | lfork %d (%d)\n", car->numb, t_dir, (t_dir + car->save_pc));
	print_one_step_fork(val, game, car, (car->pc) % MEM_SIZE);
	return ((car->pc) % MEM_SIZE);
	//car->numb??
}
