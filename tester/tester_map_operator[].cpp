/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_operator[].cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:09:33 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/24 13:10:08 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_operator[]()
{
	std_map			test;
	
	ft::fillMap<std_map, std_pair>(test, 10, RANDOMIZED_QUEUE);

	std::cout << "size = " << test.size() << std::endl;
	int		&a = test[1];
	a = 2; 
	std::cout << test[1] << std::endl;
	std::cout << "size = " << test.size() << std::endl;
	int		&b = test[15];
	std::cout << test[15] << std::endl;
	b = 6;
	std::cout << test[15] << std::endl;
	std::cout << "size = " << test.size() << std::endl;

	return (SUCCESS);
}