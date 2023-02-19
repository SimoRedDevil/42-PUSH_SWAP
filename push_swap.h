/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:56:07 by mel-yous          #+#    #+#             */
/*   Updated: 2023/02/18 21:01:10 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

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
int 	tab_size(const char **tab);
t_stack *min(t_stack *stack);
t_stack *max(t_stack *stack);
void 	re_index_stack(t_stack *stack);
void 	fill_stack_a(t_stack **stack_a, int num);

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

#endif