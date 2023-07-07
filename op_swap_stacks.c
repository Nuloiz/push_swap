/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:32:09 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/06 11:32:09 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_node	**stack_get, t_node **stack_loose)
{
	t_node	*first_a;

	if ((*stack_loose) == NULL)
		return ;
	first_a = *stack_loose;
	*stack_loose = (*stack_loose)->next;
	first_a->next = *stack_get;
	*stack_get = first_a;
	return ;
}
