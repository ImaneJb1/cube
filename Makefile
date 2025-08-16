CC = cc
CFLAGS = #-Wall -Wextra -Werror #-fsanitize=address -g3
SRC = main.c parsing/*.c parsing/*/*.c garbage_collector/*.c 
NAME = cub
LIB = -lmlx -lXext -lX11

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "🚀 Building the project..."
	@make -s all -C parsing/libft
	@$(CC) $(CFLAGS) $(OBJ) parsing/libft/libft.a $(LIB) -o $(NAME)
	@echo "✅ Build completed successfully!"


fclean : clean
	@rm -rf $(NAME)
	@make -s fclean -C parsing/libft
clean :
	@echo "🧹 Cleaning up..."
	@rm -rf $(OBJ)
	@make -s clean -C parsing/libft
	@echo "🗑️  Cleanup done!"

re : fclean all

.PHONY: all clean fclean re
.SECONDARY:
# NAME = cub3D
# CC = cc
# FLAGS = -Wall -Wextra -Werror

# LIB = ./libft-project/libft.a
# GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
# PARSING = parsing/main_parser.c parsing/ft_strcmp.c parsing/parse_dir.c parsing/parse_floor_ceiling.c parsing/struct_arr.c parsing/struct_initializer.c 
# SRCS = $(GNL) $(PARSING) $(LIB) main.c

# HEADER = header.h
# OBJ = $(SRCS:.c=.o)

# all : $(NAME)

# $(LIB):
# 	make -C ./libft-project

# %.o : %.c
# 	$(CC) $(FLAGS) -c $< -o $@

# $(NAME) : $(OBJ)
# 	$(CC) $(OBJ) -o $(NAME)
 
# clean : $(OBJ)
# 	rm $(OBJ)
# 	make -C ./libft-project clean
# fclean : clean
# 	rm $(NAME)
