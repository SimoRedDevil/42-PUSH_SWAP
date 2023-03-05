/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:35:15 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/05 13:54:57 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Do sa and sb in the same time*/
void ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_b)
	{
		swap(stack_a, NULL);
		swap(stack_b, NULL);
		ft_putendl_fd("ss", 1);
	}
}

/*Do ra and rb in the same time*/
void rr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && stack_b && *stack_a && *stack_b)
	{
		rotate(stack_a, NULL);
		rotate(stack_b, NULL);
		ft_putendl_fd("rr", 1);
	}
}

/*Do rra and rrb in the same time*/
void rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && stack_b && *stack_a && *stack_b)
	{
		rotate(stack_a, NULL);
		rotate(stack_b, NULL);
		ft_putendl_fd("rrr", 1);
	}
}