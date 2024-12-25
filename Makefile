SRCS = pipex.c ft_split.c pipex_utils.c pipex_utils2.c \
	ft_printf.c ft_printf_utils.c ft_strcat.c
SRCSB = pipex_bonus.c pipex_bonus_utils.c ft_printf.c \
	ft_printf_utils.c ft_split.c ft_strcat.c ft_strncmp.c \
	ft_strnstr.c ft_strjoin.c
OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}
NAME = pipex
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -o ${NAME}

bonus: ${OBJSB}
	$(CC) $(CFLAGS) ${OBJSB} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
