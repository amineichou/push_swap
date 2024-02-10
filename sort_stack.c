/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:07:44 by moichou           #+#    #+#             */
/*   Updated: 2024/02/10 17:42:44 by moichou          ###   ########.fr       */
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

static void sort_more(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node	*head_node_a;
	int				stack_a_size;

	head_node_a = *stack_a;
	stack_a_size = ft_stack_size(*stack_a);
	while (head_node_a && stack_a_size > 3)
	{
		push_a_to_b(&head_node_a, stack_b);
		head_node_a = head_node_a->next;
		stack_a_size--;
        printf("stack size %d\n", stack_a_size);
	}
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size > 3)
		sort_more(stack_a, stack_b);
}