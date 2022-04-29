/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:23:58 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/29 13:44:17 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "bidirectional_iterator.hpp"
#include "utils.hpp"
#include "node.hpp"

# include <iostream>

namespace ft
{

template < class Node,       
           class Compare,                     
           class Alloc,
		   class Iter
           >
class RB_tree
{
	public:

		typedef Node												node_type;
		typedef Compare												key_compare;
		typedef Alloc												value_allocator;
		typedef	Iter												iterator;
		typedef typename node_type::key_type						key_type;
		typedef typename node_type::value_type						value_type;
		typedef typename node_type::value_pointer					value_pointer;
		typedef typename Alloc::template rebind<node_type>::other	node_allocator;
		typedef typename node_type::node_pointer					node_pointer;
		typedef ft::t_node_pointers < node_pointer >				t_node_pointers;
		typedef size_t												size_type;

	private:

		node_pointer												_root_node;
		node_pointer												_begin_node;
		node_pointer												_end_node;
		size_type													_size;

	public :
	
		explicit RB_tree(const key_compare & comp = key_compare(),
					const value_allocator& alloc = value_allocator())
		:
			_root_node(NULL),
			_begin_node(NULL),
			_end_node(_init_end_node()),
			_size(0)
		{
			(void)comp;
			(void)alloc;
		}

		RB_tree(const RB_tree& x)
		:
			_root_node(NULL),
			_begin_node(NULL),
			_end_node(_init_end_node()),
			_size(x._size)	
		{
			_pre_order_insert(_root_node, x._root_node, x._end_node);
		}

		RB_tree& operator=(const RB_tree& x)
		{
			clear();
			_pre_order_insert(_root_node, x._root_node, x._end_node);
			_size = x._size;
			return *this;
		}

		~RB_tree()
		{
			_destroy_from_root(_root_node);
		}

	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		key_type	get_root_key() const
		{
			if (_root_node)
				return _root_node->get_key();
			else
				return 0;
		}

	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		node_pointer begin() {return _begin_node;}
		node_pointer begin() const {return _begin_node;}
		node_pointer end() {return _end_node;}
		node_pointer end() const {return _end_node;}
		node_pointer rbegin() {return _end_node;}
		node_pointer rbegin() const {return _end_node;}
		node_pointer rend() {return _begin_node;}
		node_pointer rend() const {return _begin_node;}

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
			return (node_allocator().max_size());
		}

	/*
	** ------------------------------------------------------------ MODIFIERS
	*/
		pair<iterator, bool> insert(const value_type& val, key_type key)
		{
			return _insert_node(val, key, _root_node);
		}

		pair<iterator, bool> insert(iterator position, const value_type& val, key_type key)
		{
			node_pointer		current_position = _iterator_to_node_pointer(position);
			node_pointer		parent = current_position->parent;

			if (position == _root_node)
				return _insert_node(val, key, _root_node);
			if (_current_position_is_after_insert(current_position, key))
				return _check_before_position(parent, val, key);
			else // iterator position is before the node to insert
				return _check_after_position(parent, val, key);
		}

		void	erase(iterator position)
		{
			node_pointer	node_to_erase = _iterator_to_node_pointer(position);

			_erase_node(node_to_erase);
			if (_empty_tree())
				clear();
		}

		void	swap(RB_tree &x)
		{
			t_tree_data<node_allocator>	tmp;

			_swap_data(tmp, *this);
			_swap_data(*this, x);
			_swap_data(x, tmp);
		}

		void clear()
		{
			_destroy_from_root(_root_node);
			_init_end_node();
		}


	/*
	** -------------------------------------------------------------- OPERATIONS
	*/
		node_pointer	find(const key_type &k)
		{
			return _find_key(k, _root_node);
		}

		node_pointer	find(const key_type& k) const
		{
			return _find_key(k, _root_node);
		}

		size_type count(const key_type& k) const
		{
			if (find(k) == _end_node)
				return 0;
			return 1;
		}

		iterator lower_bound(const key_type& k)
		{
			return _find_bound(k, _root_node, LOWER);
		}

		iterator upper_bound(const key_type& k)
		{
			return _find_bound(k, _root_node, UPPER);
		}

		void	print_tree()
		{
			_print_tree(_root_node, NULL, false, end());
		}

	private :

	/*
	** ------------------------------------------------------------ INSERT
	*/

		void	_pre_order_insert(node_pointer &current_node, node_pointer node_to_copy,
									node_pointer copy_end_node, node_pointer parent_node = NULL)
		{
			if (node_to_copy != NULL && node_to_copy != copy_end_node)
			{
				current_node = _create_node(*node_to_copy->value);
				current_node->parent = parent_node;
				current_node->color = node_to_copy->color;
				_set_begin_or_end(current_node);
				_pre_order_insert(current_node->left, node_to_copy->left, copy_end_node, current_node);
				_pre_order_insert(current_node->right, node_to_copy->right, copy_end_node, current_node);
			}
		}

		pair<iterator, bool> _insert_node(const value_type &val, key_type key,
					node_pointer &current_node, node_pointer parent_node = NULL)
		{
			if (_empty_tree()) // empty tree
				return _set_new_node(val, current_node, parent_node);
			if (_empty_node(current_node))  // empty node
				return _set_new_node(val, current_node, parent_node);
			if (_same_key(key, current_node->get_key()))
				return pair<node_pointer, bool>(current_node, false);
			if (key_compare()(key, current_node->get_key())) 
				return _insert_node(val, key, current_node->left, current_node); // insert left
			else
				return _insert_node(val, key, current_node->right, current_node); // insert right
		}

		pair<iterator, bool>	_set_new_node(const value_type &val, node_pointer &current_node,
																node_pointer const &parent_node)
		{
			current_node = _create_node(val);
			current_node->parent = parent_node;
			_set_begin_or_end(current_node);
			_balance_after_insert(current_node, parent_node);
			_root_node->color = BLACK;
			_size++;
			return pair<iterator, bool>(iterator(current_node), true);
		}

		void	_set_begin_or_end(node_pointer const &current_node)
		{
			if (current_node == _root_node)
				_init_begin_and_root_node(current_node);
			else if (key_compare()(_end_node->parent->get_key(), current_node->get_key())) // new node is end
				_set_end_node(current_node);
			else if (key_compare()(current_node->get_key(), _begin_node->get_key())) // new node is begin
				_begin_node = current_node;
		}

		void	_init_begin_and_root_node(node_pointer const &current_node)
		{
				_begin_node = current_node;
				_begin_node->right = _end_node;
				_end_node->parent = _root_node;
		}

		pair<iterator, bool>	_check_before_position(node_pointer current_position,
												const value_type &val, key_type key)
		{
			node_pointer	parent = current_position->parent;
		
			if (current_position == _root_node
				|| _current_position_is_before_insert(current_position, key))
				return _insert_node(val, key, current_position, parent);
			return _check_before_position(parent, val, key);
		}

		pair<iterator, bool>	_check_after_position(node_pointer current_position, 
												const value_type &val, key_type key)
		{
			node_pointer	parent = current_position->parent;

			if (current_position == _root_node
				|| _current_position_is_after_insert(current_position, key))
				return _insert_node(val, key, current_position, parent);
			return _check_after_position(parent, val, key);
		}

	/*
	** --------------------------------------------------- SELF-BALANCING INSERT
	*/
		void	_balance_after_insert(node_pointer current_node, node_pointer parent_node)
		{
			if (current_node == _root_node || parent_node->color == BLACK)
				return;
			switch (_find_insert_case(current_node, parent_node))
			{
				case LEFT_UNCLE_IS_RED:
					_reset_node_colors(current_node, LEFT_UNCLE_IS_RED);
					_balance_after_insert(parent_node->parent, parent_node->parent->parent);
					break;
				case RIGHT_UNCLE_IS_RED:
					_reset_node_colors(current_node, RIGHT_UNCLE_IS_RED);
					_balance_after_insert(parent_node->parent, parent_node->parent->parent);
					break;
				case INNER_LEFT_CHILD:
					_rotate_right(current_node, INNER_LEFT_CHILD);
				case OUTER_RIGHT_CHILD:
					_rotate_left(current_node->parent, OUTER_RIGHT_CHILD);
					break;
				case INNER_RIGHT_CHILD:
					_rotate_left(current_node, INNER_RIGHT_CHILD);
				case OUTER_LEFT_CHILD:
					_rotate_right(current_node->parent, OUTER_LEFT_CHILD);
			}
		}

		void	_reset_node_colors(node_pointer current_node, int insert_case)
		{
			node_pointer	uncle_node = NULL;
			node_pointer	grand_parent_node = current_node->parent->parent;
			
			if (insert_case == LEFT_UNCLE_IS_RED)
				uncle_node = grand_parent_node->left;
			else // insert case == RIGHT_UNCLE_IS_RED
				uncle_node = grand_parent_node->right;
			current_node->parent->color = BLACK;
			uncle_node->color = BLACK;
			grand_parent_node->color = RED;
		}

		void	_rotate_right(node_pointer &current_node, int insert_case)
		{
			node_pointer	new_right_child_node = current_node->parent;
			node_pointer	new_parent_node = current_node->parent->parent; // can be NULL
			node_pointer	new_grand_child_node = current_node->right; // can be NULL

			_assign_new_parent(current_node, new_parent_node);
			_assign_new_parent(new_right_child_node, current_node);
			_assign_new_parent(new_grand_child_node, new_right_child_node, ROTATE_RIGHT);
			if (new_right_child_node == _root_node)
				_root_node = current_node;
			_process_insert_case(current_node, insert_case);
		}

		void	_rotate_left(node_pointer &current_node, int insert_case)
		{
			node_pointer	new_left_child_node = current_node->parent;
			node_pointer	new_parent_node = current_node->parent->parent; // can be NULL
			node_pointer	new_grand_child_node = current_node->left; // can be NULL

			_assign_new_parent(current_node, new_parent_node);
			_assign_new_parent(new_left_child_node, current_node);
			_assign_new_parent(new_grand_child_node, new_left_child_node, ROTATE_LEFT);
			if (new_left_child_node == _root_node)
				_root_node = current_node;
			_process_insert_case(current_node, insert_case);
		}

		void	_process_insert_case(node_pointer &current_node, int insert_case)
		{
			switch (insert_case)
			{
				case INNER_LEFT_CHILD:
					current_node = current_node->right;
					break;
				case INNER_RIGHT_CHILD:
					current_node = current_node->left;
					break;
				case OUTER_LEFT_CHILD:
					current_node->color = BLACK;
					current_node->right->color = RED;
					break;
				case OUTER_RIGHT_CHILD:
					current_node->color = BLACK;
					current_node->left->color = RED;
			}
		}

		void	_assign_new_parent(node_pointer child_node,
					node_pointer parent_node, int insert_case = 0)
		{
			if (child_node != NULL)
			{
				child_node->parent = parent_node;
				_link_parent_and_child(child_node, parent_node);
			}	  // child_node == NULL
			else if (insert_case == ROTATE_LEFT)
				parent_node->right = NULL;
			else  // insert_case == ROTATE_RIGHT
				parent_node->left = NULL;
		}

		void	_link_parent_and_child(node_pointer child_node, node_pointer parent_node)
		{
			if (parent_node != NULL)
			{
				if (key_compare()(child_node->get_key(), parent_node->get_key())) // child compare less
					parent_node->left = child_node;
				else // child compare more
					parent_node->right = child_node;
			}
		}

		int	_find_insert_case(node_pointer current_node, node_pointer parent_node)
		{
			node_pointer	grand_parent_node = parent_node->parent;

			if (_is_right_child(parent_node) == true) // parent is right child
			{
				if (grand_parent_node->left != NULL
					&& grand_parent_node->left->color == RED)
					return LEFT_UNCLE_IS_RED;
				if (_is_right_child(current_node) == true) // current_node is right child
					return OUTER_RIGHT_CHILD;
				return INNER_LEFT_CHILD;
			}
			else // parent is left child
			{
				if (grand_parent_node->right != NULL
					&& grand_parent_node->right->color == RED)
					return RIGHT_UNCLE_IS_RED;
				if (_is_right_child(current_node) == true) // current_node is right child
					return INNER_RIGHT_CHILD;
				return OUTER_LEFT_CHILD;
			}
		}
		
	/*
	** ------------------------------------------------------------ ERASE
	*/
		void	_erase_node(node_pointer node_to_erase)
		{
			switch (_count_children(node_to_erase))
			{
				case NO_CHILD:
					_balance_before_erase(node_to_erase);
					_set_predecessor_pointers(node_to_erase);
					_delete_node(node_to_erase);
					break;
				case ONE_CHILD:
					_push_node_down(node_to_erase, _get_child(node_to_erase));
					_erase_node(node_to_erase);
					break;
				case TWO_CHILDREN:
					_push_node_down(node_to_erase, _find_predecessor(node_to_erase));
					_erase_node(node_to_erase);
			}
		}

		void	_push_node_down(node_pointer node_to_erase, node_pointer replacing_node)
		{
			_swap_pointers(node_to_erase, replacing_node);
			_swap_node_colors(node_to_erase, replacing_node);
		}

		void	_swap_node_colors(node_pointer node_to_erase, node_pointer replacing_node)
		{
			int	node_to_erase_color = node_to_erase->color;

			node_to_erase->color = replacing_node->color;
			replacing_node->color = node_to_erase_color;
		}

		// needing redesign
		void	_swap_pointers(node_pointer node_to_erase, node_pointer replacing_node)
		{
			t_node_pointers	replacing_node_data(replacing_node);

			_assign_new_parent(replacing_node, node_to_erase->parent);
			_assign_children(replacing_node, node_to_erase);

			// assigning node_to_erase
			node_to_erase->left = replacing_node_data.left;
			node_to_erase->right = replacing_node_data.right;
			if (replacing_node_data.parent != node_to_erase)
				_assign_new_parent(node_to_erase, replacing_node_data.parent);
			if (node_to_erase->left != NULL)
				node_to_erase->left->parent = node_to_erase;
			if (node_to_erase->right != NULL)
				node_to_erase->right->parent = node_to_erase;
			if (node_to_erase == _root_node)
				_root_node = replacing_node;
		}

		void	_assign_children(node_pointer parent_node, node_pointer new_children)
		{
			node_pointer	right_child = new_children->right;
			node_pointer	left_child = new_children->left;

			if (right_child == parent_node)
				right_child = new_children;
			else if (left_child == parent_node)
				left_child = new_children;
			parent_node->right = right_child;
			parent_node->left = left_child;
			if (right_child != NULL)
				right_child->parent = parent_node;
			if (left_child != NULL)
				left_child->parent = parent_node;
		}

		void	_set_predecessor_pointers(node_pointer node_to_erase)
		{
			node_pointer	parent = node_to_erase->parent;

			if (parent != NULL)
			{
				if (parent->left == node_to_erase)
					parent->left = NULL;
				else
					parent->right = NULL;
				if (node_to_erase == _begin_node)
					_begin_node = parent;
				if (node_to_erase->right == _end_node)
					parent->right = _end_node;
			}
			else if (node_to_erase == _root_node)
			{
				_root_node = NULL; 
				_begin_node = _end_node;
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

		size_type	_count_children(node_pointer node)
		{
			if (node->left == NULL
				&& (node->right == NULL || node->right == _end_node))
				return NO_CHILD;
			else if (node->left != NULL && node->right != NULL)
				return TWO_CHILDREN;
			return ONE_CHILD;
		}
	
	/*
	** ---------------------------------------------------- SELF-BALANCING ERASE
	*/
		void	_balance_before_erase(node_pointer current_node)
		{
			node_pointer	sibling_node = _get_sibling(current_node);

			switch (_find_violation_type(current_node))
			{
				case NO_VIOLATION:
					break;
				case PARENT_IS_RED:
					_recolor_nodes(sibling_node, PARENT_IS_RED);
					_fix_red_violation(sibling_node);
					break;
				case SIBLING_IS_RED:
					_rotate_sibling_node(current_node, sibling_node);
					_fix_red_violation(sibling_node);
					break;
				case PARENT_AND_SIBLING_ARE_BLACK:
					_recolor_nodes(sibling_node);
					if (_fix_red_violation(sibling_node) == NULL)
						_balance_before_erase(current_node->parent);
			}
		}

		void	_recolor_nodes(node_pointer sibling_node, int balance_case = 0)
		{
			if (sibling_node == NULL)
				return ;
			switch (balance_case)
			{
				case PARENT_IS_RED:
					sibling_node->parent->color = BLACK;
				default:
					sibling_node->color = RED;
			}
		}

		void	_rotate_sibling_node(node_pointer current_node, node_pointer &sibling_node)
		{
			if (_is_right_child(current_node) == true)
			{
				sibling_node = sibling_node->right;
				_rotate_left(sibling_node, INNER_RIGHT_CHILD);
				_rotate_right(sibling_node->parent, OUTER_LEFT_CHILD);
				sibling_node->parent->right->color = BLACK;
				sibling_node->left->color = RED;
				sibling_node->color = BLACK;
				sibling_node = sibling_node->left;
			}
			else // current_node is left child
			{
				sibling_node = sibling_node->left;
				_rotate_right(sibling_node, INNER_LEFT_CHILD);
				_rotate_left(sibling_node->parent, OUTER_RIGHT_CHILD);
				sibling_node->parent->left->color = BLACK;
				sibling_node->right->color = RED;
				sibling_node->color = BLACK;
				sibling_node = sibling_node->right;
			}
		}

		node_pointer	_fix_red_violation(node_pointer current_node)
		{
			node_pointer	right_child_violation = _check_right_child(current_node);
			node_pointer	left_child_violation = _check_left_child(current_node);
			
			if (right_child_violation != NULL)
				_balance_after_insert(right_child_violation, right_child_violation->parent);
			if (left_child_violation != NULL)
				_balance_after_insert(left_child_violation, left_child_violation->parent);
			if (left_child_violation != NULL || right_child_violation != NULL)
			{
				if (current_node->right)
					current_node->right->color = BLACK;
				if (current_node->left)
					current_node->left->color = BLACK;
				_root_node->color = BLACK;
			}
			if (right_child_violation != NULL)
				return right_child_violation;
			else if (left_child_violation != NULL)
				return left_child_violation;
			else
				return NULL;
		}

		node_pointer	_check_right_child(node_pointer current_node)
		{
			if (current_node == NULL)
				return NULL;
			if (current_node->right != NULL && current_node->right->color == RED)
				return current_node->right;
			else
				return NULL;
		}

		node_pointer	_check_left_child(node_pointer current_node)
		{
			if (current_node == NULL)
				return NULL;
			if (current_node->left != NULL && current_node->left->color == RED)
				return current_node->left;
			else
				return NULL;
		}

		node_pointer	_get_sibling(node_pointer current_node)
		{
			if (current_node == _root_node || current_node == NULL)
				return NULL;
			if (_is_right_child(current_node) == true)
				return current_node->parent->left;
			else
				return current_node->parent->right;
		}

		int	_find_violation_type(node_pointer current_node)
		{
			node_pointer	sibling_node = _get_sibling(current_node);

			if (current_node == _root_node 
				|| current_node == NULL || current_node->color == RED)
				return	NO_VIOLATION;
			else if (current_node->parent->color == RED)
				return PARENT_IS_RED;
			else if (sibling_node != NULL && sibling_node->color == RED)
				return SIBLING_IS_RED;
			else
				return PARENT_AND_SIBLING_ARE_BLACK;
		}

	/*
	** ------------------------------------------------------------ FIND
	*/
		node_pointer	_find_key(const key_type &k, node_pointer current_node) const
		{
			if (current_node == _end_node)
				return _end_node;
			if (_same_key(k, current_node->get_key()))
				return (current_node);
			if (key_compare()(k, current_node->get_key()) && current_node->left != NULL) 
				return _find_key(k, current_node->left); // _find_key left
			else if (current_node->right != NULL)
				return _find_key(k, current_node->right); // _find_key right
			return _end_node;
		}

		iterator	_find_bound(const key_type &k, node_pointer current_node, bool bound) const
		{
			if (current_node == _end_node)
				return _end_node;
			if (_same_key(k, current_node->get_key()))
			{
				if (bound == LOWER)
					return current_node;
				else
					return ++iterator(current_node);
			}
			else if (key_compare()(k, current_node->get_key())) // key plus petite
			{
				if (current_node->left != NULL)
					return _find_bound(k, current_node->left, bound); // _find_bound left
				return current_node;
			}
			else if (key_compare()(current_node->get_key(), k)) // key plus grande
			{
				if (current_node->right != NULL)
					return _find_bound(k, current_node->right, bound); // _find_bound right
				return ++iterator(current_node);
			}  
			return _end_node;
		}

	/*
	** ------------------------------------------------------------------- UTILS
	*/
		template <typename D, typename U>
		void	_swap_data(D &data, U &tmp)
		{
			data._root_node = tmp._root_node;
			data._end_node = tmp._end_node;
			data._begin_node = tmp._begin_node;
			data._size = tmp._size;
		}

		bool	_is_right_child(node_pointer current_node)
		{
			return (current_node->parent->right == current_node);
		}
	
		bool	_current_position_is_before_insert(node_pointer current_position, key_type insert_key)
		{
			return key_compare()(current_position->get_key(), insert_key);
		}

		bool	_current_position_is_after_insert(node_pointer current_position, key_type insert_key)
		{
			return key_compare()(insert_key, current_position->get_key());
		}

		node_pointer	_iterator_to_node_pointer(iterator iter)
		{
			return iter._base;
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

		node_pointer	_init_end_node()
		{
			_end_node = node_allocator().allocate(1);
			node_allocator().construct(_end_node, node_type());
			_end_node->value = value_allocator().allocate(1);
			_end_node->color = BLACK;
			_begin_node = _end_node;
			return _end_node;
		}

		void	_set_end_node(node_pointer const &current_node)
		{
			current_node->right = _end_node;
			_end_node->parent = current_node;
		}

		node_pointer	_create_node(const value_type &val)
		{
			node_pointer	tmp = node_allocator().allocate(1);

			node_allocator().construct(tmp, node_type());
			tmp->value = value_allocator().allocate(1);
			value_allocator().construct(tmp->value, val);
			return (tmp);
		}

		void	_delete_node(node_pointer &node)
		{
			if (node != _end_node)
			{
				_size--;
				value_allocator().destroy(node->value);
			}
			value_allocator().deallocate(node->value, 1);
			node_allocator().destroy(node);
			node_allocator().deallocate(node, 1);
			node = NULL;
		}
		
		void	_destroy_from_root(node_pointer &current_node)
		{
			if (_empty_tree())
				_delete_node(_end_node);
			else if (current_node == _end_node)
				_delete_node(current_node);
			else if (current_node != NULL)
			{
				_destroy_from_root(current_node->left);
				_destroy_from_root(current_node->right);
				_delete_node(current_node);
			}
		}
	// --------------------------------------------- print tree
		struct Trunk
		{
			Trunk 		*prev;
			std::string str;
		
			Trunk(Trunk *prev, std::string str)
			{
				this->prev = prev;
				this->str = str;
			}
		};
		
		// Helper function to print branches of the binary tree
		void _show_trunks(Trunk *p)
		{
			if (p == NULL) {
				return;
			}
		
			_show_trunks(p->prev);
			std::cout << p->str;
		}
		
		void _print_tree(node_pointer root, Trunk *prev, bool is_left, node_pointer end)
		{
			if (root == NULL || root == end) {
				return;
			}
		
			std::string prev_str = "    ";
			Trunk *trunk = new Trunk(prev, prev_str);
		
			_print_tree(root->right, trunk, true, end);
		
			if (!prev) {
				trunk->str = "———";
			}
			else if (is_left)
			{
				trunk->str = ".———";
				prev_str = "   |";
			}
			else {
				trunk->str = "`———";
				prev->str = prev_str;
			}
		
			_show_trunks(trunk);
			if (root->color == 0)
				std::cout << " " << RED_COLOR << root->get_key() << RESET << std::endl;
			else
				std::cout << " " << root->get_key() << std::endl;
			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   |";
		
			_print_tree(root->left, trunk, false, end);
			delete	trunk;
		}

};

}	// namespace ft

#endif