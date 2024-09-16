NAME		= Animal
CC			= c++
CPPFLAGS	= -std=c++98 -Wall -Werror -Wextra
INCDIR		= -I headers
SRCDIR		= ./srcs
OBJDIR		= ./obj
SRC			= main.cpp		\
				Animal.cpp		\
				Cat.cpp			\
				Brain.cpp		\
				Dog.cpp			\
				WrongAnimal.cpp	\
				WrongCat.cpp
OBJ_O		= $(SRC:.cpp=.o)
OBJ_D		= $(SRC:.cpp=.d)
RM			= rm -rf

all		: $(NAME)

$(OBJDIR)/%.o	: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(INCDIR) -o $@ -c $<

$(NAME) : $(addprefix $(OBJDIR)/,$(OBJ_O))
	$(CC) -o $@ $^

.PHONY	: all clean fclean re

clean	:
	$(RM) $(OBJDIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean
	make all

-include	$(addprefix $(OBJDIR)/,$(OBJ_D))
