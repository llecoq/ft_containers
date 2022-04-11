/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:34:54 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/10 14:21:34 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace	ft
{
	
template <class Pair, class Alloc = std::allocator<Pair> >
struct t_node
{	
	bool		color;
	Pair		*element;
	
	t_node		*parent;
	t_node		*left;
	t_node		*right;

	explicit t_node()
	:
		color(0),
		element(NULL),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	// explicit t_node(Pair const &val)
	// :
	// 	color(0),
	// 	element(NULL),
	// 	parent(NULL),
	// 	left(NULL),
	// 	right(NULL)
	// {
	// 	(void)val;
	// }

	explicit t_node(t_node const &x)
	:
		color(x.color),
		element(NULL),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	t_node	&operator=(t_node const &rhs)
	{
		color = rhs.color;
		element = _allocate_and_construct(*rhs.element);
		// reset pointers
		parent = NULL;
		right = NULL;
		left = NULL;
		return *this;
	}

	~t_node(){}

};

}	// namespace ft