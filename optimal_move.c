/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:24:54 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 18:20:29 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimal_move_1(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b && get_position(*stack_b, find_max_value(*stack_b)->index)
		<= list_size(*stack_b) / 2)
	{
		if (*stack_b
			&& get_position(*stack_b, find_max_value(*stack_b)->index - 1)
			< get_position(*stack_b, find_max_value(*stack_b)->index))
		{
			while (*stack_b
				&& get_position(*stack_b, find_max_value(*stack_b)->index - 1))
				rotate(stack_b, "rb");
			push(stack_b, stack_a, "pa");
			while (*stack_b
				&& get_position(*stack_b, find_max_value(*stack_b)->index))
				rotate(stack_b, "rb");
			push(stack_b, stack_a, "pa");
			swap(*stack_a, "sa");
		}
		else
			while (*stack_b
				&& get_position(*stack_b, find_max_value(*stack_b)->index))
				rotate(stack_b, "rb");
	}
}

void	optimal_move_2(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b
		&& get_position(*stack_b, find_max_value(*stack_b)->index)
		> list_size(*stack_b) / 2)
	{
		if (*stack_b
			&& get_position(*stack_b, find_max_value(*stack_b)->index - 1)
			> get_position(*stack_b, find_max_value(*stack_b)->index))
		{
			while (*stack_b
				&& get_position(*stack_b, find_max_value(*stack_b)->index - 1))
				reverse_rotate(stack_b, "rrb");
			push(stack_b, stack_a, "pa");
			while (*stack_b
				&& get_position(*stack_b, find_max_value(*stack_b)->index))
				reverse_rotate(stack_b, "rrb");
			push(stack_b, stack_a, "pa");
			swap(*stack_a, "sa");
		}
		else
			while (*stack_b
				&& get_position(*stack_b, find_max_value(*stack_b)->index))
				reverse_rotate(stack_b, "rrb");
	}
}
