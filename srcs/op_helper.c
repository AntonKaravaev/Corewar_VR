/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 01:48:55 by crenly-b          #+#    #+#             */
/*   Updated: 2020/01/18 16:27:26 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void ft_print_op(t_carriage *car, t_op op, int32_t args[3], t_val *val)
{
    int i;

    if (!(val->value_param == 4 || val->value_param == 30))
        return ;
    ft_printf("P %4d | %s", car->numb, op.name);
    i = 0;
    while (i < op.count_args)
    {
        if (car->targ[i] == T_REG)
            ft_printf(" r%d", args[i] + 1);
        else
            ft_printf(" %d", args[i]);
        i++;
    }
    ft_printf("\n");
}

void    print_one_step(t_val *val, t_game *game, t_carriage *car, unsigned int new_pc)
{
    unsigned int i;
	unsigned int step;

	if (new_pc < car->save_pc)
		step = MEM_SIZE - car->save_pc + new_pc;
	else
		step = new_pc - car->save_pc;
    i = 0;
    if (val->value_param == 16 || val->value_param == 30)
	{
		ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", step, car->save_pc, new_pc);
		while (i < step)
		{
			ft_printf("%.2x ", game->arena[(car->save_pc + i) % MEM_SIZE]);
			i++;
		}
		ft_printf("\n", game->arena[(car->save_pc + i) % MEM_SIZE]);
	}
}

void    print_one_step_fork(t_val *val, t_game *game, t_carriage *car, unsigned int new_pc)
{
    unsigned int i;
	unsigned int step;

	if (new_pc < car->save_pc)
		step = MEM_SIZE - car->save_pc + new_pc;
	else
		step = new_pc - car->save_pc;
    i = 0;
    if (val->value_param == 16 || val->value_param == 30)
	{
		ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", step, car->save_pc, new_pc);
		while (i < step)
		{
			ft_printf("%.2x ", game->arena[(car->save_pc + i) % MEM_SIZE]);
			i++;
		}
		ft_printf("\n");
	}
}
