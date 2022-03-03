/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_push_back.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:49:23 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/03 12:55:33 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector.hpp"
#include "../utils/tester.hpp"

void	tester_push_back(void)
{
	/* -------------------------------- FT -----------------------------------*/
	{
	ft::vector<TestClass>	ft;
	ft::vector<TestClass>::iterator	it = ft.begin();
	ft::vector<TestClass>::iterator	ite = ft.end();

	ft.push_back(TestClass());
	dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(2, "%d ", it->getNumber());
		it++;
	}
	dprintf(2, "\n");	
	ft.push_back(TestClass());
	dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(2, "%d ", it->getNumber());
		it++;
	}
	dprintf(2, "\n");	
	ft.push_back(TestClass());
	dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(2, "%d ", it->getNumber());
		it++;
	}
	dprintf(2, "\n");	
	ft.push_back(TestClass());
	dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(2, "%d ", it->getNumber());
		it++;
	}
	dprintf(2, "\n");
	ft.push_back(TestClass());
	dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(2, "%d ", it->getNumber());
		it++;
	}
	dprintf(2, "\n");	
	ft.push_back(TestClass());
	dprintf(2, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(2, "%d ", it->getNumber());
		it++;
	}
	dprintf(2, "\n");
	}
	// /* --------------------------------- STD ---------------------------------*/
	// {
	// std::vector<TestClass>	std;
	// std::vector<TestClass>::iterator	it = std.begin();
	// std::vector<TestClass>::iterator	ite = std.end();

	// std.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", std.capacity());
	// it = std.begin();
	// ite = std.end();
	// while (it != ite)
	// {
	// 	dprintf(2, "%d ", it->getNumber());
	// 	it++;
	// }
	// dprintf(2, "\n");	
	// std.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", std.capacity());
	// it = std.begin();
	// ite = std.end();
	// while (it != ite)
	// {
	// 	dprintf(2, "%d ", it->getNumber());
	// 	it++;
	// }
	// dprintf(2, "\n");	
	// std.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", std.capacity());
	// it = std.begin();
	// ite = std.end();
	// while (it != ite)
	// {
	// 	dprintf(2, "%d ", it->getNumber());
	// 	it++;
	// }
	// dprintf(2, "\n");	
	// std.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", std.capacity());
	// it = std.begin();
	// ite = std.end();
	// while (it != ite)
	// {
	// 	dprintf(2, "%d ", it->getNumber());
	// 	it++;
	// }
	// dprintf(2, "\n");
	// std.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", std.capacity());
	// it = std.begin();
	// ite = std.end();
	// while (it != ite)
	// {
	// 	dprintf(2, "%d ", it->getNumber());
	// 	it++;
	// }
	// dprintf(2, "\n");	
	// std.push_back(TestClass());
	// dprintf(2, "%zu -----------------------------------\n", std.capacity());
	// it = std.begin();
	// ite = std.end();
	// while (it != ite)
	// {
	// 	dprintf(2, "%d ", it->getNumber());
	// 	it++;
	// }
	// dprintf(2, "\n");
	// }

}