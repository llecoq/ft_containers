# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 11:27:48 by llecoq            #+#    #+#              #
#    Updated: 2022/02/27 18:02:07 by llecoq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	=			main.cpp\
						TestClass.cpp\
						tester_vector.cpp

OBJS_FILES = $(SRCS_FILES:.cpp=.o)

INCLUDES_FILES =  		vector.hpp

INCLUDES_PATH = 		containers/

INCLUDES_UTILS_PATH = 	utils/

INCLUDES_UTILS_FILES =	iterator.hpp\
						random_access_iterator.hpp\
						tester.hpp

OBJSPATH = .objs/

SRCS = $(addprefix $(SRCSPATH),$(SRCS_FILES))

OBJS = $(addprefix $(OBJSPATH),$(OBJS_FILES))

INCLUDES = $(addprefix $(INCLUDES_PATH),$(INCLUDES_FILES))

INCLUDES_UTILS = $(addprefix $(INCLUDES_UTILS_PATH),$(INCLUDES_UTILS_FILES))

NAME	= ft_containers

CXXC	= clang++

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -std=c++98

DIR		=	.objs/

all		:	$(NAME)

$(OBJSPATH)%.o:		$(SRCSPATH)%.cpp $(INCLUDES) $(INCLUDES_UTILS) Makefile
			@mkdir -p $(OBJSPATH) $(DIR)
			$(CXXC) $(CFLAGS) -c $< -o $@ -I containers/ -I utils/

$(NAME):	$(OBJS)
			$(CXXC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJSPATH) tester_results/*.test

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
