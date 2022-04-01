/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_clear.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:35:21 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 14:23:02 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_clear(void)
{
	ft::vector<TestClass> myvector;
	myvector.clear();
	ut::displayData(myvector);
	
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	
	ut::displayVec(myvector);

	ut::displayData(myvector);
	std::cout << "clear :" << std::endl;
	myvector.clear();
	ut::displayData(myvector);
	ut::displayVec(myvector);


	std::cout << "resize" << std::endl;
	myvector.resize(12, TestClass(1));
	ut::displayData(myvector);
	std::cout << "clear :" << std::endl;
	myvector.clear();
	ut::displayData(myvector);

	myvector.push_back (1101);
	myvector.push_back (2202);
	
	ut::displayVec(myvector);
}