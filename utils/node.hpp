/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:54 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/17 11:02:45 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace	ft
{

enum	e_node_color
{
	RED,
	BLACK,
	DOUBLE_BLACK
};

template <class Pair>
struct t_node
{	
	int		color;
	Pair	*value;

	t_node	*parent;
	t_node	*left;
	t_node	*right;

	explicit t_node()
	:
		color(RED),
		value(NULL),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	// explicit t_node(Pair const &val)
	// :
	// 	color(0),
	// 	value(NULL),
	// 	parent(NULL),
	// 	left(NULL),
	// 	right(NULL)
	// {
	// 	(void)val;
	// }

	// storing data, no deep copy, used for erase()
	explicit t_node(t_node const &x)
	:
		color(x.color),
		value(x.value),
		parent(x.parent),
		left(x.left),
		right(x.right)
	{}

	// t_node	&operator=(t_node &rhs)
	// {
	// 	color = rhs.color;
	// 	value = rhs.value;
	// 	parent = rhs.parent;
	// 	left = rhs.left;
	// 	right = rhs.right;
	// 	return *this;
	// }

	~t_node(){}
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