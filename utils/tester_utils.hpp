/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:30:19 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/21 17:43:38 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	TESTER_UTILS_HPP
#define	TESTER_UTILS_HPP

#include <cstdlib>

namespace ut
{
	# define RANDOM 1
	# define RANDOMIZED_QUEUE 2
	# define QUEUE 3
	
	// ------------------------------------------ display vector
	template < typename T >
	void	displayVec(T &vec)
	{
		typename T::iterator	it = vec.begin();

		std::cout << "-----------VECTOR----------" << std::endl;
		while (it != vec.end())
			std::cout << *it++ << std::endl;
		std::cout << "---------------------------" << std::endl;
	}

	template < typename T >
	void	displayData(T &vec, std::string name = "vec")
	{
		std::cout << "------------DATA-----------" << std::endl;
		std::cout << "name = " << name << std::endl;
		std::cout << "size = " << vec.size() << std::endl;
		std::cout << "capacity = " << vec.capacity() << std::endl;
		std::cout << "---------------------------" << std::endl;
	}

	template < typename T >
	void	displayDataVec(T &vec, std::string name = "vec")
	{
		std::cout << "------------DATA-----------" << std::endl;
		std::cout << "name = " << name << std::endl;
		std::cout << "size = " << vec.size() << std::endl;
		std::cout << "capacity = " << vec.capacity() << std::endl;
		typename T::iterator	it = vec.begin();

		std::cout << "-----------VECTOR----------" << std::endl;
		while (it != vec.end())
			std::cout << *it++ << std::endl;
		std::cout << "---------------------------" << std::endl;
	}

	// ------------------------------------------ display map
	template < typename T >
	void	displayMap(T &map)
	{
		typename T::iterator	it = map.begin();

		std::cout << "------------MAP------------" << std::endl;
		while (it != map.end())
			std::cout << (it++)->first << std::endl;
		std::cout << "---------------------------" << std::endl;
	}

	template < typename T >
	void	displayDataMap(T &map, std::string name = "map")
	{
		std::cout << "------------DATA-----------" << std::endl;
		std::cout << "name = " << name << std::endl;
		std::cout << "size = " << map.size() << std::endl;
		typename T::iterator	it = map.begin();

		std::cout << "------------MAP------------" << std::endl;
		while (it != map.end())
			std::cout << (it++)->first << std::endl;
		std::cout << "---------------------------" << std::endl;
	}

	// ---------------------------------------- push back
	template < typename T >
	void	pushBackVec(T &vec, int n = 10)
	{
		for (int i = 0; i < n; ++i)
			vec.push_back(i);
	}
	
	// ----------------------------------------- fill map
	template < class Map, class Pair >
	void	fillMap(Map &map, int n, int option = 0)
	{
		if (option == RANDOM)
		{
			srand (time(NULL));
			for (int i = 0; i < n; i++)
				map.insert(Pair (rand() % 1561 , rand() % 154 ) );
		}
		else if (option == RANDOMIZED_QUEUE)
		{
			map.insert(Pair(5, 5));
			map.insert(Pair(4, 4));
			map.insert(Pair(2, 2));
			map.insert(Pair(3, 3));
			map.insert(Pair(11, 11));
			map.insert(Pair(6, 6));
			map.insert(Pair(1, 1));
			map.insert(Pair(7, 7));
			map.insert(Pair(8, 8));
			map.insert(Pair(10, 10));
			map.insert(Pair(9, 9));
			map.insert(Pair(12, 12));
		}
		else // QUEUE
		{
			for (int i = 0; i < n; i++)
				map.insert(Pair(i, i));
		}
	}

	// ----------------------------------------- fill set
	template < class Set >
	void	fillSet(Set &set, int n, int option = 0)
	{
		if (option == RANDOM)
		{
			srand (time(NULL));
			for (int i = 0; i < n; i++)
				set.insert(rand() % 1561);
		}
		else if (option == RANDOMIZED_QUEUE)
		{
			set.insert(5);
			set.insert(4);
			set.insert(2);
			set.insert(3);
			set.insert(11);
			set.insert(6);
			set.insert(1);
			set.insert(7);
			set.insert(8);
			set.insert(10);
			set.insert(9);
			set.insert(12);
		}
		else // QUEUE
		{
			for (int i = 0; i < n; i++)
				set.insert(i);
		}
	}

	template < typename T >
	void	displayDataSet(T &set, std::string name = "set")
	{
		std::cout << "------------DATA-----------" << std::endl;
		std::cout << "name = " << name << std::endl;
		std::cout << "size = " << set.size() << std::endl;
		typename T::iterator	it = set.begin();

		std::cout << "------------SET------------" << std::endl;
		while (it != set.end())
			std::cout << *it++ << std::endl;
		std::cout << "---------------------------" << std::endl;
	}

}

#endif