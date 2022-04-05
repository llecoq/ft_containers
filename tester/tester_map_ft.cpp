/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/05 12:28:51 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_map_ft()
{
	// ft::vector<int>	vec;

	// ut::pushBackVec(vec, 10);

	// ft::vector<int>::iterator			it = vec.begin();
	// ft::vector<int>::const_iterator		constit = vec.begin();

	
	// constit++;




	ft::map<char,int> mymap;
	char	c;
	
	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;
	
	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c) > 0)
			std::cout << " is an element of mymap." << std::endl;
		else 
			std::cout << " is not an element of mymap." << std::endl;
	}

	
	return (SUCCESS);
}