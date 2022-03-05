/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:20:29 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/05 10:10:42 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "random_access_iterator.hpp"

namespace ft
{
	template <class Iterator>
	// pourquoi ne prends pas le _pointer meme sans virtual public ?
	class reverse_iterator : virtual public random_access_iterator<Iterator>
	{
		public :

		typedef Iterator														iterator_type;
		typedef typename random_access_iterator<Iterator>::difference_type		difference_type;
		typedef typename random_access_iterator<Iterator>::value_type			value_type;
		typedef typename random_access_iterator<Iterator>::pointer				pointer;
		typedef typename random_access_iterator<Iterator>::reference			reference;
		typedef typename random_access_iterator<Iterator>::iterator_category	iterator_category;

		// A TESTER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		/*------------------------- MEMBER FUNCTIONS -------------------------*/
		// default (1)
			reverse_iterator()
			: 
				_pointer(0)
			{}

		// initialization (2)	
			explicit reverse_iterator (iterator_type it)
			:
				_pointer(it)
			{}

		// copy (3)	
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it)
			:
				_pointer(rev_it)
			{}

		// base
		// Return base iterator (public member function )
			iterator_type base() const
			{
				return (_pointer - 1);
			}


			reverse_iterator &	operator=( reverse_iterator const &rhs )
			{
				_pointer = rhs._pointer;
				return *this;
			}

		/*
		** ------------------------------------------------------- MEMBER ACCESS
		*/
		// indirection to rvalue
		reference	& operator*( void ) const
		{
			return (*_pointer);
		}

		// member of pointer
		pointer	operator->( void ) const
		{
			return (_pointer);
		}

		// indirection to lvalue
		reference	& operator*( void )
		{
			return (*_pointer);
		}
		

		// operator*
		// Dereference iterator (public member function )

		// operator+
		// Addition operator (public member function )

		// operator++
		// Increment iterator position (public member function )

		// operator+=
		// Advance iterator (public member function )

		// operator-
		// Subtraction operator (public member function )

		// operator--
		// Decrease iterator position (public member function )

		// operator-=
		// Retrocede iterator (public member function )

		// operator->
		// Dereference iterator (public member function )

		// operator[]
		// Dereference iterator with offset (public member function )

		protected :

			pointer	_pointer;
	};
}

#endif