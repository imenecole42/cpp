NAME		= violence
CC			= c++
CPPFLAGS	= -std=c++98 -Wall -Werror -Wextra
SRC			= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ			= $(SRC:.cpp=.o)
RM			= rm -f

all		: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

.cpp.o	:
	$(CC) $(CPPFLAGS) -o $@ -c $<

.PHONY	: all clean fclean re

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re		: fclean
	make all