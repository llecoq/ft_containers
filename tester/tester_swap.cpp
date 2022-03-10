/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_swap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:58:38 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/10 15:11:28 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_swap(void)
{
	ft::vector<TestClass>	vec;
	
	ft::vector<TestClass>	vec_2(5, 100);

	ft::pushBackVec(vec);
	ft::displayData(vec, "vec");
	ft::displayVec(vec);

	ft::displayData(vec_2, "vec_2");
	ft::displayVec(vec_2);

	std::cout << "SWAP MEMBER" << std::endl;
	vec_2.swap(vec);

	ft::displayData(vec, "vec");
	ft::displayVec(vec);

	ft::displayData(vec_2, "vec_2");
	ft::displayVec(vec_2);

	std::cout << "SWAP NON MEMBER" << std::endl;
	swap(vec, vec_2);
	ft::displayData(vec, "vec");
	ft::displayVec(vec);

	ft::displayData(vec_2, "vec_2");
	ft::displayVec(vec_2);
}