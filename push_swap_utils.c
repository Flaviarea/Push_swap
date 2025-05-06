/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:09:28 by frea              #+#    #+#             */
/*   Updated: 2025/03/27 12:09:30 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    put_index(t_node **stack);
int	get_min(t_node *stack);
void    ft_put_index(t_node **stack, int size);
void    ft_radix_sort(t_node **a, t_node **b);

/*
    ft_list_size:
    Conta quanti elementi sono presenti nello stack a.
    Questo numero è usato per determinare quante passate 
    servono nel radix sort (in base al numero di bit massimo).
 */

int	ft_list_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return(size);
}

int	get_min(t_node *stack)
{
	int min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	ft_put_index(t_node **stack, int size)
{
	t_node	*current;
	t_node	*min_node;
	int		index;

	index = 0;
	while (index < size)
	{
		current = *stack;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1 && (!min_node 
						|| current->value < min_node->value))
				min_node = current;
			current = current->next;
		}
		if (min_node)
			min_node->index = index++;
	}
}

int	get_max_bits(t_node *stack)
{
	int max_index;
	int bits;

	max_index = 0;
	bits = 0;

	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix_sort(t_node **a, t_node **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = ft_list_size(*a);
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
