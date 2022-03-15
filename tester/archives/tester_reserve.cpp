/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_reserve.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:10:28 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 16:46:20 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_reserve(void)
{
	ft::vector<int> foo;
	std::cout << "making foo grow:\n";
	ft::pushBackVec(foo, 100);
	ft::displayDataVec(foo, "foo");

	std::vector<TestClass> bar;
	ft::pushBackVec(bar, 3);
	ft::displayDataVec(bar, "bar");
	
	std::cout << "reserve 100" << std::endl;
	bar.reserve(100);   // this is the only difference with foo above
	ft::displayDataVec(bar, "bar");

	std::cout << "making bar grow:\n";
	ft::pushBackVec(bar);
	ft::displayDataVec(bar, "bar");

	foo.reserve(1);
	bar.reserve(1);
	ft::displayDataVec(bar, "bar");
	foo.reserve(103);
	ft::displayDataVec(foo, "foo");
}
