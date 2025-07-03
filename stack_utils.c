/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:09:28 by frea              #+#    #+#             */
/*   Updated: 2025/03/27 12:09:30 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_node **stack, int value);
void	free_stack(t_node **stack);
int		ft_error_dup(t_node *stack);

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	add_node(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(value);
	if (!new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	ft_error_dup(t_node *stack)
{
	t_node	*a;
	t_node	*checker;

	a = stack;
	if (!a)
		return (0);
	while (a)
	{
		checker = a->next;
		while (checker)
		{
			if (a->value == checker->value)
				return (0); //changed 
			checker = checker->next;
		}
		a = a->next;
	}
	return (1);  // changed both return value
}



