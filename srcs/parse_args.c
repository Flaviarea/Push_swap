/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frea <frea@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:55:10 by frea              #+#    #+#             */
/*   Updated: 2025/05/30 15:55:16 by frea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

char	**ft_split_args(char *arg);
t_node	*init_stack_split(char **args);
void	free_split(char **args);

static int	is_empty_or_spaces(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*a;
	char	**args;

	a = NULL;
	if (argc > 2)
		a = init_stack(argc, argv);
	else
	{
		if (is_empty_or_spaces(argv[1]))
		{
			return (NULL);
		}
		args = ft_split_args(argv[1]);
		if (!args || !args[0])
		{
			if (args)
				free_split(args);
			return (NULL);
		}
		a = init_stack_split(args);
		free_split(args);
	}
	return (a);
}

char	**ft_split_args(char *arg)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args)
		return (NULL);
	return (args);
}

t_node	*init_stack_split(char **args)
{
	t_node	*a;
	int		i;
	long	num;

	a = NULL;
	i = 0;
	while (args[i])
	{
		if (!ft_is_valid_nbr(args[i]))
			handle_error(args, &a);
		num = ft_atoi_long(args[i]);
		add_node(&a, (int)num);
		if (!ft_error_dup(a))
			handle_error(args, &a);
		i++;
	}
	return (a);
}

void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
