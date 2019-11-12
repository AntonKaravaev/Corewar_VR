/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_after_fin_project.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:24:34 by crenly-b          #+#    #+#             */
/*   Updated: 2019/11/12 15:05:09 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void        ft_print_players(t_val *val)
{
    int i;

    i = 0;
	while (i < val->amount_of_players)
	{
		ft_printf("val->players[%d] = %s\n", i, val->players[i]);
		i++;
	}
}