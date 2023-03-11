/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:24:28 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 00:49:55 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*This function check's if there is nothing after the sign,
if true then throw an error.
And check if there is a number before the sign, if true throw an error*/
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

/*Check if the passed argument contains a character that isn't an digit,
if true then throw an error
PS: + and - will be skipped*/
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

/*This function check's if a number is duplicated,
if true then throw an error*/
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

/*Check if the input is valid or not*/
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
}