SRCS	= $(shell find . -name "*.cpp")

HEADERS = $(shell find . -name "*.hpp")

OBJS	= ${SRCS:.cpp=.o}

NAME	= btc

CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g3 -O0

RM		= rm -rf

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all:	$(NAME)

$(NAME): ${OBJS} ${HEADERS}	
		${CC} ${CFLAGS} ${OBJS}  -o ${NAME}

clean:	
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all re clean fclean