/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:42:41 by mel-yous          #+#    #+#             */
/*   Updated: 2023/02/18 21:01:00 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void throw_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_stack *min(t_stack *stack)
{
	t_stack *addr;
	
	addr = stack;
	while (stack)
	{
		if (stack->num < addr->num)
			addr = stack;
		stack = stack->next;
	}
	return (addr);
}

t_stack *max(t_stack *stack)
{
	t_stack *addr;
	
	addr = stack;
	while (stack)
	{
		if (stack->num > addr->num)
			addr = stack;
		stack = stack->next;
	}
	return (addr);
}

void re_index_stack(t_stack *stack)
{
	int index;
	
	index = 0;
	while (stack)
	{
		stack->index = index++;
		stack = stack->next;
	}
}

void fill_stack_a(t_stack **stack_a, int num)
{
	t_stack *tmp;

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