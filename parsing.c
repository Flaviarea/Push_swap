/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:43:32 by frea              #+#    #+#             */
/*   Updated: 2025/04/30 17:43:35 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    ft_is_valid_nbr:

*/

int ft_is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/* ft_atoi_long:
    if the str has the sign minus, then the sign will be -1, 
    so when we will mupltiply it will give it +1
*/

long ft_atoi_long(const char *str)
{
    long    result;
    int     sign;
    int     i;

    result = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
        {
            if (str[i] == '-')
                sign = -1;
            i++;
        }
    while (str[i])
    {
        if(!ft_is_digit(str[i]))
            return(0);
        result = result * 10 + (str[i] - '0');
        i++;
    }
    result = result * sign;
    if (result < INT_MIN || result > INT_MAX)
        return (0);
    return (result);
}

/*
    ft_is_valid_nbr:
    Check if the string is a valid number.
    String must be numeric, need to handle negativ nbr,
    cannot contain non-numerical char. 
    Input: a string pointer 
    Output: a integer
    
*/

int ft_is_valid_nbr(const char *str)
{
    int i;
    long nbr;

    i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return (0);
    while(str[i])
    {
        if(!ft_is_digit(str[i]))
            return(0);
        i++;
    }
    nbr = ft_atoi_long(str); //convert the string in a integer
    if (nbr == 0 && str[0] != '0')
        return (0); // nbr is not in the limits
    return (1); // nbr is valid 
}

int ft_is_within_limits(long value)
{
    return (value >= -2147483648 && value <= 2147483647);
}
