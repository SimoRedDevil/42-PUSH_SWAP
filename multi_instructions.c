/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:35:15 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 18:20:18 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_b)
	{
		swap(stack_a, NULL);
		swap(stack_b, NULL);
		ft_putendl_fd("ss", 1);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && stack_b && *stack_a && *stack_b)
	{
		rotate(stack_a, NULL);
		rotate(stack_b, NULL);
		ft_putendl_fd("rr", 1);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && stack_b && *stack_a && *stack_b)
	{
		reverse_rotate(stack_a, NULL);
		reverse_rotate(stack_b, NULL);
		ft_putendl_fd("rrr", 1);
	}
}
