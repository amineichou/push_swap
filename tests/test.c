#ifndef NULL
#define NULL ((void*)0)
#endif

#include <libc.h>
#include <time.h>

typedef struct s_stack_node
{
	int 				value;
	int					index;
    int					coast;
	int					is_above_middle;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
} t_stack_node;


void initRandom() {
    srand(time(NULL)); // Seed the random number generator with the current time
}

int generateNumber() {
    return rand() % 11;
}

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
        push(stack, generateNumber());
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
		*stack_b = *stack_b;
		*stack_b = (*stack_a)->next; 
		(*stack_b)->next = NULL;
		return ;
	}
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
	printf("pb\n");
}

t_stack_node	*ft_get_smallest_value(t_stack_node *head)
{
	t_stack_node	*smallest;

	smallest = head;
	while (head)
	{
		if (smallest->value > head->value)
			smallest = head;
		head = head->next;
	}
    return (smallest);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}


static size_t	ft_count_delimiters(char const *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**free_allocated(char **splited)
{
	size_t	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (0);
}

static char	**fill_the_splited(char **splited, const char *str, char c)
{
	int	splited_i;
	int	index;
	int	str_len;

	splited_i = 0;
	index = 0;
	while (str[index])
	{
		str_len = 0;
		while (str[index] == c)
			index++;
		while (str[index] != c && str[index])
		{
			str_len++;
			index++;
		}
		if (str_len == 0)
			break ;
		splited[splited_i] = malloc(sizeof(char) * (str_len + 1));
		if (!splited[splited_i])
			return (free_allocated(splited));
		ft_strlcpy(splited[splited_i], &str[index] - str_len, str_len + 1);
		splited_i += 1;
	}
	return (splited);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		count_del;

	if (!s)
		return (0);
	count_del = ft_count_delimiters(s, c);
	splited = malloc(sizeof(char *) * (count_del + 1));
	if (!splited)
		return (0);
	if (!fill_the_splited(splited, s, c))
		return (0);
	splited[count_del] = 0;
	return (splited);
}


int main(int ac, char **av)
{
    initRandom();
	t_stack_node *stack = NULL;
    generate_linked_list(&stack, 4, 10);

    // printf("smallest %d\n", ft_get_smallest_value(stack)->value);

    // print_stack(stack);
    // char **test = ft_split(av[1], ' ');
    // int i = 0;
    // while (test[i])
    // {
    //     printf("%s\n", test[i]);
    //     i++;
    // }
}