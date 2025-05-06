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

typedef struct s_node
{
	int	value;
	int	index;
	struct s_node	*next;
}		t_node;

//parsing
t_node	*init_stack(int argc, char *argv[]);
int		ft_is_digit(char c);
long	ft_atoi_long(const char *str);
int		ft_is_valid_nbr(const char *str);
//int ft_is_within_limits(long value);

//stack utils
t_node	*create_node(int value);
int		ft_error_dup(t_node *stack);
void	print_stack(t_node *stack);
void	free_stack(t_node **stack);
void	add_node(t_node **stack, int value);

//push_swap_utils
int		ft_list_size(t_node *stack);
int		is_sorted(t_node *stack);
void	ft_put_index(t_node **stack, int size);
int		get_min(t_node *stack);
void	ft_radix_sort(t_node **a, t_node **b);
int		get_max_bits(t_node *stack);

//operations
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

//sorting
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);

#endif
