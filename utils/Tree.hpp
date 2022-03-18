/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:23:58 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/18 15:28:08 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

namespace ft
{

template <class Pair>
struct t_node
{	
	bool		color;
	Pair		data;
	
	t_node		*parent;
	t_node		*left;
	t_node		*right;

	explicit t_node(Pair &val)
	:
		color(0),
		data(val),
		parent(NULL),
		left(NULL),
		right(NULL)
	{}

	~t_node();
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
		typedef pair<key_type, mapped_type>						value_type;

	private:

		node_pointer											_root_node;	
		node_pointer											_begin_node;	
		node_pointer											_end_node;
		allocator_type											_node_allocator;
		key_compare												_comparator;
		size_type												_size;

	public :

		// default
		explicit Tree (const key_compare & comp = key_compare(),
					const allocator_type& alloc = allocator_type())
		:
			_root_node(NULL),
			_begin_node(_root_node),
			_end_node(_root_node),
			_node_allocator(alloc),
			_comparator(comp),
			_size(0)
		{}

		Tree (const Tree& x)
		:
			_root_node(NULL),
			_begin_node(_root_node),
			_end_node(_root_node),
			_node_allocator(x._node_allocator),
			_comparator(x._comparator),
			_size(0)	
		{
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
			_comparator(comp),
			_size(0)
		{
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
			// destruct 
			// deallocate
		}
	/*
	** ------------------------------------------------------------ ITERATORS
	*/
		node_pointer begin() {return _begin_node;}

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
		pair<node_pointer, bool> insert (const value_type& val)
		{
			(void)val;
		}

	private :

		node_pointer	_create_node(const value_type& val)
		{
			node_pointer	node = _node_allocator.allocate(1);

			_node_allocator.construct(node, val);
			return (node);
		}

};

}