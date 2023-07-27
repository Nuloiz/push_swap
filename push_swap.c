/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:34:38 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/19 11:24:15 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
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

static int	no_int_twice(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (argv[i])
	{
		j = i;
		k = (int)ft_atoi(argv[i]);
		while (argv[j + 1])
		{
			if (k == (int)ft_atoi(argv[j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	sorting(char **argv)
{
	int	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (!no_int_twice(argv))
	{
		free_array(argv);
		return (ft_putendl_fd("Error", 2));
	}
	if (already_sorted(linked_list_start(argc, argv)))
		return (free_array(argv));
	argv = new_numbers(argc, argv);
	if (argc <= 3)
		three_arg(linked_list_start(argc, argv));
	else if (argc <= 5)
		five_arg(linked_list_start(argc, argv), argc);
	else
		radix_sort(linked_list_start(argc, argv));
	free_array(argv);
}

int	main(int argc, char	**argv)
{
	int	i;

	i = 0;
	argc = argc -1;
	argv = argv + 1;
	if (argc == 0)
		return (0);
	if (!correct_input_array(argc, argv[i]))
	{
		while (++i < argc)
		{
			if (!correct_input_digits(argv[i]))
				return ((int)write(2, "Error\n", 6));
			i++;
		}
	}
	else
	{
		argv = new_array(ft_split(argv[0], ' '));
		if (argv == NULL)
		{
			free_array(argv);
			return ((int)write(2, "Error\n", 6));
		}
	}
	sorting(argv);
	free_array(argv);
	return (1);
}
