/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:15:20 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/15 19:02:25 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	test()
{
	// ft_map	map;
	ft_test_map				copy;
	ft_test_map::iterator	it2;
	ft_test_map::iterator	it3;
	ft_test_map::iterator	it4;
	ft_test_map::iterator	it5;
	ft_test_map::iterator	it11;
	// ut::fillMap<ft_test_map, ft_test_pair>(map, 10, RANDOM);
	// map.print_tree();
	ut::fillMap<ft_test_map, ft_test_pair>(copy, 5, RANDOMIZED_QUEUE);
	it2 = copy.find(2);
	it3 = copy.find(3);
	it4 = copy.find(4);
	it5 = copy.find(5);
	it4 = copy.find(4);
	it11 = copy.find(11);
	copy.print_tree();
	std::cout << "erase" << std::endl;
	copy.erase(4);
	// std::cout << "it2 = " << it2->first << std::endl;
	// std::cout << "it3 = " << it3->first << std::endl;
	// std::cout << "it4 = " << it4->first << std::endl;
	// std::cout << "it5 = " << it5->first << std::endl;
	// std::cout << "it11 = " << it11->first << std::endl;
	// copy.erase(1);
	// copy.print_tree();
	// map = copy;
	// map.print_tree();

	return 0;
}