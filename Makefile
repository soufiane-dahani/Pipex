SRCS = pipex.c ft_split.c pipex_utils.c pipex_utils2.c \
	ft_printf.c ft_printf_utils.c ft_strcat.c

OBJS = ${SRCS:.c=.o}
NAME = pipex
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -o ${NAME}
all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re
