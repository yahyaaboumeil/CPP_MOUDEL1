C = g++ -g 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ClsContact.cpp ClsPhoneBook.cpp main.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = phonebook 

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