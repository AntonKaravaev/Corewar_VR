# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 01:00:32 by crenly-b          #+#    #+#              #
#    Updated: 2019/11/27 17:15:46 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

FLAGS = -Wall -Wextra -Werror
HEADER = -I includes -I libft/includes
LIB		= -L libft/ -lft

LIST = main validation  validation_sup1 validation_sup2 delete_after_fin_project \
		olya_read_memory olya_init_game olya_show olya_operation ft_zjmp anton_func_1_4 \
		anton_func_5_8 \

OBJS = $(addprefix objs/, $(addsuffix .o, $(LIST)))

all: $(NAME)

objs/%.o: srcs/%.c includes/corewar.h includes/op.h
		gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME): objs make_lib $(OBJS) libft/libft.a 
		@gcc -o $(NAME) $(OBJS) $(LIB)
		@echo ✅ Corewar compiled!

make_lib:
	@make -C libft

objs:
		@mkdir objs 2> /dev/null || true

clean:
		@make -C libft/ clean
		@rm -rf ./objs/

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all
