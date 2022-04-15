/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:15:20 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/15 12:03:34 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	test()
{
	ft_map	map;
	ft_map	copy;

	// ut::fillMap<ft_map, ft_pair>(map, 10, RANDOM);
	// map.print_tree();
	// ut::fillMap<ft_map, ft_pair>(copy, 5, RANDOM);
	copy.insert(ft_pair(4, 4));
	copy.insert(ft_pair(5, 5));
	copy.insert(ft_pair(2, 2));
	copy.insert(ft_pair(3, 3));
	copy.insert(ft_pair(1, 1));
	copy.print_tree();

	map = copy;
	map.print_tree();

	return 0;
}