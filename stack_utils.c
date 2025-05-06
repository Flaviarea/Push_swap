i/* ************************************************************************** */
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
//#include <stdio.h>

void	add_node(t_node **stack, int value);
void	free_stack(t_node **stack);
void	print_stack(t_node *stack);
int	ft_error_dup(t_node *stack);

/*
    create_node:
    creare un nuovo nodo. Ogni nodo rappresenta un elemento dello stack.
*/

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

/*
    add_node:
    aggiungere un nuvo nodo all'inizio dello stack. 
    Quando aggiungiamo un elemento a uno stack, lo inseriamo all'inizio della lista, 
    modificando il puntatore head dello stack.
    Il nuovo nodo punta al primo nodo
    Il "top" dello stack è ora il nuovo nod
*/

void	add_node(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(value);
	if (!new_node)
		return;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

/*
    free_stack:
*/

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

// elimina questa funzione che è solo di debug
/*void print_stack(t_node *stack)
{
    t_node *current;

    current = stack;
    while (current != NULL)
    {
        printf("%d ", current->value); // change to ft_printf!!
        current = current->next;
    }
    printf("\n"); // change to ft_printf!!
}
    */

/*
    ft_error_dup:
    Check if there are duplicted nbr in the stack
    Stack is a list we pass after the function init_stack has initialized it. 
    Input: a pointer to a list(stack)
    Return: 1 if it finds a duplicate, 0 if it doesn't.

*/

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
				return (1);
			checker = checker->next;
		}
		a = a->next;
	}
	return (0);
}
