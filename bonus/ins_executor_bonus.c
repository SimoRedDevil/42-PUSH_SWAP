/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_executor_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:34:13 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 19:49:47 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	s_ins(t_stack *stack_a, t_stack *stack_b, const char *ins)
{
	if (ft_strcmp(SA, ins) == 0)
		swap(stack_a);
	else if (ft_strcmp(SB, ins) == 0)
		swap(stack_b);
	else if (ft_strcmp(SS, ins) == 0)
		ss(stack_a, stack_b);
}

static void	p_ins(t_stack **stack_a, t_stack **stack_b, const char *ins)
{
	if (ft_strcmp(PA, ins) == 0)
		push(stack_b, stack_a);
	if (ft_strcmp(PB, ins) == 0)
		push(stack_a, stack_b);
}

static void	r_ins(t_stack **stack_a, t_stack **stack_b, const char *ins)
{
	if (ft_strcmp(RA, ins) == 0)
		rotate(stack_a);
	else if (ft_strcmp(RB, ins) == 0)
		rotate(stack_b);
	else if (ft_strcmp(RR, ins) == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(RRA, ins) == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(RRB, ins) == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(RRR, ins) == 0)
		rrr(stack_a, stack_b);
}

void	do_ins(t_stack **stack_a, t_stack **stack_b, char **spl_ins)
{
	int	i;

	i = 0;
	if (!spl_ins)
		return ;
	while (spl_ins[i])
	{
		s_ins(*stack_a, *stack_b, spl_ins[i]);
		p_ins(stack_a, stack_b, spl_ins[i]);
		r_ins(stack_a, stack_b, spl_ins[i]);
		i++;
	}
}
