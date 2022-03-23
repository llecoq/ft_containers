/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:23:58 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/23 11:43:44 by llecoq           ###   ########.fr       */
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

	~t_node() {std::cout << "t_node destructor" << std::endl;}
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
	public :
		node_pointer											_end_node;
	private :
		allocator_type											_node_allocator;
		key_compare												_comp;
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
			_comp(comp),
			_size(0)
		{std::cout << "tree default constructor" << std::endl;}

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
			std::cout << "tree destructor" << std::endl;

			_destroy_from_root(root_node);
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
		pair<node_pointer, bool> insert (const t_node &new_node, node_pointer &current_node,
											node_pointer parent_node = NULL)
		{
			if (_empty_tree()) // empty tree
				return _set_new_node(new_node, current_node, parent_node);
			if (_empty_node(current_node))  // empty node
				return _set_new_node(new_node, current_node, parent_node);
			if (_same_key(new_node.element.first, current_node->element.first))
				return pair<node_pointer, bool>(current_node, false);
			parent_node = current_node;
			if (_comp(new_node.element.first, current_node->element.first)) 
				return insert(new_node, current_node->left); // insert left
			else
				return insert(new_node, current_node->right); // insert right
		}

	private :

		node_pointer	_create_node(const t_node& new_node)
		{
			node_pointer	tmp = _node_allocator.allocate(1);

			_node_allocator.construct(tmp, new_node);
			return (tmp);
		}

		pair<node_pointer, bool>	_set_new_node(const t_node &new_node, node_pointer &current_node,
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