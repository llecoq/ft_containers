# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 11:27:48 by llecoq            #+#    #+#              #
#    Updated: 2022/04/13 17:42:41 by llecoq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	=				main.cpp

INCLUDES_UTILS_FILES =		utils.hpp\
							tester.hpp\
							tester_utils.hpp\
							RB_tree.hpp\
							node.hpp\
							pair.hpp\
							metafunctions.hpp

INCLUDES_FILES =  			vector.hpp\
							stack.hpp\
							map.hpp

ITERATORS_FILES =  			iterator.hpp\
							random_access_iterator.hpp\
							bidirectional_iterator.hpp\
							RB_tree_iterator.hpp\
							reverse_iterator.hpp

TESTER_FILES =				tester_map_ft.cpp\
							test.cpp\
							TestClass.cpp
							# tester_vector_ft.cpp\
							# tester_vector_std.cpp\
							# tester_pair.cpp\
							# tester_stack_ft.cpp\
							# tester_stack_std.cpp\

INCLUDES_PATH = 			containers/
INCLUDES_UTILS_PATH = 		utils/
INCLUDES_ITERATOR_PATH =	iterators/
INCLUDES_TESTER_PATH = 		tester/

OBJSPATH = .objs/

OBJS_FILES = $(SRCS_FILES:.cpp=.o) $(TESTER_SRCS:.cpp=.o)

TESTER_SRCS = $(addprefix $(INCLUDES_TESTER_PATH),$(TESTER_FILES))

OBJS = $(addprefix $(OBJSPATH),$(OBJS_FILES))

INCLUDES = $(addprefix $(INCLUDES_PATH),$(INCLUDES_FILES))

INCLUDES_UTILS = $(addprefix $(INCLUDES_UTILS_PATH),$(INCLUDES_UTILS_FILES))

INCLUDES_ITERATOR = $(addprefix $(INCLUDES_ITERATOR_PATH),$(ITERATORS_FILES))

NAME	= ft_containers

CXXC	= clang++

RM		= rm -rf

# CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3 $(DFLAGS)

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address $(DFLAGS)

DIR		=	.objs/

all		:	$(NAME)

$(OBJSPATH)%.o:		$(SRCSPATH)%.cpp $(INCLUDES) $(INCLUDES_UTILS) $(INCLUDES_ITERATOR) Makefile tester/TestClass.hpp
			@mkdir -p $(OBJSPATH) $(DIR)
			@mkdir -p $(OBJSPATH) .objs/tester
			$(CXXC) $(CFLAGS) -c $< -o $@ -I containers/ -I utils/ -I tester/ -I iterators/

$(NAME):	$(OBJS)
			$(CXXC) $(CFLAGS) $(OBJS) -o $(NAME)

$(TEST):	@

clean:
			$(RM) $(OBJSPATH) 
			# tester/tester_results/*.test

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

std:		$(TEST)
			@sh tester/scripts/test_std.sh

ft:			$(TEST)
			@sh tester/scripts/test_ft.sh

diff:		$(TEST)
			@sh tester/scripts/test_diff.sh

vector:		$(NAME)
			@sh tester/scripts/test_vector.sh

stack:		$(NAME)
			@sh tester/scripts/test_stack.sh

pair:		$(NAME)
			@sh tester/scripts/test_pair.sh

full:		$(NAME)
			@sh tester/scripts/test_vector.sh
			@sh tester/scripts/test_stack.sh
			@sh tester/scripts/test_pair.sh

.PHONY:		all clean fclean re stack vector pair full ft std
