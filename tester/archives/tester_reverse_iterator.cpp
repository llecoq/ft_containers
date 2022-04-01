/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_reverse_iterator.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:19:12 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 14:23:02 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_reverse_iterator(void)
{
	ft::vector<TestClass>					myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	ut::displayVec(myvector);

	ft::vector<TestClass>::reverse_iterator	rev_it = myvector.rbegin();
	ft::vector<TestClass>::reverse_iterator	rev_ite (myvector.rend());
	ft::vector<TestClass>::reverse_iterator	copy;
	copy = rev_it;
	std::cout << "*rev_it = " << *rev_it;
	std::cout << "*copy = " << *copy;
	std::cout << "*rev_ite - 1 = " << *(rev_ite - 1);
	while (++rev_it != rev_ite)
		std::cout << "base = " << *rev_it.base() << "*rev_it = " << *rev_it;
	rev_ite = myvector.rend();
	std::cout << *(rev_ite - 2);
	rev_it = myvector.rbegin();
	std::cout << *(rev_it + 3);
	std::cout << (rev_it + 3)->getI() << std::endl;
	std::cout << rev_it[2];
	std::cout << "myvector has " << myvector.rend() - myvector.rbegin() << " elements." << std::endl;
	rev_it = 3 + myvector.rbegin();
	std::cout << "The fourth element from the end is: " << *rev_it;
	std::cout << (myvector.rbegin() == myvector.rend()) << std::endl;
	std::cout << (myvector.rbegin() == myvector.rbegin()) << std::endl;
	std::cout << (myvector.rbegin() != myvector.rend()) << std::endl;
	std::cout << (myvector.rbegin() != myvector.rbegin()) << std::endl;
	std::cout << (myvector.rbegin() < myvector.rend()) << std::endl;
	std::cout << (myvector.rend() < myvector.rbegin()) << std::endl;
	std::cout << (myvector.rend() > myvector.rbegin()) << std::endl;
	std::cout << (myvector.rbegin() > myvector.rend()) << std::endl;
	std::cout << (myvector.rbegin() >= myvector.rend()) << std::endl;
	std::cout << (myvector.rbegin() >= myvector.rbegin()) << std::endl;
	std::cout << (myvector.rbegin() <= myvector.rend()) << std::endl;
	std::cout << (myvector.rbegin() <= myvector.rbegin()) << std::endl;
}