/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:08:10 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/21 15:45:30 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
	#define RESET 		  "\033[0m"
	#define BLACK_COLOR   "\033[30m"      /* Black */
	#define RED_COLOR     "\033[31m"      /* Red */

	enum	e_child
	{
		NO_CHILD = 0,
		ONE_CHILD = 1,
		TWO_CHILDREN = 2
	};

	enum	e_bound
	{
		LOWER = 0,
		UPPER = 1
	};

	enum	e_insert
	{
		LEFT_UNCLE_IS_RED = 1,
		RIGHT_UNCLE_IS_RED = 2,
		INNER_LEFT_CHILD = 3,
		OUTER_RIGHT_CHILD = 4,
		INNER_RIGHT_CHILD = 5,
		OUTER_LEFT_CHILD = 6,
		ROTATE_RIGHT = 7,
		ROTATE_LEFT = 8,
		ERASE = 9
	};

	enum	e_erase
	{
		NO_VIOLATION = 0,
		PARENT_IS_RED = 1,
		SIBLING_IS_RED = 2,
		PARENT_AND_SIBLING_ARE_BLACK = 3
	};

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
	template < class Alloc >
	struct	t_vector_data
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

	template < class Alloc >
	struct	t_tree_data
	{
		typedef	Alloc											allocator_type;
		typedef typename allocator_type::pointer				node_pointer;
		typedef typename allocator_type::size_type				size_type;

		node_pointer											_root_node;
		node_pointer											_begin_node;
		node_pointer											_end_node;
		size_type												_size;
	};

}

#endif