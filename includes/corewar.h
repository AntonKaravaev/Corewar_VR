/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:55:33 by crenly-b          #+#    #+#             */
/*   Updated: 2020/01/19 18:47:06 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"
# include <string.h>
# include "op.h"

# define STR_OF_PLAYERS 500
# define MAX_LENGTH_OF_PLAYER 100

# define LEN_ARGS_CODE 1

typedef struct	s_champ
{
    int			d;
    int			number; // anton
	char		name[PROG_NAME_LENGTH + 1];
	int			exec_code_size;
	char		comment[COMMENT_LENGTH + 1];
	__uint8_t	exec_code[CHAMP_MAX_SIZE];
}   t_champ;

typedef enum	e_bool
{
	false,
	true 
} t_bool; 

typedef struct	s_carriage
{
	int				numb; // index in list?
	t_bool			carry;
	uint8_t		operation; //byte
	int				live; //initilize -1 ? yes // hook 
	int				hookbefexe;
	unsigned int	pc; //address
	int				step; // ??
	unsigned int	save_pc;
	int32_t		reg[REG_NUMBER];
	uint8_t		targ[3];
	int32_t		without_move;
	//int32_t      	args[3];
}	t_carriage;

typedef struct	s_game
{
	uint8_t	arena[MEM_SIZE];
	t_champ	champ[MAX_PLAYERS];
	int		last_alive;//int?
	int		hook;
	int		live; // количество выполеннных live в ctd
	int		cycles_to_die;
	int		checks;//количество проверок, в которых ctd не меняется 
	t_list	*carriages;
	int		champs;
	int		dump_value; // костыль Антона!
	int		count_carriage;
}			t_game;

typedef struct	s_val
{
    char	str_of_players[STR_OF_PLAYERS];
    t_champ	inf_play[MAX_PLAYERS];
    char	players[MAX_PLAYERS][MAX_LENGTH_OF_PLAYER];
    char	temp_players[MAX_PLAYERS][MAX_LENGTH_OF_PLAYER];
    int		amount_of_players;
    int		flag_dump; // -dump
    int		dump_value; // -dump
	int		v_param;
	int		value_param;
    int		flag_visual; // -v
	int		flag_aff_flag;
}				t_val;


typedef struct	s_op
{
  char			*name;
  uint8_t		code;
  t_bool		tcode;
  int			count_args;
  uint8_t		targ[3];
  uint32_t		wait_cycles;
  int			dir_size;
  t_bool		idx_mod;
  //int		(*func)(t_game *, t_carriage, t_op); 
}			t_op;

//int				main(int argc, char *argv[]);
void			ft_find_players_and_flags(t_val *val);
int				ft_if_minus_n(char ***str, t_val *val, int *i, int *pos);
int				ft_if_dump(char ***str, t_val *val, int *i);
void            ft_print_players(t_val *val);
void			ft_sort_players(t_val *val);
int				ft_if_point_cor(char ***str, t_val *val, int *i, int *j);
int				ft_check_pos(int pos);
int				ft_dump_param(char ***str, t_val *val, int *i);
int				ft_if_visual(char ***str, t_val *val, int *i);
int				ft_if_aff_flag(char ***str, t_val *val, int *i);
void		    ft_analyse_players(t_val *val, t_champ *champ, int *champs);
//void	ft_val_initial(t_val *val);


void			init_champ(int fd, t_champ *champ);
void            init_game(t_game *game, int amount_of_players);
void			start_game(t_val *val, t_game *game, int dump_value);
void			show_game(t_game *game);
void			show_carriage_list(t_list *car_list);
void			show_arena(t_game *game);
void			cycles_before_execution(t_carriage *car, __uint8_t oper);
void			operation(t_val *val, t_game *game, t_carriage *car, __uint8_t operation);
void			ft_introducing_contestants(t_champ champ[], int champs);

//int				take_values(t_carriage *car, uint8_t arena[], t_op op);
int				shift_arg(__uint8_t t_array[], int size, int dir_size);
int32_t			take_value_shift_pc(__uint8_t type, __uint8_t arena[], t_carriage *car, t_op op);
int				check_targ(__uint8_t arena[], t_carriage *car, t_op op, unsigned int *new_pc);
void			take_targ(__uint8_t byte, __uint8_t targ[], int size);
t_carriage		copy_carriage(t_carriage *car, t_game *game);
void			int_to_bytes(int numb, __uint8_t arena[], int pc, int size);
int				bytes_to_int(__uint8_t arena[], int pc, int size);
int				idx_mod(int pc);

void						ft_old_error(char **str);
int         				ft_check_dump(char ***str, int number, int *i);
void						ft_print_op(t_carriage *car, t_op op, int32_t args[3], t_val *val);
//int				mod(int pc);

void    					print_one_step(t_val *val, t_game *game, t_carriage *car, unsigned int new_pc);
void    					print_one_step_fork(t_val *val, t_game *game, t_carriage *car, unsigned int new_pc);
unsigned int				op_live(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_ld(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_st(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_add(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_sub(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_and(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_or(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_xor(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_zjmp(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_ldi(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_sti(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_fork(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_lld(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_lldi(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_lfork(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_aff(t_val *val, t_game *, t_carriage *, t_op);
unsigned int				op_null(t_val *val, t_game *, t_carriage *, t_op);

static t_op		op_tab[16] =
{
	{
		.name = "live", 
  		.code = 1, 
  		.tcode = false,
  		.count_args = 1,
  		.targ = {T_DIR, 0, 0},
  		.wait_cycles = 10,
  		.dir_size = 4,
		.idx_mod = true,
  	//	.func = &op_live
	},
	{
		.name = "ld", 
  		.code = 2, 
  		.tcode = true,
  		.count_args = 2,
  		.targ = {T_DIR | T_IND, T_REG, 0},
  		.wait_cycles = 5,
  		.dir_size = 4,
		.idx_mod = true,
  	//	.func = &op_ld
	},
	{
		.name = "st", 
  		.code = 3, 
  		.tcode = true,
  		.count_args = 2,
  		.targ = {T_REG, T_IND | T_REG, 0},
  		.wait_cycles = 5,
  		.dir_size = 4,
		.idx_mod = true,
  	//	.func = &op_st
	},
	{
		.name = "add", 
  		.code = 4, 
  		.tcode = true,
  		.count_args = 3,
  		.targ = {T_REG, T_REG, T_REG},
  		.wait_cycles = 10,
  		.dir_size = 4,
  		.idx_mod = true,
	//	.func = &op_add
	},
	{
		.name = "sub", 
  		.code = 5, 
  		.tcode = true,
  		.count_args = 3,
  		.targ = {T_REG, T_REG, T_REG},
  		.wait_cycles = 10,
  		.dir_size = 4,
		.idx_mod = true,
  	//	.func = &op_sub
	},
	{
		.name = "and", 
  		.code = 6, 
  		.tcode = true,
  		.count_args = 3,
  		.targ = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
  		.wait_cycles = 6,
  		.dir_size = 4,
		.idx_mod = true,
  	//	.func = &op_and
	},
	{
		.name = "or", 
  		.code = 7, 
  		.tcode = true,
  		.count_args = 3,
  		.targ = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
  		.wait_cycles = 6,
  		.dir_size = 4,
  		.idx_mod = true,
	//	.func = &op_or
	},
	{
		.name = "xor", 
  		.code = 8, 
  		.tcode = true,
  		.count_args = 3,
  		.targ = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
  		.wait_cycles = 6,
  		.dir_size = 4,
		.idx_mod = true,
  	//	.func = &op_xor
	},
	{
		.name = "zjmp", 
  		.code = 9, 
  		.tcode = false, //?
  		.count_args = 1,
  		.targ = {T_DIR, 0, 0},
  		.wait_cycles = 20,
  		.dir_size = 2,
		.idx_mod = true,
  	//	.func = &op_zjmp
	},
	{
		.name = "ldi", 
  		.code = 10, 
  		.tcode = true,
  		.count_args = 3,
  		.targ = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
  		.wait_cycles = 25,
  		.dir_size = 2,
		.idx_mod = true,
  	//	.func = &op_ldi
	},
	{
		.name = "sti", 
  		.code = 11, 
  		.tcode = true,
  		.count_args = 3,
  		.targ = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
  		.wait_cycles = 25,
  		.dir_size = 2,
		.idx_mod = true,
  	//	.func = &op_sti
	},
	{
		.name = "fork", 
  		.code = 12, 
  		.tcode = false,
  		.count_args = 1,
  		.targ = {T_DIR, 0, 0},
  		.wait_cycles = 800,
  		.dir_size = 2,
		.idx_mod = true,
  	//	.func = &op_fork
	},
	{
		.name = "lld", 
  		.code = 13, 
  		.tcode = true,
  		.count_args = 2,
  		.targ = {T_DIR | T_IND, T_REG, 0},
  		.wait_cycles = 10,
  		.dir_size = 4,
		.idx_mod = false,
  	//	.func = &op_lld
	},
	{
		.name = "lldi", 
  		.code = 14, 
  		.tcode = true,
  		.count_args = 3,
  		.targ = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
  		.wait_cycles = 50,
  		.dir_size = 2,
		.idx_mod = true,
  	//	.func = &op_lldi
	},
	{
		.name = "lfork", 
  		.code = 15, 
  		.tcode = false,
  		.count_args = 1,
  		.targ =  {T_DIR, 0, 0},
  		.wait_cycles = 1000,
  		.dir_size = 2,
		.idx_mod = false,
  	//	.func = &op_lfork
	},
	{
		.name = "aff",
  		.code = 16,
  		.tcode = true,
  		.count_args = 1,
  		.targ =  {T_REG, 0, 0},
  		.wait_cycles = 2,
  		.dir_size = 4,
		.idx_mod = true,
  	//	.func = &op_aff
	}
//	{0, 0, {0}, 0, 0, 0, 0, 0, &op_null}
};



#endif

/*
    Размер файла не должен быть больше 682 bytes

ФУНКЦИЯ ДЛЯ ПОИСКА РАЗМЕРА ФАЙЛА!
fseek(f, 0, SEEK_END); // seek to end of file
size = ftell(f); // get current file pointer
fseek(f, 0, SEEK_SET); // seek back to beginning of file
// proceed with allocating memory and reading the file

*/