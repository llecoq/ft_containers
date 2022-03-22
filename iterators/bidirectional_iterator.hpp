/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:15 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/22 11:06:25 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"
#include "../utils/pair.hpp"
#include "../utils/Tree.hpp"

namespace ft
{

template < class Key, class T >
class bidirectional_iterator 
	: virtual public iterator< bidirectional_iterator_tag, pair<Key, T> >
{
	private :
		
		typedef	t_node< pair<Key, T> >										_node;
		typedef	iterator< bidirectional_iterator_tag, _node > 				_node_iterator;
		typedef iterator< bidirectional_iterator_tag, pair<Key, T> >		_iterator;
		typedef typename iterator_traits<_iterator>::pointer				_data_pointer;
		typedef typename iterator_traits<_iterator>::reference				_data_reference;
	
	public :

		typedef typename bidirectional_iterator::difference_type			difference_type;
		typedef typename bidirectional_iterator::value_type					value_type;
		typedef typename iterator_traits<_node_iterator>::pointer			pointer;
		typedef typename iterator_traits<_node_iterator>::reference			reference;
		typedef typename bidirectional_iterator::iterator_category			iterator_category;

	private:

		pointer																_node_pointer;

	public :
		// default
		bidirectional_iterator()
		{}
		
		bidirectional_iterator(pointer node_pointer)
		:
			_node_pointer(node_pointer)
		{}

		~bidirectional_iterator()
		{}



	/*
	** ----------------------------------------------------------- MEMBER ACCESS
	*/
		reference	operator*( void ) const
		{
			return (*(_node_pointer->data));
		}

		_data_pointer	operator->( void ) const
		{
			return (&_node_pointer->data);
		}

		reference	operator*( void )
		{
			return (*(_node_pointer->data));
		}

// a == b
		bool	operator==( const bidirectional_iterator &rhs )
		{
			return (rhs._node_pointer == _node_pointer);
		}

// a != b
		bool	operator!=( const bidirectional_iterator &rhs )
		{
			return (!(rhs._node_pointer == _node_pointer));
		}

// ++a
		bidirectional_iterator	& operator++( void )
		{
			// _pointer++;
			return (*this);
		}

		bidirectional_iterator	operator++( int )
		{
			random_access_iterator	tmp(*this);
			
			// _pointer++;
			return (tmp);
		}
// a++
// *a++

// --a
// a--
// *a--

};

}

#endif