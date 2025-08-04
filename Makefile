NAME = cub3D
CC = cc
FLAGS = -Wall -Wextra -Werror

LIB = ./libft-project/libft.a
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
PARSING = parsing/*.c
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
