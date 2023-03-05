/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:18:55 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/04 21:41:27 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two_numbers(t_stack *stack_a)
{
	if (stack_a->num > stack_a->next->num)
		swap(stack_a, "sa");
}

void sort_three_numbers(t_stack **stack_a)
{
	int median;

	median = (*stack_a)->next->num;
	if (median > (*stack_a)->num &&
		median > (*stack_a)->next->next->num)
	{
		reverse_rotate(stack_a, "rra");
		if ((*stack_a)->num > (*stack_a)->next->num)
			swap(*stack_a, "sa");
	}
	else if (median < (*stack_a)->num &&
		median < (*stack_a)->next->next->num)
	{
		if ((*stack_a)->num - (*stack_a)->next->next->num < 0)
			swap(*stack_a, "sa");
		else
			rotate(stack_a, "ra");
	}
	else if (median < (*stack_a)->num &&
		median > (*stack_a)->next->next->num)
	{
		swap(*stack_a, "sa");
		reverse_rotate(stack_a, "rra");
	}
}

void sort_four_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *min_val;
	int min_val_pos;

	min_val = find_min_value(*stack_a);
	min_val_pos = get_position(*stack_a, min_val->index);
	if (min_val_pos == 1)
		rotate(stack_a, "ra");
	else if (min_val_pos == 2)
	{
		reverse_rotate(stack_a, "rra");
		reverse_rotate(stack_a, "rra");
	}
	else if (min_val_pos == 3)
		reverse_rotate(stack_a, "rra");
	push(stack_a, stack_b, "pb");
	sort_three_numbers(stack_a);
	push(stack_b, stack_a, "pa");
}

void sort_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *min_val;
	int min_val_pos;

	min_val = find_min_value(*stack_a);
	min_val_pos = get_position(*stack_a, min_val->index);
	if (min_val_pos == 1)
		rotate(stack_a, "ra");
	else if (min_val_pos == 2)
	{
		rotate(stack_a, "ra");
		rotate(stack_a, "ra");
	}
	else if (min_val_pos == 3)
	{
		reverse_rotate(stack_a, "rra");
		reverse_rotate(stack_a, "rra");
	}
	else if (min_val_pos == 4)
		reverse_rotate(stack_a, "rra");
	push(stack_a, stack_b, "pb");
	sort_four_numbers(stack_a, stack_b);
	push(stack_b, stack_a, "pa");
}