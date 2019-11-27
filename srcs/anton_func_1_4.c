/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anton_func_1_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:07:30 by crenly-b          #+#    #+#             */
/*   Updated: 2019/11/27 18:04:03 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    ft_live(t_game *game, t_carriage *car)
{
    (void)game;
    (void)car;
	ft_printf("I want to do ft_live\n");
}

void    ft_ld(t_game *game, t_carriage *car)
{
    (void)game;
    (void)car;
	ft_printf("I want to do ft_ld\n");
    car->pc = (car->pc + 1) % MEM_SIZE;
}

void    ft_st(t_game *game, t_carriage *car)
{
    (void)game;
    (void)car;
	ft_printf("I want to do ft_st\n");
    car->pc = (car->pc + 1) % MEM_SIZE;
}

void    ft_add(t_game *game, t_carriage *car)
{
    (void)game;
    (void)car;
	ft_printf("I want to do ft_add\n");
}
