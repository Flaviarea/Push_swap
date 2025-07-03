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

/*
    main:
    Read the arguments from the command line and convert them to numbers.
    Initialize the stack a with these numbers.
    Handle errors (duplicates, non-numeric values, int bounds).
    Call Radix Sort to sort the numbers.
    Print the operations performed.

    creiamo due liste e una int size per tenere conto di ?
*/

/*int main(int argc, char *argv[])
{
    t_node *node_a;
    t_node *node_b;
    int size;

    node_a = NULL;
    node_b = NULL;
    if (argc < 2)
        return(0);

    if (argc > 1)
    {
        node_a = init_stack(argc, argv); // transform input into a linked list
        size = ft_list_size(node_a); // count elements of the list
        ft_put_index(&node_a, size); // assign a index to the number for radix sort
        ft_radix_sort(&node_a, &node_b); // sort numbers
        free(node_a);
        free(node_b);
    }
    return(0);
}
    */

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a || is_sorted(a))
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
