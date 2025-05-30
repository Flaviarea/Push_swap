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

t_node	*parse_args(int argc, char **argv)
{
	char	**args;
	t_node	*a;

	a = NULL;
	if (argc == 2)
	{
		args = ft_split_args(argv[1]);
		if (!args)
			return (NULL);
		a = init_stack_split(args);
		free_split(args);
	}
	else
		a = init_stack(argc, argv);
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
			return (free_stack(&a), NULL);
		num = ft_atoi_long(args[i]);
		if (ft_error_dup(a))
			return (free_stack(&a), NULL);
		add_node(&a, (int)num);
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
