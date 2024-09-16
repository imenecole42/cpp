NAME		= ClapTrap
CC			= c++
CPPFLAGS	= -std=c++98 -MMD -MP -Wall -Werror -Wextra
OBJDIR		= ./obj
SRC			=	main.cpp		\
 				ClapTrap.cpp
OBJ_O		= $(SRC:.cpp=.o)
OBJ_D		= $(SRC:.cpp=.d)
RM			= rm -rf

all		: $(NAME)

$(OBJDIR)/%.o	: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -o $@ -c $<

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
