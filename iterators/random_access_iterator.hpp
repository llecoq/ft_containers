/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:01:12 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/06 13:59:27 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

# include <iostream>

namespace ft
{

template <typename T>
class random_access_iterator
	: virtual public iterator_traits< iterator<random_access_iterator_tag, T> >
{
	public :

		typedef typename random_access_iterator::difference_type	difference_type;
		typedef typename random_access_iterator::value_type			value_type;
		typedef typename random_access_iterator::pointer			pointer;
		typedef typename random_access_iterator::reference			reference;
		typedef typename random_access_iterator::iterator_category	iterator_category;

	protected :

		pointer														_base;

	public :
	
	/*
	** ------------------------------------------------------------ CONSTRUCTORS
	*/
		random_access_iterator()
		:
			_base(NULL)
		{}

		random_access_iterator( random_access_iterator const &src )
		:
			_base(src._base)
		{}
	
		random_access_iterator( pointer pointer )
		:
			_base(pointer)
		{}

		// const_iterator conversion
		template <typename Iter>
		random_access_iterator(const random_access_iterator<Iter> &src)
		:
			_base(src.base())
		{}

		random_access_iterator &	operator=( random_access_iterator const &rhs )
		{
			_base = rhs._base;
			return *this;
		}

		~random_access_iterator(){}
	
	/*
	** ----------------------------------------------------------- MEMBER ACCESS
	*/
		reference	operator*( void ) const
		{
			return (*_base);
		}

		pointer	operator->( void ) const
		{
			return (_base);
		}

		reference	operator*( void )
		{
			return (*_base);
		}
		

	/*
	** ------------------------------------------------- DE/IN-CREMENT OPERATORS
	*/
		random_access_iterator	& operator++( void )
		{
			_base++;
			return (*this);
		}

		random_access_iterator	operator++( int )
		{
			random_access_iterator	tmp(*this);
			
			_base++;
			return (tmp);
		}

		random_access_iterator	& operator--( void )
		{
			_base--;
			return (*this);
		}
		
		random_access_iterator	operator--( int )
		{
			random_access_iterator	tmp(*this);
			
			_base--;
			return (tmp);
		}


	/*
	** ---------------------------------------------------- ARITHMETIC OPERATORS
	*/
		random_access_iterator	operator+( difference_type n ) const
		{
			random_access_iterator	tmp(*this);

			tmp._base += n;
			return (tmp);
		}

		friend random_access_iterator	operator+( difference_type n, random_access_iterator rhs )
		{
			rhs._base += n;
			return (rhs);
		}
	
		random_access_iterator	operator-( difference_type const n ) const
		{
			random_access_iterator	tmp(*this);

			tmp._base -= n;
			return (tmp);
		}

		difference_type	operator-( random_access_iterator const &rhs ) const
		{
			return (_base - rhs._base);
		}


	/*
	** ------------------------------------------- COMPOUND ASSIGNMENT OPERATORS
	*/
		random_access_iterator	& operator+=( difference_type const n )
		{
			_base += n;
			return (*this);
		}

		random_access_iterator	& operator-=( difference_type const n )
		{
			_base -= n;
			return (*this);
		}

	/*
	** ---------------------------------------------------- COMPARISON OPERATORS
	*/
		bool	operator==( random_access_iterator rhs ) const
		{
			return (_base == rhs._base);
		}

		bool	operator!=( random_access_iterator rhs ) const
		{
			return (_base != rhs._base);
		}

	/*
	** ----------------------------------------- INEQUALITY RELATIONAL OPERATORS
	*/
		bool	operator<(random_access_iterator const &rhs) const
		{
			return (_base < rhs._base);
		}
		
		bool	operator>(random_access_iterator const &rhs) const
		{
			return (_base > rhs._base);
		}

		bool	operator<=(random_access_iterator const &rhs) const
		{
			return (_base <= rhs._base);
		}
		
		bool	operator>=(random_access_iterator const &rhs) const
		{
			return (_base >= rhs._base);
		}


	/*
	** ------------------------------------------------- OUTPUT STREAM OPERATORS
	*/
		friend std::ostream	&operator<<(std::ostream &output, random_access_iterator const &rhs)
		{
			output << rhs._base;
			return (output);
		}


	/*
	** --------------------------------------------------------------- SUBSCRIPT
	*/
		reference	operator[]( difference_type index )
		{
			return (_base[index]);
		}

		pointer base() const
		{
			return (_base);
		}

		// operator random_access_iterator<const value_type> () const
		// { 	
		// 	return (random_access_iterator<const value_type>(_pointer));
		// }
};


}

#endif