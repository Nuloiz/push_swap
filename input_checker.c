/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:29:34 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/27 15:29:34 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	correct_input_digits(char *argv)
{
	int		i;
	long	test;

	i = 0;
	test = ft_atoi(argv);
	if (test > 2147483647 || test < -2147483648)
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

static int	correct_input_array(int argc, char *argv)
{
	int		i;

	i = 0;
	if (argc != 1)
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != ' ' && argv[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

char	**input_checker(int argc, char **argv)
{
	int		i;
	char	**list;

	i = 0;
	list = argv;
	if (!correct_input_array(argc, list[i]))
	{
		while (++i < argc)
		{
			if (!correct_input_digits(list[i]))
				return (NULL);
		}
	}
	else
	{
		list = new_array(ft_split(list[0], ' '));
		if (list == NULL)
		{
			free_array(list);
			return (NULL);
		}
	}
	return (list);
}
