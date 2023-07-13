/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_and_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:38:09 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/11 13:39:52 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(int argc, char **argv)
{
	int	i;
	int	j;

	i = -2147483647;
	j = 0;
	while (j < argc)
	{
		if (ft_atoi(argv[j]) < i)
			return (0);
		i = ft_atoi(argv[j]);
		j++;
	}
	return (1);
}

void	three_arg(t_node *stack_a)
{
	if (stack_a->value > stack_a->next->value)
		stack_a = sa(stack_a);
	if (stack_a->next->next != NULL)
	{
		if (stack_a->next->value > stack_a->next->next->value)
		{
			rotate_stack(&stack_a, NULL, "ra");
			stack_a = sa(stack_a);
			rotate_stack(&stack_a, NULL, "rra");
		}
	}
}
