/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:34:38 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/05 14:51:12 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	correct_input_digits(char *argv)
{
	int	i;

	i = 0;
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
	int	i;

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

static int	no_int_twice(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (argv[i])
	{
		j = i;
		k = ft_atoi(argv[i]);
		while (argv[j + 1])
		{
			if (k == ft_atoi(argv[j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	sorting(int argc, char **argv)
{
	if (!no_int_twice(argv))
		return (ft_printf("Error\n"));
	if (already_sorted(linked_list_start(argc, argv)))
		return (0);
	argv = new_numbers(argc, argv);
	if (argc <= 3)
		three_arg(linked_list_start(argc, argv));
	else if (argc <= 5)
		five_arg(linked_list_start(argc, argv), argc);
	else
		radix_sort(linked_list_start(argc, argv));
	return (1);
}

int	main(int argc, char	**argv)
{
	int		i;

	i = 0;
	argc = argc -1;
	argv = argv + 1;
	if (!correct_input_array(argc, argv[i]))
	{
		while (i < argc)
		{
			if (!correct_input_digits(argv[i]))
				return (ft_printf("Error\n"));
			i++;
		}
	}
	else
	{
		argv = ft_split(argv[0], ' ');
		i = 1;
		while (argv[i++])
			argc++;
	}
	return (sorting(argc, argv));
}
