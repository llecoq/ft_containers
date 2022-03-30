/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:54:16 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/30 14:13:55 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include "../iterators/bidirectional_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/Tree.hpp"

#include <memory>
#include <functional>

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
		typedef bidirectional_iterator<value_type>						iterator;
		typedef bidirectional_iterator<const value_type>				const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename allocator_type::size_type						size_type;


	private :

		typedef t_node<value_type>										_t_node;
		typedef typename Alloc::template rebind<_t_node>::other			_node_allocator;
		typedef typename _node_allocator::pointer						_node_pointer;
		typedef	Tree<Key, T, Compare, _node_allocator, iterator>		_base;

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
			&& !is_floating_point<InputIterator>::value, InputIterator>::type* = 0)
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
		const_iterator begin() const {return const_iterator(_tree.begin());}
		iterator end() {return iterator(_tree.end());}
		const_iterator end() const {return const_iterator(_tree.end());}
		reverse_iterator rbegin() {return reverse_iterator(_tree.rbegin());}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(_tree.rbegin());}
		reverse_iterator rend() {return reverse_iterator(_tree.rend());}
		const_reverse_iterator rend() const {return const_reverse_iterator(_tree.rend());}

	/*
	** ------------------------------------------------------------ CAPACITY
	*/
		bool empty() const {return _tree.empty();}

		size_type size() const {return _tree.size();}

		size_type max_size() const {return _tree.max_size();}

	/*
	** ------------------------------------------------------------ ELEMENT ACCESS
	*/

		mapped_type& operator[] (const key_type& k)
		{
			_t_node	tmp(value_type(k, mapped_type()));
			pair<iterator, bool>	ret = _tree.insert(tmp, _tree.root_node);
			
			return ret.first->second;
		}

	/*
	** ------------------------------------------------------------ MODIFIERS
	*/

		void	print_tree()
		{
			printTree(_tree.root_node, _tree._end_node);
			std::cout << std::endl;
		}

		// single element (1)	
		pair<iterator,bool> insert (const value_type& val)
		{	
			_t_node			tmp(val);

			return (_tree.insert(tmp, _tree.root_node));
		}

		// with hint (2)	
		iterator insert (iterator position, const value_type& val)
		{
			if (_faster_from_root(val.first, position->first))
				return _tree.insert(_t_node(val), _tree.root_node).first;
		
			_node_pointer	current_position = &position;
			_node_pointer	parent = current_position->parent;

			if (position == end()
				|| _position_is_after_insert(current_position, val.first))
			{
				if (position == begin())
					return _tree.insert(_t_node(val), current_position->left, current_position).first;
				return _check_before_position(parent, val);
			}
			else if (_position_is_before_insert(current_position, val.first))
				return _check_after_position(parent, val);
			return position; // insert key = root key
		}

		
		// range (3)	
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

		void erase (iterator position)
		{
			_node_pointer	node_to_erase = &position;
			
			_tree.erase(node_to_erase);
		}

			
		size_type erase (const key_type& k)
		{
			iterator		position = find(k);
			
			if (position != end())
			{
				_node_pointer	node_to_erase = &position;
				
				_tree.erase(node_to_erase);
				return	1;
			}
			return 0;
		}

		// enable if iterator and const_iterator are bidirectional iterator types that point to elements
		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				_node_pointer	node_to_erase = &(first++);

				erase(node_to_erase);
			}
		}

	/*
	** -------------------------------------------------------------- OPERATIONS
	*/
		iterator find (const key_type& k)
		{
			return _tree.find(k);
		}
		
		const_iterator find (const key_type& k) const;

	private :

		iterator	_check_before_position(_node_pointer current_position, const value_type &val)
		{
			_node_pointer	parent = current_position->parent;
				
			if (_position_is_root(current_position)
				|| _position_is_before_insert(current_position, val.first))
				return _tree.insert(_t_node(val), current_position, parent).first;
			return _check_before_position(parent, val);
		}

		iterator	_check_after_position(_node_pointer current_position, const value_type &val)
		{
			_node_pointer	parent = current_position->parent;

			if (_position_is_root(current_position)
				|| _position_is_after_insert(current_position, val.first))
				return _tree.insert(_t_node(val), current_position, parent).first;
			return _check_after_position(parent, val);
		}

		bool	_position_is_root(_node_pointer position)
		{
			return (position == _tree.get_root_node());
		}

		bool	_position_is_before_insert(_node_pointer current_position, key_type insert_key)
		{
			return key_compare()(current_position->element.first, insert_key);
		}

		bool	_position_is_after_insert(_node_pointer current_position, key_type insert_key)
		{
			return key_compare()(insert_key, current_position->element.first);
		}

		bool	_faster_from_root(key_type insert_key, key_type position_key)
		{
			return size() < 2 || _position_is_opposite_way(insert_key, position_key);
		}

		bool	_position_is_opposite_way(key_type insert_key, key_type position_key)
		{
			key_type	root_key = _tree.get_root_key();
			bool		position_is_before_root = key_compare()(position_key, root_key);
			bool		position_is_after_root = key_compare()(root_key, position_key);
			bool		root_is_before_insert = key_compare()(root_key, insert_key);
			bool		root_is_after_insert = key_compare()(insert_key, root_key);

			if ((position_is_before_root && root_is_before_insert)
				|| (position_is_after_root && root_is_after_insert))
				return true;
			return (!root_is_after_insert && !root_is_before_insert); // insert_key = root_key
		}

};

}

#endif