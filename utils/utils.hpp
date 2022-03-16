/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:08:10 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/16 14:44:34 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "vector.hpp"

namespace ft
{
/*
** ------------------------------------------------------------------------ PAIR
*/
	template <class T1, class T2>
	struct	pair
	{
			typedef T1		first_type;
			typedef T2		second_type;

			first_type		first;
			second_type		second;

		// -------------------------------------------------------- constructors
			// default
			pair(): first(), second() {}
			// copy
			template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {std::cout << "pair copy constructor" << std::endl;}
			// initialization
			pair (const first_type& a, const second_type& b) : first(a), second(b) {}
		// ----------------------------------------------------------- operator=
			pair& operator= (const pair& pr) {first = pr.first; second = pr.second; return *this;} 	
	};
	// ---------------------------------------------------- relational operators
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }
	
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }
	
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
	
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }
	
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }
	
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }
/*
** ------------------------------------------------------------------- MAKE PAIR
*/
	template <class T1,class T2>
	pair<T1,T2>	make_pair (T1 x, T2 y) {return pair<T1,T2>(x,y);}


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
}

#endif