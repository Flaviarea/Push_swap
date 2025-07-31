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
long	ft_atoi_long(const char *str);
int		ft_is_valid_nbr(const char *str);

t_node	*init_stack(int argc, char *argv[])
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (argc > i)
	{
		if (!ft_is_valid_nbr(argv[i]))
		{
			write(2, "Error\n", 6);
			if (stack)
				free_stack(&stack); 
			exit(1);
		}
		add_node(&stack, ft_atoi_long(argv[i]));
		if (!ft_error_dup(stack))
		{
			write(2, "Error\n", 6);
			free_stack(&stack);
			exit(1);
		}
		i++;
	}
	return (stack);
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi_long(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!ft_is_digit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_is_digit(str[i])) 
			return (0);
		result = result * 10 + (str[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return (0);
		if (sign == -1 && - result < INT_MIN)
			return (0);
		i++;
	}
	return (result * sign);
}

int	ft_is_valid_nbr(const char *str)
{
	int			i;
	long		nbr;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_is_digit(str[i++]))
			return (0);
	}
	nbr = ft_atoi_long(str);
	if (nbr == 0)
	{
		if (str[0] == '0' && str[1] == '\0')
			return (1);
		if ((str[0] == '+' || str[0] == '-') && str[1] == '0' && str[2] == '\0')
			return (1);
		return (0);
	}
	return (1);
}
