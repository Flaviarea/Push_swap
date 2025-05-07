NAME = push_swap
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror 

SRC = parsing.c \
	operations.c \
	push_swap_utils.c \
	push_swap.c \
	stack_utils.c \
	sorting.c \
	rotation.c \
	radix_sort.c \
	double_rotation.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	cc $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean	
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
