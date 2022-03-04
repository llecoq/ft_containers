/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_reserve.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:10:28 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/04 12:50:19 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_reserve(void)
{
	ft::vector<TestClass>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
	if (sz!=foo.capacity()) {
		sz = foo.capacity();
	std::cout << "capacity changed: " << sz << '\n';
	}
	}

	ft::vector<TestClass> bar;
	for (int i=0; i<3; ++i) {
		bar.push_back(TestClass(i));}
	sz = bar.capacity();
	dprintf(2, "RESERVE\n");
	bar.reserve(100);   // this is the only difference with foo above
	for (ft::vector<TestClass>::iterator it = bar.begin(); it != bar.end(); it++)
		dprintf(2, "%d ", it->getNumber());
	dprintf(2, "\n");
	for (ft::vector<TestClass>::iterator it = bar.begin(); it != bar.end(); it++)
		dprintf(2, "%d ", it->getI());
	dprintf(2, "\n");
	
	std::cout << "making bar grow:\n";
	for (int i=0; i<10; ++i) {
		bar.push_back(TestClass(i));
	if (sz!=bar.capacity()) {
		sz = bar.capacity();
	std::cout << "capacity changed: " << sz << '\n';
	}
	}
}
