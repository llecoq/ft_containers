/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:49:09 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/12 15:16:31 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
#define TESTER_HPP

#if std_lib
	#define TESTING "Testing with std library"
	#include <map>
	#include <stack>
	#include <limits>
	#include <iterator>
	#include <vector>
	namespace ft = std;
#else
	# define TESTING "Testing with ft library"
	# include "metafunctions.hpp"
	# include "../containers/vector.hpp"
	# include "../containers/stack.hpp"
	# include "../containers/map.hpp"
	# include "utils.hpp"
#endif

#  include "TestClass.hpp"
#  include "tester_utils.hpp"

// #include <iostream>
#include <string>
// #include <cstdlib>

# include <vector>
# include <stack>
# include <map>
# include <stdio.h>

int		tester_vector_ft();
int		tester_vector_std();
int		tester_pair_ft();
int		tester_pair_std();
int		tester_stack_ft();
int		tester_stack_std();
int		tester_map_ft();
int		test();

int		tester_bidirectional_it();

typedef std::map<int, int> 		std_map;
typedef ft::map<int, int> 		ft_map;
typedef std::pair<int, int>		std_pair;
typedef ft::pair<int, int>		ft_pair;

#define ERROR 1
#define SUCCESS 0



#endif