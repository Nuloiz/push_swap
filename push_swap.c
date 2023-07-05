/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:34:38 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/05 14:51:12 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	correct_input(char	*argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
	i++;
	}
	return (1);
}

int	main_s(int argc, char	**argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!correct_input(argv[i]))
			return (0);
		i++;
	}
	linked_list_start(argc, argv);

	/*sa = ft_printf("sa\n");
	// Switch Element 1 and 2 of Stack A
	sb = ft_printf("sb\n");
	// Switch Element 1 and 2 of Stack B
	ss = ft_printf("ss\n");
	// Switch Element 1 and 2 of Stack A and Stack B
	pa = ft_printf("pa\n");
	// Put First Element of Stack A on Top of Stack B
	pb = ft_printf("pb\n");
	// Put First Element of Stack B on top of STack A
	ra = ft_printf("ra\n");
	// Put First Element of Stack A at the Last Place and shift everything Up
	rb = ft_printf("rb\n");
	// Put First Element of STack B at the Last Place and shift everything Up
	rr = ft_printf("rr\n");
	// Put First Element of Stack A and Stack B at the Last Place and shift everything Up
	rra = ft_printf("rra\n");
	// Put Last Element of Stack A On Top of Stack A and shift everything Down
	rrb = ft_printf("rrb\n");
	// Put Last ELement of Stack B on Top of Stack B and shift everything Down
	rrr = ft_printf("rrr\n");
	// Put Last Element of Stack A and Stack B On Top of its Stack and shift everything Down*/
	return (0);
}

int	main(int argc, char** argv)
{
	return (main_s(argc - 1, argv + 1));
}
