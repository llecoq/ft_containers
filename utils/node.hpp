/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:54 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/15 10:33:34 by llecoq           ###   ########.fr       */
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

	explicit t_node(t_node const &x)
	:
		color(x.color),
		value(NULL),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	// operator= used when erase() is called
	t_node	&operator=(t_node const &rhs)
	{
		Pair	*tmp = value;
		
		value = rhs->value;
		rhs->value = tmp;
		return *this;
	}

	~t_node(){}

};

}	// namespace ft