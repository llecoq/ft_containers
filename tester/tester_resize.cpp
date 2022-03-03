/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_resize.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:42:26 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/03 18:00:26 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_resize()
{
	ft::vector<TestClass>		vec;

	for (int i = 0; i < 4; i++)
		vec.push_back(TestClass());
	for (ft::vector<TestClass>::iterator it = vec.begin(); it != vec.end(); it++)
		dprintf(2, "%d ", it->getNumber());
	dprintf(2, "\n");
	vec.resize(20, TestClass());
	dprintf(2, "capacity = %zu\n", vec.capacity());
	for (ft::vector<TestClass>::iterator it = vec.begin(); it != vec.end(); it++)
		dprintf(2, "%d ", it->getNumber());
	dprintf(2, "\n");
	vec.resize(2, TestClass());
}