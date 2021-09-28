NAMEV = tester_vector

NAMEM = tester_map

NAMES = tester_stack

SRCV = 	./vector_test/tester_vector.cpp	

SRCM = ./map_test/map_main.cpp

SRCS = ./stack_test/tester_stack.cpp

OBJV = $(SRCV:.cpp=.o)

OBJM = $(SRCM:.cpp=.o)

OBJS = $(SRCS:.cpp=.o)

CXX = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: vector map stack

vector : $(NAMEV)

$(NAMEV) :	$(OBJV)
			$(CXX) $(CPPFLAGS) -o $(NAMEV) $(OBJV)

map : $(NAMEM)

$(NAMEM) :	$(OBJM)
			$(CXX) $(CPPFLAGS) -o $(NAMEM) $(OBJM)

stack : $(NAMES)

$(NAMES) :	$(OBJS)
			$(CXX) $(CPPFLAGS) -o $(NAMES) $(OBJS)

clean : 
		rm $(OBJV) $(OBJM) $(OBJS)

fclean : clean
		rm $(NAMEV) $(NAMEM) $(NAMES)

re : fclean all
