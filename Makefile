NAME = cub3D

SRCS = srcs/init.c \
			srcs/map_check.c
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \

OBJS = srcs/init.o \
			srcs/map_check.o
			srcs/get_next_line.o \
			srcs/get_next_line_utils.o \

INCLUDES = -I/includes/solong.h

CFLAGS = -Wall -Werror -Wextra -g

GCC = gcc 

LIB = libmlx_Linux.a -I./usr/include -L /usr/lib/ -Lmlx_linux -Imlx_linux -lXext -lX11 -lm

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