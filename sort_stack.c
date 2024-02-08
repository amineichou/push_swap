/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:07:44 by moichou           #+#    #+#             */
/*   Updated: 2024/01/14 22:43:17 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack_node **stack)
{
	if ((*stack)->value < (*stack)->next->value)
		swap_stack_a(stack);
	if (!check_sorted(*stack))
	{
		rotate_a(stack);
		if (!check_sorted(*stack))
		{
			if ((*stack)->value > (*stack)->next->value)
				swap_stack_a(stack);
		}
	}
}

static void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (stack_size(*stack_a) > 3)
		push_a_to_b(stack_a, stack_b);
	sort_three(stack_a);
    if ((*stack_b)->value > (*stack_b)->next->value)
		swap_stack_b(stack_b);
	push_b_to_a(stack_a, stack_b);
	push_b_to_a(stack_a, stack_b);
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
}