/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:01:12 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/14 11:47:32 by llecoq           ###   ########.fr       */
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
		random_access_iterator()
		:
			_pointer(0)
		{}

		random_access_iterator( random_access_iterator const &src )
		{
			*this = src;
		}
	
		~random_access_iterator(){}

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
		** ------------------------------------------------------- MEMBER ACCESS
		*/
		reference	operator*( void ) const
		{
			return (*_pointer);
		}

		pointer	operator->( void ) const
		{
			return (_pointer);
		}

		reference	operator*( void )
		{
			return (*_pointer);
		}
		

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

		difference_type	operator-( random_access_iterator const &rhs ) const
		{
			return (_pointer - rhs._pointer);
		}


		/*
		** --------------------------------------- COMPOUND ASSIGNMENT OPERATORS
		*/
		random_access_iterator	& operator+=( difference_type const n )
		{
			_pointer += n;
			return (*this);
		}

		random_access_iterator	& operator-=( difference_type const n )
		{
			_pointer -= n;
			return (*this);
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


		/*
		** ------------------------------------- INEQUALITY RELATIONAL OPERATORS
		*/
		bool	operator<(random_access_iterator const &rhs) const
		{
			return (_pointer < rhs._pointer);
		}
		
		bool	operator>(random_access_iterator const &rhs) const
		{
			return (_pointer > rhs._pointer);
		}

		bool	operator<=(random_access_iterator const &rhs) const
		{
			return (_pointer <= rhs._pointer);
		}
		
		bool	operator>=(random_access_iterator const &rhs) const
		{
			return (_pointer >= rhs._pointer);
		}


		/*
		** --------------------------------------------- OUTPUT STREAM OPERATORS
		*/
		friend std::ostream	&operator<<(std::ostream &output, random_access_iterator const &rhs)
		{
			output << rhs._pointer;
			return (output);
		}


		/*
		** ----------------------------------------------------------- SUBSCRIPT
		*/
		reference	operator[]( difference_type index )
		{
			return (_pointer[index]);
		}

	protected :

		pointer		_pointer;
};


}

#endif