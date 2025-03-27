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
initialize the stack with the args.
*/

t_node  *init_stack(int argc, char *argv[])
{
    t_node *stack = NULL;
    int i;

    i = 1; // argv start from 1
    while (argc > i)
    {
        if (!ft_is_valid_nbr(argv[i]))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        add_node(&stack, ft_atoi(argv[i])); // converts and add the nbr to the stack
        i++;
    }
    if (ft_has_dup(stack))
    {
        write(2, "Error\n", 6);
        free_stack(&stack);
        exit(1);
    }
    return(stack);
}

/*
    main:
    Read the arguments from the command line and convert them to numbers.
    Initialize the stack a with these numbers.
    Handle errors (duplicates, non-numeric values, int bounds).
    Call Radix Sort to sort the numbers.
    Print the operations performed.
*/

int main(int argc, char *argv[])
{
    t_node *node_a;
    t_node *node_b;
    int size;

    node_a = NULL;
    node_b = NULL;
    if (argc < 2)
        return;

    if (argc > 1)
    {
        ft_create_node(&node_a, argc, argv); // transform input into a linked list
        size = ft_list_size(node_a); // count elements of the list
        ft_put_index(&node_a, size); // assign a index to the number for radix sort
        ft_radixsort(&node_a, &node_b); // sort numbers
        ft_free(node_a);
        ft_free(node_b);
    }
    return(0);
}
