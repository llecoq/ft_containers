/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:20:29 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/08 18:13:17 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "random_access_iterator.hpp"

namespace ft
{
template <class Iterator>
class reverse_iterator
{
	public :

	typedef Iterator										iterator_type;
	typedef typename Iterator::difference_type				difference_type;
	typedef typename Iterator::value_type					value_type;
	typedef typename Iterator::pointer						pointer;
	typedef typename Iterator::reference					reference;
	typedef typename Iterator::iterator_category			iterator_category;

	// A TESTER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/*------------------------- MEMBER FUNCTIONS -------------------------*/
	// default (1)
		reverse_iterator()
		: 
			_rev_it(0)
		{}

	// initialization (2)	
		explicit reverse_iterator (iterator_type it)
		:
			_rev_it(it)
		{}

	// copy (3)	
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it)
		:
			_rev_it(rev_it)
		{}

	// base
	// Return base iterator (public member function )
		iterator_type base() const
		{
			return (_rev_it + 1);
		}

		reverse_iterator	&operator=( iterator_type const &rhs )
		{
			_rev_it = rhs;
			return *this;
		}

	// Call operator NOT WORKING
		reverse_iterator	&operator()( reverse_iterator const &rhs )
		{
			_rev_it = rhs._rev_it;
			return *this;
		}

	/*
	** ------------------------------------------------------- MEMBER ACCESS
	*/
	// indirection to rvalue
	// reference	operator*( void ) const
	// {
	// 	return (*_rev_it);
	// }

	// // member of pointer
	// pointer	operator->( void ) const
	// {
	// 	return (_pointer);
	// }

	// // indirection to lvalue
	// reference	& operator*( void )
	// {
	// 	return (*_pointer);
	// }
	
	bool	operator!=(reverse_iterator const &rhs)
	{
		return (rhs._rev_it != _rev_it);
	}

	// operator*
	// Dereference iterator (public member function )
	// Internally, the function decreases a copy of its base iterator and returns the result of dereferencing it. << stupid ?
	reference operator*() const
	{
		return (*(base() - 1));
	}

	// operator+
	// Addition operator (public member function )
	reverse_iterator operator+(difference_type n) const
	{
		reverse_iterator	tmp(*this);
		tmp._rev_it -= n;
		return tmp;
	}

	// operator++
	reverse_iterator& operator++()
	{
		_rev_it--;
		return *this;
	}
	
	reverse_iterator  operator++(int)
	{
		reverse_iterator	tmp(*this);

		_rev_it--;
		return tmp;
	}

	// operator+=
	// Advance iterator (public member function )
	reverse_iterator& operator+= (difference_type n)
	{
		_rev_it = _rev_it - n;
		return *this;
	}

	// operator-
	// Subtraction operator (public member function )
	reverse_iterator operator-(difference_type n) const
	{
		reverse_iterator	tmp(*this);
		tmp._rev_it += n;
		return tmp;
	}

	// operator--
	reverse_iterator& operator--()
	{
		_rev_it++;
		return *this;
	}
	
	reverse_iterator  operator--(int)
	{
		reverse_iterator	tmp(*this);

		_rev_it++;
		return tmp;
	}

	// operator-=
	// Retrocede iterator (public member function )
	reverse_iterator& operator-= (difference_type n)
	{
		_rev_it = _rev_it + n;
		return *this;
	}

	// operator->
	// Dereference iterator (public member function )
	pointer operator->() const
	{
		
	}

	// operator[]
	// Dereference iterator with offset (public member function )

	protected :

		iterator_type	_rev_it;

};

}

#endif