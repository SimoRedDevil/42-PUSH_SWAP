/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:52:27 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/02 14:49:47 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(int num)
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->index = -1;
	node->num = num;
	node->next = NULL;
	return (node);
}

int	list_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void list_clear(t_stack **stack)
{
	t_stack *tmp;
	
	tmp = *stack;
	while (tmp)
	{
		tmp = (*stack)->next;
		(*stack)->next = NULL;
		free(*stack);
		*stack = tmp;
	}
}