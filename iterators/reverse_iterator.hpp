/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:20:29 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/29 12:09:18 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

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

	/*------------------------- MEMBER FUNCTIONS -------------------------*/
	reverse_iterator()
	: 
		_base(0)
	{}

	explicit reverse_iterator (iterator_type it)
	:
		_base(it)
	{}

	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& rev_it)
	:
		_base(rev_it.base())
	{}

	iterator_type base() const
	{
		return (_base);
	}

	iterator_type	&operator=( iterator_type const &rhs ) const
	{
		_base = rhs;
		return *this;
	}


	/*
	** ------------------------------------------------------- MEMBER ACCESS
	*/
	
	bool	operator!=(reverse_iterator const &rhs)
	{
		return (rhs._base != _base);
	}

	reference operator*() const
	{
		iterator_type	tmp = _base;

		tmp--;
		return (*(tmp));
	}

	reverse_iterator operator+(difference_type n) const
	{
		reverse_iterator	tmp(*this);
		tmp._base -= n;
		return tmp;
	}

	reverse_iterator& operator++()
	{
		_base--;
		return *this;
	}
	
	reverse_iterator  operator++(int)
	{
		reverse_iterator	tmp(*this);

		_base--;
		return tmp;
	}

	reverse_iterator& operator+= (difference_type n)
	{
		_base = _base - n;
		return *this;
	}

	reverse_iterator operator-(difference_type n) const
	{
		reverse_iterator	tmp(*this);
		tmp._base += n;
		return tmp;
	}

	reverse_iterator& operator--()
	{
		_base++;
		return *this;
	}
	
	reverse_iterator  operator--(int)
	{
		reverse_iterator	tmp(*this);

		_base++;
		return tmp;
	}

	reverse_iterator& operator-= (difference_type n)
	{
		_base = _base + n;
		return *this;
	}

	pointer operator->() const
	{
		return &(operator*());
	}

	reference operator[] (difference_type n) const
	{
		return (base()[-n-1]);
	}

	/*
	** ------------------------------------------- NON-MEMBER FUNCTION OVERLOADS
	*/
	friend difference_type	operator- (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return (rhs._base - lhs._base);
	}

	friend reverse_iterator<Iterator> operator+ ( difference_type n,
            const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

	/*------------------------------- RELATIONNAL OPERATORS */
	friend bool operator== (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return (lhs._base == rhs._base);
	}
	
	friend bool operator!= (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return (lhs._base != rhs._base);
	}
	
	friend bool operator< (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return (lhs._base > rhs._base);
	}
	
	friend bool operator<= (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return (lhs._base >= rhs._base);
	}

	friend bool operator> (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return (lhs._base < rhs._base);
	}

	friend bool operator>= (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs)
	{
		return (lhs._base <= rhs._base);
	}

	protected :

		iterator_type	_base;

};


}

#endif