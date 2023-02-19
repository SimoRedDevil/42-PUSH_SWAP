/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:55:39 by mel-yous          #+#    #+#             */
/*   Updated: 2023/02/19 18:31:54 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void start_sorting(int stack_size, t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size == 1)
		exit(1);
	else if (stack_size == 2)
		sort_two_numbers(*stack_a);
	else if (stack_size == 3)
		sort_three_numbers(stack_a);
	else if (stack_size == 4)
		sort_four_numbers(stack_a, stack_b);
	else if (stack_size == 5)
		sort_five_numbers(stack_a, stack_b);
}	

int	main(int argc, char **argv)
{
	char **spl_args;
	t_stack *stack_a;
	t_stack *stack_b;
	int i;

	if (argc == 1)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	spl_args = get_splitted_args(argc, argv);
	parse_input((const char **)spl_args);
	while (spl_args[i])
	{
		fill_stack_a(&stack_a, ft_atoi(spl_args[i]));
		i++;
	}
	re_index_stack(stack_a);
	start_sorting(i, &stack_a, &stack_b);
	// while (stack_a)
	// {
	// 	printf("%d --> %d\n", stack_a->num, stack_a->index);
	// 	stack_a = stack_a->next;
	// }
}
