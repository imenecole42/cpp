CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = ScalarConverter
SRCDIR = .
INCDIR = .
BUILDDIR = objects
OBJDIR = $(BUILDDIR)

SRCS = ScalarConverter.cpp\
		main.cpp
INCS = *.hpp
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$< -o $@

clean:
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(TARGET)

re: clean all
