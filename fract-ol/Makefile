NAME		=	fractol

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

FILES		= 	${shell find ./source -name "*.c"}
SRC			= 	$(FILES)
OBJ			=	$(patsubst %.c,%.o,$(SRC))
HEAD		=	./include/fractal.h
INC			=	-I$(HEAD)

LIBFT_DIR	=	./libft

.PHONY:		all clean fclean re bonus rebonus

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) $(MLX_FLAGS) $(INC) $(OBJ) $(LIBFT_DIR)/libft.a -o $(NAME)
			@echo "\033[32m[$(NAME)] compiled."

%.o:		%.c $(HEAD)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@make clean -C $(LIBFT_DIR)
			@$(RM) $(OBJ)
			@echo "\033[32m[$(NAME)] removed object files."

fclean:		clean
			@make fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)
			@echo "\033[32m[$(NAME)] removed executable files."

re:			fclean all

bonus:		all

rebonus:	re
