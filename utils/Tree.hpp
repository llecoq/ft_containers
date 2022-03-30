/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:23:58 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/30 15:16:49 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "../iterators/RB_tree_iterator.hpp"

#include <iostream>

namespace ft
{

enum	e_child
{
	NO_CHILD = 0,
	ONE_CHILD = 1,
	TWO_CHILDREN = 2
};

template <class Pair>
struct t_node
{	
	bool		color;
	Pair		element;
	
	t_node		*parent;
	t_node		*left;
	t_node		*right;

	explicit t_node()
	:
		color(0),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	explicit t_node(Pair const &val)
	:
		color(0),
		element(val),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	~t_node()
	{
		// std::cout << "t_node destructor" << std::endl;
	}
};

template < class Key,
           class T,        
           class Compare,                     
           class Alloc,
		   class Iter
           >
class Tree
{
	public:

		typedef Key												key_type;
		typedef T												mapped_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;

		typedef	Iter											iterator;
		typedef ft::RB_tree_iterator<iterator>					RB_tree_iterator;

		typedef typename allocator_type::pointer				node_pointer;
		typedef typename allocator_type::reference				node_reference;
		typedef typename allocator_type::const_pointer			const_node_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef pair<key_type, mapped_type>						value_type;
		typedef t_node < value_type >							node;

		node_pointer											root_node;

	private:

		node_pointer											_begin_node;
	public :
		node_pointer											_end_node; // en public pour printTree
	private :
		allocator_type											_node_allocator;
		key_compare												_comp;
		size_type												_size;

		// RB_tree_iterator<Iter>									_iterator;

	public :

		// default
		explicit Tree (const key_compare & comp = key_compare(),
					const allocator_type& alloc = allocator_type())
		:
			root_node(NULL),
			_begin_node(root_node),
			_end_node(root_node),
			_node_allocator(alloc),
			_comp(comp),
			_size(0)
		{
			// std::cout << "tree default constructor" << std::endl;
		}

		Tree (const Tree& x)
		:
			root_node(NULL),
			_begin_node(root_node),
			_end_node(root_node),
			_node_allocator(x._node_allocator),
			_comp(x._comp),
			_size(0)	
		{
			std::cout << "tree copy constructor" << std::endl;
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
			_comp(comp),
			_size(0)
		{
			std::cout << "tree range constructor" << std::endl;
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
			// std::cout << "tree destructor" << std::endl;
			_destroy_from_root(root_node);
		}

	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		key_type	get_root_key() const
		{
			return root_node->element.first;
		}

		node_pointer	get_root_node()
		{
			return root_node;
		}

	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		node_pointer begin() {return _begin_node;}
		node_pointer end() {return _end_node;}

		node_pointer rbegin() {return _end_node;}
		node_pointer rend() {return _begin_node;}

	/*
	** ------------------------------------------------------------ CAPACITY
	*/
		bool empty() const
		{
			return (root_node == NULL);
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

		pair<node_pointer, bool> insert (const value_type& val)
		{
			return _insert_node(node(val), root_node);
		}

		pair<node_pointer, bool> insert (iterator position, const value_type& val)
		{
			RB_tree_iterator	tree_iter(position);
			node_pointer		current_position = tree_iter.base();
			node_pointer		parent = current_position->parent;

			if (position == end()
				|| _position_is_after_insert(current_position, val.first))
			{
				if (position == begin())
					return _insert_node(node(val), current_position->left, current_position);
				return _check_before_position(parent, val);
			}
			else if (_position_is_before_insert(current_position, val.first))
				return _check_after_position(parent, val);
			return _insert_node(node(val), root_node);
		}

		// void	erase(node_pointer &current_node)
		// {
		// 	size_type	number_of_children = _count_children(current_node);
		
		// 	switch (number_of_children)
		// 	{
		// 		case NO_CHILD:
		// 		{
		// 			if (current_node == _end_node)
		// 				return ;
		// 			_set_predecessor_pointer(current_node, NULL);
		// 			_delete_node(current_node);
		// 			break;
		// 		}
		// 		case ONE_CHILD:
		// 		{
		// 			node_pointer	child = _get_child(current_node);

		// 			_set_predecessor_pointer(current_node, child);
		// 			_delete_node(current_node);
		// 			break;
		// 		}
		// 		case TWO_CHILDREN:
		// 		{
		// 			node_pointer	successor = _find_successor(current_node->left); // va a gauche car a droite peut etre end_node

		// 			current_node->element = successor->element;
		// 			erase(successor);
		// 			break;
		// 		}
		// 	}
		// }

	/*

	** -------------------------------------------------------------- OPERATIONS
	*/

		node_pointer	find(const key_type &k)
		{
			return _find_key(k, root_node);
		}


	private :

		pair<node_pointer, bool> _insert_node (const node &new_node, node_pointer &current_node,
											node_pointer parent_node = NULL)
		{
			if (_empty_tree()) // empty tree
				return _set_new_node(new_node, current_node, parent_node);
			if (_empty_node(current_node))  // empty node
				return _set_new_node(new_node, current_node, parent_node);
			if (_same_key(new_node.element.first, current_node->element.first))
				return pair<node_pointer, bool>(current_node, false);
			if (_comp(new_node.element.first, current_node->element.first)) 
				return _insert_node(new_node, current_node->left, current_node); // insert left
			else
				return _insert_node(new_node, current_node->right, current_node); // insert right
		}

		pair<node_pointer, bool>	_check_before_position(node_pointer current_position, const value_type &val)
		{
			node_pointer	parent = current_position->parent;
				
			if (_position_is_root(current_position)
				|| _position_is_before_insert(current_position, val.first))
				return _insert_node(node(val), current_position, parent);
			return _check_before_position(parent, val);
		}

		pair<node_pointer, bool>	_check_after_position(node_pointer current_position, const value_type &val)
		{
			node_pointer	parent = current_position->parent;

			if (_position_is_root(current_position)
				|| _position_is_after_insert(current_position, val.first))
				return _insert_node(node(val), current_position, parent);
			return _check_after_position(parent, val);
		}

		bool	_position_is_root(node_pointer position)
		{
			return (position == root_node);
		}

		bool	_position_is_before_insert(node_pointer current_position, key_type insert_key)
		{
			return key_compare()(current_position->element.first, insert_key);
		}

		bool	_position_is_after_insert(node_pointer current_position, key_type insert_key)
		{
			return key_compare()(insert_key, current_position->element.first);
		}

		node_pointer	_find_successor(node_pointer current_node)
		{
			while (current_node->right != NULL)
				current_node = current_node->right;
			return current_node;
		}

		void	_delete_node(node_pointer &node)
		{
			if (node != _end_node)
				_size--;
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
		}

		node_pointer	_get_child(node_pointer	const &node)
		{
			return node->left ? node->left : node->right;
		}

		void	_set_predecessor_pointer(node_pointer &current_node, node_pointer child)
		{
			node_pointer	parent = current_node->parent;

			if (parent != NULL)
			{
				if (parent->left == current_node)
					parent->left = child;
				else
					parent->right = child;
				if (child != NULL)
					child->parent = parent;
				if (current_node == _begin_node)
					_begin_node = current_node->parent;
			}
			else
			{
				root_node = child; 
				if (child != NULL)
					child->parent = NULL;
				else     // begin_node with no child
				{
					_node_allocator.deallocate(_end_node, 1);
					_begin_node = _end_node = root_node = NULL;
				}
			}
		}

		size_type	_count_children(node_pointer node)
		{
			if (node->left == NULL && node->right == NULL)
				return 0;
			else if (node->left != NULL && node->right != NULL)
				return 2;
			return 1;
		}

		node_pointer	_find_key(const key_type &k, node_pointer &current_node)
		{
			if (_same_key(k, current_node->element.first))
				return (current_node);
			if (_comp(k, current_node->element.first) && current_node->left != NULL) 
				return _find_key(k, current_node->left); // _find_key left
			else if (current_node->right != NULL)
				return _find_key(k, current_node->right); // _find_key right
			return _end_node;
		}

		node_pointer	_create_node(const node& new_node)
		{
			node_pointer	tmp = _node_allocator.allocate(1);

			_node_allocator.construct(tmp, new_node);
			return (tmp);
		}

		pair<node_pointer, bool>	_set_new_node(const node &new_node, node_pointer &current_node,
													node_pointer const &parent_node)
		{
			current_node = _create_node(new_node);
			current_node->parent = parent_node;
			_set_begin_or_end(current_node);
			_size++;
			return pair<node_pointer, bool>(current_node, true);
		}

		void	_set_begin_or_end(node_pointer const &current_node)
		{
			if (current_node == root_node)
				_init_end_node();
			else if (_comp(_end_node->parent->element.first, current_node->element.first)) // new node is end
				_set_end_node(current_node);
			else if (_comp(current_node->element.first, _begin_node->element.first)) // new node is begin
				_begin_node = current_node;
		}

		bool	_same_key(key_type const &current_key, key_type const &new_key)
		{
			return (!_comp(current_key, new_key) && !_comp(new_key, current_key));
		}

		bool	_empty_node(node_pointer const &node)
		{
			return (node == NULL || node == _end_node);
		}
		
		bool	_empty_tree()
		{
			return (empty());
		}

		void	_init_end_node()
		{
				_end_node = _node_allocator.allocate(1);
				_end_node->right = NULL;
				_end_node->left = NULL;
				_end_node->parent = root_node;
				_begin_node = root_node;
				root_node->right = _end_node;
		}

		void	_set_end_node(node_pointer const &current_node)
		{
			current_node->right = _end_node;
			_end_node->parent = current_node;
		}

		void	_destroy_from_root(node_pointer &current_node)
		{
			if (current_node != NULL)
			{
				_destroy_from_root(current_node->left);
				_destroy_from_root(current_node->right);
				_node_allocator.destroy(current_node);
				_node_allocator.deallocate(current_node, 1);
			}
		}
};

}

#endif