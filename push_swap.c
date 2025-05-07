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

int		main(int argc, char **argv);
void	ft_radix_sort(t_node **a, t_node **b);

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

void	rr(t_node **a, t_node **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write (1, "rr\n", 3);
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
