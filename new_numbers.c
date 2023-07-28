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

static char	**move_back(char **list, char **new)
{
	int	i;

	i = 0;
	while (new[i] != NULL)
	{
		free(list[ft_atoi(new[i])]);
		list[ft_atoi(new[i])] = ft_itoa(i);
		if (!list[ft_atoi(new[i])])
			return (free_array(list), NULL);
		i++;
	}
	free_array(new);
	return (list);
}

char	**new_numbers(int argc, char **list)
{
	int		i;
	int		min;
	int		pos;
	int		loop;
	char	**new;

	loop = -1;
	new = ft_calloc(argc + 1, sizeof(char **));
	while (++loop < argc)
	{
		i = 0;
		min = 2147483647;
		while (list[i] != NULL)
		{
			if (ft_strncmp(list[i], "!", 1) && ft_atoi(list[i]) < min)
			{
				min = (int)ft_atoi(list[i]);
				pos = i;
			}
			i++;
		}
		list[pos] = ft_strdup("!");
		if (!list[pos])
			return (free_array_list(list), free_array(new), NULL);
		new[loop] = ft_itoa(pos);
		if (!new[loop])
			return (free_array(new), free_array_list(list), NULL);
	}
	return (move_back(list, new));
}
