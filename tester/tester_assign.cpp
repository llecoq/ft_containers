/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_assign.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:40:17 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/11 15:20:12 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_assign(void)
{
	ft::vector<TestClass> first;
	ft::vector<TestClass> second;
	ft::vector<TestClass> third;

	first.assign (7,100);             // 7 ints with a value of 100
	ft::displayData(first);
	ft::displayVec(first);

	first.assign (10,100);             // 7 ints with a value of 100
	ft::displayData(first);
	ft::displayVec(first);

	ft::vector<TestClass>::iterator it;
	it=first.begin()+1;

	// second.assign (it,first.end()-1); // the 5 central values of first
	// ft::displayData(second);
	// ft::displayVec(second);

	// int myints[] = {1776,7,4};
	// third.assign (myints,myints+3);   // assigning from array.
	// ft::displayData(third);
	// ft::displayVec(third);

	ft::displayVec(first);
	first.assign(1, 10);
	ft::displayData(first);
	ft::displayVec(first);
	// first.assign(second.begin(), second.end());
	ft::displayVec(first);
	first.assign(20, 10);
	first.assign(5, 10);


	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}