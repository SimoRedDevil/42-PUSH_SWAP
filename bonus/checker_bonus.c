/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:13:08 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/15 15:30:58 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*call_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static void	is_sorted(t_stack *stack_a, t_stack *stack_b, int original_sz)
{
	int	i;
	int	sz;

	i = 0;
	if (!stack_a || original_sz != list_size(stack_a) || stack_b)
	{
		free_mem(NULL, &stack_a, &stack_b);
		ft_putendl_fd("KO", 1);
		exit(0);
	}
	sz = list_size(stack_a);
	while (i < sz && stack_a)
	{
		if (stack_a->index != i)
		{
			free_mem(NULL, &stack_a, &stack_b);
			ft_putendl_fd("KO", 1);
			exit(0);
		}
		i++;
		stack_a = stack_a->next;
	}
	free_mem(NULL, &stack_a, &stack_b);
	ft_putendl_fd("OK", 1);
	exit(0);
}

static void	exec_checker(t_stack **stack_a, t_stack **stack_b, const char *buff)
{
	char	**spl_ins;
	int		stack_a_sz;

	spl_ins = ft_split(buff, '\n');
	stack_a_sz = list_size(*stack_a);
	do_ins(stack_a, stack_b, spl_ins);
	indexing_by_order(*stack_a);
	is_sorted(*stack_a, *stack_b, stack_a_sz);
	free_mem(spl_ins, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	**spl_args;
	char	*input_ins;
	char	*buff;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	buff = NULL;
	spl_args = get_splitted_args(argc, argv);
	parse_input((const char **)spl_args);
	while (*spl_args)
		fill_stack_a(&stack_a, ft_atoi(*(spl_args++)));
	while (1)
	{
		input_ins = get_next_line(INPUT_FD);
		if (!input_ins)
			break ;
		check_input_ins((const char *)input_ins);
		buff = call_strjoin(buff, input_ins);
		free(input_ins);
	}
	exec_checker(&stack_a, &stack_b, (const char *)buff);
}
