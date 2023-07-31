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

#include "push_swap.h"

static int	no_int_twice(char **list)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (list[i])
	{
		j = i;
		k = (int)ft_atoi(list[i]);
		while (list[j + 1])
		{
			if (k == (int)ft_atoi(list[j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	sorting(int num_of_arg, t_node *stack)
{
	if (already_sorted(stack))
	{
		free_stack(stack);
		return ;
	}
	if (num_of_arg <= 3)
		three_arg(stack);
	else if (num_of_arg <= 5)
		five_arg(num_of_arg, stack);
	else
		radix_sort(stack);
}

static void	new_list(char **list)
{
	t_node	*stack;
	int		*new_list;
	int		num_of_arg;

	num_of_arg = 0;
	while (list[num_of_arg])
		num_of_arg++;
	if (!no_int_twice(list))
		return (ft_putendl_fd("Error", 2));
	new_list = new_numbers(num_of_arg, list);
	if (!new_list)
		return ;
	stack = linked_list_start(num_of_arg, new_list);
	if (!stack)
		return ;
	sorting(num_of_arg, stack);
}

int	main(int argc, char	**argv)
{
	char	**list;

	argc = argc -1;
	argv = argv + 1;
	if (argc == 0)
		return (0);
	list = input_checker(argc, argv);
	if (!list)
		return (0);
	new_list(list);
	return (1);
}
