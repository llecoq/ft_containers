/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:56 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/04 17:15:12 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

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
		typedef random_access_iterator<value_type>					iterator;
		typedef random_access_iterator<const value_type>			const_iterator;   // iterator a creer
		typedef reverse_iterator<iterator>							reverse_iterator;
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
		// :
		// 	_begin(nullptr),
		// 	_end(nullptr),
		// 	_end_capacity(nullptr),
		// 	_allocator(alloc)
		// {
		// 	_vector_allocation(static_cast<size_type>(last - first));
		// 	while (first != last)
		// 		_construct_at_end(*first++);
		// };
		
		/* 															    copy (4)
		**	Constructs a container with a copy of each of the elements in x, in 
		**	the same order.
		*/	
		vector (const vector& x)
		:
			_begin(nullptr),
			_end(nullptr),
			_end_capacity(nullptr),
			_allocator(x._allocator)
		{
			_vector_allocation(x.size());
			for (size_type i = 0; i < x.size(); i++)
				_construct_at_end(x._begin[i]);
		}

		/* 															    copy (1)
		**															  assignment
		**
		*/
		vector& operator= (const vector& x)
		{
			// clear ?
			// if *this.capacity() > x, original malloc error et leaks
			// assign ?
			(void)x;
		}

		/*
		** ---------------------------------------------------------- DESTRUCTOR
		*/	

		~vector()
		{
			if (_begin != nullptr)
			{
				_destruct_backward(_end, size());
				_allocator.deallocate(_begin, capacity());
			}
		}

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

		iterator rbegin()
		{
			return (_end - 1);
		}

		iterator end()
		{
			return (_end);
		}
		
		// const_iterator end() const;

		iterator rend()
		{
			return (_begin);
		}
		
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
		void resize (size_type n, value_type val = value_type())
		{
			if (n < size())
				_destruct_backward(_end, size() - n);
			else if (n > capacity())
				_expand_vector(_end, n, val);
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
		void reserve (size_type n)
		{
			if (n > capacity())
				_reallocate_and_copy_elements(_end, n);
		}

	/*
	** ---------------------------------------------------------- ELEMENT ACCESS
	*/
		// Access element
		reference operator[] (size_type n)
		{
			return _begin[n];
		}

		// const_reference operator[] (size_type n) const;

		// Returns a reference to the element at position n in the vector.
		reference at (size_type n)
		{
			if (n > size())
				throw std::out_of_range("vector");
			return _begin[n];
		}

		// const_reference at (size_type n) const;
		
		// Access element (public member function )
		reference front()
		{
			return *_begin;
		}
		// const_reference front() const;

		// Access first element (public member function )
		reference back()
		{
			return *(_end - 1);
		}
		// const_reference back() const;

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

		void pop_back(void)
		{
			_destruct_backward(_end, 1);
		}

		// insert
		// Insert elements (public member function )
		// erase
		// Erase elements (public member function )
		iterator erase (iterator position)
		{
			pointer				element_to_erase;
			difference_type		index;

			index = position - begin();
			element_to_erase = _begin + index;

			_allocator.destroy(element_to_erase);
			
			return position;
		}
		// iterator erase (iterator first, iterator last);
		// swap
		// void swap (vector& x)
		// {
			
		// }
		// Swap content (public member function )
		// clear
		// Clear content (public member function )

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

		void	_construct_backward(pointer old_end, size_type number_of_elements, const value_type &val)
		{
			_end = _begin = _begin + number_of_elements + 1;

			_allocator.construct(--_begin, val);
			while (number_of_elements-- > 0)
				_allocator.construct(--_begin, *--old_end);
		}
		
		void	_construct_backward(pointer old_end, size_type number_of_elements)
		{
			while (number_of_elements-- > 0)
				_allocator.construct(--_begin, *--old_end);
		}
		
		void	_destruct_backward(pointer &end, size_type size)
		{
				while (size-- > 0)
					_allocator.destroy(--end);
		}

		// faire passer petite structure dedans pour avoir une fonction plus generale
		// avec size, capacity, val etc. ?

		void	_reallocate_and_copy_elements(pointer old_end, const value_type &val)
		{
			size_type	new_capacity = capacity();
			size_type	old_size = size();

			if (new_capacity == 0)
				new_capacity = 1;
			else
				new_capacity *= 2;
			_vector_allocation(new_capacity);
			_construct_backward(old_end, old_size, val);
			_destruct_backward(old_end, old_size);
			_allocator.deallocate(old_end, old_size);
		}

		void	_reallocate_and_copy_elements(pointer old_end, size_type new_capacity)
		{
			size_type	old_size = size();

			_vector_allocation(new_capacity);
			_begin = _end = _begin + old_size;
			_construct_backward(old_end, old_size);
			_destruct_backward(old_end, old_size);
			_allocator.deallocate(old_end, old_size);
		}

		void	_expand_vector(pointer old_end, size_type new_capacity, const value_type &val)
		{
			size_type	old_size = size();
		
			_vector_allocation(new_capacity);
			_begin = _end = _begin + old_size;
			_construct_at_end(new_capacity - old_size, val);
			_construct_backward(old_end, old_size);
			_destruct_backward(old_end, old_size);
			_allocator.deallocate(old_end, old_size);
		}

};
}

#endif