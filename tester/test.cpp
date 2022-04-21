/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:15:20 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/21 21:03:18 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	test()
{
		{
					{
			std::cout << "-------------- INSERT / ERASE -------------" << std::endl;
			ft_test_map map;

			map.insert(ft_test_pair(1, 1));
			ut::fillMap<ft_test_map,ft_test_pair > (map, 20, RANDOM);
			ft_test_map mymap;
			
			// first insert function version (single parameter):
			mymap.insert ( ft_pair(6, 100) );
			mymap.insert ( ft_pair(26, 200) );
			
			ft::pair<ft_test_map::iterator,bool> ret;
			ret = mymap.insert ( ft_test_pair(26, 500) );
			if (ret.second==false)
			{
				std::cout << "element 26 already existed";
				std::cout << " with a value of " << ret.first->second << std::endl;
			}
			
			// // second insert function version (with hint position):
			ft_map::iterator it = mymap.end();
			std::cout << "size = " << mymap.size() << std::endl;
			mymap.insert (it, ft_test_pair(3, 300));  // max efficiency inserting
			std::cout << "size = " << mymap.size() << std::endl;
			it = mymap.insert (it, ft_test_pair(4, 400));
			std::cout << "it->second 4 = " << it->second << std::endl;
			it = mymap.insert (mymap.end(), ft_test_pair(27, 700));
			std::cout << "it->second 27 = " << it->second << std::endl;
			it = mymap.insert (mymap.begin(), ft_test_pair(2, 900));
			it = mymap.insert (mymap.end(), ft_test_pair(1, 30));
			it = mymap.insert (mymap.end(), ft_test_pair(90, 30));
			mymap.insert(it, ft_test_pair(90, 1));
			std::cout << "it->second 1 = " << it->second << std::endl;
			std::cout << "find 4 = " << mymap.find(4)->second << std::endl;
			std::cout << "find 3 = " << mymap.find(3)->second << std::endl;
			std::cout << "find 2 = " << mymap.find(2)->second << std::endl;
			std::cout << "find 27 = " << mymap.find(27)->second << std::endl;
			std::cout << "find 90 = " << mymap.find(90)->second << std::endl;
			mymap.insert(ft_test_pair(5, 5));
			std::cout << "size = " << mymap.size() << std::endl;
			ut::fillMap<ft_test_map, ft_test_pair>(mymap, 20, RANDOMIZED_QUEUE);
			it = mymap.find(1);
			mymap.erase(it);
			it = mymap.find(27);
			mymap.erase(it);
			it = mymap.find(11);
			mymap.erase(it);
			it = mymap.find(6);
			mymap.erase(it);

			std::cout << "size = " << mymap.size() << std::endl;
			std::cout << "erase" << std::endl;
			mymap.erase(90);
			std::cout << "erase" << std::endl;
			mymap.erase(mymap.begin(), mymap.end());
			it = mymap.begin();
			while (it != mymap.end())
			{
				std::cout << it->first << std::endl;
				it++;
			}
			std::cout << "size = " << mymap.size() << std::endl;
			std::cout << "erase" << std::endl;
			mymap.erase(mymap.begin(), mymap.end());
			std::cout << "size = " << mymap.size() << std::endl;
			std::cout << std::endl;
			// ft_test_map myset;

			// // myset.insert(1);
			// // myset.insert(2);
			// // myset.insert(3);
			// // myset.insert(4);
			// // myset.insert(5);
			
			// myset.insert(5);
			// myset.insert(4);
			// myset.insert(2);
			// myset.insert(3);
			// myset.insert(11);
			// myset.insert(6);
			// myset.insert(1);
			// myset.insert(7);
			// myset.insert(8);
			// myset.insert(10);
			// myset.insert(9);
			// myset.insert(12);


			// // myset.erase(itlow,itup);        // erases [itlow,itup)

			// // // print content:
			// // for (ft_set::iterator it=myset.begin(); it!=myset.end(); ++it)
			// // std::cout << *it << std::endl;
			// myset.insert(20);
			// myset.insert(17);
			// myset.insert(30);
			// myset.insert(29);
			// myset.erase(11);
			// myset.print_tree();
			
			// itlow = myset.lower_bound(0);
			// std::cout << *itlow << std::endl;
			// itup = myset.upper_bound(13);
			// if (itup == myset.end())
			// 	std::cout << "OK" << std::endl;
			// else
			// 	std::cout << "KO" << std::endl;
			// // myset.print_tree();
			// std::cout << *myset.upper_bound(5) << std::endl;
			// std::cout << *myset.lower_bound(5) << std::endl;
			// std::cout << *myset.upper_bound(3) << std::endl;
			// std::cout << *myset.lower_bound(3) << std::endl;
			// std::cout << *myset.upper_bound(2) << std::endl;
			// std::cout << *myset.lower_bound(2) << std::endl;

		} // INSERT ERASE
		}
	return 0;
}