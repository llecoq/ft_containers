/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:19:02 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 13:05:35 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_insert(void)
{
	// ft::vector<TestClass>				vec(10, 500);
	// ft::vector<TestClass>::iterator	vec_it = vec.begin();
	// // ft::vector<TestClass>::iterator	vec_ite = vec.end();
	
	// ft::vector<TestClass>	vec_2;
	// // ft::vector<TestClass>::iterator	vec_2_it = vec_2.begin();

	// vec.insert(vec_it, 5, 10);
	// ft::displayData(vec);
	// ft::displayVec(vec);
	// vec_2.insert(vec_2_it, vec_it, vec_ite);

	ft::vector<TestClass> myvector (3, TestClass(100));
	ft::vector<TestClass>::iterator it;

	ft::displayData(myvector);
	std::cout << "resize 6" << std::endl;
	myvector.resize(6, TestClass());
	ft::displayData(myvector);
	ft::displayVec(myvector);

	it = myvector.begin();
	std::cout << "insert ( it + 1 , 200 )" << std::endl;
	it = myvector.insert ( it + 1 , 200 );

	std::cout << "insert ( it + 1 , 200 )" << std::endl;
	it = myvector.insert ( it + 1 , 200 );

	ft::displayData(myvector);
	ft::displayVec(myvector);

	std::cout << "insert ( it,5,300 )" << std::endl;
	myvector.insert (it,5,300);
	myvector.insert (myvector.begin() + 5,1,50);
	myvector.insert (myvector.begin() + 12,20,1);

	ft::displayData(myvector);
	ft::displayVec(myvector);

	// // "it" no longer valid, get a new one:
	// it = myvector.begin();

	// std::vector<TestClass> anothervector (2, TestClass(400));
	// 	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, myarray+3);

	// std::cout << "myvector contains:\n";
	// for (it=myvector.begin(); it<myvector.end(); it++)
	// 	std::cout <<  it->getI() << "(copy " << it->getNumber() << ")" << ' ';
	// std::cout << '\n';
}