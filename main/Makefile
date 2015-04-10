CC  = clang

SRC = $(wildcard ../shared/*.c) $(wildcard *.c) $(wildcard */*.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -g
FLAGS = -W -Wall -Werror -pedantic

NAME = corewar

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: clean fclean test
