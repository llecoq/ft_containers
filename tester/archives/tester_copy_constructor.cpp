/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_copy_constructor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:56:21 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 14:23:02 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_copy_constructor()
{
	{	/* COPY CONSTRUCTOR */
		ft::vector<TestClass>		vec;
	
		ut::pushBackVec(vec, 5);
		ut::displayData(vec);
		ut::displayVec(vec);

		ft::vector<TestClass>		copy(vec);
		ut::displayData(copy, "copy");
		ut::displayVec(copy);

		// /* RANGE */
		ft::vector<TestClass>	range(vec.begin() + 1, vec.end());
		ut::displayData(range, "range");
		ut::displayVec(range);
	}
	{	/* OPERATOR= */
		ft::vector<TestClass>		vec;
		ft::vector<TestClass>		copy;
	
		ut::pushBackVec(vec, 5);
		for (int i = 10; i > 0; i--)
			copy.push_back(TestClass(i));
		ut::displayData(vec);
		ut::displayVec(vec);
		ut::displayData(copy, "copy");
		ut::displayVec(copy);

		copy = vec;
		ut::displayData(copy, "copy");
		ut::displayVec(copy);
	}	
}