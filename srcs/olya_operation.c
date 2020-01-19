#include "corewar.h"

void cycles_before_execution(t_carriage *car, uint8_t oper)
{
	
	int i;

	i = 0;
	while (i < 16)
	{
		if (op_tab[i].code == oper)
		{
			car->hookbefexe = op_tab[i].wait_cycles;	
			break;
		}
		i++;
	}
	if (i == 16)
		car->hookbefexe = 0;
/*
	if (oper == 0x10)
		car->hookbefexe = 2;
	else if (oper == 0x02 || oper == 0x3)
		car->hookbefexe = 5;
	else if (oper == 0x06 || oper == 0x07 || oper == 0x08)
		car->hookbefexe = 6;
	else if (oper == 0x01 || oper == 0x04 || oper == 0x05 || oper == 0x0d)
		car->hookbefexe = 10;
	else if (oper == 0x09)
		car->hookbefexe = 20;
	else if (oper == 0x0a || oper == 0x0b)
		car->hookbefexe = 25;
	else if (oper == 0x0e)
		car->hookbefexe = 50;
	else if (oper == 0x0c)
		car->hookbefexe = 800;
	else if (oper == 0x0f)
		car->hookbefexe = 1000;
	else
		car->hookbefexe = 0;
		*/
	car->operation = oper;
}

void	addition_operation(t_val * val, t_game *game, t_carriage *car, uint8_t operation)
{
	if (operation == 0x09)
		car->pc = op_zjmp(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x0a)
		car->pc = op_ldi(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x0b)
		car->pc = op_sti(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x0c)
		car->pc = op_fork(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x0d)
		car->pc = op_lld(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x0e)
		car->pc = op_lldi(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x0f)
		car->pc = op_lfork(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x10)
		car->pc = op_aff(val, game, car, op_tab[operation - 1]);
	else
		car->pc = (car->pc + 1) % MEM_SIZE;
	
} 

void	operation(t_val * val, t_game *game, t_carriage *car, uint8_t operation)
{
	/*
	int i;

	i = 0;
	while (i < 18)
	{
		if (op_tab[i].code == operation)
			op_tab[i].func(game, car);
	}
	*/
//	ft_printf("%x\n", operation);
	car->save_pc = car->pc % MEM_SIZE;
	if (operation == 0x01)
		car->pc = op_live(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x02)
		car->pc = op_ld(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x03)
		car->pc = op_st(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x04)
		car->pc = op_add(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x05)
		car->pc = op_sub(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x06)
		car->pc = op_and(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x07)
		car->pc = op_or(val, game, car, op_tab[operation - 1]);
	else if (operation == 0x08)
		car->pc = op_xor(val, game, car, op_tab[operation - 1]);
	else
		addition_operation(val, game, car, operation);
}