/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:43:54 by frea              #+#    #+#             */
/*   Updated: 2025/04/30 17:43:57 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	sa(t_node **a)
{
	t_node	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_node **b)
{
	t_node	*tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
	write(1, "ss\n", 3);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		write(1, "pb\n", 3);
	}
}
