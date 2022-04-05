/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:23:58 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/05 22:02:57 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

# include "../iterators/bidirectional_iterator.hpp"

#include "../iterators/RB_tree_iterator.hpp"
#include "../utils/utils.hpp"

#include <iostream>

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
		element(Pair()),
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

	explicit t_node(t_node const &x)
	:
		color(x.color),
		element(x.element),
		parent(NULL),
		left(NULL),
		right(NULL)
	{
		// std::cout << "t_node copy constructor" << std::endl;
	}

	t_node	&operator=(t_node const &rhs)
	{
		// std::cout << "t_node copy assignment constructor" << std::endl;

		color = rhs.color;
		element = rhs.element;
	
		// reset pointers
		parent = NULL;
		right = NULL;
		left = NULL;
		return *this;
	}

	~t_node()
	{
		// std::cout << "t_node destructor" << std::endl;
	}
};

enum	e_child
{
	NO_CHILD = 0,
	ONE_CHILD = 1,
	TWO_CHILDREN = 2
};

enum	e_bound
{
	LOWER = 0,
	UPPER = 1
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
		typedef typename allocator_type::pointer				node_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef pair<const key_type, mapped_type>				value_type;
		typedef ft::t_node < value_type >						t_node;

	private:

		typedef ft::RB_tree_iterator<iterator>					_RB_tree_iterator;

		node_pointer											_root_node;
		node_pointer											_begin_node;
		node_pointer											_end_node;
		allocator_type											_node_allocator;
		size_type												_size;

		friend void	printTree<t_node>(t_node *root, t_node *end);
		friend void	print2D<t_node>(t_node *root, int space, t_node *end);

	public :
		// default
		explicit Tree (const key_compare & comp = key_compare(),
					const allocator_type& alloc = allocator_type())
		:
			_root_node(NULL),
			_begin_node(_root_node),
			_end_node(_root_node),
			_node_allocator(alloc),
			_size(0)
		{
			(void)comp;
			// std::cout << "tree default constructor" << std::endl;
		}

		Tree (const Tree& x)
		:
			_root_node(NULL),
			_begin_node(_root_node),
			_end_node(_root_node),
			_node_allocator(x._node_allocator),
			_size(0)	
		{
			// std::cout << "tree copy constructor" << std::endl;
			// copy aaaaall
		}
	
		template <class InputIterator>
		Tree (InputIterator first, InputIterator last,
			const key_compare & comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		:
			_root_node(NULL),
			_begin_node(_root_node),
			_end_node(_root_node),
			_node_allocator(alloc),
			_size(0)
		{
			// std::cout << "tree range constructor" << std::endl;
			(void)first;
			(void)last;
			(void)comp;
		}

		Tree& operator= (const Tree& x)
		{
			clear();
			_pre_order_insert(_root_node, x._root_node, x._end_node);
			return *this;
		}

		void	_pre_order_insert(node_pointer &current_node, node_pointer node_to_copy,
									node_pointer copy_end_node, node_pointer parent_node = NULL)
		{
			if (node_to_copy != NULL && node_to_copy != copy_end_node)
			{
				_set_new_node(*node_to_copy, current_node, parent_node);
				_pre_order_insert(current_node->left, node_to_copy->left, copy_end_node, current_node);
				_pre_order_insert(current_node->right, node_to_copy->right, copy_end_node, current_node);
			}
		}

		// destructor
		~Tree ()
		{
			// std::cout << "tree destructor" << std::endl;
			_destroy_from_root(_root_node);
		}

	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		key_type	get_root_key() const
		{
			if (_root_node)
				return _root_node->element.first;
			else
				return 0;
		}

	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		node_pointer begin() {return _begin_node;}
		// node_pointer begin() const {return _begin_node;}
		node_pointer end() {return _end_node;}
		// node_pointer end() const {return _end_node;}

		node_pointer rbegin() {return _end_node;}
		// node_pointer rbegin() const {return _end_node;}
		node_pointer rend() {return _begin_node;}
		// node_pointer rend() const {return _begin_node;}

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
		pair<iterator, bool> insert (const value_type& val)
		{
			return _insert_node(t_node(val), _root_node);
		}

		pair<iterator, bool> insert (iterator position, const value_type& val)
		{
			node_pointer		current_position = _iterator_to_pointer(position);
			node_pointer		parent = current_position->parent;

			if (_position_is_after_insert(current_position, val.first))
				return _check_before_position(parent, val);
			else if (_position_is_before_insert(current_position, val.first))
				return _check_after_position(parent, val);
			return _insert_node(t_node(val), _root_node);
		}

		void	erase(iterator position)
		{
			node_pointer	node_to_erase = _iterator_to_pointer(position);

			_erase_node(node_to_erase);
		}

		void	swap (Tree &x)
		{
			t_tree_data<allocator_type>	tmp;

			_swap_data(tmp, *this);
			_swap_data(*this, x);
			_swap_data(x, tmp);
		}

		void clear()
		{
			_destroy_from_root(_root_node);
			_root_node = _end_node = _begin_node = NULL;
		}


	/*
	** -------------------------------------------------------------- OPERATIONS
	*/
		node_pointer	find (const key_type &k)
		{
			return _find_key(k, _root_node);
		}

		node_pointer	find (const key_type& k) const
		{
			return _find_key(k, _root_node);
		}


		size_type count (const key_type& k) const
		{
			if (find(k) == _end_node)
				return 0;
			return 1;
		}

		iterator lower_bound (const key_type& k)
		{
			return _find_bound(k, _root_node, LOWER);
		}

		// const_iterator lower_bound (const key_type& k) const
		// {
		// }

		iterator upper_bound (const key_type& k)
		{
			return _find_bound(k, _root_node, UPPER);
		}

		iterator	_find_bound(const key_type &k, node_pointer current_node, bool bound) const
		{
			if (current_node == _end_node)
				return _end_node;
			if (_same_key(k, current_node->element.first))
			{
				if (bound == LOWER)
					return current_node;
				else if (current_node->right != NULL)
					return _find_successor(current_node);
			}
			else if (key_compare()(k, current_node->element.first)) // key plus petite
			{
				if (current_node->left != NULL)
					return _find_bound(k, current_node->left, bound); // _find_bound left
				return current_node;
			} 
			else if (key_compare()(current_node->element.first, k)) // key plus grande
			{
				if (current_node->right != NULL)
					return _find_bound(k, current_node->right, bound); // _find_bound right
				return ++iterator(current_node);
			}  
			return _end_node;
		}

		void	print_tree()
		{
			printTree(_root_node, end());
		}

	private :

	/*
	** ------------------------------------------------------------ INSERT
	*/
		pair<iterator, bool> _insert_node (const t_node &new_node, node_pointer &current_node,
											node_pointer parent_node = NULL)
		{
			if (_empty_tree()) // empty tree
				return _set_new_node(new_node, current_node, parent_node);
			if (_empty_node(current_node))  // empty node
				return _set_new_node(new_node, current_node, parent_node);
			if (_same_key(new_node.element.first, current_node->element.first))
				return pair<node_pointer, bool>(current_node, false);
			if (key_compare()(new_node.element.first, current_node->element.first)) 
				return _insert_node(new_node, current_node->left, current_node); // insert left
			else
				return _insert_node(new_node, current_node->right, current_node); // insert right
		}

		pair<iterator, bool>	_set_new_node(const t_node &new_node, node_pointer &current_node,
													node_pointer const &parent_node)
		{
			current_node = _create_node(new_node);
			current_node->parent = parent_node;
			_set_begin_or_end(current_node);
			_size++;
			return pair<iterator, bool>(iterator(current_node), true);
		}

		void	_set_begin_or_end(node_pointer const &current_node)
		{
			if (current_node == _root_node)
				_init_end_node();
			else if (key_compare()(_end_node->parent->element.first, current_node->element.first)) // new node is end
				_set_end_node(current_node);
			else if (key_compare()(current_node->element.first, _begin_node->element.first)) // new node is begin
				_begin_node = current_node;
		}

		pair<iterator, bool>	_check_before_position(node_pointer current_position, const value_type &val)
		{
			node_pointer	parent = current_position->parent;
		
			if (current_position == _root_node
				|| _position_is_before_insert(current_position, val.first))
				return _insert_node(t_node(val), current_position, parent);
			return _check_before_position(parent, val);
		}

		pair<iterator, bool>	_check_after_position(node_pointer current_position, const value_type &val)
		{
			node_pointer	parent = current_position->parent;

			if (current_position == _root_node
				|| _position_is_after_insert(current_position, val.first))
				return _insert_node(t_node(val), current_position, parent);
			return _check_after_position(parent, val);
		}

		
	/*
	** ------------------------------------------------------------ ERASE
	*/
		void	_erase_node(node_pointer &current_node)
		{
			size_type	number_of_children = _count_children(current_node);
		
			switch (number_of_children)
			{
				case NO_CHILD:
				{
					if (current_node == _end_node)
						return ;
					_set_predecessor_pointer(current_node, NULL);
					_delete_node(current_node);
					break;
				}
				case ONE_CHILD:
				{
					node_pointer	child = _get_child(current_node);

					_set_predecessor_pointer(current_node, child);
					_delete_node(current_node);
					break;
				}
				case TWO_CHILDREN:
				{
					node_pointer	predecessor = _find_predecessor(current_node); // va à gauche car droite peut être end_node

					current_node->element = predecessor->element;
					erase(predecessor);
					break;
				}
			}
		}

		node_pointer	_find_successor(node_pointer current_node) const
		{
			current_node = current_node->right;
			
			while (current_node->left != NULL)
				current_node = current_node->left;
			return current_node;
		}

		node_pointer	_find_predecessor(node_pointer current_node) const
		{
			current_node = current_node->left;

			while (current_node->right != NULL)
				current_node = current_node->right;
			return current_node;
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
				_root_node = child; 
				if (child != NULL)
					child->parent = NULL;
				else     // begin_node with no child
				{
					_node_allocator.deallocate(_end_node, 1);
					_begin_node = _end_node = _root_node = NULL;
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

	/*
	** ------------------------------------------------------------ FIND
	*/
		node_pointer	_find_key(const key_type &k, node_pointer current_node) const
		{
			if (_same_key(k, current_node->element.first))
				return (current_node);
			if (key_compare()(k, current_node->element.first) && current_node->left != NULL) 
				return _find_key(k, current_node->left); // _find_key left
			else if (current_node->right != NULL)
				return _find_key(k, current_node->right); // _find_key right
			return _end_node;
		}


	/*
	** ------------------------------------------------------------ UTILS
	*/
		template <typename D, typename U>
		void	_swap_data(D &data, U &tmp)
		{
			data._root_node = tmp._root_node;
			data._end_node = tmp._end_node;
			data._begin_node = tmp._begin_node;
			data._size = tmp._size;
		}

		bool	_position_is_before_insert(node_pointer current_position, key_type insert_key)
		{
			return key_compare()(current_position->element.first, insert_key);
		}

		bool	_position_is_after_insert(node_pointer current_position, key_type insert_key)
		{
			return key_compare()(insert_key, current_position->element.first);
		}

		node_pointer	_iterator_to_pointer(iterator iter)
		{
			return _RB_tree_iterator(iter).base();
		}

		bool	_same_key(key_type const &current_key, key_type const &new_key) const
		{
			return (!key_compare()(current_key, new_key) && !key_compare()(new_key, current_key));
		}

		bool	_empty_node(node_pointer const &node)
		{
			return (node == NULL || node == _end_node);
		}

		node_pointer	_get_child(node_pointer	const &node)
		{
			return node->left ? node->left : node->right;
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
			_end_node->parent = _root_node;
			_begin_node = _root_node;
			_root_node->right = _end_node;
		}

		void	_set_end_node(node_pointer const &current_node)
		{
			current_node->right = _end_node;
			_end_node->parent = current_node;
		}

		node_pointer	_create_node(const t_node& new_node)
		{
			node_pointer	tmp = _node_allocator.allocate(1);

			_node_allocator.construct(tmp, new_node);
			return (tmp);
		}

		void	_delete_node(node_pointer &node)
		{
			if (node != _end_node)
				_size--;
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
		}
		
		void	_destroy_from_root(node_pointer &current_node)
		{
			if (current_node == _end_node)
				_node_allocator.deallocate(current_node, 1);
			else if (current_node != NULL)
			{
				_destroy_from_root(current_node->left);
				_destroy_from_root(current_node->right);
				_node_allocator.destroy(current_node);
				_node_allocator.deallocate(current_node, 1);
				_size--;
			}
			current_node = NULL;
		}
};

}

#endif