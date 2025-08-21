# CC = cc
# CFLAGS = #-Wall -Wextra -Werror #-fsanitize=address -g3
# SRC = main.c  parsing/get_next_line/*.c  parsing/map_parsing/*.c parsing/textures_parser/*.c garbage_collector/*.c \
# parsing/free_exit.c parsing/ft_strcmp.c parsing/global.c parsing/open_file.c parsing/struct_initializer.c \
# NAME = cub
# LIB = -lmlx -lXext -lX11

# %.o: %.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
# OBJ = $(SRC:.c=.o)

# all : $(NAME)

# $(NAME) : $(OBJ)
# 	@echo "🚀 Building the project..."
# 	@make -s all -C parsing/libft
# 	@$(CC) $(CFLAGS) $(OBJ) parsing/libft/libft.a $(LIB) -o $(NAME)
# 	@echo "✅ Build completed successfully!"


# fclean : clean
# 	@rm -rf $(NAME)
# 	@make -s fclean -C parsing/libft
# clean :
# 	@echo "🧹 Cleaning up..."
# 	@rm -rf $(OBJ)
# 	@make -s clean -C parsing/libft
# 	@echo "🗑️  Cleanup done!"

# re : fclean all

# .PHONY: all clean fclean re
# .SECONDARY:
NAME = cub
CC = cc
# FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -lXext -lX11 -lm

LIB = parsing/libft/libft.a

# Collect all sources
SRCS = $(wildcard *.c) \
       $(wildcard garbage_collector/*.c) \
       $(wildcard raycasting/*.c) \
       $(wildcard parsing/*.c) \
       $(wildcard parsing/get_next_line/*.c) \
       $(wildcard parsing/map_parsing/*.c) \
       $(wildcard parsing/textures_parser/*.c)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(LIB):
	make -C parsing/libft

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LIB) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C parsing/libft clean

fclean: clean
	rm -f $(NAME)
	make -C parsing/libft fclean

re: fclean all

.PHONY: all clean fclean re

