/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:35:49 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 21:42:43 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_exist(t_stack *stack, int chunk)
{
	while (stack)
	{
		if (stack->index < chunk)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	push_a_to_b_and_rr(t_stack **stack_a, t_stack **stack_b, int chunk)
{
	int	current_chunk;

	current_chunk = chunk;
	push(stack_a, stack_b, "pb");
	if (*stack_a && (*stack_a)->index > current_chunk)
		rr(stack_a, stack_b);
	else if (*stack_a && (*stack_a)->index < current_chunk)
		rotate(stack_b, "rb");
}

static void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	current_chunk;
	int	pivot;

	current_chunk = chunk_size;
	pivot = chunk_size / 2;
	while (*stack_a)
	{
		while (chunk_exist(*stack_a, current_chunk) && *stack_a)
		{
			if ((*stack_a)->index < current_chunk)
			{
				if ((*stack_a)->index < pivot)
					push_a_to_b_and_rr(stack_a, stack_b, current_chunk);
				else
					push(stack_a, stack_b, "pb");
			}
			else
				rotate(stack_a, "ra");
		}
		pivot = (current_chunk * 2 + chunk_size) / 2;
		current_chunk += chunk_size;
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int stack_a_size)
{
	int	chunk_size;

	chunk_size = stack_a_size / BIG_CHUNK;
	if (stack_a_size <= 100)
		chunk_size = stack_a_size / SMALL_CHUNK;
	push_a_to_b(stack_a, stack_b, chunk_size);
	while (*stack_b)
	{
		if (*stack_b
			&& !get_position(*stack_b, find_max_value(*stack_b)->index))
			push(stack_b, stack_a, "pa");
		optimal_move_1(stack_a, stack_b);
		optimal_move_2(stack_a, stack_b);
	}
}
