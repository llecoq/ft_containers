/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_reverse_iterator.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:19:12 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/08 18:37:59 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_reverse_iterator(void)
{
	std::vector<TestClass>					myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	ft::vector<TestClass>::reverse_iterator	rev_it = myvector.rbegin();
	ft::displayVec(myvector);
	// ft::vector<TestClass>::reverse_iterator	rev_it (myvector.rbegin());
	ft::vector<TestClass>::reverse_iterator	rev_ite (myvector.rend());
	ft::vector<TestClass>::reverse_iterator	copy;
	copy = rev_it;
	std::cout << "*rev_it = " << *rev_it << std::endl;
	std::cout << "*copy = " << *copy << std::endl;
	std::cout << "*rev_ite = " << *rev_ite << std::endl;
	while (rev_it != rev_ite)
		std::cout << "base = " << *rev_it.base() << " *rev_it = " << *rev_it++ << std::endl;
	rev_ite = myvector.rend();
	std::cout << *(rev_ite + 2) << std::endl;
	std::cout << *(rev_it - 3) << std::endl;
}