#include "corewar.h"

unsigned int	op_live(t_val *val, t_game *game, t_carriage *car, t_op op)
{
    int32_t t_dir;

	game->live++;
//	ft_printf("LIVE _ I was from here ----------------\n");
	car->pc = (car->pc + 1) % MEM_SIZE;
	t_dir = take_value_shift_pc(T_DIR, game->arena, car, op);
	car->live = game->hook;
	if (t_dir < 0 && t_dir >= -(game->champs))
		game->last_alive = -t_dir;
	if (val->value_param == 4 || val->value_param == 30)
		ft_printf("P %4d | live %d\n", car->numb, t_dir);
	//car->step = car->pc; // Проделки АНТОНА! отвратительно 
	//car->step =  
	print_one_step(val, game, car, car->pc);
	return (car->pc);
}
