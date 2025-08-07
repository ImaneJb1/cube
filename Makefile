NAME = cub3D
CC = cc
FLAGS = -Wall -Wextra -Werror

LIB = ./libft-project/libft.a
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
PARSING = parsing/main_parser.c parsing/ft_strcmp.c parsing/parse_dir.c parsing/parse_floor_ceiling.c parsing/struct_arr.c parsing/struct_initializer.c 
SRCS = $(GNL) $(PARSING) $(LIB) main.c

HEADER = header.h
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(LIB):
	make -C ./libft-project

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
 
clean : $(OBJ)
	rm $(OBJ)
	make -C ./libft-project clean
fclean : clean
	rm $(NAME)