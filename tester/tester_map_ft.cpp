/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/22 17:37:23 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_map_ft()
{
	ft::map<char, TestClass>			test;
	ft::map<char, TestClass>			test2;
	// test2.insert(ft::pair<char, TestClass>('a', 1));


	// int i = 0;
	// for (char c = 'a'; c < 'z'; c++)
	test.insert(ft::pair<char, TestClass>('e', 5));
	test.insert(ft::pair<char, TestClass>('d', 4));
	test.insert(ft::pair<char, TestClass>('b', 2));
	test.insert(ft::pair<char, TestClass>('c', 3));
	test.insert(ft::pair<char, TestClass>('k', 11));
	test.insert(ft::pair<char, TestClass>('f', 6));
	test.insert(ft::pair<char, TestClass>('a', 1));
	test.insert(ft::pair<char, TestClass>('g', 7));
	test.insert(ft::pair<char, TestClass>('h', 8));
	test.insert(ft::pair<char, TestClass>('j', 10));
	test.insert(ft::pair<char, TestClass>('i', 9));
	test.insert(ft::pair<char, TestClass>('l', 12));
	std::cout << std::endl;
	test.print_tree();
	ft::map<char, TestClass>::iterator	it = test.begin();
	// std::map<char, TestClass>::iterator	it2 = test.begin();
	ft::map<char, TestClass>::iterator	ite = test.end();
	// ite--;

	std::cout << it->first << std::endl;
	std::cout << ite->first << std::endl;

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