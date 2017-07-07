NAME1		= push_swap
NAME2		= checker

INC			= includes
LIBFT		= libft/includes
CC			= gcc
FLAGS		= -Wall -Werror -Wextra

FILENAMES1	= push_swap.c 
FILENAMES2	= checker.c operations.c condition.c helper.c

SRC1		= $(addprefix src/, $(FILENAMES1))
SRC2		= $(addprefix src/, $(FILENAMES2))

OBJ1		= $(addprefix build/, $(FILENAMES1:.c=.o))
OBJ2		= $(addprefix build/, $(FILENAMES2:.c=.o))

OBJ			= $(OBJ1)
OBJ			= $(OBJ2)

.PHONY: all clean fclean re test

all : build libft $(NAME1) $(NAME2)

build/%.o: src/%.c
	$(CC) $(FLAGS) -I $(LIBFT) -I inc -c $< -o $@

$(NAME1): $(OBJ1)
	$(CC) $(OBJ1) -I $(LIBFT) libft/libft.a -I inc -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) -I $(LIBFT) libft/libft.a -I inc -o $(NAME2)

build:
	mkdir -p build
	make -C libft

clean:
	rm -rf build
	make fclean -C libft

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)

re: fclean all
