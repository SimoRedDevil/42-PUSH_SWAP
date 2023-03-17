/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_split_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:53:20 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/15 15:35:39 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*call_strjoin(char *s1, char *s2)
{
	int		i;
	char	*with_space;
	char	*result;

	i = 0;
	while (s2[i] == ' ')
		i++;
	if (s2[i] == '\0')
		throw_error();
	if (!s1)
		s1 = ft_strdup("");
	with_space = ft_strjoin(s1, " ");
	result = ft_strjoin(with_space, s2);
	free(s1);
	free(with_space);
	return (result);
}

char	**get_splitted_args(int ac, char **av)
{
	int		i;
	char	*joined;
	char	**tab;

	i = 1;
	joined = NULL;
	while (i < ac)
	{
		joined = call_strjoin(joined, av[i]);
		i++;
	}
	tab = ft_split((const char *)joined, ' ');
	free(joined);
	joined = NULL;
	if (!tab)
		throw_error();
	return (tab);
}
