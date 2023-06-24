NAME = cub3d

SRC = ../abouassi/cub3D.c ../abouassi/moves.c ../abouassi/functions_mlx.c\
../abouassi/cub3D_parce.c ../abouassi/free_err.c ../abouassi/cub_tool1.c\
string_action.c parce_first_element.c main.c drawing_walls.c\
drawing.c det_coord.c\


OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

CC = cc

all	: ${NAME}

${NAME} : ${OBJ}
		make -C ../libft
		${CC} ${CFLAGS} ${OBJ} ../libft/libft.a -o ${NAME} $(MLX_FLAG)

clean :
	$(RM) $(OBJ)

clean_all :
	make clean -C ../libft
	$(RM) $(OBJ)

fclean	:	clean
		make fclean -C ../libft
		$(RM) $(NAME)

re	:	fclean all