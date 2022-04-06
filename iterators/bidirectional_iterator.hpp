/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:15 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/06 15:00:01 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"
#include "pair.hpp"
#include "Tree.hpp"

namespace ft
{

template < class Pair >
class bidirectional_iterator 
	: virtual public iterator_traits < iterator< bidirectional_iterator_tag, Pair > >
{
	
	public :

		typedef typename bidirectional_iterator::difference_type		difference_type;
		typedef typename bidirectional_iterator::value_type				value_type;
		typedef typename bidirectional_iterator::pointer				pointer;
		typedef typename bidirectional_iterator::reference				reference;
		typedef typename bidirectional_iterator::iterator_category		iterator_category;

	private :
		
		friend class RB_tree_iterator<bidirectional_iterator>;
	
		typedef	t_node< Pair >											_node;
		typedef	iterator< bidirectional_iterator_tag, _node > 			_node_iterator;
		typedef typename iterator_traits<_node_iterator>::pointer		_node_pointer;

		_node_pointer													_base;
		
	public :
	
		bidirectional_iterator()
		:
			_base(NULL)
		{}
		
		bidirectional_iterator( bidirectional_iterator const &src )
		:
			_base(src._base)
		{}

		bidirectional_iterator(_node_pointer node_ptr)
		:
			_base(node_ptr)
		{}

		template <typename Iter>
		bidirectional_iterator(const bidirectional_iterator<Iter> &src)
		:
			_base(reinterpret_cast<typename bidirectional_iterator<const Iter>::_node_pointer >(src.base()))
		{}

		~bidirectional_iterator()
		{}
		
		bidirectional_iterator &	operator=( bidirectional_iterator const &rhs )
		{
			_base = rhs._base;
			return *this;
		}


	/*
	** ----------------------------------------------------------- MEMBER ACCESS
	*/
		reference	operator*( void ) const
		{
			return (_base->element);
		}

		pointer	operator->( void ) const
		{
			return (&_base->element);
		}

		reference	operator*( void )
		{
			return (_base->element);
		}

		bool	operator==( const bidirectional_iterator &rhs ) const
		{
			return (rhs._base == _base);
		}

		bool	operator!=( const bidirectional_iterator &rhs ) const
		{
			return (!(rhs._base == _base));
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

		_node_pointer base() const
		{
			return (_base);
		}
		// operator bidirectional_iterator<const value_type> () const
		// { 	
		// 	return (bidirectional_iterator<const value_type>(this));
		// }

		// _node_pointer	operator&() {return _base;}
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
			if (_base->right != NULL)
			{
				_base = _base->right;
				while (_base->left != NULL)
					_base = _base->left;
			}
			else
			{
				_node_pointer	parent = _base->parent;
				
				while (parent != NULL && _base == parent->right)
				{
					_base = parent;
					parent = parent->parent;
				}
				_base = parent;
			}
		}

		void	_decrement()
		{
			if (_base->left != NULL)
			{
				_base = _base->left;
				while (_base->right != NULL)
					_base = _base->right;
			}
			else
			{
				_node_pointer	parent = _base->parent;
				
				while (parent != NULL && _base == parent->left)
				{
					_base = parent;
					parent = parent->parent;
				}
				_base = parent;
			}
		}
};

}

#endif