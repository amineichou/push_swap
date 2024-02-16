/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:07:44 by moichou           #+#    #+#             */
/*   Updated: 2024/02/16 15:45:12 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack_node **stack)
{
	if (check_sorted(*stack))
		return ;
	if ((*stack)->value > (*stack)->next->value)
		swap_stack_a(stack);
	if (!check_sorted(*stack))
		reverse_rotate_a(stack);
	if (!check_sorted(*stack))
		swap_stack_a(stack);
}

static void update_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	set_index(*stack_a);
	set_index(*stack_b);
	set_target_node(*stack_a, *stack_b);
	set_position_middle(*stack_a, *stack_b);
	set_cost(*stack_a, *stack_b);
}

static void	put_cheapest_on_top(t_stack_node **stack_a, t_stack_node **stack_b)
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
	cheapest = cheapest->target_node;
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

static void	final_step(t_stack_node **stack_a)
{
	t_stack_node	*smallest_node_value;
	int				rotate_steps;

	smallest_node_value = ft_get_smallest_value(*stack_a);
	if (smallest_node_value->is_above_middle)
		rotate_steps = smallest_node_value->index;
	else
		rotate_steps = ft_stack_size(*stack_a) - smallest_node_value->index;
	while (rotate_steps)
	{
		if (smallest_node_value->is_above_middle)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		rotate_steps--;
	}
}

static void	best_move(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_a_size;
	int	med;

	stack_a_size = ft_stack_size(*stack_a);
	med = (ft_get_biggest_value(*stack_a)->value + ft_get_smallest_value(*stack_a)->value) / 2;
	while (stack_a_size > 3)
	{
		push_a_to_b(stack_a, stack_b);
		if((*stack_b)->value > med)
			rotate_b(stack_b);
		stack_a_size--;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		update_stack(stack_a, stack_b);
		put_cheapest_on_top(stack_a, stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	update_stack(stack_a, stack_b);
	final_step(stack_a);
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size > 3)
		best_move(stack_a, stack_b);
}