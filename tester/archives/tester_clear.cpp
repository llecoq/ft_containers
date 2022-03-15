/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_clear.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:35:21 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 14:37:38 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_clear(void)
{
	ft::vector<TestClass> myvector;
	myvector.clear();
	ft::displayData(myvector);
	
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	
	ft::displayVec(myvector);

	ft::displayData(myvector);
	std::cout << "clear :" << std::endl;
	myvector.clear();
	ft::displayData(myvector);
	ft::displayVec(myvector);


	std::cout << "resize" << std::endl;
	myvector.resize(12, TestClass(1));
	ft::displayData(myvector);
	std::cout << "clear :" << std::endl;
	myvector.clear();
	ft::displayData(myvector);

	myvector.push_back (1101);
	myvector.push_back (2202);
	
	ft::displayVec(myvector);
}