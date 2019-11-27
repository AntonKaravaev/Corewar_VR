/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:00:55 by crenly-b          #+#    #+#             */
/*   Updated: 2019/11/14 12:56:47 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

int		main(int argc, char *argv[])
{
	t_val	val;
	t_game	game;
	int		dump_value;

	dump_value = 0; //найти это значение из консоли 
	ft_val_initial(&val);
	if (argc >= 2)
	{
		ft_catch_argv(&val, argc, &argv);
		ft_find_players_and_flags(&val);
		ft_analyse_players(&val, game.champ);
		init_game(&game, val.amount_of_players, dump_value);
	}
	else
		ft_error("Not enough arguments.");
	return (0);
}
