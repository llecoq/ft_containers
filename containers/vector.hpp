/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:56 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/03 13:00:25 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <string>
#include <iostream>
#include "../utils/random_access_iterator.hpp"

namespace	ft
{

template < class T, class Alloc = std::allocator<T> > //        GENERIC TEMPLATE
class vector
{
	public:
	/*
	** ----------------------------------------------------- TEMPLATE PARAMETERS
	*/
		typedef	T												value_type;
		typedef	Alloc											allocator_type;
	
	/*
	** ------------------------------------------------------------ MEMBER TYPES
	*/
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef random_access_iterator<value_type>					iterator;   // iterator a creer
		typedef random_access_iterator<const value_type>			const_iterator;   // iterator a creer
		// typedef ft::reverse_iterator<iterator>					reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;
		typedef typename allocator_type::size_type					size_type;
		
	/*
	** ------------------------------------------------------------ CONSTRUCTORS
	**
	** 																 default (1)
	**							Constructs an empty container, with no elements.
	*/
		explicit vector (const allocator_type& alloc = allocator_type())
		:
			_begin(nullptr),
			_end(nullptr),
			_end_capacity(nullptr),
			_allocator(alloc)
		{
			// std::cout << "VECTOR DEFAULT CONSTRUCTOR" << std::endl;
		}
		
		/* 															    fill (2)
		**	Constructs a container with n elements. Each element is a copy of val.
		*/
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
		:
			_begin(nullptr),
			_end(nullptr),
			_end_capacity(nullptr),
			_allocator(alloc)
		{
			// std::cout << "VECTOR FILL CONSTRUCTOR" << std::endl;
			
			if (n > 0)
			{
				_vector_allocation(n);
				_construct_at_end(n, val);
			}					
		}

		/* 															   range (3)
		**	Constructs a container with as many elements as the range [first,last),
		**	with each element constructed from its corresponding element in that 
		**	range, in the same order.
		*/

		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last,	const allocator_type& alloc = allocator_type(),
		// 		typename enable_if<!is_integral<InputIterator>::value>::type* = 0) : _alloc(alloc)

		// template <class InputIterator>
		//         vector (InputIterator first, InputIterator last,
		//                 const allocator_type& alloc = allocator_type())
		// {
		// 	std::cout << "VECTOR RANGE CONSTRUCTOR" << std::endl;
		
		// 	(void)first;
		// 	(void)last;
		// 	(void)alloc;
		// };
		
		/* 															    copy (4)
		**	Constructs a container with a copy of each of the elements in x, in 
		**	the same order.
		*/	
		vector (const vector& x)
		{
			std::cout << "COPY" << std::endl;

			(void)x;
		}

		/*
		** ---------------------------------------------------------- DESTRUCTOR
		*/	

		~vector()
		{
			if (_begin != nullptr)
			{
				_destruct_from_end(_end, size());
				_allocator.deallocate(_begin, capacity());
			}
		}

		// ~vector()
		// {
		// 	if (_begin != nullptr)
		// 	{
		// 		_destruct_and_deallocate_vector(_begin, DESTRUCTOR);
		// 		// _allocator.deallocate(_begin, capacity());
		// 	}
		// }

	/*
	** --------------------------------------------------------------- ITERATORS
	*/
	    
		iterator begin()
		{
			return (_begin);
		}

		// const_iterator begin() const
		// {
		// 	return (_begin);
		// }
	
		iterator end()
		{
			return (_end);
		}
		
		// const_iterator end() const;
		
	/*
	** ---------------------------------------------------------------- CAPACITY
	*/

		// This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
		size_type size() const
		{
			return static_cast<size_type>(_end - _begin);		
		}

		size_type max_size() const
		{
			if (sizeof(value_type) == sizeof(char))
				return std::numeric_limits<size_type>::max() / 2;
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
		}

		// Resizes the container so that it contains n elements.
		// If n is smaller than the current container size, the content is reduced to its first n elements, 
		// removing those beyond (and destroying them).
		// If n is greater than the current container size, the content is expanded by inserting at the end as 
		// many elements as needed to reach a size of n. If val is specified, the new elements are initialized as 
		// copies of val, otherwise, they are value-initialized.
		// If n is also greater than the current container capacity, an automatic reallocation of the allocated 
		// storage space takes place.
		// Notice that this function changes the actual content of the container by inserting or erasing elements 
		// from it.
		void resize (size_type n, value_type val = value_type())
		{
			// if n < size
			//	destruct from end
			(void)n;
			(void)val;
		}

		// Return size of allocated storage capacity
		size_type capacity() const
		{
			return static_cast<size_type>(_end_capacity - _begin);
		}

		// Test whether vector is empty
		bool empty() const
		{
			return (_begin == _end);
		}

		// Request a change in capacity
		// Requests that the vector capacity be at least enough to contain n elements.
		// If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
		// In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
		// This function has no effect on the vector size and cannot alter its elements.		
		void reserve (size_type n)
		{
			if (n > capacity())
			{
				// reallocate storage increasing capacity
			}
		}

	/*
	** --------------------------------------------------------------- MODIFIERS
	**
	**																    range(1)
	**		In the range version (1), the new contents are elements constructed 
	**		from each of the elements in the range between first and last, in the
	**		same order.
	*/

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			(void)first;
			(void)last;
		}

		/*																 fill(2)
		**	In the fill version (2), the new contents are n elements, each init-
		**	-ialized to a copy of val.
		*/

		void assign (size_type n, const value_type &val)
		{
			(void)n;
			(void)val;
		}

		void push_back (const value_type& val)
		{
			if (_end != _end_capacity)
				_allocator.construct(_end++, val);
			else
				_reallocate_and_copy_elements(_end, val);
		}




T &		operator[]( unsigned int index )
{
return _begin[index];
};

	class	lengthErrorException : public std::exception
	{
		virtual const char * what() const throw()
		{
			return "vector";
		}
	} lenghtErrorException;

	private :

		pointer											_begin;
		pointer											_end;
		pointer											_end_capacity;
		allocator_type									_allocator;

		void	_vector_allocation(size_type n)
		{
			if (n > max_size())
				throw lenghtErrorException;
			_begin = _end = _allocator.allocate(n);
			_end_capacity = _begin + n;
		}

		void	_construct_at_end(size_type n, const value_type &val)
		{
			while (n-- > 0)
				_allocator.construct(_end++, val);
		}

		void	_construct_at_end(const value_type &val)
		{
			_allocator.construct(_end++, val);
		}

		void	_construct_from_end(pointer old_end, size_type number_of_elements, const value_type &val)
		{
			_end = _begin = _begin + number_of_elements + 1;

			_allocator.construct(--_begin, val);
			while (number_of_elements-- > 0)
				_allocator.construct(--_begin, *--old_end);
		}
		
		void	_destruct_from_end(pointer &end, size_type size)
		{
				while (size-- > 0)
					_allocator.destroy(--end);
		}

		void	_reallocate_and_copy_elements(pointer old_end, const value_type &val)
		{
			size_type	new_capacity = capacity();
			size_type	old_size = size();

			if (new_capacity == 0)
				new_capacity = 1;
			else
				new_capacity *= 2;
			_vector_allocation(new_capacity);
			_construct_from_end(old_end, old_size, val);
			_destruct_from_end(old_end, old_size);
			_allocator.deallocate(old_end, old_size);
		}

};
}

#endif