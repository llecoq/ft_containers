/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:08:10 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/30 14:53:37 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib>

namespace ft
{

	# define COUNT 10
	# define RANDOM 1
	# define RANDOMIZED_QUEUE 2

/*
** ----------------------------------------------------- LEXICOGRAPHICAL COMPARE
*/
	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (comp(first1, last2));
	}

/*
** ----------------------------------------------------------------------- EQUAL
*/
	template <class InputIterator1, class InputIterator2>
	bool	equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool	equal (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}
/*
** ----------------------------------------------------------------------- UTILS
*/
	// --------------------------------------------- data
	template < class T, class Alloc = std::allocator<T> >
	struct	data
	{
		typedef	Alloc											allocator_type;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::size_type				size_type;

		pointer													_begin;
		pointer													_end;
		pointer													_end_capacity;
		allocator_type											_allocator;
		size_type												capacity;
		size_type												size;
	};

	// ------------------------------------------ display
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

	// ---------------------------------------- push back
	template < typename T >
	void	pushBackVec(T &vec, int n = 10)
	{
		for (int i = 0; i < n; ++i)
			vec.push_back(i);
	}

	// --------------------------------------- print 2D BSC
	template < typename Node >
	void	print2D(Node *root, int space, Node *end)
	{
		if (root == NULL || root == end)
			return;
		space += COUNT;
		print2D(root->right, space, end);
		std::cout << std::endl;
		for (int i = COUNT; i < space; i++)
			std::cout << " ";
		std::cout << root->element.first << " - " << root->element.second;
		if (root->parent)
			std::cout << " (parent = " << root->parent->element.first << ")" << std::endl;
		print2D(root->left, space, end);
	}

	template < typename Node >
	void	printTree(Node *root, Node *end)
	{
		print2D(root, 0, end);
	}

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
		else
		{
			for (int i = 0; i < n; i++)
				map.insert(Pair(i, i));
		}
	}



}

#endif