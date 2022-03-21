/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:54:16 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/19 16:55:03 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>

// # include "../utils/utils.hpp"
# include "../iterators/bidirectional_iterator.hpp"
# include "../utils/pair.hpp"
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
		typedef pair<key_type, mapped_type>								value_type;
				
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef bidirectional_iterator<key_type, mapped_type>			iterator;
		// typedef bidirectional_iterator<key_type, mapped_type>			const_iterator;
		// typedef reverse_iterator<iterator>								reverse_iterator;
		// typedef reverse_iterator<const_iterator>						const_reverse_iterator;
		// typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename allocator_type::size_type						size_type;


	private :

		typedef t_node<value_type>										_t_node;
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

		//-------------------------------------------------------------- range
		template <class InputIterator>
		map	(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value
			&& !std::is_floating_point<InputIterator>::value, InputIterator>::type* = 0)
		:
			_tree(_base(first, last, comp, alloc))
		{}

		//-------------------------------------------------------------- copy
		map	(const map& x)
		:
			_tree(_base(x._tree))
		{}

		//-------------------------------------------------------------- assign
		map& operator= (const map& x)
		{
			_tree = x._tree;
		}
	
		//-------------------------------------------------------------- destructor
		~map () {}

	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		iterator begin() {return iterator(_tree.begin());}
		iterator end() {return iterator(_tree.end());}
	
		// const_iterator begin() const;

	/*
	** ------------------------------------------------------------ CAPACITY
	*/
		bool empty() const {return _tree.empty();}

		size_type size() const {return _tree.size();}

		size_type max_size() const {return _tree.max_size();}

	/*
	** ------------------------------------------------------------ ELEMENT ACCESS
	*/

	/*
	** ------------------------------------------------------------ MODIFIERS
	*/

		void	print_tree()
		{
			print2D(_tree.root_node);
		}
	
		// single element (1)	
		pair<iterator,bool> insert (const value_type& val)
		{	
			_t_node	tmp(val);
			return (_tree.insert(tmp, _tree.root_node));
		}

		// with hint (2)	
		iterator insert (iterator position, const value_type& val);

		// range (3)	
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

};

}

#endif