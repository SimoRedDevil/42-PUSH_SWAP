/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:43:39 by mel-yous          #+#    #+#             */
/*   Updated: 2023/03/15 15:39:22 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"

# define INPUT_FD 0

typedef int	t_bool;
# define FALSE 0
# define TRUE 1

# define SA "sa"
# define SB "sb"
# define SS "ss"

# define PA "pa"
# define PB "pb"

# define RA "ra"
# define RB "rb"
# define RR "rr"

# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	throw_error(void);
char	**get_splitted_args(int ac, char **av);
void	parse_input(const char **tab);
void	fill_stack_a(t_stack **stack_a, int num);
t_stack	*create_node(int num);
int		list_size(t_stack *stack);
void	list_clear(t_stack **stack);
int		ft_strcmp(const char *s1, const char *s2);

void	swap(t_stack *stack);
void	push(t_stack **source, t_stack **destination);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	free_mem(char **str, t_stack **stack_a, t_stack **stack_b);
void	indexing_by_order(t_stack *stack);
void	check_input_ins(const char *ins);

void	do_ins(t_stack **stack_a, t_stack **stack_b, char **spl_ins);
#endif