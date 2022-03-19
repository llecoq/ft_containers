/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:23:58 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/19 16:47:20 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "pair.hpp"

namespace ft
{

template <class Pair>
struct t_node
{	
	bool		color;
	Pair		data;
	
	t_node		*parent;
	t_node		*left;
	t_node		*right;

	explicit t_node(Pair const &val)
	:
		color(0),
		data(val),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	~t_node(){}
};

template < class Key,
           class T,        
           class Compare,                     
           class Alloc
           >
class Tree
{
	public:

		typedef Key												key_type;
		typedef T												mapped_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;

		typedef typename allocator_type::pointer				node_pointer;
		typedef typename allocator_type::const_pointer			const_node_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef t_node < pair<key_type, mapped_type> >			t_node;
		typedef pair<key_type, mapped_type>						value_type;

		node_pointer											root_node;

	private:

		node_pointer											_begin_node;
		node_pointer											_end_node;
		allocator_type											_node_allocator;
		key_compare												_comparator;
		size_type												_size;

	public :

		// default
		explicit Tree (const key_compare & comp = key_compare(),
					const allocator_type& alloc = allocator_type())
		:
			root_node(NULL),
			_begin_node(root_node),
			_end_node(root_node),
			_node_allocator(alloc),
			_comparator(comp),
			_size(0)
		{}

		Tree (const Tree& x)
		:
			root_node(NULL),
			_begin_node(root_node),
			_end_node(root_node),
			_node_allocator(x._node_allocator),
			_comparator(x._comparator),
			_size(0)	
		{
			// copy aaaaall
		}
	
		template <class InputIterator>
		Tree (InputIterator first, InputIterator last,
			const key_compare & comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		:
			root_node(NULL),
			_begin_node(root_node),
			_end_node(root_node),
			_node_allocator(alloc),
			_comparator(comp),
			_size(0)
		{
			(void)first;
			(void)last;
		}

		Tree& operator= (const Tree& x)
		{
			(void)x;
		}

		// destructor
		~Tree ()
		{
			// destruct 
			// deallocate
		}
	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		node_pointer begin() {return _begin_node;}
		node_pointer end() {return _end_node;}

	/*
	** ------------------------------------------------------------ CAPACITY
	*/
		bool empty() const
		{
			return (_size == 0);
		}

		size_type size() const
		{
			return (_size);
		}

		size_type max_size() const
		{
			return (_node_allocator.max_size());
		}

	/*
	** ------------------------------------------------------------ ELEMENT ACCESS
	*/

	/*
	** ------------------------------------------------------------ MODIFIERS
	*/
		pair<node_pointer, bool> insert (const t_node &new_node, node_pointer &current_node)
		{
			if (root_node == NULL)  // empty tree
			{
				root_node = _create_node(new_node);
				_begin_node = _end_node = root_node;
				return pair<node_pointer, bool>(root_node, true);
			}
			if (current_node == NULL)  // empty
			{
				current_node = _create_node(new_node);
				if (new_node.data.first > _end_node->data.first)
					_end_node = current_node;
				else if (new_node.data.first < _begin_node->data.first)
					_begin_node = current_node;
				return pair<node_pointer, bool>(current_node, true);
			}
			if (new_node.data.first == current_node->data.first) // do nothing
				return pair<node_pointer, bool>(current_node, false);
			if (new_node.data.first < current_node->data.first) // insert left
				return insert(new_node, current_node->left);
			else
				return insert(new_node, current_node->right); // insert right
			return pair<node_pointer, bool>(root_node, false);
		}

	private :

		node_pointer	_create_node(const t_node& new_node)
		{
			node_pointer	tmp = _node_allocator.allocate(1);

			_node_allocator.construct(tmp, new_node);
			return (tmp);
		}

};

}

#endif