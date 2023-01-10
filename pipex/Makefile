NAME = pipex

CFLAGS = -Wall -Werror -Wextra

SRCS = pipex.c nursery.c errs.c util1.c util2.c

OBJS = ${SRCS:c=o} 

%.o : %.c pipex.h Makefile
	${CC} ${CFLAGS} -c $<

${NAME} : ${OBJS} pipex.h Makefile
	${CC} ${OBJS} -o $@

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all