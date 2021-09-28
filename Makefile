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

SRCV = 	./vector_test/tester_vector.cpp	

OBJV = $(SRCV:.cpp=.o)

CXX = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

vector : $(NAMEV)

$(NAMEV) :	$(OBJV)
			$(CXX) $(CFLAGS) -o $(NAMEV) $(OBJV)


