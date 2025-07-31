NAME = push_swap
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror -I include -I $(LIBFT_DIR)

SRC_DIR = srcs
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

REMOVE = rm -rf

SRC = $(SRC_DIR)/parsing.c \
	$(SRC_DIR)/operations.c \
	$(SRC_DIR)/push_swap_utils.c \
	$(SRC_DIR)/push_swap.c \
	$(SRC_DIR)/stack_utils.c \
	$(SRC_DIR)/sorting.c \
	$(SRC_DIR)/rotation.c \
	$(SRC_DIR)/radix_sort.c \
	$(SRC_DIR)/double_rotation.c \
	$(SRC_DIR)/parse_args.c 

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) 
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	cc $(CFLAGS) -I . -I $(LIBFT_DIR) -c $< -o $@

clean:
	$(REMOVE) $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean	
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
