/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:01:12 by llecoq            #+#    #+#             */
/*   Updated: 2022/02/28 19:25:11 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{

template <class T>
class random_access_iterator : virtual public iterator_traits< iterator<random_access_iterator_tag, T> >
{
	public:

		typedef typename iterator<random_access_iterator_tag, T>::difference_type		difference_type;
		typedef typename iterator<random_access_iterator_tag, T>::value_type			value_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer				pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference				reference;
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category		iterator_category;

		/*
		** -------------------------------------------------------- CONSTRUCTORS
		*/
	// Is default-constructible, copy-constructible, copy-assignable and destructible
	// Default
		random_access_iterator()
		:
			_pointer(nullptr)
		{}
	// Copy
		random_access_iterator( random_access_iterator const &src )
		{
			*this = src;
		}
	// Destructor
		~random_access_iterator(){}

	// copy assignment
		random_access_iterator( random_access_iterator::pointer pointer )
		{
			_pointer = pointer;
		}

		random_access_iterator &	operator=( random_access_iterator const &rhs )
		{
			_pointer = rhs._pointer;
			return *this;
		}

		/*
		** ------------------------------------------------ COMPARISON OPERATORS
		*/

		bool	operator==( random_access_iterator rhs ) const
		{
			return (_pointer == rhs._pointer);
		}
	
		bool	operator!=( random_access_iterator rhs ) const
		{
			return (_pointer != rhs._pointer);
		}

		// Can be dereferenced as an rvalue (if in a dereferenceable state).
			// *a
			// a->m

		// For mutable iterators (non-constant iterators):
		// Can be dereferenced as an lvalue (if in a dereferenceable state).	
			// *a = t

		/*
		** --------------------------------------------- DE/IN-CREMENT OPERATORS
		*/

		random_access_iterator	& operator++( void )
		{
			_pointer++;
			return (*this);
		}

		random_access_iterator	operator++( int )
		{
			random_access_iterator	tmp(*this);
			
			_pointer++;
			return (tmp);
		}

		value_type& operator*( void ) const
		{
			return (*this->_pointer);
		}

		random_access_iterator	& operator--( void )
		{
			_pointer--;
			return (*this);
		}
		
		random_access_iterator	operator--( int )
		{
			random_access_iterator	tmp(*this);
			
			_pointer--;
			return (tmp);
		}

		// *a--

		/*
		** ------------------------------------------------ ARITHMETIC OPERATORS
		*/

		random_access_iterator	operator+( difference_type n ) const
		{
			random_access_iterator	tmp(*this);

			tmp._pointer += n;
			return (tmp);
		}

		friend random_access_iterator	operator+( difference_type n, random_access_iterator rhs )
		{
			rhs._pointer += n;
			return (rhs);
		}
	
		random_access_iterator	operator-( difference_type const n ) const
		{
			random_access_iterator	tmp(*this);

			tmp._pointer -= n;
			return (tmp);
		}

		// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH
		friend random_access_iterator	operator-( random_access_iterator const &rls, random_access_iterator const &rhs )
		{
			random_access_iterator	tmp(rls);
			
			*tmp._pointer -= *rhs._pointer;
			return (tmp);
		}

		/*
		** ------------------------------------- INEQUALITY RELATIONAL OPERATORS
		*/

		bool	operator<(random_access_iterator const &rhs) const
		{
			return (*this->_pointer < *rhs._pointer);
		}
		
		bool	operator>(random_access_iterator const &rhs) const
		{
			return (*this->_pointer > *rhs._pointer);
		}

		bool	operator<=(random_access_iterator const &rhs) const
		{
			return (*this->_pointer <= *rhs._pointer);
		}
		
		bool	operator>=(random_access_iterator const &rhs) const
		{
			return (*this->_pointer >= *rhs._pointer);
		}

		/*
		** --------------------------------------- COMPOUND ASSIGNMENT OPERATORS
		*/

		random_access_iterator	&operator+=( difference_type const n )
		{
			_pointer += n;
			return (*this);
		}

		random_access_iterator	&operator-=( difference_type const n )
		{
			_pointer -= n;
			return (*this);
		}

		/*
		** --------------------------------------------- OUTPUT STREAM OPERATORS
		*/

		friend std::ostream	&operator<<(std::ostream &output, random_access_iterator const &rhs)
		{
			output << rhs._pointer;
			return (output);
		}


	protected :

		pointer		_pointer;
};


}

#endif