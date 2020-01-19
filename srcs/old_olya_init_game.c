/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_olya_init_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:22:20 by crenly-b          #+#    #+#             */
/*   Updated: 2020/01/18 14:44:39 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int revision(t_game *game, t_val *val)
{
	t_list *list;
	t_carriage *car;
	t_list *pr_list;

	game->checks++;
	list = game->carriages;
	while (list != NULL)
	{
		car = (t_carriage*)(list->content);
		if (game->hook - car->live >= game->cycles_to_die) //удаление каретки 
		{
			//ft_printf("del = %d\n", car->numb);
			if (val->value_param == 30)
			{
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", car->numb, car->live > 0 ? game->hook - car->live : game->hook, game->cycles_to_die);
			}
			free(car);
			if (game->carriages == list)
			{
				game->carriages = list->next;
				ft_memdel((void**)&list);
				list = game->carriages;
			}
			else
			{
				pr_list->next = list->next;
				ft_memdel((void**)&list);
				list = pr_list->next;
			}
		}
		else
		{
			//ft_printf("Notdel = %d\n", car->numb);
			pr_list = list;
			list = list->next;
		}
	}
	//ft_printf("check = %d ", game->checks);
	if (game->live >= NBR_LIVE || game->checks >= MAX_CHECKS) //?game->checks > MAX_CHECKS
	{
		game->cycles_to_die -= CYCLE_DELTA;
		if (val->value_param == 30)
			ft_printf("Cycle to die is now %d\n", game->cycles_to_die);
		game->checks = 0;
	}
	//ft_printf("hook=%d,  live=%d,  ctd = %d\n", game->hook, game->live, game->cycles_to_die);
	//show_carriage_list(game->carriages);
	game->live = 0;
	return (game->cycles_to_die);
}

void		start_game(t_val *val, t_game *game, int dump_value)
{
	t_list      *list;
	t_carriage  *car;
	int         left_to_check;
	t_champ		champ;

	left_to_check = game->cycles_to_die;
	while (game->carriages != NULL) //hook
	{
		//ft_printf("now cycle %d\n", game->hook);
		
		if (val->value_param == 2 || val->value_param == 30)
		{
			if (val->dump_value != 0)
				ft_printf("It is now cycle %d\n", game->hook);
		}
		list = game->carriages;
		while (list != NULL) // hook of carriage
		{
			car = (t_carriage*)(list->content);
			//ft_printf("car->numb = %d\n", -car->reg[0]);
			if (car->hookbefexe == 0) 
				cycles_before_execution(car, game->arena[(car->pc) % MEM_SIZE]);
			if (car->hookbefexe > 0)
				car->hookbefexe--;
			if (car->hookbefexe == 0)
				operation(val, game, car, car->operation);// доделать
			list = list->next;
		}
		left_to_check--;
		if (left_to_check <= 0)//или в начале?
			left_to_check = revision(game, val);
		if (game->hook == dump_value)
		{
			//ft_printf("\n\nAFTER DUMP = %d \n\n", dump_value);
			show_arena(game);
			//ft_error("STOP GAME BY DUMP");
			exit(1); // bad
		}
		game->hook++;
	}
	champ = game->champ[game->last_alive - 1];
	ft_printf("Contestant %d, \"%s\", has won !\n", game->last_alive, champ.name);
}

void            init_game(t_game *game, int amount_of_players)
{
	int i;
	int j;
	int bite;
	t_carriage new_carriage;
	t_list *new;

	//init_arena
	ft_bzero(game->arena, MEM_SIZE);
	i = 0;
	while (i < amount_of_players)
	{
		j = 0;
		bite = j + MEM_SIZE / amount_of_players * i;
		while (j < (game->champ[i]).exec_code_size && 
				bite <  MEM_SIZE / amount_of_players * (i + 1))
		{
			game->arena[bite] = (game->champ[i]).exec_code[j];
			bite++;
			j++;
		}
		i++;
	}
	game->last_alive = amount_of_players;// true?
	game->hook = 1;
	game->live = 0;
	game->cycles_to_die = CYCLE_TO_DIE;
	game->checks = 0;
	game->carriages = NULL;
	game->champs = amount_of_players;
	game->count_carriage = amount_of_players;
	i = 0;
	while (++i  < REG_NUMBER)
		new_carriage.reg[i] = 0;
	//new_carriage.operation = 0; // norm? 
	new_carriage.live = -1; // ?
	new_carriage.carry = 0;
	//new_carriage.step = 0; //right ?
	new_carriage.hookbefexe = 0;
	i = 0;
	while(++i <= amount_of_players)
	{
		new_carriage.numb = i;
		new_carriage.pc = (MEM_SIZE / amount_of_players) * (i - 1);
		new_carriage.reg[0] = -i;
		if (!(new = ft_lstnew((void*)&new_carriage, sizeof(t_carriage))))
			ft_error("memor :(");
		ft_lstadd(&(game->carriages), new); 
	}
	//  ft_printf("\n\nAFTER INIT \n\n");
	//  show_arena(game);
	//  ft_printf("\n\nEND AFTER INIT \n\n");
}
