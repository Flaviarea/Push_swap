/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:09:50 by frea              #+#    #+#             */
/*   Updated: 2025/03/27 12:09:52 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	rotate_stack(t_node **stack);
void	reverse_rotate_stack(t_node **stack);

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_node **a, t_node **b)
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
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	int	i;

	i = 0;
	while (i++ < 2)
		push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	rotate_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
}

void	reverse_rotate_stack(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = *stack;
	if (*stack && (*stack)->next)
	{
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
