/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_copy_constructor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:56:21 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 14:44:07 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_copy_constructor()
{
	{	/* COPY CONSTRUCTOR */
		ft::vector<TestClass>		vec;
	
		ft::pushBackVec(vec, 5);
		ft::displayData(vec);
		ft::displayVec(vec);

		ft::vector<TestClass>		copy(vec);
		ft::displayData(copy, "copy");
		ft::displayVec(copy);

		// /* RANGE */
		ft::vector<TestClass>	range(vec.begin() + 1, vec.end());
		ft::displayData(range, "range");
		ft::displayVec(range);
	}
	{	/* OPERATOR= */
		ft::vector<TestClass>		vec;
		ft::vector<TestClass>		copy;
	
		ft::pushBackVec(vec, 5);
		for (int i = 10; i > 0; i--)
			copy.push_back(TestClass(i));
		ft::displayData(vec);
		ft::displayVec(vec);
		ft::displayData(copy, "copy");
		ft::displayVec(copy);

		copy = vec;
		ft::displayData(copy, "copy");
		ft::displayVec(copy);
	}	
}