/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_bidirectional_it.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:48:52 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 14:28:12 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int		tester_bidirectional_it()
{
	std_map			test;
	
	ut::fillMap<std_map, ft_pair>(test, 10, RANDOMIZED_QUEUE);

	std_map::iterator	it = test.begin();
	std_map::iterator	ite = test.end();
	
	std::cout << "increment" << std::endl;
	while (it != ite)
	{
		std::cout << it->first << std::endl;
		it++;
	}
	// std::cout << "it = " << it->first << std::endl;
	// it++;  // segfault like the original
	std::cout << "decrement" << std::endl;
	while (--it != test.begin())
		std::cout << it->first << std::endl;
	it--;  // original segfault but mine doesnt at this stage but segfault if one more it--;
	std_map::reverse_iterator	revit = test.rbegin();
	std_map::reverse_iterator	revite = test.rend();

	std::cout << "reverse increment" << std::endl;
	while (revit != revite)
	{
		std::cout << revit->first << std::endl;
		revit++;
	}
	std::cout << "reverse decrement" << std::endl;
	while (--revit != test.rbegin())
		std::cout << revit->first << std::endl;
	
	// std_map::const_iterator constit = test.begin();
	// std_map::const_reverse_iterator revconstit = test.rbegin();
	// (void)constit;
	// (void)revconstit;

	return (SUCCESS);
}