/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_copy_constructor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:56:21 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/04 11:13:53 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_copy_constructor()
{
	ft::vector<TestClass>		vec;

	for (int i = 0; i < 5; i++)
		vec.push_back(TestClass());
	for (ft::vector<TestClass>::iterator it = vec.begin(); it != vec.end(); it++)
		dprintf(2, "%d ", it->getNumber());
	dprintf(2, "\n");
	dprintf(2, "vec capacity = %zu   zize = %zu\n", vec.capacity(), vec.size());
	
	ft::vector<TestClass>		copy(vec);
	for (ft::vector<TestClass>::iterator it = copy.begin(); it != copy.end(); it++)
		dprintf(2, "%d ", it->getNumber());
	dprintf(2, "\n");
	dprintf(2, "copy capacity = %zu   zize = %zu\n", copy.capacity(), copy.size());

}