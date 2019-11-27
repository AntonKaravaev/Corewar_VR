#include "corewar.h"

int revision(t_game *game)
{
	t_list *list;
	t_carriage *car;
	t_list *pr_list;
	char *str;

	game->checks++;

	//dell died carriage
	
	//for test
	ft_printf("введите переменную live\n");
	get_next_line(0, &str);
	game->live = ft_atoi(str);

	list = game->carriages;
	while (list != NULL)
	{
		car = (t_carriage*)(list->content);
		if (game->hook - car->live > game->cycles_to_die) //удаление каретки 
		{
			ft_printf("del = %d\n", car->numb);
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
			ft_printf("Notdel = %d\n", car->numb);
			pr_list = list;
			list = list->next;
		}
	}
	//модификация c_t_d
	ft_printf("check = %d ", game->checks);
	if (game->live >= NBR_LIVE || game->checks > MAX_CHECKS)
	{
		game->cycles_to_die -= CYCLE_DELTA;
		game->checks = 0;
	}
	ft_printf("hook=%d,  live=%d,  ctd = %d\n",
		game->hook, game->live, game->cycles_to_die);
	show_carriage_list(game->carriages);
	game->live = 0;
	return (game->cycles_to_die);
}

void start_game(t_game *game, int dump_value)
{
	t_list      *list;
	t_carriage  *car;
	int         left_to_check;

	left_to_check = game->cycles_to_die;
	/*
	//test
	game->hook = 24244;
	game->cycles_to_die=136;
	left_to_check = 0;
	*/
	while (game->carriages != NULL) //hook
	{	
		list = game->carriages;
		while (list != NULL) // hook of carriage
		{
			car = (t_carriage*)(list->content);
			if (car->hookbefexe == 0) 
				cycles_before_execution(car, car->operation);
			if (car->hookbefexe > 0)
				car->hookbefexe--;
			if (car->hookbefexe == 0)
				//operations(game, car, car->operation);// доделать
			list=list->next;
		}
		if (left_to_check <= 0)//или в начале?
			left_to_check = revision(game);
		left_to_check--;
		game->hook++;
		if (game->hook == dump_value)
			show_arena(game);
	}
}

void            init_game(t_game *game, int amount_of_players, int dump_value)
{
	int i;
	int j;
	int bite;
	t_carriage new_carriage;
	t_list *new;

	//init_arena
	dump_value = 0;
	ft_bzero(game->arena, MEM_SIZE);
	i = 0;
	while (i < amount_of_players)
	{
		j = 0;
		bite = j + MEM_SIZE / amount_of_players * i;
		while (j < (game->champ[i]).exec_code_size && bite <  MEM_SIZE / amount_of_players * (i + 1))
		{
			game->arena[bite] = (game->champ[i]).exec_code[j];
			bite++;
			j++;
		}
		i++;
	}

	game->last_alive = amount_of_players;// true?
	game->hook = 0;
	game->live = 0;
	game->cycles_to_die = CYCLE_TO_DIE;
	game->checks = 0;
	game->carriages = NULL;
	i = 0;
	while (++i  < REG_NUMBER)
		new_carriage.reg[i] = 0;
	new_carriage.operation = 0; // norm? 
	new_carriage.live = -1;
	new_carriage.carry = 0;
	new_carriage.step = 0; //right ?
	new_carriage.hookbefexe = 0;
	i = 0;
	while(++i <= amount_of_players)
	{
		new_carriage.numb = i;
		new_carriage.pc = (MEM_SIZE / amount_of_players) * i;
		new_carriage.reg[0] = -i;
		if (!(new = ft_lstnew((void*)&new_carriage, sizeof(t_champ))))
			ft_error("memor :(");
		ft_lstadd(&(game->carriages), new); 
	}
	show_game(game);
	start_game(game, dump_value);
}