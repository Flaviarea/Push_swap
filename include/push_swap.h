/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:09:50 by frea              #+#    #+#             */
/*   Updated: 2025/03/27 12:09:52 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include "libft/include/libft.h"

typedef struct s_node
{
	int					value;
	int					index;
	struct s_node		*next;
}		t_node;

typedef struct s_sort
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		size;
	int		i;
}	t_sort;

//radix_sort.c
void	ft_radix_sort(t_node **a, t_node **b);
void	push_min_to_b(t_node **a, t_node **b);
void	handle_error(char **args, t_node **stack);

//parsing.c
t_node	*init_stack(int argc, char *argv[]);
int		ft_is_digit(char c);
long	ft_atoi_long(const char *str);
int		ft_is_valid_nbr(const char *str);

//parse_args.c
char	**ft_split_args(char *arg);
t_node	*init_stack_split(char **args);
void	free_split(char **args);
t_node	*parse_args(int argc, char **argv);

//stack utils.c
t_node	*create_node(int value);
int		ft_error_dup(t_node *stack);
void	free_stack(t_node **stack);
void	add_node(t_node **stack, int value);
void	print_error_and_exit(char **args, t_node **stack);

//push_swap_utils.c
int		ft_list_size(t_node *stack);
int		is_sorted(t_node *stack);
void	ft_put_index(t_node **stack, int size);
int		get_min(t_node *stack);
int		get_max_bits(t_node *stack);

//operations.c
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

//sorting.c
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	rotate_stack(t_node **stack);
void	reverse_rotate_stack(t_node **stack);

//rotation.c
void	ra(t_node **a);
void	rb(t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);

//double_rotation.c
void	rr(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
