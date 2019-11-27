#include "corewar.h"

void cycles_before_execution(t_carriage *car, uint8_t oper)
{
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
}


void addition_operation(t_game *game, t_carriage *car, uint8_t operation)
{
	if (operation == 0x09)
		car->pc = (car->pc + ft_zjmp(game, car)) % MEM_SIZE;
		/*
	else if (operation == 0x0a)
		car->addr = (car->addr + ft_ldi(game, car)) % MEM_SIZE;
	else if (operation == 0x0b)
		car->addr = (car->addr + ft_sti(game, car)) % MEM_SIZE;
	else if (operation == 0x0c)
		car->addr = (car->addr + ft_fork(game, car)) % MEM_SIZE;
	else if (operation == 0x0d)
		car->addr = (car->addr + ft_lld(game, car)) % MEM_SIZE;
	else if (operation == 0x0e)
		car->addr = (car->addr + ft_lldi(game, car)) % MEM_SIZE;
	else if (operation == 0x0f)
		car->addr = (car->addr + ft_lfork(game, car)) % MEM_SIZE;
	else if (operation == 0x10)
		car->addr = (car->addr + ft_aff(game, car)) % MEM_SIZE;
	*/
	else
		car->pc = (car->pc + 1) % MEM_SIZE;
	
} 

void	operation(t_game *game, t_carriage *car, uint8_t oper)
{
	
	if (oper == 0x01)
		ft_live(game, car);
	else if (oper == 0x02)
		ft_ld(game, car);
	if (oper == 0x03)
		ft_st(game, car);
	else if (oper == 0x04)
		ft_add(game, car);
	else if (oper == 0x05)
		ft_sub(game, car);
	else if (oper == 0x06)
		ft_and(game, car);
	else if (oper == 0x07)
		ft_or(game, car);
	else if (oper == 0x08)
		ft_xor(game, car);
	else
		addition_operation(game, car, oper); // Нужно ли oper???

}