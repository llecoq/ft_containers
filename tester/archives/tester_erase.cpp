/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_erase.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:02:50 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 14:23:02 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_erase(void)
	{
		ft::vector<TestClass> myvector;

		// set some values (from 1 to 10)
		ut::pushBackVec(myvector);
		ut::displayDataVec(myvector);

		// erase the 6th element
		std::cout << std::endl << "erase 6th element" << std::endl;
		myvector.erase (myvector.begin()+5);
		ut::displayDataVec(myvector);

		// erase the first 3 elements:
		std::cout << "erase 3 first elements" << std::endl;
		myvector.erase (myvector.begin(),myvector.begin()+3);
		ut::displayDataVec(myvector);
	}