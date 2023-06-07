NAME = cub3D

SRC =	cub3D.c\
		cub3D_parce.c\

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g

RM = rm -rf

CC = cc

all	: ${NAME}

${NAME} : ${OBJ}
		make -C libft
		${CC} ${CFLAGS} ${OBJ} libft/libft.a -o ${NAME}

clean :
	make clean -C libft
	$(RM) $(OBJ) 
	
fclean	:	clean
		make fclean -C libft
		$(RM) $(NAME)

re	:	fclean all