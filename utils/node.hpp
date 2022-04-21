/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:54 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/21 15:17:01 by llecoq           ###   ########.fr       */
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

	~t_node_map(){}
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