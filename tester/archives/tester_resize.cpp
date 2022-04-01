/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_resize.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:42:26 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 14:23:02 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_resize()
{
	ft::vector<TestClass>		vec;

	for (int i = 0; i < 3; i++)
		vec.push_back(TestClass());
	vec.reserve(4);
	ut::displayVec(vec);
	ut::displayData(vec);
	vec.resize(15, TestClass());
	ut::displayData(vec);
	ut::displayVec(vec);
	vec.resize(2, TestClass());
	ut::displayData(vec);
	ut::displayVec(vec);
	vec.resize(20, 1);
	ut::displayData(vec);
	ut::displayVec(vec);
}