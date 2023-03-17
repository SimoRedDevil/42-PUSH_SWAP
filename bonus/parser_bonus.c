/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:24:28 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/15 15:39:22 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_bool	check_minus_plus(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '+' || str[i] == '-'))
		{
			if (!ft_isdigit(str[i + 1]))
				return (FALSE);
			if (i > 0 && ft_isdigit(str[i - 1]))
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static t_bool	check_numbers_only(const char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str++;
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static t_bool	check_dup(const char **tab, const char *num, int pos)
{
	int	i;

	i = 0;
	while (i < pos && tab[i])
	{
		if (ft_atoi(num) == ft_atoi(tab[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	parse_input(const char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!check_minus_plus(tab[i]) || !check_numbers_only(tab[i])
			|| !check_dup(tab, tab[i], i))
		{
			free_mem((char **)tab, NULL, NULL);
			throw_error();
		}
		ft_atoi(tab[i]);
		i++;
	}
}
