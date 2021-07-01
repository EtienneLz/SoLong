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

INCLUDES = -I/includes/solong.h

CFLAGS = -Wall -Wextra -Werror -g 

GCC = gcc

LIB = minilibx-linux/libmlx_Linux.a -I./usr/include -L minilibx-linux -Lmlx_linux -Imlx_linux -lXext -lX11 -lm

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		${GCC} ${CFLAGS} ${INCLUDES} ${OBJS} ${LIB} -o ${NAME}

bonus: ${OBJSBONUS}
		${GCC} ${CFLAGS} ${INCLUDES} ${OBJSBONUS} ${LIB} -o ${NAME}

clean: 
	${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re