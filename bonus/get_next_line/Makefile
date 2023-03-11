# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 18:52:19 by mel-yous          #+#    #+#              #
#    Updated: 2023/03/10 18:52:46 by mel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all