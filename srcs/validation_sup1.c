/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_sup1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:05:17 by crenly-b          #+#    #+#             */
/*   Updated: 2019/11/12 15:06:24 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_if_point_cor(char ***str, t_val *val, int *i, int *j)
{
	if (ft_strstr((*str)[*i], ".cor") != NULL && (*str)[*i][0] != '.')
	{
		if (val->amount_of_players > MAX_PLAYERS)
			ft_error("Too many players.");
		ft_strcat(val->temp_players[(*j)++], (*str)[*i]);
		val->amount_of_players++;
		return (1);
	}
	return (0);
}

int			ft_if_visual(char ***str, t_val *val, int *i)
{
	if (ft_strequ((*str)[*i], "-v") == 1)
		{
			if (val->flag_visual == 0)
			{
				val->flag_visual = 1;
				return (1);
			}
			else
				ft_error("Incorrect input visualisation \"-v\".");
		}
	else
		ft_error("Incorrect input.");
	return (0);
}

int			ft_if_dump(char ***str, t_val *val, int *i)
{
	if (ft_strequ((*str)[*i], "-dump") == 1)
	{
		if (val->flag_dump == 0)
		{
			val->flag_dump = 1;
			if ((*str)[++(*i)] != NULL)
			{
				val->dump_value = ft_check_dump(ft_atoi((*str)[*i]));
				return (1);
			}
			else
				ft_error("Incorrect input ""-dump"" value.");
		}
		else
			ft_error("Incorrect input \"-dump\".");
	}
	return (0);
}

int         ft_if_minus_n(char ***str, t_val *val, int *i, int *pos)
{
    if (ft_strequ((*str)[*i], "-n") == 1)
	{
		if (val->amount_of_players > MAX_PLAYERS)
			ft_error("Too many players.");
		if ((*str)[++(*i)] == NULL)
			ft_error("Incorrect input.");
		*pos = ft_check_pos(ft_atoi((*str)[*i]) - 1);
		if (val->players[*pos][0] == 0)
		{
			if ((*str)[++(*i)] == NULL)
				ft_error("Incorrect input.");
			if (ft_strstr((*str)[*i], ".cor") != NULL && (*str)[*i][0] != '.')
			{
				ft_strcat(val->players[*pos], (*str)[*i]);
				val->amount_of_players++;
				return (1);
			}
			else
				ft_error("Incorrect input.");
		}
		else
			ft_error("Duplication of player's positions.");
	}
	return (0);
}