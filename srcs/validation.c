/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:04:31 by crenly-b          #+#    #+#             */
/*   Updated: 2019/11/12 15:04:04 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	int pos;

	i = -1;
	j = 0;
	pos = 0;
	while ((*str)[++i] != NULL)
	{
		if (ft_if_point_cor(str, val, &i, &j) == 1)
		    ;
		else if (ft_if_minus_n(str, val, &i, &pos) == 1)
            ;
		else if (ft_if_dump(str, val, &i) == 1)
		    ;
		else if (ft_if_visual(str, val, &i) == 1)
		    ;
	}
	ft_sort_players(val);
    ft_print_players(val);
}

void	ft_find_players_and_flags(t_val *val)
{
	char **str;

	if (!(str = ft_strsplit(val->str_of_players, ' ')))
		ft_error("Some problems with input.");
	ft_find_flags(val, &str);
	ft_str2del(&str);
}