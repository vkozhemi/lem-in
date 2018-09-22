NAME := lem-in

LIB_DIR := ./libftprintf/
SRC_DIR := ./src/
OBJ_DIR := ./objects/
INC_DIR := ./includes/

SRCS := main.c ft_error.c ft_validation.c ft_validation2.c ft_walk_room.c ft_find_path.c ft_check_error.c
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC := gcc
FLAGS := -g -Wall -Wextra -Werror

LIBFT = $(LIB_DIR)libftprintf.a
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)includes

HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ $(CC) $(OBJ) $(FLAGS) $(HDR_FLAGS) -o $(NAME) $(LIBFT)
	@	# -fsanitize=address

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

$(LIBFT):
	@ make -C $(LIB_DIR)

clean:
	@ make clean -C $(LIB_DIR)
	@ rm -f $(OBJ)
	

fclean:
	@ make fclean -C $(LIB_DIR)
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_DIR)

re: fclean all
