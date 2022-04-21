/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:44:21 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/21 16:01:52 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

# include "bidirectional_iterator.hpp"
# include "reverse_iterator.hpp"
# include "RB_tree.hpp"

#include <memory>
#include <functional>

namespace ft
{

template  < class T,                      
			class Compare = std::less<T>,   
			class Alloc = std::allocator<T>      
			>
class set
{
	
	public :

		typedef	T														key_type;
		typedef	T														value_type;
		typedef Compare													key_compare;
		typedef Compare													value_compare;
		typedef Alloc													allocator_type;
		typedef allocator_type::reference								reference;
		typedef allocator_type::const_reference							const_reference;
		typedef allocator_type::pointer									pointer;
		typedef allocator_type::const_pointer							const_pointer;
	private :	
		typedef	ft::t_node_set<value_type, key_type>					_node_type;
	public :
		typedef ft::bidirectional_iterator<value_type, _node_type>		iterator;
		typedef ft::bidirectional_iterator<const value_type, _node_type>const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename allocator_type::size_type						size_type;

	private :

		typedef	RB_tree<_node_type, Compare, allocator_type, iterator>	_RB_tree_base;

		_RB_tree_base													_tree;

	public :
	/*
	** ------------------------------------------------------------ CONSTRUCTORS
	*/
		//-------------------------------------------------------------- empty
		explicit set (const key_compare& comp = key_compare(),
        			      const allocator_type& alloc = allocator_type())
		:
			_tree(_RB_tree_base(comp, alloc));
		{}

range (2)	
template <class InputIterator>
  set (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const allocator_type& alloc = allocator_type());
copy (3)	
set (const set& x);


};


}	// namespace ft


#endif