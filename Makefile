NAME = SoLong

SRCS = srcs/init.c \
			srcs/map_check.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/error.c \
			srcs/input.c \
			srcs/movement.c \
			srcs/win_refresh.c \
			srcs/utils.c \

SRCBONUS = srcs/init.c \
			srcs/map_check.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/error.c \
			srcs/input.c \
			srcs/movement.c \
			srcs_bonus/win_refresh_bonus.c \
			srcs_bonus/itoa.c \
			srcs/utils.c \

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${SRCBONUS:.c=.o}

PATH_MLX = minilibx-linux

INCLUDES = -I/includes/solong.h

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

GCC = gcc

LIB = minilibx-linux/libmlx_Linux.a -I./usr/include -L minilibx-linux -Lmlx_linux -Imlx_linux -lXext -lX11 -lm

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		make -C $(PATH_MLX)
		${GCC} ${CFLAGS} ${INCLUDES} ${OBJS} ${LIB} -o ${NAME}

bonus: ${OBJSBONUS}
		make -C $(PATH_MLX)
		${GCC} ${CFLAGS} ${INCLUDES} ${OBJSBONUS} ${LIB} -o ${NAME}

clean:
	make -C $(PATH_MLX) clean
	${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
	make -C $(PATH_MLX) clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re