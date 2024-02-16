FLAGS = #-Wall -Wextra -Werror
CC = cc
NAME = push_swap
PUSH_SWAP_SRC = push_swap.c
SRC =  ft_split.c utils.c set_stack.c sort_stack.c push.c reverse_rotate.c rotate.c swap.c stack_updater.c sort_tools.c
OBJ = $(SRC:.c=.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(PUSH_SWAP_OBJ)
	$(CC) $(FLAGS) $(PUSH_SWAP_OBJ) $(OBJ) -fsanitize=address -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(PUSH_SWAP_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
