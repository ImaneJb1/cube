NAME       = cub3D
NAME_BONUS = cub3D_bonus
CC         = cc
CFLAGS     = -Wall -Wextra -Werror

MLX        = -lmlx -lXext -lX11 -lm -g
OBJ_D      = obj
OBJ_D_BONUS = obj_bonus
LIB        = libft/libft.a

SRCS       = $(shell find ./cub_mandatory -name "*.c")
SRCS_BONUS = $(shell find ./cub_bonus -name "*.c")
OBJ        = $(SRCS:%.c=$(OBJ_D)/%.o)
OBJ_BONUS  = $(SRCS_BONUS:%.c=$(OBJ_D_BONUS)/%.o)

HEADER = cub_mandatory/header.h 
HEADER_BONUS = cub_bonus/header_bonus.h

all: $(NAME)
bonus: $(NAME_BONUS)

$(LIB):
	@make -C libft >/dev/null

$(OBJ_D)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_D_BONUS)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB) $(HEADER)
	@echo "🛠️  Compiling cub3D..."
	@$(CC) $(OBJ) $(LIB) $(MLX) -o $(NAME)
	@echo "🔗 Linking cub3D..."
	@echo "✅ Build completed!"

$(NAME_BONUS): $(OBJ_BONUS) $(LIB) $(HEADER_BONUS)
	@echo "🛠️  Compiling cub3D_bonus..."
	@$(CC) $(OBJ_BONUS) $(LIB) $(MLX) -o $(NAME_BONUS)
	@echo "🔗 Linking cub3D_bonus..."
	@echo "✅ Bonus build completed!"

clean:
	@rm -rf $(OBJ_D) $(OBJ_D_BONUS)
	@make -C libft clean >/dev/null
	@echo "🧹 Objects cleaned!"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C libft fclean >/dev/null
	@echo "🗑️  Binaries removed!"

re: fclean all

.PHONY: all clean fclean re bonus
