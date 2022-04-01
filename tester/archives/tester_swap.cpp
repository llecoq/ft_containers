/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_swap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:58:38 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 14:23:02 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_swap(void)
{
	ft::vector<TestClass>	vec;
	
	ft::vector<TestClass>	vec_2(5, 100);

	ut::pushBackVec(vec);
	ut::displayData(vec, "vec");
	ut::displayVec(vec);

	ut::displayData(vec_2, "vec_2");
	ut::displayVec(vec_2);

	std::cout << "SWAP MEMBER" << std::endl;
	vec_2.swap(vec);

	ut::displayData(vec, "vec");
	ut::displayVec(vec);

	ut::displayData(vec_2, "vec_2");
	ut::displayVec(vec_2);

	std::cout << "SWAP NON MEMBER" << std::endl;
	swap(vec, vec_2);
	ut::displayData(vec, "vec");
	ut::displayVec(vec);

	ut::displayData(vec_2, "vec_2");
	ut::displayVec(vec_2);
}