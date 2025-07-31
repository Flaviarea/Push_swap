/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:17:48 by frea              #+#    #+#             */
/*   Updated: 2025/05/07 18:17:50 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_min_to_b(t_node **a, t_node **b)
{
	int		min;
	int		pos;
	int		size;
	t_node	*tmp;

	min = get_min(*a);
	size = ft_list_size(*a);
	pos = 0;
	tmp = *a;
	while (tmp->value != min)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
		while (pos--)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
	pb(a, b);
}

void	handle_error(char **args, t_node **stack)
{
	write(2, "Error\n", 6);
	free_split(args);
	free_stack(stack);
	exit(1);
}
