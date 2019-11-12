/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:55:33 by crenly-b          #+#    #+#             */
/*   Updated: 2019/11/12 15:00:07 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"
# include <string.h> 

# define STR_OF_PLAYERS 500
# define MAX_PLAYERS 4
# define SOP_FLAGS 4
# define MAX_LENGTH_OF_PLAYER 100
# define MEM_SIZE 4096
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

// -n
// -dump
// - vm

// has too large a code (993 bytes > 682 bytes) 
// Champion exec code


typedef struct	s_val
{
    char	str_of_players[STR_OF_PLAYERS];
    char	players[MAX_PLAYERS][MAX_LENGTH_OF_PLAYER];
    char	temp_players[MAX_PLAYERS][MAX_LENGTH_OF_PLAYER];
    int		amount_of_players;
    int		flag_dump; // -dump
    int		dump_value; // -dump
    int		flag_visual; // -v
}				t_val;


int				main(int argc, char *argv[]);
void			ft_find_players_and_flags(t_val *val);
int				ft_if_minus_n(char ***str, t_val *val, int *i, int *pos);
int				ft_if_dump(char ***str, t_val *val, int *i);
void            ft_print_players(t_val *val);
void			ft_sort_players(t_val *val);
int				ft_if_point_cor(char ***str, t_val *val, int *i, int *j);
int				ft_check_pos(int pos);
int				ft_check_dump(int dump);
int				ft_if_visual(char ***str, t_val *val, int *i);

#endif


/*
    Размер файла не должен быть больше 682 bytes

ФУНКЦИЯ ДЛЯ ПОИСКА РАЗМЕРА ФАЙЛА!
fseek(f, 0, SEEK_END); // seek to end of file
size = ftell(f); // get current file pointer
fseek(f, 0, SEEK_SET); // seek back to beginning of file
// proceed with allocating memory and reading the file

*/