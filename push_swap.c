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

static int	correct_input_digits(char	*argv)
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

static int	correct_input_array(int argc, char *argv)
{
	int	i;

	i = 0;
	if (argc != 1)
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}


int	main(int argc, char	**argv)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 0;
	argc = argc -1;
	argv = argv + 1;

	if (!correct_input_array(argc, argv[i]))
	{
		while (i < argc)
		{
			if (!correct_input_digits(argv[i]))
				return (0);
			i++;
		}
	}
	else
	{
		argv = ft_split(argv[0], ' ');
		i = 1;
		while (argv[i++])
			argc++;
	}
	stack_a = linked_list_start(argc, argv);
	stack_b = test_stack_b(argc);
	ft_printf("Stack A:");
	print_list(stack_a);
	ft_printf("Stack B:");
	print_list(stack_b);
	// empty
	// empty:
	// empty;
	ft_printf("Stack A / Stack B with sa/sb:");
	stack_a = swap_first(stack_a);
	print_list(stack_a);
	// sa
	stack_b = swap_first(stack_b);
	print_list(stack_b);
	// sb
	ft_printf("Stack A / Stack B with ss");
	stack_a = swap_first(stack_a);
	print_list(stack_a);
	stack_b = swap_first(stack_b);
	print_list(stack_b);
	//ss
	ft_printf(("Stack A / Stack B with pa"));
	push_stack(&stack_a, &stack_b);
	//pa
	print_list(stack_a);
	ft_printf(("Stack A / Stack B with pb"));
	push_stack(&stack_b, &stack_a);
	//pb
	print_list(stack_a);
	ft_printf("Stack A / Stack B with ra/rb");
	stack_a = rotate_first(&stack_a);
	//ra
	stack_b = rotate_first(&stack_b);
	//rb
	print_list(stack_a);
	print_list(stack_b);
	ft_printf("Stack A / Stack B with rr");
	stack_a = rotate_first(&stack_a);
	stack_b = rotate_first(&stack_b);
	//rr
	print_list(stack_a);
	print_list(stack_b);
	ft_printf("Stack A / Stack B with rra/rrb");
	stack_a = rotate_last(&stack_a);
	//rra
	stack_b = rotate_last(&stack_b);
	//rrb
	print_list(stack_a);
	print_list(stack_b);
	ft_printf("Stack A / Stack B with rrr");
	stack_a = rotate_last(&stack_a);
	stack_b = rotate_last(&stack_b);
	//rrr
	print_list(stack_a);
	print_list(stack_b);
	return (0);
}
