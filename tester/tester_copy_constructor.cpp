/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_copy_constructor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:56:21 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/11 16:07:43 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_copy_constructor()
{
	{	/* COPY CONSTRUCTOR */
		ft::vector<TestClass>		vec;
	
		for (int i = 0; i < 5; i++)
			vec.push_back(TestClass(i));
		for (ft::vector<TestClass>::iterator it = vec.begin(); it != vec.end(); it++)
			dprintf(2, "%d ", it->getNumber());
		dprintf(2, "\n");
		for (ft::vector<TestClass>::iterator it = vec.begin(); it != vec.end(); it++)
			dprintf(2, "%d ", it->getI());
		dprintf(2, "\n");
		dprintf(2, "vec capacity = %zu   zize = %zu\n", vec.capacity(), vec.size());
		
		ft::vector<TestClass>		copy(vec);
		for (ft::vector<TestClass>::iterator it = copy.begin(); it != copy.end(); it++)
			dprintf(2, "%d ", it->getNumber());
		dprintf(2, "\n");
		for (ft::vector<TestClass>::iterator it = copy.begin(); it != copy.end(); it++)
			dprintf(2, "%d ", it->getI());
		dprintf(2, "\n");
		dprintf(2, "copy capacity = %zu   zize = %zu\n", copy.capacity(), copy.size());

		// /* RANGE */
		// ft::vector<TestClass>	range(vec.begin() + 1, vec.end());
		// for (ft::vector<TestClass>::iterator it = range.begin(); it != range.end(); it++)
		// 	dprintf(2, "%d ", it->getNumber());
		// dprintf(2, "\n");
		// for (ft::vector<TestClass>::iterator it = range.begin(); it != range.end(); it++)
		// 	dprintf(2, "%d ", it->getI());
		// dprintf(2, "\n");
		// dprintf(2, "range capacity = %zu   zize = %zu\n", range.capacity(), range.size());
	}
	{	/* OPERATOR= */
		// std::vector<TestClass>		vec;
		// std::vector<TestClass>		copy;
	
		// for (int i = 0; i < 5; i++)
		// 	vec.push_back(TestClass(i));
		// for (int i = 10; i > 0; i--)
		// 	copy.push_back(TestClass(i));
		// dprintf(2, "vec :\tsize = %zu\tcapacity = %zu\n", vec.size(), vec.capacity());
		// for (std::vector<TestClass>::iterator it = vec.begin(); it != vec.end(); it++)
		// 	dprintf(2, "%d ", it->getNumber());
		// dprintf(2, "\n");
		// for (std::vector<TestClass>::iterator it = vec.begin(); it != vec.end(); it++)
		// 	dprintf(2, "%d ", it->getI());
		// dprintf(2, "\ncopy :\tsize = %zu\tcapacity = %zu\n", copy.size(), copy.capacity());
		// for (std::vector<TestClass>::iterator it = copy.begin(); it != copy.end(); it++)
		// 	dprintf(2, "%d ", it->getNumber());
		// dprintf(2, "\n");
		// for (std::vector<TestClass>::iterator it = copy.begin(); it != copy.end(); it++)
		// 	dprintf(2, "%d ", it->getI());
		// dprintf(2, "\n");
		// copy = vec;
		// dprintf(2, "\ncopy :\tsize = %zu\tcapacity = %zu\n", copy.size(), copy.capacity());
		// for (std::vector<TestClass>::iterator it = copy.begin(); it != copy.end(); it++)
		// 	dprintf(2, "%d ", it->getNumber());
		// dprintf(2, "\n");
		// for (std::vector<TestClass>::iterator it = copy.begin(); it != copy.end(); it++)
		// 	dprintf(2, "%d ", it->getI());
		// dprintf(2, "\n");

	}

}