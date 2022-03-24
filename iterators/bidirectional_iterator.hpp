/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:15 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/24 14:28:16 by llecoq           ###   ########.fr       */
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
	: virtual public iterator_traits < iterator< bidirectional_iterator_tag, pair<Key, T> > >
{
	private :
		
		typedef	t_node< pair<Key, T> >									_node;
		typedef	iterator< bidirectional_iterator_tag, _node > 			_node_iterator;
		typedef typename iterator_traits<_node_iterator>::pointer		_node_pointer;
	
	public :

		typedef typename bidirectional_iterator::difference_type		difference_type;
		typedef typename bidirectional_iterator::value_type				value_type;
		typedef typename bidirectional_iterator::pointer				pointer;
		typedef typename bidirectional_iterator::reference				reference;
		typedef typename bidirectional_iterator::iterator_category		iterator_category;

	private:

		_node_pointer													_node_ptr;

	public :

		bidirectional_iterator()
		{}
		
		bidirectional_iterator(_node_pointer node_ptr)
		:
			_node_ptr(node_ptr)
		{}

		~bidirectional_iterator()
		{}


	/*
	** ----------------------------------------------------------- MEMBER ACCESS
	*/
		reference	operator*( void ) const
		{
			return (_node_ptr->element);
		}

		pointer	operator->( void ) const
		{
			return (&_node_ptr->element);
		}

		reference	operator*( void )
		{
			return (_node_ptr->element);
		}

		bool	operator==( const bidirectional_iterator &rhs ) const
		{
			return (rhs._node_ptr == _node_ptr);
		}

		bool	operator!=( const bidirectional_iterator &rhs ) const
		{
			return (!(rhs._node_ptr == _node_ptr));
		}

		bidirectional_iterator	& operator++( void )
		{
			_increment();
			return (*this);
		}

		bidirectional_iterator	operator++( int )
		{
			bidirectional_iterator	tmp(*this);

			_increment();
			return (tmp);
		}

		bidirectional_iterator	& operator--( void )
		{
			_decrement();
			return (*this);
		}

		bidirectional_iterator	operator--( int )
		{
			bidirectional_iterator	tmp(*this);

			_decrement();
			return (tmp);
		}

		_node_pointer	operator&() {return _node_ptr;}
// *a++

// *a--

	private :

		void	_increment()
		{
			// If the current node has a non-null right child,
				// Take a step down to the right
				// Then run down to the left as far as possible 
			// If the current node has a null right child,
				// move up the tree until we have moved over a left child link
			if (_node_ptr->right != NULL)
			{
				_node_ptr = _node_ptr->right;
				while (_node_ptr->left != NULL)
					_node_ptr = _node_ptr->left;
			}
			else
			{
				_node_pointer	parent = _node_ptr->parent;
				
				while (parent != NULL && _node_ptr == parent->right)
				{
					_node_ptr = parent;
					parent = parent->parent;
				}
				_node_ptr = parent;
			}
		}

		void	_decrement()
		{
			if (_node_ptr->left != NULL)
			{
				_node_ptr = _node_ptr->left;
				while (_node_ptr->right != NULL)
					_node_ptr = _node_ptr->right;
			}
			else
			{
				_node_pointer	parent = _node_ptr->parent;
				
				while (parent != NULL && _node_ptr == parent->left)
				{
					_node_ptr = parent;
					parent = parent->parent;
				}
				_node_ptr = parent;
			}
		}
};

}

#endif