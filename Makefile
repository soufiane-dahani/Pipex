SRCS = pipex.c 

OBJS = ${SRCS:.c=.o}
NAME = pipex
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re
