# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 11:27:48 by llecoq            #+#    #+#              #
#    Updated: 2022/03/03 13:12:18 by llecoq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	=				main.cpp

INCLUDES_UTILS_FILES =		TestClass.hpp\
							tester.hpp

INCLUDES_FILES =  			vector.hpp

ITERATORS_FILES =  			iterator.hpp\
							random_access_iterator.hpp

TESTER_FILES =				tester_vector.cpp\
							tester_push_back.cpp

INCLUDES_PATH = 			containers/

INCLUDES_UTILS_PATH = 		utils/

INCLUDES_ITERATOR_PATH =	iterators/

TESTER_PATH = 				tester/

OBJSPATH = .objs/

OBJS_FILES = $(SRCS_FILES:.cpp=.o) $(TESTER_SRCS:.cpp=.o)

TESTER_SRCS = $(addprefix $(TESTER_PATH),$(TESTER_FILES))

OBJS = $(addprefix $(OBJSPATH),$(OBJS_FILES))

INCLUDES = $(addprefix $(INCLUDES_PATH),$(INCLUDES_FILES))

INCLUDES_UTILS = $(addprefix $(INCLUDES_UTILS_PATH),$(INCLUDES_UTILS_FILES))

INCLUDES_ITERATOR = $(addprefix $(INCLUDES_ITERATOR_PATH),$(ITERATORS_FILES))

NAME	= ft_containers

CXXC	= clang++

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -std=c++98

DIR		=	.objs/

all		:	$(NAME)

$(OBJSPATH)%.o:		$(SRCSPATH)%.cpp $(INCLUDES) $(INCLUDES_UTILS) $(INCLUDES_ITERATOR) Makefile
			@mkdir -p $(OBJSPATH) $(DIR)
			@mkdir -p $(OBJSPATH) .objs/tester
			$(CXXC) $(CFLAGS) -c $< -o $@ -I containers/ -I utils/

$(NAME):	$(OBJS)
			$(CXXC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJSPATH) tester_results/*.test

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
