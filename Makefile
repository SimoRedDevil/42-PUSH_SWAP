# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:23:26 by mel-yous          #+#    #+#              #
#    Updated: 2023/03/10 20:50:22 by mel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
SRCS = push_swap.c linked_list_func.c helper.c indexing.c read_join_split.c parser.c \
	   single_instructions.c multi_instructions.c optimal_move.c tiny_sort.c large_sort.c
OBJS = $(SRCS:.c=.o)

B_SRCS = bonus/checker_bonus.c bonus/helper_bonus.c bonus/indexing_bonus.c bonus/ins_executor_bonus.c \
         bonus/join_split_bonus.c bonus/linked_list_func_bonus.c bonus/multi_ins_bonus.c \
		 bonus/parser_bonus.c bonus/single_ins_bonus.c
B_OBJS = $(B_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a
GNL = bonus/get_next_line/gnl.a

all: $(NAME)
bonus: $(B_NAME)

$(B_NAME): $(B_OBJS)
	make -C libft/
	make -C bonus/get_next_line/
	$(CC) $(B_OBJS) $(LIBFT) $(GNL) -o $(B_NAME)

%_bonus.o: %_bonus.c bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft/
	make clean -C bonus/get_next_line/
	rm -rf $(OBJS)
	rm -rf $(B_OBJS)
fclean:	clean
	rm -rf $(NAME)
	rm -rf $(B_NAME)
	rm -rf $(LIBFT)
	rm -rf $(GNL)
re : fclean all