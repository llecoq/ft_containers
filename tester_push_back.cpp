/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_push_back.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:49:23 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/02 16:31:11 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.hpp"
#include "utils/tester.hpp"

void	tester_push_back(void)
{
	ft::vector<TestClass>	ft;

	ft.push_back(TestClass());
	dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	
	ft.push_back(TestClass());
	dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	
	// ft.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	
	// ft.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	
	// ft.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	
	// ft.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	
	ft::vector<TestClass>::iterator	it = ft.begin();
	ft::vector<TestClass>::iterator	ite = ft.end();
	while (it != ite)
	{
		dprintf(2, "%d ", it->getNumber());
		it++;
	}
	dprintf(2, "\n");
	// ft::vector<int>	vec;
	// for (int i = 0; i < 10; i++)
	// 	vec.push_back(i);
	// ft::vector<int>::iterator	it = vec.begin();
	// for (; it != vec.end(); it++)
	// {
	// 	dprintf(2, "%d ", *it);
	// }
	
	// ft.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
	// std.push_back(TestClass());
	// dprintf(2, "%zu\n", std.capacity());
}