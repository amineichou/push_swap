/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:32:15 by moichou           #+#    #+#             */
/*   Updated: 2024/02/18 17:27:58 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node *biggest;
	
	if (check_sorted(*stack))
		return ;
	biggest = ft_get_biggest_value(*stack);
	if (biggest == (*stack))
		rotate_a(stack);
	else if (biggest == (*stack)->next)
		reverse_rotate_a(stack);
	if (!check_sorted(*stack))
		swap_stack_a(stack);
}

void	update_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	set_index(*stack_a);
	set_index(*stack_b);
	set_target_node(*stack_a, *stack_b);
	set_position_middle(*stack_a, *stack_b);
	set_cost(*stack_a, *stack_b);
}

static void	put_cheapest_target_on_top(t_stack_node **stack_a, t_stack_node *cheapest)
{
	int	rotate_steps;

	if (cheapest->is_above_middle)
		rotate_steps = cheapest->index;
	else
		rotate_steps = ft_stack_size(*stack_a) - cheapest->index;
	while (rotate_steps)
	{
		if (cheapest->is_above_middle)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		rotate_steps--;
	}
}

void	put_cheapest_on_top(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;
	int 			rotate_steps;

	cheapest = ft_get_lowest_coast(*stack_b);
	if (cheapest->is_above_middle)
		rotate_steps = cheapest->index;
	else
		rotate_steps = ft_stack_size(*stack_b) - cheapest->index;
	while (rotate_steps)
	{
		if (cheapest->is_above_middle)
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
		rotate_steps--;
	}
	put_cheapest_target_on_top(stack_a, cheapest->target_node);
}

void choose_on_top(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;
	int				rotate_steps;

	cheapest = ft_get_lowest_coast(*stack_b);
	if (cheapest->is_above_middle && cheapest->target_node->is_above_middle)
	{
		while (cheapest->target_node->value != (*stack_a)->value && cheapest->value != (*stack_b)->value)
		{
			rotate_a_b(stack_a, stack_b);
			printf("kh");
		}
	}
	else if (!cheapest->is_above_middle && !cheapest->target_node->is_above_middle)
	{
		while (cheapest->target_node->value != (*stack_a)->value && cheapest->value != (*stack_b)->value)
		{
			reverse_rotate_a_b(stack_a, stack_b);
			printf("kh");
		}
	}
	put_cheapest_on_top(stack_a, stack_b);
}
