/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:17:54 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/12 16:17:54 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*move_back(int *new)
{
	int	*list;
	int	i;

	list = NULL;
	i = 0;
	while (new[i])
	{
		list[new[i]] = i;
		i++;
	}
	return (list);
}

/*static int	*new_int_list(int argc, char **list)
{
	int	*new;
	int	i;

	new = NULL;
	i = 0;
	while (i < argc)
	{
		new[i] = (int)ft_atoi(list[i]);
		i++;
	}
	return (new);
}*/

int	*new_numbers(int argc, char **list)
{
	int		i;
	int		min;
	int		pos;
	int		loop;
	int		*new;

	loop = -1;
	new = malloc(argc * sizeof(int));
	if (!new)
		return (NULL);
	while (++loop < argc)
	{
		i = 0;
		min = 2147483647;
		while (list[i])
		{
			if (ft_strncmp(list[i], "!", 1) && ft_atoi(list[i]) <= min)
			{
				min = (int)ft_atoi(list[i]);
				pos = i;
			}
			i++;
		}
		list[pos] = "!";
		new[loop] = pos;
	}
	free_array_list(argc, list);
	return (move_back(new));
}
