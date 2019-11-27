#include "corewar.h"

void show_arena(t_game *game)
{
    int i;

    i = 0;
    ft_printf("\nARENA\n");
    while (i <  MEM_SIZE)
    {
        ft_printf("%.2x", game->arena[i]);
        i++;
        if (i % (2 * 32) == 0)//last лишний
            ft_putchar('\n');
        else if (i % 2 == 0)//last лишний
            ft_putchar(' ');
    }
}

void show_game(t_game *game)
{
    ft_printf("last_alive = %d\n hook = %d\n live = %d\n cycle_to_die = %d\n checks= %d\n", 
        game->last_alive, game->hook, game->live, game->cycles_to_die, game->checks);
    show_arena(game);
    show_carriage_list(game->carriages);
}

void show_carriage_list(t_list *car_list)
{
    t_carriage *car;
    int i;

    ft_printf("\nCARRIAGE\n");
    while (car_list != NULL)
    {
        car = (t_carriage*)(car_list->content);  
        //for test!!!!
       // if (car->numb == 2)
       //     car->live = 0;
        ft_printf("numb = %d\ncarry = %d\n operation = %.2x\n", car->numb, car->carry, car->operation);
        ft_printf("live = %d\naddr = %d\n step = %d\n", car->live, car->pc, car->step);
        i = 0;
        while (i  < REG_NUMBER)
        {
            ft_printf("red[%d] = %d\n", i, car->reg[i]);
            i++;
        }
        ft_printf("\n");
        car_list = car_list->next;
    }
}