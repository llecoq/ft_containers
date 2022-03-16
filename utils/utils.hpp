/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:08:10 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/16 09:45:31 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "vector.hpp"

namespace ft
{
/*
** ----------------------------------------------------------------------- UTILS
*/
	// -------------------------- lexicographical compare
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

	// -------------------------------------------- equal
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
}

#endif