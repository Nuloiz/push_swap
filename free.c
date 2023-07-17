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
