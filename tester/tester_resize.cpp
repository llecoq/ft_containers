/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_resize.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:42:26 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/07 14:37:34 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_resize()
{
	std::vector<TestClass>		vec;

	// for (int i = 0; i < 3; i++)
	// 	vec.push_back(TestClass());
	vec.reserve(4);
	for (std::vector<TestClass>::iterator it = vec.begin(); it != vec.end(); it++)
		dprintf(2, "%d ", it->getNumber());

	dprintf(2, "\n");
	dprintf(2, "capacity = %zu\n", vec.capacity());
	vec.resize(15);
	dprintf(2, "capacity = %zu    size = %zu\n", vec.capacity(), vec.size());
	for (std::vector<TestClass>::iterator it = vec.begin(); it != vec.end(); it++)
		dprintf(2, "%d ", it->getNumber());
	dprintf(2, "\n");
	vec.resize(2, TestClass());
}