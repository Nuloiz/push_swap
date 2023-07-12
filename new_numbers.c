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

static char	**move_back(char **argv, char **new)
{
	int	i;

	i = 0;
	while (new[i] != NULL)
	{
		argv[ft_atoi(new[i])] = ft_itoa(i);
		i++;
	}
	return (argv);
}

char	**new_numbers(int argc, char **argv)
{
	int		i;
	int		min;
	int		pos;
	int		loop;
	char	**new;

	loop = -1;
	new = ft_calloc(argc + 1, sizeof(char **));
	while (loop++ < argc)
	{
		i = 0;
		min = INT32_MAX;
		while (argv[i] != NULL)
		{
			if (ft_strncmp(argv[i], "!", 1) && ft_atoi(argv[i]) < min)
			{
					min = ft_atoi(argv[i]);
					pos = i;
			}
			i++;
		}
		argv[pos] = ft_strdup("!");
		new[loop] = ft_itoa(pos);
	}
	return (move_back(argv, new));
}
