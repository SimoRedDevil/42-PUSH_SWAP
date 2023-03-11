/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:28:20 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 15:32:01 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

static int	ft_skipper(const char *str, int *ptrsign)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*(ptrsign) *= (-1);
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					i;
	int					sign;

	result = 0;
	sign = 1;
	i = ft_skipper(str, &sign);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647 && sign == 1)
			throw_error();
		else if (result > 2147483648 && sign == -1)
			throw_error();
		i++;
	}
	return ((int)result * sign);
}
