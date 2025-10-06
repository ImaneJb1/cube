NAME    = cub
CC      = cc
CFLAGS  = -I./ -MMD -MP
MLX     = -lmlx -lXext -lX11 -lm

OBJ_D   = obj
LIB     = parsing/libft/libft.a

# Collect all sources
SRCS = $(shell find . -name "*.c")
OBJ  = $(SRCS:%.c=$(OBJ_D)/%.o)
DEP  = $(OBJ:.o=.d)

HEADER = header.h

all: $(NAME)

$(LIB):
	@make -C parsing/libft

# Rule to compile .c -> .o (+ .d)
$(OBJ_D)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LIB) $(MLX) -o $(NAME)
	@echo "✅ Build completed successfully!"

clean:
	rm -rf $(OBJ_D)
	make -C parsing/libft clean

fclean: clean
	rm -f $(NAME)
	make -C parsing/libft fclean

re: fclean all

.PHONY: all clean fclean re

# Include auto-generated dependencies
-include $(DEP)

.SECONDARY: $(OBJ)
