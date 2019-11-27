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

void operation(t_game *game, t_carriage *car, uint8_t operation)
{
	/*
	if (operation == 0x01)
		car->addr = (car->addr + ft_live(game, car)) % MEM_SIZE;
	else if (operation == 0x02)
		car->addr = (car->addr + ft_ld(game, car)) % MEM_SIZE;
	else if (operation == 0x03)
		car->addr = (car->addr + ft_st(game, car)) % MEM_SIZE;
	else if (operation == 0x04)
		car->addr = (car->addr + ft_add(game, car)) % MEM_SIZE;
	else if (operation == 0x05)
		car->addr = (car->addr + ft_sub(game, car)) % MEM_SIZE;
	else if (operation == 0x06)
		car->addr = (car->addr + ft_and(game, car)) % MEM_SIZE;
	else if (operation == 0x07)
		car->addr = (car->addr + ft_or(game, car)) % MEM_SIZE;
	else if (operation == 0x08)
		car->addr = (car->addr + ft_xor(game, car)) % MEM_SIZE;
	*/
	//else
		addition_operation(game, car, operation);

}