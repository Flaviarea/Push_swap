/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:09:50 by frea              #+#    #+#             */
/*   Updated: 2025/05/07 18:41:46 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);

void	ra(t_node **a)
{
	t_node	*tmp;
	t_node	*last;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_node **b)
{
	t_node	*tmp;
	t_node	*last;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		last = *b;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	if (*a && (*a)->next)
	{
		prev = NULL;
		last = *a;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *a;
		*a = last;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_node **b)
{
	t_node	*prev;
	t_node	*last;

	if (*b && (*b)->next)
	{
		prev = NULL;
		last = *b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *b;
		*b = last;
		write(1, "rrb\n", 4);
	}
}
