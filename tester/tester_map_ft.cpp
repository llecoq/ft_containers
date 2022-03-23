/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/23 14:52:12 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

typedef ft::map<int, int> 		ft_map;
typedef std::map<int, int> 		std_map;
typedef ft::pair<int, int>		ft_pair;
typedef std::pair<int, int>		std_pair;


int	tester_map_ft()
{

	ft_map			test;
	ft::fillMap<ft_map, ft_pair>(test, 50, RANDOM);

	// std_map			test_std;
	// ft::fillMap<std_map, std_pair>(test_std, 10, RANDOM);

	std::cout << std::endl;
	test.print_tree();
	ft_map::iterator	it = test.begin();
	ft_map::iterator	ite = test.end();
	
	// std::cout << it->first << std::endl;
	// std::cout << ite->first << std::endl;

	// it++;
	// std::cout << it->first << std::endl;
	std::cout << "increment" << std::endl;
	while (it != ite)
	{
		std::cout << it->first << std::endl;
		it++;
	}
	std::cout << "decrement" << std::endl;
	while (--it != test.begin())
	{
		std::cout << it->first << std::endl;
	}
	// std::map<char, TestClass>::iterator	it = test.begin();
	// std::map<char, TestClass>::iterator	it2 = test.begin();
	// std::map<char, TestClass>::iterator	ite = test.end();
	// ite--;


	// std::cout << (it == it2) << std::endl;

	// ft::map<char, int>::iterator::

	// int	i = 0;


	// std::cout << "find" << std::endl;
	// it = test.find('h');
	// std::cout << "erase" << std::endl;
	// test.erase('k');
	// std::cout << "erase done" << std::endl;
	// std::cout << "insert" << std::endl;
	// test.insert(std::pair<char, TestClass>('k', 12));
	// std::cout << "insert done" << std::endl;

	return (SUCCESS);
}