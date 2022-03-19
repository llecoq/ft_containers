/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/19 14:04:21 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_map_ft()
{
	ft::map<char, TestClass>			test;

	test.insert(ft::pair<char, TestClass>('a', 1));
	ft::map<char, TestClass>::iterator	it = test.begin();

	// (void)it;
	std::cout << it->second << std::endl;
	// ft::map<char, int>::iterator::

	// int	i = 0;

	// for (char c = 'a'; c < 'z'; c++)

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