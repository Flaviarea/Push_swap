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

int		ft_is_digit(char c);
long		ft_atoi_long(const char *str);
int		ft_is_valid_nbr(const char *str);
int		ft_is_within_limits(long value);

/*
    initialize the stack with the args.
    skip first argc, which is the programm = argc starts with 1
    possiamo avere tati argv quanti le integers
    ma i non 'e nel loop, quindi rimane sempre 1 ? perch'e creo i invece di fare while argc > 1?
    ft_is_valid_nbr controlla che le integers siano nella rande dei caratteri validi 
    add_node cosa fa?
    t_has_dup controlla che siano solo numer originali senza doppioi 
    Return: the stack, perche?
*/

t_node	*init_stack(int argc, char *argv[])
{
	t_node		*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (argc > i)
	{
		if (!ft_is_valid_nbr(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		add_node(&stack, ft_atoi_long(argv[i]));
		i++;
	}
	if (ft_error_dup(stack))
	{
		write(2, "Error\n", 6);
		free_stack (&stack);
		exit (1);
	}
	return (stack);
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/*  
    ft_atoi_long:
    if the str has the sign minus, then the sign will be -1, 
    so when we will mupltiply it will give it +1
*/

long	ft_atoi_long(const char *str)
{
	long		result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		while (str[i])
		{
			if (!ft_is_digit(str[i]))
				return (0);
			result = result * 10 + (str[i] - '0');
			i++;
		}
		result = result * sign;
		if (result < INT_MIN || result > INT_MAX)
			return (0);
		return (result);
	}
}

/*
    ft_is_valid_nbr:
    Check if the string is a valid number.
    String must be numeric, need to handle negativ nbr,
    cannot contain non-numerical char. 
    Input: a string pointer 
    Output: a integer
*/

int	ft_is_valid_nbr(const char *str)
{
	int		i;
	long	nbr;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	nbr = ft_atoi_long(str);
	if (nbr == 0 && str[0] != '0')
		return (0);
	return (1);
}

int	ft_is_within_limits(long value)
{
	return (value >= -2147483648 && value <= 2147483647);
}
