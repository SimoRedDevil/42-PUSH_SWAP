/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ins_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:09:55 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/10 15:33:16 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*Swap two first numbers of the following stack*/
void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

/*Take the first element at the top of source
and put it at the top of destination*/
void	push(t_stack **source, t_stack **destination)
{
	t_stack	*tmp;

	if (!source || !(*source))
		return ;
	tmp = *source;
	if (!(*destination))
	{
		*source = (*source)->next;
		tmp->next = NULL;
		*destination = tmp;
	}
	else
	{
		*source = (*source)->next;
		tmp->next = *destination;
		(*destination) = tmp;
	}
}

/*The first element becomes the last one*/
void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*sec;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	sec = *stack;
	(*stack) = (*stack)->next;
	while (sec->next)
		sec = sec->next;
	sec->next = head;
	head->next = NULL;
}

/*The last element becomes the first one*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*sec;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	sec = *stack;
	while (sec->next->next)
		sec = sec->next;
	while (head->next)
		head = head->next;
	head->next = *stack;
	*stack = head;
	sec->next = NULL;
}
