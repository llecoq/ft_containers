/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:19:02 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/10 16:38:36 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_insert(void)
{
	std::vector<TestClass>				vec(10, 500);
	std::vector<TestClass>::iterator	vec_it = vec.begin();
	// std::vector<TestClass>::iterator	vec_ite = vec.end();
	
	std::vector<TestClass>	vec_2;
	// std::vector<TestClass>::iterator	vec_2_it = vec_2.begin();

	vec.insert(vec_it, 5, 10);
	ft::displayData(vec);
	ft::displayVec(vec);
	// vec_2.insert(vec_2_it, vec_it, vec_ite);

}
	// std::vector<TestClass> myvector (3, TestClass(100));
	// std::vector<TestClass>::iterator it;

	// std::cout << "capacity = " << myvector.capacity() << " size = " << myvector.size() << std::endl;
	// std::cout << "resize" << std::endl;
	// myvector.resize(6, TestClass());
	// std::cout << "capacity = " << myvector.capacity() << " size = " << myvector.size() << std::endl;
	// std::cout << "myvector contains:\n";
	// for (it=myvector.begin(); it != myvector.end(); it++)
	// 	std::cout << it->getI() << "(copy " << it->getNumber() << ")" << ' ';
	// std::cout << '\n';

	// it = myvector.begin();
	// it = myvector.insert ( it + 1 , 200 );

	// std::cout << "myvector contains:\n";
	// // for (it=myvector.begin(); it<myvector.end(); it++) NE MARCHE PAS ITERATOR OVERLOAD A REVOIR
	// for (it=myvector.begin(); it != myvector.end(); it++)
	// 	std::cout << it->getI() << "(copy " << it->getNumber() << ")" << ' ';
	// std::cout << '\n';

	// myvector.insert (it - 3,2,300);

	// std::cout << "myvector contains:\n";
	// for (it=myvector.begin(); it<myvector.end(); it++)
	// 	std::cout <<  it->getI() << "(copy " << it->getNumber() << ")" << ' ';
	// std::cout << '\n';

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