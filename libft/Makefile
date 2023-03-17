# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 20:18:10 by mel-yous          #+#    #+#              #
#    Updated: 2023/03/10 22:46:45 by mel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_atoi.c ft_putendl_fd.c ft_substr.c\
		ft_bzero.c ft_putstr_fd.c ft_strlen.c ft_isalnum.c ft_split.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strdup.c ft_isdigit.c ft_strrchr.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $<

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)
re : fclean all

.PHONY: all clean fclean re