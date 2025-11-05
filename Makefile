NAME       = cub3D
NAME_BONUS = cub3D_bonus
CC      = cc
CFLAGS  = # -Wall -Wextra Werror

MLX     = -lmlx -lXext -lX11 -lm #-g -fsanitize=address 

OBJ_D   = obj
OBJ_D_BONUS   = obj_bonus
LIB     = libft/libft.a

# Collect all sources
# SRCS = $(wildcard garbage_collector/*.c) \
#        $(wildcard raycasting/*.c) \
#        $(wildcard parsing/*.c) \
#        $(wildcard parsing/get_next_line/*.c) \
#        $(wildcard parsing/map_parsing/*.c) \
#        $(wildcard parsing/textures_parser/*.c)\
#        $(wildcard raycasting/*/*.c)
GNL = get_next_line/*.c
SRCS = $(shell find ./cub_mandatory -name "*.c")
SRCS_BONUS = $(shell find ./cub_bonus -name "*.c")
OBJ	 = $(SRCS:%.c=$(OBJ_D)/%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=$(OBJ_D_BONUS)/%.o)
# DEP  = $(OBJ:.o=.d)

HEADER = cub_mandatory/header.h
HEADER_BONUS = cub_bonus/header_bonus.h

all: $(NAME)
bonus: $(NAME_BONUS)

$(LIB):
	@make -C libft

# Rule to compile .c -> .o (+ .d)
$(OBJ_D)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_D_BONUS)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB) $(HEADER)
	$(CC) $(OBJ) $(LIB) $(MLX) -o $(NAME)
	@echo "✅ Build completed successfully!"

$(NAME_BONUS): $(OBJ_BONUS) $(LIB) $(HEADER_BONUS)
	$(CC) $(OBJ_BONUS) $(LIB) $(MLX) -o $(NAME_BONUS)
	@echo "✅ Build completed successfully!"
clean:
	rm -rf $(OBJ_D)
	rm -rf $(OBJ_D_BONUS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re

# Include auto-generated dependencies
# -include $(DEP)

.SECONDARY: $(OBJ) $(OBJ_BONUS)
