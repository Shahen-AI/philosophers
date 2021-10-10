NAME = philo
SRCS = main.c ${shell find "./src/" -name "*.c"}
OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
		${CC} -o ${NAME} ${OBJS}

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
