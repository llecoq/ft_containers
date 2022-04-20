/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:54 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/20 12:08:01 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace	ft
{

enum	e_node_colors
{
	RED,
	BLACK
};

template <class Pair>
struct t_node
{	
	bool	color;
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