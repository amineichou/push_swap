/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:05:12 by moichou           #+#    #+#             */
/*   Updated: 2024/02/09 21:02:23 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// take the top node of b and push it to a
void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*stack_a_last;
	t_stack_node	*stack_b_last;
	t_stack_node	*stack_a_last_prev;
	if (ft_stack_size(*stack_a) == 0)
		return ;
	stack_a_last = get_last_node(stack_a);
	stack_b_last = get_last_node(stack_b);
	stack_a_last_prev = *stack_a;
	while (stack_a_last_prev->next->next != NULL)
		stack_a_last_prev = stack_a_last_prev->next;
	if (!stack_b_last)
	{
		*stack_b = stack_a_last;
		stack_a_last_prev->next = NULL;
		ft_putstr("pb\n");
		return ;
	}
	stack_a_last_prev->next = NULL;
	stack_b_last->next = stack_a_last;
	ft_putstr("pb\n");
}

void	push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*stack_a_top;
	t_stack_node	*stack_b_top;
	t_stack_node	*stack_b_sec;

	if (ft_stack_size(*stack_b) == 0)
		return ;
	stack_a_top = (*stack_a);
	stack_b_top = (*stack_b);
	// check if there's only one node in stack b
	if (ft_stack_size(*stack_b) == 1)
	{
		stack_b_top->next = stack_a_top;
		*stack_a = stack_b_top;
		*stack_b = NULL;
	}
	else
	{
		stack_b_sec = (*stack_b)->next;
		stack_b_top->next = stack_a_top;
		*stack_a = stack_b_top;
		*stack_b = stack_b_sec;
	}
	ft_putstr("pa\n");
}
