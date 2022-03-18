/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/17 17:03:36 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_map_ft()
{
	std::map<char, TestClass>			test;
	std::map<char, TestClass>::iterator	it;

	int	i = 0;

	for (char c = 'a'; c < 'z'; c++)
		test.insert(std::pair<char, TestClass>(c, i++));

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