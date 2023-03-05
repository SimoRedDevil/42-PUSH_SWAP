/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:35:49 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/05 15:55:31 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int chunk_exist(t_stack *stack, int chunk)
{
	while (stack)
	{
		if (stack->index < chunk)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int fees_calculator(t_stack *stack, int first_max, int second_max)
{
	int half_stack;

	half_stack = list_size(stack) / 2;
}

/* Push from stack A to stack B in chunks FORM! */
static void push_from_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int chunk_size;
	int current_chunk;
	int mediane;

	chunk_size = list_size(*stack_a) / big_chunk;
	current_chunk = chunk_size;
	mediane = chunk_size / 2;
	while (*stack_a)
	{
		while (chunk_exist(*stack_a, current_chunk) && *stack_a)
		{
			if ((*stack_a)->index < current_chunk)
			{
				if ((*stack_a)->index < mediane)
				{
					push(stack_a, stack_b, "pb");
					if (*stack_a && (*stack_a)->index > current_chunk)
					{
						rr(stack_a, stack_b);
						continue;
					}
					else if (*stack_a && (*stack_a)->index < current_chunk)
						rotate(stack_b, "rb");
				}
				else
					push(stack_a, stack_b, "pb");
			}
			else
				rotate(stack_a, "ra");
		}
		mediane = (current_chunk * 2 + chunk_size) / 2;
		current_chunk += chunk_size;
	}
}

void big_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_from_a_to_b(stack_a, stack_b);
	while ((*stack_b)->next)
	{
		if (get_position(*stack_b, find_max_value(*stack_b)->index) == 0)
			push(stack_b, stack_a, "pa");
		if (get_position(*stack_b, find_max_value(*stack_b)->index) < list_size(*stack_b) / 2)
			while (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index) != 0)
				rotate(stack_b, "rb");
		else if (get_position(*stack_b, find_max_value(*stack_b)->index) >= list_size(*stack_b) / 2)
			while (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index) != 0)
				reverse_rotate(stack_b, "rrb");
	}
	push(stack_b, stack_a, "pa");
}
