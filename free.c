/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:55:50 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/14 09:55:50 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*pos;

	pos = stack;
	while (pos != NULL)
	{
		pos = stack->next;
		free(stack);
		stack = pos;
	}
}

void	free_array(char	**array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array);
		i++;
	}
	free(array);
}

void	free_array_list(int argc, char	**array)
{
	int	i;

	i = 0;
	while (i <= argc)
	{
		if (ft_strncmp(array[i], "!", 1) == 0)
		{
			free(array[i]);
		}
		i++;
	}
}

char	**new_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (NULL);
		i++;
	}
	return (argv);
}
