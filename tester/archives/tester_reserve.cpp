/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_reserve.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:10:28 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 14:23:02 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_reserve(void)
{
	ft::vector<int> foo;
	std::cout << "making foo grow:\n";
	ut::pushBackVec(foo, 100);
	ut::displayDataVec(foo, "foo");

	std::vector<TestClass> bar;
	ut::pushBackVec(bar, 3);
	ut::displayDataVec(bar, "bar");
	
	std::cout << "reserve 100" << std::endl;
	bar.reserve(100);   // this is the only difference with foo above
	ut::displayDataVec(bar, "bar");

	std::cout << "making bar grow:\n";
	ut::pushBackVec(bar);
	ut::displayDataVec(bar, "bar");

	foo.reserve(1);
	bar.reserve(1);
	ut::displayDataVec(bar, "bar");
	foo.reserve(103);
	ut::displayDataVec(foo, "foo");
}
