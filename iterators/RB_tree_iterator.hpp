/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:28:48 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/30 14:43:54 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_ITERATOR_HPP
#define RB_TREE_ITERATOR_HPP

#include "bidirectional_iterator.hpp"

namespace ft
{
	
template < class Iter >
class RB_tree_iterator : virtual private Iter
{
	private :

		typedef	Iter												_bidirectional_iterator;
		typedef typename _bidirectional_iterator::_node_pointer		_node_pointer;

		_node_pointer												_node_ptr;

	public :

		RB_tree_iterator()
		:
			_node_ptr(NULL)
		{}
	
		RB_tree_iterator(_bidirectional_iterator iter)
		:
			_node_ptr(iter._node_ptr)
		{}

		~RB_tree_iterator()
		{}

		RB_tree_iterator &	operator=( RB_tree_iterator const &rhs )
		{
			_node_ptr = rhs._node_ptr;
			return *this;
		}

		_node_pointer		base()
		{
			return _node_ptr;
		}
	
};


} // namespace ft

#endif