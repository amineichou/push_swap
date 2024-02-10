NAME = test
CC = cc
SRC = test.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -fsanitize=address -o $(NAME)

clean:
	rm $(OBJ)

re: clean all