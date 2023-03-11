/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:54:07 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 18:41:28 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	throw_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	fill_stack_a(t_stack **stack_a, int num)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (*stack_a == NULL)
		*stack_a = create_node(num);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_node(num);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_input_ins(const char *ins)
{
	int	len;

	len = gnl_ft_strlen(ins, '\n');
	if (len <= 1 || len >= 4)
		throw_error();
	if (ins[0] != 's' && ins[0] != 'r' && ins[0] != 'p')
		throw_error();
	if (len == 2)
	{
		if (ins[0] == 's')
			if (ins[1] != 'a' && ins[1] != 'b' && ins[1] != 's')
				throw_error();
		if (ins[0] == 'r')
			if (ins[1] != 'a' && ins[1] != 'b' && ins[1] != 'r')
				throw_error();
		if (ins[0] == 'p')
			if (ins[1] != 'a' && ins[1] != 'b')
				throw_error();
	}
	if (len == 3)
		if (ins[1] != 'r' || (ins[2] != 'a' && ins[2] != 'b' && ins[2] != 'r'))
			throw_error();
}
