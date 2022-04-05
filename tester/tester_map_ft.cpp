/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/05 14:39:08 by llecoq           ###   ########.fr       */
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
	{
		std::cout << "lower and upper bounds" << std::endl;

		ft::map<int,int> mymap;
		ft::map<int,int>::iterator itlow,itup;

		mymap[1]=20;
		mymap[2]=40;
		mymap[3]=60;
		mymap[4]=80;
		mymap[5]=100;
		
		ut::fillMap<ft::map<int, int>, ft::pair<int, int> >(mymap, 10, RANDOMIZED_QUEUE);

		itlow=mymap.lower_bound (2);  // itlow points to b
		itup=mymap.upper_bound (4);   // itup points to e (not d!)
		std::cout << itup->first << std::endl;

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (ft::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

		
		// mymap.print_tree();
		itlow = mymap.lower_bound(0);
		std::cout << itlow->first << std::endl;
		itup = mymap.upper_bound(13);
		if (itup == mymap.end())
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
		std::cout << mymap.upper_bound(5)->first << std::endl;
		std::cout << mymap.lower_bound(5)->first << std::endl;
		std::cout << mymap.upper_bound(3)->first << std::endl;
		std::cout << mymap.lower_bound(3)->first << std::endl;
		std::cout << mymap.upper_bound(2)->first << std::endl;
		std::cout << mymap.lower_bound(2)->first << std::endl;
	}

	{
		std::cout << "equal range" << std::endl;
	
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << std::endl;;

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << std::endl;;
	}


	// ft::map<char,int> mymap;

	// char	c;
	
	// mymap ['a']=101;
	// mymap ['c']=202;
	// mymap ['f']=303;
	
	// for (c = 'a'; c < 'h'; c++)
	// {
	// 	std::cout << c;
	// 	if (mymap.count(c) > 0)
	// 		std::cout << " is an element of mymap." << std::endl;
	// 	else 
	// 		std::cout << " is not an element of mymap." << std::endl;
	// }

	
	return (SUCCESS);
}