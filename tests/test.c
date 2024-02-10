#ifndef NULL
#define NULL ((void*)0)
#endif

#include <libc.h>

typedef struct s_stack_node
{
	int 				value;
	int					index;
    int					coast;
	int					is_above_middle;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
} t_stack_node;


t_stack_node *create_node(int value) {
    t_stack_node *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (new_node) {
        new_node->value = value;
        new_node->next = NULL;
    }
    return new_node;
}

void push(t_stack_node **stack, int value) {
    t_stack_node *new_node = create_node(value);
    if (new_node) {
        new_node->next = *stack;
        *stack = new_node;
    }
}

void print_stack(t_stack_node *stack) {
    while (stack) {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void generate_linked_list(t_stack_node **stack, int start, int end) {
    if (start > end)
        return;
    for (int i = end; i >= start; i--) {
        push(stack, i);
    }
}

//##########################################################################################


t_stack_node	*get_prev_node(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*last;

	last = head;
	current  = head;
	while (last->next)
	{
		current = last;
		last = last->next;
	}
	return (current);
}

t_stack_node	*ft_get_last_node(t_stack_node *stack)
{
    t_stack_node *last;

    if (!stack)
        return (NULL);
    last = stack;
    while (last->next)
        last = last->next;
    return (last);
}

void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;
	if (!(*stack_b))
	{
		(*stack_b) = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		(*stack_b)->next = NULL;
		return ;
	}
    temp = *stack_a;   // Temporarily hold the top of stack A
    *stack_a = (*stack_a)->next;     // Move the top of stack A to the next node
    temp->next = *stack_b;           // Set the next of the temp node to the top of stack B
    *stack_b = temp;   
	printf("pb\n");
}

int main(void)
{
	t_stack_node *stack = NULL;
    t_stack_node *stack_sec = NULL;
    generate_linked_list(&stack, 1, 10);

    for (int i = 0; i < 5; i++)
    {
        push_a_to_b(&stack, &stack_sec);
    }

    print_stack(stack);
    print_stack(stack_sec);
}