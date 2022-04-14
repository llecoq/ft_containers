/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:15:20 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/14 15:58:38 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	test()
{
	ft_map	map;

	ut::fillMap<ft_map, ft_pair>(map, 50, QUEUE); // 7 diff
	map.print_tree();
	std::cout << std::endl;

	return 0;
}