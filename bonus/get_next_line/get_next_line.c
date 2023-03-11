/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:43:51 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/09 16:53:39 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_found_nl(char *save)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_save_temp(char *s1, char *s2)
{
	char	*tmp;

	if (!s1)
		s1 = gnl_ft_strdup("");
	tmp = gnl_ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

static char	*ft_extract_line(char **save)
{
	char	*tmp;
	char	*line;
	int		i;
	int		full_len;

	if (!save || !(*save))
		return (NULL);
	tmp = gnl_ft_strdup(*save);
	full_len = gnl_ft_strlen(tmp, '\0');
	i = gnl_ft_strlen(tmp, '\n');
	free(*save);
	line = gnl_ft_substr(tmp, 0, i + 1);
	*save = gnl_ft_substr(tmp, i + 1, full_len - i);
	free(tmp);
	tmp = NULL;
	return (line);
}

static void	ft_read_save(int fd, char **save)
{
	char	*buff;
	int		r;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(*save);
		return ;
	}
	r = 1;
	while (r != 0 && ft_found_nl(*save) == 0)
	{
		r = (int)read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(buff);
			free(*save);
			*save = NULL;
			return ;
		}
		buff[r] = '\0';
		*save = ft_save_temp(*save, buff);
	}
	free(buff);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*currentline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	ft_read_save(fd, &save);
	currentline = ft_extract_line(&save);
	return (currentline);
}
