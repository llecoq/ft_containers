/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/19 16:48:05 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_map_ft()
{
	ft::map<char, TestClass>			test;

	// int i = 0;
	// for (char c = 'a'; c < 'z'; c++)
	test.insert(ft::pair<char, TestClass>('h', 5));
	test.insert(ft::pair<char, TestClass>('a', 10));
	test.insert(ft::pair<char, TestClass>('z', 4));
	test.insert(ft::pair<char, TestClass>('a', 80));
	test.insert(ft::pair<char, TestClass>('j', 100));
	test.insert(ft::pair<char, TestClass>('k', 0));
	test.insert(ft::pair<char, TestClass>('b', 0));
	test.insert(ft::pair<char, TestClass>('l', 6));
	test.insert(ft::pair<char, TestClass>('e', 62));
	test.insert(ft::pair<char, TestClass>('p', 68));
	test.insert(ft::pair<char, TestClass>('b', 564));
	test.insert(ft::pair<char, TestClass>('y', 654));
	
	test.print_tree();
	ft::map<char, TestClass>::iterator	it = test.begin();

	std::cout << it->first << std::endl;
	it = test.end();
	std::cout << it->first << std::endl;

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