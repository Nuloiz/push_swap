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

static int	correct_input_digits(char	*argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
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
		if (!ft_isdigit(argv[i]) && argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}


int	main(int argc, char	**argv)
{
	int		i;
	t_node	*stack_a;

	i = 0;
	argc = argc -1;
	argv = argv + 1;

	if (!correct_input_array(argc, argv[i]))
	{
		while (i < argc)
		{
			if (!correct_input_digits(argv[i]))
				return (0);
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
	stack_a = linked_list_start(argc, argv);
	//testing_operations(stack_a);
	radix_sort(stack_a);
	return (0);
}
