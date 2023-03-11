/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:24:28 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 19:35:55 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_minus_plus(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '+' || str[i] == '-'))
		{
			if (!ft_isdigit(str[i + 1]))
				throw_error();
			if (i > 0 && ft_isdigit(str[i - 1]))
				throw_error();
		}
		i++;
	}
}

static void	check_numbers_only(const char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str++;
		if (!ft_isdigit(*str))
			throw_error();
		str++;
	}
}

static void	check_duplication(const char **tab, const char *num, int pos)
{
	int	i;

	i = 0;
	while (i < pos && tab[i])
	{
		if (ft_atoi(num) == ft_atoi(tab[i]))
			throw_error();
		i++;
	}
}

static void	check_if_sorted(const char **tab)
{
	int	i;
	int	is_sorted;
	int	j;

	i = 0;
	is_sorted = 1;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) > ft_atoi(tab[j]))
			{
				is_sorted = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	if (is_sorted == 1)
		exit(0);
}

void	parse_input(const char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		check_minus_plus(tab[i]);
		check_numbers_only(tab[i]);
		check_duplication(tab, tab[i], i);
		i++;
	}
	check_if_sorted(tab);
}
