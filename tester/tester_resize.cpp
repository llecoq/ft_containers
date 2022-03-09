/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_resize.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:42:26 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/09 14:07:39 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_resize()
{
	ft::vector<TestClass>		vec;

	// for (int i = 0; i < 3; i++)
	// 	vec.push_back(TestClass());
	vec.reserve(4);
	// ft::displayVec(vec);
	ft::displayData(vec);
	vec.resize(15);
	ft::displayData(vec);
	ft::displayVec(vec);
	vec.resize(2, TestClass());
}