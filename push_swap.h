/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:09:50 by frea              #+#    #+#             */
/*   Updated: 2025/03/27 12:09:52 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define INT_MAX 2147483647
#define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
//# include "libft.h"

typedef struct s_node
{
    int value;
    struct s_node *next;
}   t_node;

//operazioni
int ft_is_digit(char c);
long ft_atoi_long(const char *str);
int ft_is_valid_nbr(const char *str);


//stack utils
int ft_error_dup(t_node *stack)
void print_stack(t_node *stack)
void free_stack(t_node **stack)
void    add_node(t_node **stack, int value)
t_node *create_node(int value)

# endif

