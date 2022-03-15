/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:19:02 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 13:48:55 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_insert(void)
{
	std::vector<TestClass> myvector (3, TestClass(100));
	std::vector<TestClass>::iterator it;

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
	std::cout << "(myvector.begin() + 5,1,50)" << std::endl;
	myvector.insert (myvector.begin() + 5,1,50);

	ft::displayData(myvector);
	ft::displayVec(myvector);

	std::cout << "insert (myvector.begin() + 12,20,1)" << std::endl;
	myvector.insert (myvector.begin() + 12,20,1);

	ft::displayData(myvector);
	ft::displayVec(myvector);

	it = myvector.begin();
	std::vector<TestClass> anothervector (2, TestClass(400));
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

	ft::displayData(myvector);
	ft::displayVec(myvector);

	int myarray [] = { 501,502,503,504,505,506,507,508 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	ft::displayData(myvector);
	ft::displayVec(myvector);
}