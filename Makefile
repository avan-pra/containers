# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 14:20:13 by jereligi          #+#    #+#              #
#    Updated: 2021/04/06 11:35:51 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
			$(CXX) $(CFLAGS) -o $(NAMEV) $(OBJV)

map : $(NAMEM)

$(NAMEM) :	$(OBJM)
			$(CXX) $(CFLAGS) -o $(NAMEM) $(OBJM)

stack : $(NAMES)

$(NAMES) :	$(OBJS)
			$(CXX) $(CFLAGS) -o $(NAMES) $(OBJS)
