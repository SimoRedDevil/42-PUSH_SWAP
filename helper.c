/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:42:41 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 18:33:06 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*find_min_value(t_stack *stack)
{
	int		min_index;
	t_stack	*min_val;

	min_index = stack->index;
	min_val = stack;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_val = stack;
		}
		stack = stack->next;
	}
	return (min_val);
}

t_stack	*find_max_value(t_stack *stack)
{
	int		max_index;
	t_stack	*max_val;

	max_index = stack->index;
	max_val = stack;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_val = stack;
		}
		stack = stack->next;
	}
	return (max_val);
}

void	free_mem(char **str, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	list_clear(stack_a);
	list_clear(stack_b);
}
