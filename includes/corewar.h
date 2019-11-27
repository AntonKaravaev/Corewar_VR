/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:55:33 by crenly-b          #+#    #+#             */
/*   Updated: 2019/11/14 13:08:44 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"
# include <string.h>
# include "op.h"

# define STR_OF_PLAYERS 500
# define MAX_LENGTH_OF_PLAYER 100

// -n
// -dump
// - vm

// has too large a code (993 bytes > 682 bytes) 
// Champion exec code

typedef struct s_champ
{
    int fd;
    int number; // anton
	char name[PROG_NAME_LENGTH];
	int exec_code_size;
	char comment[COMMENT_LENGTH];
	uint8_t exec_code[CHAMP_MAX_SIZE];
}   t_champ;

typedef struct s_carriage
{
	int numb; // index in list?
	int carry : 1;
	uint8_t operation; //byte
	int live; //initilize -1 ? yes // hook 
	int	hookbefexe;
	int pc; //address
	int step;
	int reg[REG_NUMBER];
}	t_carriage;

typedef struct s_game
{
	uint8_t	arena[MEM_SIZE];
	t_champ	champ[MAX_PLAYERS];
	int		last_alive;//int?
	int		hook;
	int		live; // количество выполеннных live в ctd
	int		cycles_to_die;
	int		checks;//количество проверок, в которых ctd не меняется 
	t_list	*carriages;
}	t_game;

typedef struct	s_val
{
    char	str_of_players[STR_OF_PLAYERS];
    t_champ     inf_play[MAX_PLAYERS];
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
void		    ft_analyse_players(t_val *val, t_champ *champ);



void            init_champ(int fd, t_champ *champ);
void            init_game(t_game *game, int amount_of_players, int dump_value);
void			show_game(t_game *game);
void			show_carriage_list(t_list *car_list);
void			show_arena(t_game *game);
void			cycles_before_execution(t_carriage *car, uint8_t oper);
int				ft_zjmp(t_game *game, t_carriage *car);
#endif

/*
    Размер файла не должен быть больше 682 bytes

ФУНКЦИЯ ДЛЯ ПОИСКА РАЗМЕРА ФАЙЛА!
fseek(f, 0, SEEK_END); // seek to end of file
size = ftell(f); // get current file pointer
fseek(f, 0, SEEK_SET); // seek back to beginning of file
// proceed with allocating memory and reading the file

*/