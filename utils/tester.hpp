/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:49:09 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/22 12:21:07 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
#define TESTER_HPP

#if std_lib
	#define TESTING "Testing with std library"
	// #include <map>
	// #include <stack>
	// #include <set>
	#include <limits>
	#include <iterator>
	// #include <vector>
	namespace ft = std;
#else
	#define TESTING "Testing with ft library"
	#include "metafunctions.hpp"
	#include "vector.hpp"
	#include "stack.hpp"
	#include "map.hpp"
	#include "set.hpp"
	#include "utils.hpp"
#endif

#include "TestClass.hpp"
#include "tester_utils.hpp"

# include <string>
# include <vector>
# include <stack>
# include <map>
# include <set>
# include <stdio.h>

int		tester_vector();
int		tester_pair();
int		tester_stack();
int		tester_map();
int		tester_set();

typedef std::map<int, int> 			std_map;
typedef ft::map<int, int> 			ft_map;
typedef std::pair<int, int>			std_pair;
typedef ft::pair<int, int>			ft_pair;
typedef ft::set<int>				ft_set;
typedef std::set<int>				std_set;

typedef std::map<int, TestClass> 	std_test_map;
typedef ft::map<int, TestClass> 	ft_test_map;
typedef std::pair<int, TestClass>	std_test_pair;
typedef ft::pair<int, TestClass>	ft_test_pair;

#define ERROR 1
#define SUCCESS 0

#endif