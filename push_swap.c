/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:09:11 by frea              #+#    #+#             */
/*   Updated: 2025/03/27 12:09:14 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **stack);
void	rb(t_node **b);

/*
    main:
    Read the arguments from the command line and convert them to numbers.
    Initialize the stack a with these numbers.
    Handle errors (duplicates, non-numeric values, int bounds).
    Call Radix Sort to sort the numbers.
    Print the operations performed.
    creiamo due puntatori alle linked list e una int size che 
    memorizza la lunghezza di node_a, che serve per capire quante 
	iterazioni fare nel radix sort.
*/

/*  
    is_sorted:
*/

int	is_sorted(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = init_stack(argc, argv);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	size = ft_list_size(a);
	ft_put_index(&a, size);
	if (size == 2)
		sa(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size == 4)
		sort_four(&a, &b);
	else if (size == 5)
		sort_five(&a, &b);
	else
		ft_radix_sort(&a, &b);
			return (free_stack(&a), free_stack(&b), 0);
}

