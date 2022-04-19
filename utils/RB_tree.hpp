/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:23:58 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/19 19:19:12 by llecoq           ###   ########.fr       */
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

template < class Key,
           class T,        
           class Compare,                     
           class Alloc,
		   class Iter
           >
class RB_tree
{
	public:

		typedef Key												key_type;
		typedef T												mapped_type;
		typedef Compare											key_compare;
		typedef Alloc											value_allocator;
		typedef	Iter											iterator;
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef value_type*										value_pointer;
		typedef ft::t_node < value_type >						t_node;
		typedef typename Alloc::template rebind<t_node>::other	node_allocator;
		typedef typename node_allocator::pointer				node_pointer;
		typedef ft::t_node_pointers < node_pointer >			t_node_pointers;
		typedef size_t											size_type;

	private:

		node_pointer											_root_node;
		node_pointer											_begin_node;
		node_pointer											_end_node;
		size_type												_size;

		friend void	printTree<t_node>(t_node* root, Trunk *prev, bool isLeft, t_node* end);

	public :
	
		// default
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
			// std::cout << "RB_tree default constructor" << std::endl;
		}

		RB_tree(const RB_tree& x)
		:
			_root_node(NULL),
			_begin_node(NULL),
			_end_node(_init_end_node()),
			_size(x._size)	
		{
			_pre_order_insert(_root_node, x._root_node, x._end_node);
			// std::cout << "RB_tree copy constructor" << std::endl;
		}

		RB_tree& operator=(const RB_tree& x)
		{
			clear();
			_pre_order_insert(_root_node, x._root_node, x._end_node);
			_size = x._size;
			return *this;
		}

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

		// destructor
		~RB_tree()
		{
			// std::cout << "RB_tree destructor" << std::endl;
			_destroy_from_root(_root_node);
		}

	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		key_type	get_root_key() const
		{
			if (_root_node)
				return _root_node->value->first;
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
		pair<iterator, bool> insert(const value_type& val)
		{
			return _insert_node(val, _root_node);
		}

		pair<iterator, bool> insert(iterator position, const value_type& val)
		{
			node_pointer		current_position = _iterator_to_pointer(position);
			node_pointer		parent = current_position->parent;

			if (_position_is_after_insert(current_position, val.first))
				return _check_before_position(parent, val);
			else if (_position_is_before_insert(current_position, val.first))
				return _check_after_position(parent, val);
			return _insert_node(val, _root_node);
		}

		void	erase(iterator position)
		{
			node_pointer	node_to_erase = _iterator_to_pointer(position);

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
			printTree(_root_node, NULL, false, end());
		}

	private :

	/*
	** ------------------------------------------------------------ INSERT
	*/
		pair<iterator, bool> _insert_node(const value_type &val, node_pointer &current_node,
											node_pointer parent_node = NULL)
		{
			if (_empty_tree()) // empty tree
				return _set_new_node(val, current_node, parent_node);
			if (_empty_node(current_node))  // empty node
				return _set_new_node(val, current_node, parent_node);
			if (_same_key(val.first, current_node->value->first))
				return pair<node_pointer, bool>(current_node, false);
			if (key_compare()(val.first, current_node->value->first)) 
				return _insert_node(val, current_node->left, current_node); // insert left
			else
				return _insert_node(val, current_node->right, current_node); // insert right
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
			else if (key_compare()(_end_node->parent->value->first, current_node->value->first)) // new node is end
				_set_end_node(current_node);
			else if (key_compare()(current_node->value->first, _begin_node->value->first)) // new node is begin
				_begin_node = current_node;
		}

		void	_init_begin_and_root_node(node_pointer const &current_node)
		{
				_begin_node = current_node;
				_begin_node->right = _end_node;
				_end_node->parent = _root_node;
		}

		pair<iterator, bool>	_check_before_position(node_pointer current_position, const value_type &val)
		{
			node_pointer	parent = current_position->parent;
		
			if (current_position == _root_node
				|| _position_is_before_insert(current_position, val.first))
				return _insert_node(val, current_position, parent);
			return _check_before_position(parent, val);
		}

		pair<iterator, bool>	_check_after_position(node_pointer current_position, const value_type &val)
		{
			node_pointer	parent = current_position->parent;

			if (current_position == _root_node
				|| _position_is_after_insert(current_position, val.first))
				return _insert_node(val, current_position, parent);
			return _check_after_position(parent, val);
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
					break;
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
			// _balance_after_insert(grand_parent_node, grand_parent_node->parent);
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
					break;
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
				if (key_compare()(child_node->value->first, parent_node->value->first)) // child compare less
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
					_set_predecessor_pointers(node_to_erase);
					// _balance_before_erase(node_to_erase);
					_delete_node(node_to_erase);
					break;
				case ONE_CHILD:
					_push_node_down(node_to_erase, _get_child(node_to_erase));
					_erase_node(node_to_erase);
					break;
				case TWO_CHILDREN:
					_push_node_down(node_to_erase, _find_predecessor(node_to_erase));
					_erase_node(node_to_erase);
					break;
			}
		}

		// void	_balance_before_erase(node_pointer current_node)
		// {
		// 	switch (_find_violation_type(current_node))
		// 	{
		// 		case /* PARENT RED (sibling black) */:
		// 			// parent->color = BLACK;
		// 			// sibling->color = RED;
		// 			// if (_red_violation(sibling))
		// 			//		_balance_after_insert(node_in_violation);
		// 			break;
		// 		case /* SIBLING RED (parent black) */:
		// 			// sibling->color = RED;
		// 			// if (_right_child(current_node))
		// 			// 		_rotate_right(sibling);
		// 			// else // left child
		// 			//		_rotate_left(sibling);
		// 			// sibling->color = RED;
		// 			// if (_red_violation(sibling))
		// 			//		_balande_after_insert(node_in_violation);
		// 			break;
		// 		case /* PARENT BLACK SIBLING BLACK */:
		// 			// sibling->color = RED;
		// 			// if (_red_violation(sibling))
		// 			// {
		// 			// 		_balance_after_insert(node_in_violation);
		// 			// 		if (node_in_violation->color == RED)
		// 			//			node_in_violation->color = BLACK
		// 			//		else
		// 			//			node_in_violation->parent->color = BLACK;
		// 			// }
		// 			// else
		// 			//		_balance_before_erase(current_node->parent);
		// 			break;
		// 	}
		// }

		void	_push_node_down(node_pointer node_to_erase, node_pointer replacing_node)
		{
			_swap_pointers(node_to_erase, replacing_node);
			_swap_node_colors(node_to_erase, replacing_node);
		}

		void	_swap_node_colors(node_pointer node_to_erase, node_pointer replacing_node)
		{
			int	node_to_erase_color = node_to_erase->color;

			if (node_to_erase->color == replacing_node->color == BLACK)
				node_to_erase->color = DOUBLE_BLACK;
			else
			{
				node_to_erase->color = replacing_node->color;
				replacing_node->color = node_to_erase_color;
			}
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
			{
				_assign_new_parent(node_to_erase, replacing_node_data.parent);
				_assign_new_parent(node_to_erase->right, node_to_erase);
				_assign_new_parent(node_to_erase->left, node_to_erase);
			}
			else
			{
				// parent deja link
				if (node_to_erase->left != NULL)
					node_to_erase->left->parent = node_to_erase;
				if (node_to_erase->right != NULL)
					node_to_erase->right->parent = node_to_erase;
			}
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
			else if (node_to_erase == _root_node)// node_to_erase == _root_node
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



	/*
	** ------------------------------------------------------------ FIND
	*/
		node_pointer	_find_key(const key_type &k, node_pointer current_node) const
		{
			if (current_node == _end_node)
				return _end_node;
			if (_same_key(k, current_node->value->first))
				return (current_node);
			if (key_compare()(k, current_node->value->first) && current_node->left != NULL) 
				return _find_key(k, current_node->left); // _find_key left
			else if (current_node->right != NULL)
				return _find_key(k, current_node->right); // _find_key right
			return _end_node;
		}

		iterator	_find_bound(const key_type &k, node_pointer current_node, bool bound) const
		{
			if (current_node == _end_node)
				return _end_node;
			if (_same_key(k, current_node->value->first))
			{
				if (bound == LOWER)
					return current_node;
				else if (current_node->right != NULL)
					return _find_successor(current_node);
			}
			else if (key_compare()(k, current_node->value->first)) // key plus petite
			{
				if (current_node->left != NULL)
					return _find_bound(k, current_node->left, bound); // _find_bound left
				return current_node;
			}
			else if (key_compare()(current_node->value->first, k)) // key plus grande
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
	
		bool	_position_is_before_insert(node_pointer current_position, key_type insert_key)
		{
			return key_compare()(current_position->value->first, insert_key);
		}

		bool	_position_is_after_insert(node_pointer current_position, key_type insert_key)
		{
			return key_compare()(insert_key, current_position->value->first);
		}

		node_pointer	_iterator_to_pointer(iterator iter)
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
			node_allocator().construct(_end_node, t_node());
			_end_node->value = value_allocator().allocate(1);
			_end_node->right = NULL;
			_end_node->left = NULL;
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

			node_allocator().construct(tmp, t_node());
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
};

}	// namespace ft

#endif