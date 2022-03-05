/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:19:02 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/05 10:39:22 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_insert(void)
{
	std::vector<TestClass> myvector (3, TestClass(100));
	std::vector<TestClass>::iterator it;

	std::cout << "myvector contains:\n";
	for (it=myvector.begin(); it != myvector.end(); it++)
		std::cout << it->getI() << "(copy" << it->getNumber() << ")" << ' ';
	std::cout << '\n';

	it = myvector.begin();
	it = myvector.insert ( it + 1 , 200 );

	std::cout << "myvector contains:\n";
	// for (it=myvector.begin(); it<myvector.end(); it++) NE MARCHE PAS ITERATOR OVERLOAD A REVOIR
	for (it=myvector.begin(); it != myvector.end(); it++)
		std::cout << it->getI() << "(copy" << it->getNumber() << ")" << ' ';
	std::cout << '\n';

	// myvector.insert (it,2,300);

	// std::cout << "myvector contains:\n";
	// for (it=myvector.begin(); it<myvector.end(); it++)
	// 	std::cout <<  it->getI() << "(copy" << it->getNumber() << ")" << ' ';
	// std::cout << '\n';

	// // "it" no longer valid, get a new one:
	// it = myvector.begin();

	// std::vector<TestClass> anothervector (2, TestClass(400));
	// 	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, myarray+3);

	// std::cout << "myvector contains:\n";
	// for (it=myvector.begin(); it<myvector.end(); it++)
	// 	std::cout <<  it->getI() << "(copy" << it->getNumber() << ")" << ' ';
	// std::cout << '\n';

}