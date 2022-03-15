/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_push_back.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:49:23 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 14:55:59 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_push_back(void)
{
	/* -------------------------------- FT -----------------------------------*/
	{
	ft::vector<TestClass>	ft;
	ft::vector<TestClass>::iterator	it = ft.begin();
	ft::vector<TestClass>::iterator	ite = ft.end();

	ft.push_back(TestClass());
	dprintf(1, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(1, "%d ", it->getNumber());
		it++;
	}
	dprintf(1, "\n");	
	ft.push_back(TestClass());
	dprintf(1, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(1, "%d ", it->getNumber());
		it++;
	}
	dprintf(1, "\n");	
	ft.push_back(TestClass());
	dprintf(1, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(1, "%d ", it->getNumber());
		it++;
	}
	dprintf(1, "\n");	
	ft.push_back(TestClass());
	dprintf(1, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(1, "%d ", it->getNumber());
		it++;
	}
	dprintf(1, "\n");
	ft.push_back(TestClass());
	dprintf(1, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(1, "%d ", it->getNumber());
		it++;
	}
	dprintf(1, "\n");	
	ft.push_back(TestClass());
	dprintf(1, "%zu -----------------------------------\n", ft.capacity());
	it = ft.begin();
	ite = ft.end();
	while (it != ite)
	{
		dprintf(1, "%d ", it->getNumber());
		it++;
	}
	dprintf(1, "\n");
	}
}