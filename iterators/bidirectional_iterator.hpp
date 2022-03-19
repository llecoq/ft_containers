/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:15 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/19 14:24:04 by llecoq           ###   ########.fr       */
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
		
		typedef	t_node< pair<Key, T> >									_node;
		typedef	iterator<bidirectional_iterator_tag, _node> 			_iterator;
		typedef typename iterator_traits< iterator < bidirectional_iterator_tag, pair<Key, T> > >::pointer							_data_pointer;
		typedef typename iterator_traits< iterator < bidirectional_iterator_tag, pair<Key, T> > >::reference						_data_reference;
	
	public :

		typedef typename iterator_traits<_iterator>::difference_type	difference_type;
		typedef typename iterator_traits<_iterator>::value_type			value_type;
		typedef typename iterator_traits<_iterator>::pointer			pointer;
		typedef typename iterator_traits<_iterator>::reference			reference;
		typedef typename iterator_traits<_iterator>::iterator_category	iterator_category;

	private:

		pointer															_node_pointer;

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
};

}

#endif