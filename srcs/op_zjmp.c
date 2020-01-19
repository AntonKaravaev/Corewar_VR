#include "corewar.h"

unsigned int	op_zjmp(t_val *val, t_game *game, t_carriage *car, t_op op)
{
	int32_t	t_dir;

	// ft_printf("ZJMP _ I was from here ----------------\n");
	t_dir = bytes_to_int(game->arena, car->pc + 1, op.dir_size);
	if (car->carry == 1)
	{
		car->pc = ((car->pc + idx_mod(t_dir))) % MEM_SIZE;
		if (val->value_param == 4 || val->value_param == 30)
			ft_printf("P %4d | zjmp %d OK\n", car->numb,  t_dir); // не отрабатывет 45 цикл ld_carry.cor
		return ((car->pc));
	}
	if (val->value_param == 4 || val->value_param == 30) //БЫЛО
		ft_printf("P %4d | zjmp %d FAILED\n", car->numb,  t_dir); // ТАК

	// if (val->value_param == 4 || val->value_param == 30) // А теперь
	// 	ft_printf("P %4d | zjmp %d FAILED\n", car->numb,  t_dir);
	car->step = 1 + op.dir_size;
	print_one_step(val, game, car, (car->save_pc + car->step) % MEM_SIZE); /// ZJMP Надо разбираться! // МОЖЕТ БЫТЬ ВЕРНУТЬ
	//ft_printf("res = %x\n", ((car->pc + 1) % MEM_SIZE)); // Test Anton 16.01
	return ((car->pc + op.dir_size + 1) % MEM_SIZE); // + t_dir_size??
}
