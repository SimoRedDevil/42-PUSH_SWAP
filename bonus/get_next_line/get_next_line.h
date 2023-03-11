/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:43:54 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 18:50:09 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	gnl_ft_strlen(const char *s, char c);
char	*gnl_ft_strdup(const char *s1);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_substr(char *s, unsigned int start, size_t len);
#endif
