/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:31:59 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/06 11:31:59 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*swap_first(t_node *head)
{
	t_node	*first;
	t_node	*second;

	if (head == NULL || head->next == NULL)
		return (head);
	first = head;
	second = head->next;
	first->next = second->next;
	second->next = first;
	head = second;
	return (head);
}
