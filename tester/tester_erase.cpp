/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_erase.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:02:50 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/05 13:49:50 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_erase(void)
{
	ft::vector<TestClass> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(TestClass(i));

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i].getI() << "(copy " << myvector[i].getNumber() << ")";

	// erase the 6th element
	std::cout << std::endl << "erase 6th element" << std::endl;
	myvector.erase (myvector.begin()+5);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i].getI() << "(copy " << myvector[i].getNumber() << ")";

	// erase the first 3 elements:
	// std::cout << std::endl << "erase 3 first elements" << std::endl;
	// myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "\nmyvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i].getI() << "(copy" << myvector[i].getNumber() << ")";
	std::cout << std::endl;
}