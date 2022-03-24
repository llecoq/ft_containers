/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/24 11:32:37 by llecoq           ###   ########.fr       */
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
	ft::fillMap<ft_map, ft_pair>(test, 10, RANDOMIZED_QUEUE);

	// ft::fillMap<std_map, std_pair>(test_std, 10, RANDOM);

	std::cout << std::endl;
	test.print_tree();
	ft_map::iterator	it = test.begin();
	ft_map::iterator	ite = test.end();
	
	std::cout << "increment" << std::endl;
	while (it != ite)
	{
		std::cout << it->first << std::endl;
		it++;
	}
	std::cout << "decrement" << std::endl;
	while (--it != test.begin())
		std::cout << it->first << std::endl;

	ft_map::reverse_iterator	revit = test.rbegin();
	ft_map::reverse_iterator	revite = test.rend();

	std::cout << "reverse increment" << std::endl;
	while (revit != revite)
	{
		std::cout << revit->first << std::endl;
		revit++;
	}
	std::cout << "reverse decrement" << std::endl;
	while (--revit != test.rbegin())
		std::cout << revit->first << std::endl;
	
	return (SUCCESS);
}