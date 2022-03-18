/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:54:16 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/18 11:48:34 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>

# include "../utils/utils.hpp"
# include "../utils/Tree.hpp"

namespace ft
{

template < class Key,                                  
           class T,        
           class Compare = std::less<Key>,                     
           class Alloc = std::allocator<pair<const Key,T> > 
           >
class map
{
	public :

		typedef Key														key_type;
		typedef T														mapped_type;
		typedef Compare													key_compare;
		typedef Alloc													allocator_type;
				
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		// typedef bidirectional_iterator<key_type, mapped_type>			iterator;
		// typedef bidirectional_iterator<key_type, mapped_type>			const_iterator;
		// typedef reverse_iterator<iterator>								reverse_iterator;
		// typedef reverse_iterator<const_iterator>						const_reverse_iterator;
		// typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename allocator_type::size_type						size_type;

	private :

		// typedef	typename ft::pair<key_type, mapped_type>				_value_type;
		typedef t_node<pointer>											_t_node;
		typedef typename Alloc::template rebind<_t_node>::other			_node_allocator;
		typedef	Tree<Key, T, Compare, _node_allocator>					_base;

		_base															_tree;

	public :
	/*
	** ------------------------------------------------------------ CONSTRUCTORS
	*/
		//-------------------------------------------------------------- empty
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
		:
			_tree(_base(comp, alloc))
		{}

		// //-------------------------------------------------------------- range
		template <class InputIterator>
		map	(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value
			&& !std::is_floating_point<InputIterator>::value, InputIterator>::type* = 0)
		:
			_tree(_base(first, last, comp, alloc))
		{}

		// //-------------------------------------------------------------- copy
		map	(const map& x)
		:
			_tree(_base(x._tree))
		{}

		// typedef struct	_s_node					_t_node;

		// struct _s_node
		// {
		// 	// bool color ?  enum IS_BLACK IS_RED
		// 	_t_node					*parent;
		// 	pointer					data;
		// 	_t_node					*left;
		// 	_t_node					*right;
		// };
		// _t_node									_root_node;
		// _t_node									_begin_node;
		// _t_node									_end_node;
		// size_type								_size;
		// allocator_type							_allocator;
		// key_compare								_comparator;


};

}

#endif