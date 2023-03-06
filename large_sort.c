/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:35:49 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/06 01:40:57 by mel-yous         ###   ########.fr       */
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

static int best_fees_calc(t_stack *stack)
{
	int half_stack;
	int first_max_pos;
	int second_max_pos;

	half_stack = list_size(stack) / 2;
	first_max_pos = get_position(stack, find_max_value(stack)->index);
	second_max_pos = get_position(stack, find_max_value(stack)->index - 1);

	return (0);
}

/* Push from stack A to stack B in chunks FORM! */
static void push_from_a_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int current_chunk;
	int mediane;

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
						rr(stack_a, stack_b);
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

void big_sort(t_stack **stack_a, t_stack **stack_b, int stack_a_size)
{
	int chunk_size;
	
	chunk_size = stack_a_size / big_chunk;
	if (stack_a_size <= 100)
		chunk_size = stack_a_size / small_chunk;
	push_from_a_to_b(stack_a, stack_b, chunk_size);
	while (*stack_b)
	{
		if (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index) == 0)
			push(stack_b, stack_a, "pa");
		if (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index) <= list_size(*stack_b) / 2)
		{
			if (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index - 1) < get_position(*stack_b, find_max_value(*stack_b)->index))
			{
				while (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index - 1) != 0)
					rotate(stack_b, "rb");
				push(stack_b, stack_a, "pa");
				while (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index) != 0)
					rotate(stack_b, "rb");
				push(stack_b, stack_a, "pa");
				swap(*stack_a, "sa");
			}
			else
				while (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index) != 0)
					rotate(stack_b, "rb");
		}
		else
		{
			if (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index - 1) > get_position(*stack_b, find_max_value(*stack_b)->index))
			{
				while (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index - 1) != 0)
					reverse_rotate(stack_b, "rrb");
				push(stack_b, stack_a, "pa");
				while (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index) != 0)
					reverse_rotate(stack_b, "rrb");
				push(stack_b, stack_a, "pa");
				swap(*stack_a, "sa");
			}
			else
			{
				while (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index) != 0)
					reverse_rotate(stack_b, "rrb");
				// push(stack_b, stack_a, "pa");
			}
		}
	}
}
