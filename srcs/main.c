/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:00:55 by crenly-b          #+#    #+#             */
/*   Updated: 2019/11/10 16:47:47 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_catch_argv(t_val *val, int ac, char ***str)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (i > 1)
			ft_strcat(val->str_of_players, " ");
		ft_strcat(val->str_of_players, ((*str)[i]));
		i++;
	}
}

void	ft_val_initial(t_val *val)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_bzero(&val->players[i], MAX_LENGTH_OF_PLAYER);
		i++;
	}
	i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_bzero(&val->temp_players[i], MAX_LENGTH_OF_PLAYER);
		i++;
	}
	i = 0;
	ft_bzero(&val->str_of_players, STR_OF_PLAYERS);
	val->amount_of_players = 0;
	val->flag_dump = 0;
    val->flag_visual = 0;
	val->dump_value = 0;
}

int		ft_check_pos(int pos)
{
	if (pos < 0 || pos >= MAX_PLAYERS)
		ft_error("Incorrect position of the player.");
	return (pos);
}

int		ft_check_dump(int dump)
{
	if (dump <= 0)
		ft_error("Incorrect dump.");
	return (1);
}

void	ft_find_flags(t_val *val, char ***str)
{
	int i;
	int j;
	int z;
	int pos;

	i = 0;
	j = 0;
	z = 0;
	pos = 0;
	while ((*str)[i] != NULL)
	{
		if (ft_strstr((*str)[i], ".cor") != NULL && (*str)[i][0] != '.')
		{
			if (val->amount_of_players > MAX_PLAYERS)
				ft_error("Too many players.");
			ft_strcat(val->temp_players[j++], (*str)[i]);
			val->amount_of_players++;
		}
		else if (ft_strequ((*str)[i], "-n") == 1)
		{
			if (val->amount_of_players > MAX_PLAYERS)
				ft_error("Too many players.");
			i++;
			if ((*str)[i] == NULL)
				ft_error("Incorrect input.");
			pos = ft_check_pos(ft_atoi((*str)[i]) - 1);
			if (val->players[pos][0] == 0)
			{
				i++;
				if ((*str)[i] == NULL)
					ft_error("Incorrect input.");
				if (ft_strstr((*str)[i], ".cor") != NULL && (*str)[i][0] != '.')
				{
					ft_strcat(val->players[pos], (*str)[i]);
					val->amount_of_players++;
				}
				else
					ft_error("Incorrect input.");
			}
			else
				ft_error("Duplication of player's positions.");
		}
		else if (ft_strequ((*str)[i], "-dump") == 1)
		{
			if (val->flag_dump == 0)
			{
				val->flag_dump = 1;
				if ((*str)[++i] != NULL)
					val->dump_value = ft_check_dump(ft_atoi((*str)[i]));
				else
					ft_error("Incorrect input ""-dump"" value.");
			}
			else
				ft_error("Incorrect input \"-dump\".");
		}
		else if (ft_strequ((*str)[i], "-v") == 1)
		{
			if (val->flag_visual == 0)
				val->flag_visual = 1;
			else
				ft_error("Incorrect input visualisation \"-v\".");
		}
		else
			ft_error("Incorrect input.");
		i++;
	}
	if (val->amount_of_players == 0)
		ft_error("No players.");
	if (val->amount_of_players > MAX_PLAYERS)
		ft_error("Too much players.");
	i = 0;
	j = 0;
	while (i < MAX_PLAYERS)
	{
		if (val->players[i][0] == 0)
		{
			while (j < val->amount_of_players)
			{
				if (val->temp_players[j][0] != 0)
				{
					ft_strcat(val->players[i], val->temp_players[j]);
					j++;
					break ;
				}
				j++;
			}
		}
		i++;
	}
	i = 0;
	z = 0;
	while (i < MAX_PLAYERS)
	{
		if (val->players[i][0] == 0)
		{
			z = i;
			while (z < MAX_PLAYERS && val->players[z][0] == 0)
				z++;
			if (z < MAX_PLAYERS && val->players[z][0] != 0)
			{
				ft_strcat(val->players[i], val->players[z]);
				z++;
			}
		}
		i++;
	}
	i = 0;
	while (i < val->amount_of_players)
	{
		ft_printf("val->players[%d] = %s\n", i, val->players[i]);
		i++;
	}
}

void	ft_find_players_and_flags(t_val *val)
{
	char **str;

	if (!(str = ft_strsplit(val->str_of_players, ' ')))
		ft_error("Some problems with input.");
	ft_find_flags(val, &str);
	ft_str2del(&str);
}

int		main(int argc, char *argv[])
{
	t_val	val;

	ft_val_initial(&val);
	if (argc >= 2)
	{
		ft_catch_argv(&val, argc, &argv);
		ft_find_players_and_flags(&val);
	}
	else
		ft_error("Not enough arguments.");
	return (0);
}
