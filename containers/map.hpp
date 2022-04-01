/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:54:16 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 15:04:22 by llecoq           ###   ########.fr       */
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
		// typedef value_compare::													value_compare;
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
		key_compare														_comp;

	public :
	/*
	** ------------------------------------------------------------ CONSTRUCTORS
	*/
		//-------------------------------------------------------------- empty
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
		:
			_tree(_base(comp, alloc)),
			_comp(comp)
		{}

		//-------------------------------------------------------------- range
		template <class InputIterator>
		map	(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value
			&& !is_floating_point<InputIterator>::value, InputIterator>::type* = 0)
		:
			_tree(_base(first, last, comp, alloc)),
			_comp(comp)
		{}

		//-------------------------------------------------------------- copy
		map	(const map& x)
		:
			_tree(_base(x._tree)),
			_comp(_comp)
		{}

		//-------------------------------------------------------------- assign
		map& operator= (const map& x)
		{
			_tree = x._tree;
			_comp = x._comp;
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
			return _tree.insert(value_type(k, mapped_type())).first->second;
		}

	/*
	** ------------------------------------------------------------ MODIFIERS
	*/

		void	print_tree()
		{
			_tree.print_tree();
		}

		// single element (1)	
		pair<iterator,bool> insert (const value_type& val)
		{	
			return _tree.insert(val);
		}

		// with hint (2)	
		iterator insert (iterator position, const value_type& val)
		{
			if (_faster_from_root(val.first, position))
				return _tree.insert(val).first;
			return _tree.insert(position, val).first; // insert key = root key
		}

		
		// range (3)	
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last);

		void erase (iterator position)
		{
			_tree.erase(position);
		}

			
		size_type erase (const key_type& k)
		{
			iterator		position = find(k);
			
			if (position != end())
			{
				_tree.erase(position);
				return	1;
			}
			return 0;
		}

		// enable if iterator and const_iterator are bidirectional iterator types that point to elements
		void erase (iterator first, iterator last)
		{
			if (empty())
				return ;
			while (first != last)
				erase(first++);
		}

		void swap (map& x)
		{
			_tree.swap(x._tree);
		}

		friend void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
		{
			y._tree.swap(x._tree);
		}

		void clear()
		{
			_tree.clear();
		}
	/*
	** -------------------------------------------------------------- OBESERVERS
	*/
		key_compare key_comp() const
		{
			return _comp;
		}
		
		class value_compare : std::binary_function<value_type, value_type, bool>
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
			protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
			return comp(x.first, y.first);
			}
		};

		value_compare value_comp() const
		{
			return value_compare(key_compare());
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

		bool	_faster_from_root(key_type insert_key, iterator position)
		{
			if (size() < 5) // arbitrary
				return true;
			if (position == end())
				position--;
			return size() < 2 || _position_is_opposite_way(insert_key, position->first);
		}

		bool	_position_is_opposite_way(key_type insert_key, key_type position_key)
		{
			key_type	root_key = _tree.get_root_key();
			bool		position_is_before_root = _comp(position_key, root_key);
			bool		position_is_after_root = _comp(root_key, position_key);
			bool		root_is_before_insert = _comp(root_key, insert_key);
			bool		root_is_after_insert = _comp(insert_key, root_key);

			if ((position_is_before_root && root_is_before_insert)
				|| (position_is_after_root && root_is_after_insert))
				return true;
			return (!root_is_after_insert && !root_is_before_insert); // insert_key = root_key
		}

};

}

#endif