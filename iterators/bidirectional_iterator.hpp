/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:15 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/23 14:50:39 by llecoq           ###   ########.fr       */
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
		typedef typename iterator_traits<_iterator>::pointer				_element_pointer;
		typedef typename iterator_traits<_iterator>::reference				_element_reference;
	
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
			return (*(_node_pointer->element));
		}

		_element_pointer	operator->( void ) const
		{
			return (&_node_pointer->element);
		}

		reference	operator*( void )
		{
			return (*(_node_pointer->element));
		}

		bool	operator==( const bidirectional_iterator &rhs )
		{
			return (rhs._node_pointer == _node_pointer);
		}

		bool	operator!=( const bidirectional_iterator &rhs )
		{
			return (!(rhs._node_pointer == _node_pointer));
		}

		bidirectional_iterator	& operator++( void )
		{
			// If the current node has a non-null right child,
				// Take a step down to the right
				// Then run down to the left as far as possible 
			// If the current node has a null right child,
				// move up the tree until we have moved over a left child link
			if (_node_pointer->right != NULL)
			{
				_node_pointer = _node_pointer->right;
				while (_node_pointer->left != NULL)
					_node_pointer = _node_pointer->left;
			}
			else
			{
				pointer	parent = _node_pointer->parent;
				
				while (parent != NULL && _node_pointer == parent->right)
				{
					_node_pointer = parent;
					parent = parent->parent;
				}
				_node_pointer = parent;
			}
			return (*this);
		}

		bidirectional_iterator	operator++( int )
		{
			bidirectional_iterator	tmp(*this);

			if (_node_pointer->right != NULL)
			{
				_node_pointer = _node_pointer->right;
				while (_node_pointer->left != NULL)
					_node_pointer = _node_pointer->left;
			}
			else
			{
				pointer	parent = _node_pointer->parent;
				
				while (parent != NULL && _node_pointer == parent->right)
				{
					_node_pointer = parent;
					parent = parent->parent;
				}
				_node_pointer = parent;
			}
			return (tmp);
		}

		bidirectional_iterator	& operator--( void )
		{
			if (_node_pointer->left != NULL)
			{
				_node_pointer = _node_pointer->left;
				while (_node_pointer->right != NULL)
					_node_pointer = _node_pointer->right;
			}
			else
			{
				pointer	parent = _node_pointer->parent;
				
				while (parent != NULL && _node_pointer == parent->left)
				{
					_node_pointer = parent;
					parent = parent->parent;
				}
				_node_pointer = parent;
			}
			return (*this);
		}

		bidirectional_iterator	operator--( int )
		{
			bidirectional_iterator	tmp(*this);

			if (_node_pointer->left != NULL)
			{
				_node_pointer = _node_pointer->left;
				while (_node_pointer->right != NULL)
					_node_pointer = _node_pointer->right;
			}
			else
			{
				pointer	parent = _node_pointer->parent;
				
				while (parent != NULL && _node_pointer == parent->left)
				{
					_node_pointer = parent;
					parent = parent->parent;
				}
				_node_pointer = parent;
			}
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