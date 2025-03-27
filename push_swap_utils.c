/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:09:28 by frea              #+#    #+#             */
/*   Updated: 2025/03/27 12:09:30 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
    ft_is_valid_nbr:
    Check if the string is a valid number.
    String must be numeric, need to handle negativ nbr,
    cannot contain non-numerical char. 
    Input: a string pointer 
    Output: a integer
*/

int ft_is_valid_nbr(char *s)
{
    int i;

    i = 0;
    if (s[i] == '+' || s[i] == '-') //handle the sign
    {
        i++;
    }
    while(s[i])
    {
        if(!ft_isdigit(s[i]))
        {
            return(0);
        }
        i++
    }
    long nbr = ft_atoi(s) //convert the string in a integer
    if (nbr < INT_MIN || INT_MAX)
    {
        return (0); // nbr is not in the limits
    }
    return (1); // nbr is valid 
}

/*
    ft_has_dup:
    Check if there are duplicted nbr in the stack
    Stack is a list we pass after the function init_stack has initialized it. 
    Input: a pointer to a list(stack)
    Return: 1 if it finds a duplicate, 0 if it doesn't.
*/

int ft_has_dup(t_node *stack)