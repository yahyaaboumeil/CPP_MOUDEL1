C = g++ 
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

SRCS = megaphone.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = megaphone

.c.o:
	${C} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${C} ${CFLAGS} -o $@ $^

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all fclean re clean