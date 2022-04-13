/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:15:20 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/13 19:10:57 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	test()
{
	ft_map	map;

	ut::fillMap<ft_map, ft_pair>(map, 10, QUEUE);
	map.print_tree();

	return 0;
}