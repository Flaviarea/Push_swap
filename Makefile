NAME = push_swap
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = parsing.c \
	operations.c \
	push_swap_utils.c \
	push_swap.c \
	stack_utils.c \
	sorting.c \
	rotation.c \
	radix_sort.c \
	double_rotation.c \
	parse_args.c \

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) 
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	cc $(CFLAGS) -I . -I $(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean	
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
