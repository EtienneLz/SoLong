NAME = SoLong

SRCS = srcs/init.c \
			srcs/map_check.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/error.c \
			srcs/input.c \
			srcs/movement.c \
			srcs/win_init.c \

OBJS = srcs/init.o \
			srcs/map_check.o \
			srcs/get_next_line.o \
			srcs/get_next_line_utils.o \
			srcs/error.o \
			srcs/input.o \
			srcs/movement.o \
			srcs/win_init.o \


INCLUDES = -I/includes/solong.h

CFLAGS = -Wall -Wextra -g

GCC = gcc 

LIB = minilibx-linux/libmlx_Linux.a -I./usr/include -L minilibx-linux -Lmlx_linux -Imlx_linux -lXext -lX11 -lm

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		${GCC} ${CFLAGS} ${INCLUDES} ${OBJS} ${LIB} -o ${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re