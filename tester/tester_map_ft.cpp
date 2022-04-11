/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/11 15:23:44 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	tester_map_ft()
{
	/*------------------------------ CONSTRUCTOR ----------------------------*/
	{	
		std::cout << "-------------- CONSTRUCTOR ---------------" << std::endl;
		// empty constructor
		ft_map	empty;

		std::cout << "empty size = " << empty.size() << std::endl;
		// std::cout << "empty end =  " << empty.end()->first << std::endl;
		// std::cout << "empty begin =  " << empty.begin()->first << std::endl;

		// range constructor
		ft::vector< ft::pair <int,int> > vect;

		int arr[] = {10, 20, 5, 40 };
		int arr1[] = {30, 60, 20, 50};
		int n = sizeof(arr)/sizeof(arr[0]);
	
		for (int i = 0; i < n; i++)
			vect.push_back( ft::make_pair(arr[i],arr1[i]) );
		
		ft_map	map(vect.begin(), vect.end());
		ft_map	map2(map.begin(), map.end());

		std::cout << "map begin = " << map.begin()->first << std::endl;
		std::cout << "map2 begin = " << map2.begin()->first << std::endl;
		std::cout << "map size = " << map.size() << std::endl;
		std::cout << "map2 size = " << map2.size() << std::endl;
		std::cout << "vect size = " << vect.size() << std::endl;

		// copy constructor
		ft_map	copy(map);
		std::cout << "copy begin = " << copy.begin()->first << std::endl;
		std::cout << "copy size = " << copy.size() << std::endl;
		if (map == copy)
			std::cout << "copy constructor OK" << std::endl;
		std::cout << std::endl;
	}

	/*------------------------------ COPY ASSIGNMENT ----------------------------*/
	{
		std::cout << "-------------- COPY ASSIGNMENT ---------------" << std::endl;
		ft_map	map;
		ft_map	copy;
		ft_map	empty;

		ut::fillMap<ft_map, ft_pair>(map, 20, RANDOM);
		ut::fillMap<ft_map, ft_pair>(copy, 10, RANDOM);
		if (map != copy)
			std::cout << "map is not yet assigned to copy" << std::endl;
		std::cout << "copy assignment : copy = map" << std::endl;
		copy = map;
		if (map == copy)
			std::cout << "copy assignment successful" << std::endl;
		std::cout << "copy assignment : copy = empty" << std::endl;
		map = empty;
		ut::displayDataMap(map, "map");
		std::cout << "copy assignment : empty  = copy" << std::endl;
		empty = copy;
		if (empty == copy)
			std::cout << "copy assignment successful" << std::endl;
		std::cout << std::endl;
	}

	/*------------------------------ ITERATORS ----------------------------*/
	{
		std::cout << "-------------- ITERATORS ---------------" << std::endl;
		ft_map			test;

		ut::fillMap<ft_map, ft_pair>(test, 10, RANDOMIZED_QUEUE);
		ft_map::iterator		it = test.begin();
		ft_map::const_iterator	constit = test.begin();

		it++;
		constit++;

		ft_map::iterator	ite = test.end();
		
		std::cout << "increment" << std::endl;
		while (it != ite)
		{
			std::cout << it->first << std::endl;
			it++;
		}
		// it++;  // segfault like the original
		std::cout << "decrement" << std::endl;
		while (--it != test.begin())
			std::cout << it->first << std::endl;
		it--;
		ft_map::reverse_iterator	revit = test.rbegin();
		ft_map::reverse_iterator	revite = test.rend();

		std::cout << "reverse increment" << std::endl;
		while (revit != revite)
		{
			std::cout << revit->first << std::endl;
			revit++;
		}
		std::cout << "reverse decrement" << std::endl;
		while (--revit != test.rbegin())
			std::cout << revit->first << std::endl;
		
		ft_map::const_reverse_iterator revconstit = test.rbegin();
		revconstit++;
		std::cout << revconstit->first << std::endl;
		std::cout << std::endl;
	}

	/*------------------------------ CAPACITY ----------------------------*/
	{
		std::cout << "-------------- CAPACITY ---------------" << std::endl;
	
		std::cout << std::endl;
	}

	/*------------------------------ ELEMENT ACCESS ----------------------------*/
	{
		std::cout << "-------------- ELEMENT ACCESS ---------------" << std::endl;
		ft_map			test;
	
		ut::fillMap<ft_map, ft_pair>(test, 10, RANDOMIZED_QUEUE);

		std::cout << "size = " << test.size() << std::endl;
		int		&a = test[1];
		a = 2; 
		std::cout << test[1] << std::endl;
		std::cout << "size = " << test.size() << std::endl;
		int		&b = test[15];
		std::cout << test[15] << std::endl;
		b = 6;
		std::cout << test[15] << std::endl;
		std::cout << "size = " << test.size() << std::endl;
	
		std::cout << std::endl;
	}

	/*------------------------------ MODIFIERS ----------------------------*/
	{
		std::cout << "-------------- MODIFIERS ---------------" << std::endl;
	
		//-------------------------- INSERT / ERASE
		{
			std::cout << "-------------- INSERT / ERASE -------------" << std::endl;
			ft::map<int, TestClass> map;

			map.insert(ft::pair<int, TestClass>(1, 1));
			ut::fillMap<ft::map<int, TestClass>,ft::pair<int, TestClass> > (map, 20, RANDOM);
			ft_map mymap;
			
			// first insert function version (single parameter):
			mymap.insert ( ft_pair(6, 100) );
			mymap.insert ( ft_pair(26, 200) );
			
			ft::pair<ft_map::iterator,bool> ret;
			ret = mymap.insert ( ft_pair(26, 500) );
			if (ret.second==false)
			{
				std::cout << "element 26 already existed";
				std::cout << " with a value of " << ret.first->second << std::endl;
			}
			
			// // second insert function version (with hint position):
			ft_map::iterator it = mymap.end();
			std::cout << "size = " << mymap.size() << std::endl;
			mymap.insert (it, ft_pair(3, 300));  // max efficiency inserting
			std::cout << "size = " << mymap.size() << std::endl;
			it = mymap.insert (it, ft_pair(4, 400));
			std::cout << "it->second 4 = " << it->second << std::endl;
			it = mymap.insert (mymap.end(), ft_pair(27, 700));
			std::cout << "it->second 27 = " << it->second << std::endl;
			it = mymap.insert (mymap.begin(), ft_pair(2, 900));
			it = mymap.insert (mymap.end(), ft_pair(1, 30));
			it = mymap.insert (mymap.end(), ft_pair(90, 30));
			mymap.insert(it, ft_pair(90, 1));
			std::cout << "it->second 1 = " << it->second << std::endl;
			std::cout << "find 4 = " << mymap.find(4)->second << std::endl;
			std::cout << "find 3 = " << mymap.find(3)->second << std::endl;
			std::cout << "find 2 = " << mymap.find(2)->second << std::endl;
			std::cout << "find 27 = " << mymap.find(27)->second << std::endl;
			std::cout << "find 90 = " << mymap.find(90)->second << std::endl;
			mymap.insert(ft_pair(5, 5));
			std::cout << "size = " << mymap.size() << std::endl;
			ut::fillMap<ft_map, ft_pair>(mymap, 20, RANDOMIZED_QUEUE);
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
		} // INSERT ERASE
	
		//-------------------------- CLEAR
		{
			std::cout << "-------------- CLEAR -------------" << std::endl;
			ft_map	map;

			map.clear();
			ut::fillMap<ft_map, ft_pair>(map, 20, RANDOMIZED_QUEUE);
			ut::displayDataMap<ft_map>(map);
			map.clear();
			ut::displayDataMap<ft_map>(map);
			std::cout << std::endl;
		} // CLEAR

		//-------------------------- SWAP
		{
			std::cout << "-------------- SWAP -------------" << std::endl;
			ft::map<char, TestClass> foo,bar;

			foo['x']=100;
			foo['y']=200;
			
			bar['a']=11;
			bar['b']=22;
			bar['c']=33;
			
			foo.swap(bar);
			
			std::cout << "foo contains:" << std::endl;
			for (ft::map<char, TestClass>::iterator it = foo.begin(); it != foo.end(); ++it)
				std::cout << it->first << " => " << it->second << std::endl;
			
			std::cout << "bar contains:" << std::endl;
			for (ft::map<char, TestClass>::iterator it = bar.begin(); it != bar.end(); ++it)
				std::cout << it->first << " => " << it->second << std::endl;
			
			std::cout << "swap friend" << std::endl;

			swap(foo, bar);

			std::cout << "foo contains:" << std::endl;
			for (ft::map<char, TestClass>::iterator it = foo.begin(); it != foo.end(); ++it)
				std::cout << it->first << " => " << it->second << std::endl;
			
			std::cout << "bar contains:" << std::endl;
			for (ft::map<char, TestClass>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
		} // SWAP
	}

	/*------------------------------ OBSERVERS ----------------------------*/
	{
		std::cout << "-------------- OBSERVERS ---------------" << std::endl;
		//-------------------------- KEY_COMPARE
		{
			ft::map<char,int> mymap;
			ft::map<char,int>::key_compare mycomp = mymap.key_comp();
			
			mymap['a']=100;
			mymap['b']=200;
			mymap['c']=300;
			
			std::cout << "mymap contains:\n";
			
			char highest = mymap.rbegin()->first;     // key value of last element
			
			ft::map<char,int>::iterator it = mymap.begin();
			do {
				std::cout << it->first << " => " << it->second << std::endl;
			} while ( mycomp((*it++).first, highest) );
		} // KEY_COMPARE

		//-------------------------- VALUE_COMP
		{
			ft::map<char,int> mymap;
			
			mymap['x']=1001;
			mymap['y']=2002;
			mymap['z']=3003;
			
			std::cout << "mymap contains:\n";
			
			ft::pair<char,int> highest = *mymap.rbegin();          // last element
			
			ft::map<char,int>::iterator it = mymap.begin();
			do{
			std::cout << it->first << " => " << it->second << std::endl;
			} while ( mymap.value_comp()(*it++, highest) );
		} // VALUE_COMP
		
		std::cout << std::endl;
	}

	/*------------------------------ OPERATIONS ----------------------------*/
	{
		std::cout << "-------------- OPERATIONS ---------------" << std::endl;
	
		std::cout << std::endl;
	}

	/*------------------------------ ALLOCATOR ----------------------------*/
	{
		std::cout << "-------------- ALLOCATOR ---------------" << std::endl;
	
		std::cout << std::endl;
	}

	return (SUCCESS);
}

