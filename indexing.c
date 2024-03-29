/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:38:31 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/15 15:27:29 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_fake_array(int array_size, t_stack *stack)
{
	int	i;
	int	*fake_arr;

	fake_arr = (int *)malloc(array_size * sizeof(int));
	if (!fake_arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		fake_arr[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (fake_arr);
}

static void	sort_fake_array(int array_size, int *fake_arr)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < array_size)
	{
		j = i + 1;
		while (j < array_size)
		{
			if (fake_arr[i] > fake_arr[j])
			{
				tmp = fake_arr[j];
				fake_arr[j] = fake_arr[i];
				fake_arr[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	indexing_by_order(t_stack *stack)
{
	int	*fake_arr;
	int	stack_size;
	int	i;

	stack_size = list_size(stack);
	fake_arr = create_fake_array(stack_size, stack);
	if (!fake_arr)
		throw_error();
	sort_fake_array(stack_size, fake_arr);
	i = 0;
	while (stack)
	{
		i = 0;
		while (i < stack_size)
		{
			if (stack->num == fake_arr[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
	free(fake_arr);
}

int	get_position(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}
