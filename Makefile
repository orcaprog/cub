NAME = cub3D

NAME_BONUS = cub3D_bonus

SRC =	src/cub3D.c\
		src/main.c\
		src/cub3D_parce.c\
		src/free_err.c\
		src/cub_tool1.c\
		src/moves.c\
		src/functions_mlx.c\
		src/linked.c\
		src/string_action.c\
		src/parce_first_element.c\
		src/drawing.c\
		src/det_coord.c\
		src/drawing_walls.c\
		src/cub_utils.c\
		src/cub.c\

SRC_BONUS =	src_bonus/cub3D.c\
		src_bonus/main.c\
		src_bonus/cub3D_parce.c\
		src_bonus/free_err.c\
		src_bonus/cub_tool1.c\
		src_bonus/put_cub.c\
		src_bonus/moves.c\
		src_bonus/functions_mlx.c\
		src_bonus/linked.c\
		src_bonus/wapean.c\
		src_bonus/string_action.c\
		src_bonus/parce_first_element.c\
		src_bonus/drawing.c\
		src_bonus/det_coord.c\
		src_bonus/drawing_walls.c\
		src_bonus/open_door.c\
		src_bonus/cub_utils.c\
		src_bonus/cub.c\

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}


CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

CC = cc

all : ${NAME}

${NAME} : ${OBJ}
		make -C libft
		${CC} ${CFLAGS} ${OBJ} libft/libft.a -o ${NAME} $(MLX_FLAG)

bonus	: ${NAME_BONUS}

${NAME_BONUS} : ${OBJ_BONUS}
		make -C libft
		${CC} ${CFLAGS} ${OBJ_BONUS} libft/libft.a -o ${NAME_BONUS} $(MLX_FLAG)

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

clean_all :
	make clean -C libft
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean	:	clean
		make fclean -C libft
		$(RM) $(NAME)
		$(RM) $(NAME_BONUS)

re	:	fclean all