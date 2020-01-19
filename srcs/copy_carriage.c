#include "corewar.h"

t_carriage copy_carriage(t_carriage *car, t_game *game)
{
	t_carriage	new_car;
	int			i;

	i = -1;
	while (++i < REG_NUMBER)
		new_car.reg[i] = car->reg[i];
	new_car.carry = car->carry;
	new_car.live = car->live;
	new_car.hookbefexe = 0;
	game->count_carriage++;
	new_car.numb = game->count_carriage;
	return (new_car);
}