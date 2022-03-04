/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_element_access.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:01:18 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/04 13:50:48 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_element_access(void)
{
	{	// OPERATOR[]
		ft::vector<int> myvector (10);   // 10 zero-initialized elements

		ft::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	{	// AT
		ft::vector<int> myvector (10);   // 10 zero-initialized ints
		
		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;
		
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
		try
		{
			std::cout << myvector.at(15);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{	// FRONT
		ft::vector<int> myvector;
		
		// std::cout << myvector.back() << std::endl; // undefined when called on empty vector
		myvector.push_back(78);
		myvector.push_back(16);
		
		// now front equals 78, and back 16
		
		myvector.front() -= myvector.back();
		
		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}
	{	// BACK
		ft::vector<int> myvector;
		
		myvector.push_back(10);
		
		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}
		
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
}