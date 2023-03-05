/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:56:07 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/05 14:02:57 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

# define small_chunk 5;
# define big_chunk 10;

typedef struct s_stack
{
	int num;
	int index;
	struct s_stack *next;
} t_stack;

char	**get_splitted_args(int ac, char **av);
void	throw_error();
void	parse_input(const char **tab);
t_stack	*create_node(int num);
int		list_size(t_stack *stack);
int 	tab_size(const char **tab);
void 	indexing_by_order(t_stack *stack);
void 	set_position(t_stack *stack);
int 	get_position(t_stack *stack, int index);
void 	fill_stack_a(t_stack **stack_a, int num);
void	free_this_shit(char **str, t_stack **stack);
void 	list_clear(t_stack **stack);
t_stack *find_min_value(t_stack *stack);
t_stack *find_max_value(t_stack *stack);

void	swap(t_stack *stack, char *ins_name);
void 	push(t_stack **source, t_stack **destination, char *ins_name);
void	rotate(t_stack **stack, char *ins_name);
void	reverse_rotate(t_stack **stack, char *ins_name);

void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void 	rrr(t_stack **stack_a, t_stack **stack_b);

void 	sort_two_numbers(t_stack *stack_a);
void 	sort_three_numbers(t_stack **stack_a);
void 	sort_four_numbers(t_stack **stack_a, t_stack **stack_b);
void 	sort_five_numbers(t_stack **stack_a, t_stack **stack_b);
void	big_sort(t_stack **stack_a, t_stack **stack_b);

#endif