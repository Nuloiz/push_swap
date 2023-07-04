/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:34:09 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/04 12:05:56 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_list(void)
{
	t_node	*p;

	p = NULL;
	ft_printf("\n[");
	while (p != NULL)
	{
		ft_printf(" %d ", p->value);
		p = p->next;
	}
	ft_printf("]");
}

static t_node	*new_node(int current)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(struct s_node));
	new->value = current;
	new->next = new;
	return (new);
}

int	linked_list_start(int argc, char **argv)
{
	int		i;
	t_node	*head;

	i = 0;
	head = NULL;
	while (i++ < argc)
		new_node(ft_atoi(argv[i]));
	print_list();
	return (1);
}
