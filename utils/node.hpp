/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:54 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/29 13:52:57 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace	ft
{

enum	e_colors
{
	RED,
	BLACK
};

template <class Pair, class T>
struct t_node_map
{
	typedef	T				key_type;
	typedef Pair			value_type;
	typedef Pair*			value_pointer;
	typedef t_node_map*		node_pointer;

	bool					color;
	value_pointer			value;
		
	node_pointer			parent;
	node_pointer			left;
	node_pointer			right;

	//	parent, left and right shouldn't be initiated to NULL because incrementing iterator to end() 
	//	or decrementing iterator to begin() should segfault like in std::map
	explicit t_node_map()
	:
		color(RED),
		value(NULL),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	key_type	get_key( void )
	{
		return value->first;
	}

};

template <class T, class U = T>
struct t_node_set
{
	typedef	U				key_type;
	typedef T				value_type;
	typedef T*				value_pointer;
	typedef t_node_set*		node_pointer;

	bool					color;
	value_pointer			value;
		
	node_pointer			parent;
	node_pointer			left;
	node_pointer			right;

	explicit t_node_set()
	:
		color(RED),
		value(NULL),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	key_type	get_key( void )
	{
		return *value;
	}

};

template <typename NodePtr>
struct t_node_pointers
{
	NodePtr	parent;
	NodePtr	left;
	NodePtr right;

	explicit t_node_pointers(NodePtr node)
	:
		parent(node->parent),
		left(node->left),
		right(node->right)
	{}
};


}	// namespace ft