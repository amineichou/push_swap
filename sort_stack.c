/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:07:44 by moichou           #+#    #+#             */
/*   Updated: 2024/02/12 13:09:16 by moichou          ###   ########.fr       */
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

// static void	set_cost(t_stack_node *stack_a, t_stack_node *stack_b)
// {
// 	t_stack_node	*head_a;
// 	int				middle_a;
// 	int				middle_b;
// 	int				big_smallest;

// 	middle_a = ft_stack_size(stack_a) / 2;
// 	middle_b = ft_stack_size(stack_b) / 2;
// 	while (head_a)
// 	{
// 		if (head_a->index >= middle_a)
// 		{
			
// 		}
// 		head_a = head_a->next;
// 	}
// }

static void	set_index(t_stack_node *stack)
{
	t_stack_node	*head;
	int 			i;

	head = stack;
	i = 0;
	while (head)
	{
		head->index = i;
		head = head->next;
		i++;
	}
}

static void	set_target_node(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*head_a;
	t_stack_node	*head_b;

	head_b = stack_b;
	while (head_b)
	{
		head_a = stack_a;
		while (head_a)
		{
			if (head_b->value > head_a->value && head_b->target_node
				&& head_b->target_node->value > head_a->value)
				head_b->target_node = head_a;
			head_a = head_a->next;
		}
		if (head_b->target_node == NULL)
			head_b->target_node = ft_get_smallest_value(stack_a);
		head_b = head_b->next;
	}
}

static void sort_more(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				stack_a_size;

	stack_a_size = ft_stack_size(*stack_a);
    // push everything to stack b exept last 3 nodes
	while (stack_a_size > 3)
	{
		push_a_to_b(stack_a, stack_b);
		stack_a_size--;
	}
	sort_three(stack_a);
	set_index(*stack_a);
	set_index(*stack_b);
    set_target_node(*stack_a, *stack_b);
	// set_cost(*stack_a, *stack_b);
	// while (*stack_b)
	// {
	// 	push_b_to_a(stack_a, stack_b);
	// }
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