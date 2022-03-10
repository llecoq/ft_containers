/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:56 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/10 15:10:19 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstddef>
#include <limits>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utils/utils.hpp"

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
		typedef random_access_iterator<const value_type>			const_iterator;
		typedef reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
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
			_begin(0),
			_end(0),
			_end_capacity(0),
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
			_begin(0),
			_end(0),
			_end_capacity(0),
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
		// 	_begin(0),
		// 	_end(0),
		// 	_end_capacity(0),
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
			_begin(0),
			_end(0),
			_end_capacity(0),
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
			// assign(x._begin, x._end);
			(void)x;
		}

		/*
		** ---------------------------------------------------------- DESTRUCTOR
		*/	

		~vector()
		{
			if (_begin != 0)
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

		const_iterator begin() const
		{
			return (_begin);
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(_end));
		}

		const_reverse_iterator rbegin() const
		{
			return (reverse_iterator(_end));
		}

		iterator end()
		{
			return (_end);
		}
		
		const_iterator end() const
		{
			return (_end);
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(_begin));
		}

		reverse_iterator rend() const
		{
			return (reverse_iterator(_begin));
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
			{
				_update_data(_old_vector);
				_expand_vector(_end, n, val);
			}
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
			{
				_update_data(_old_vector);
				_reallocate_and_copy_elements(_end, n);
			}
		}

	/*
	** ---------------------------------------------------------- ELEMENT ACCESS
	*/
		// Access element
		reference operator[] (size_type n)
		{
			return _begin[n];
		}

		const_reference operator[] (size_type n) const
		{
			return _begin[n];
		}

		// Returns a reference to the element at position n in the vector.
		reference at (size_type n)
		{
			if (n > size())
				throw std::out_of_range("vector");
			return _begin[n];
		}

		const_reference at (size_type n) const
		{
			if (n > size())
				throw std::out_of_range("vector");
			return _begin[n];
		}
		
		// Access element (public member function )
		reference front()
		{
			return *_begin;
		}

		const_reference front() const
		{
			return *_begin;
		}

		// Access first element (public member function )
		reference back()
		{
			return *(_end - 1);
		}

		const_reference back() const
		{
			return *(_end - 1);
		}

	/*
	** --------------------------------------------------------------- MODIFIERS
	**
	**																    range(1)
	**		In the range version (1), the new contents are elements constructed 
	**		from each of the elements in the range between first and last, in the
	**		same order.
	*/

		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last)
		// {
		// 	// if needed, new allocation with new size() = new capacity()
		// 	// clear()
		// 	// construct at end
		// 	// dealloc old
			
		// 	// if pas dalloc
		// 	// assign operator= from begin to end, then construct at end
		// 	// destruct at end 
		// 	(void)first;
		// 	(void)last;
		// }

		/*																 fill(2)
		**	In the fill version (2), the new contents are n elements, each init-
		**	-ialized to a copy of val.
		*/

		void assign (size_type n, const value_type &val)
		{
			// if n > capacity()
			//		clear()
			//		construct at end
			//		deallocate old
			// else
			//		assign
			//		destruct_backward / construct_at_end
			_update_data(_old_vector);
			if (n > capacity())
			{
				clear();
				_allocator.deallocate(_begin, _old_vector.capacity);
				_vector_allocation(n);
				_construct_at_end(n, val);
			}
			else
			{
				for (size_t i = 0; i < n && i < size(); i++)
					*(_old_vector._begin++) = val;
				if (n > size())
					_construct_at_end(n - size(), val);
				_destruct_backward(_old_vector._begin);
			}
		}

		void push_back (const value_type& val)
		{
			if (_end != _end_capacity)
				_allocator.construct(_end++, val);
			else
			{
				_update_data(_old_vector);
				_reallocate_and_copy_elements(_end, val);
			}
		}

		void pop_back(void)
		{
			_destruct_backward(_end, 1);
		}

		// A REVOIR MOOOOOOCHE BEURK
		// Le vrai tourne en boucle si position > end, comme le mien lolz
		// single element (1)	
		iterator insert (iterator position, const value_type& val)
		{
			iterator		insert_iter = position;

			if (_end == _end_capacity)
			{
				pointer		insert_ptr = _iterator_to_pointer(position);
				pointer		old_end = _end;
				size_type	old_size = size();
				size_type	insert_position = static_cast<size_type>(position - begin());
			
				_vector_allocation(capacity() + 1);
				_construct_backward(insert_ptr, insert_position, val);
				while (_end != _end_capacity)
					_construct_at_end(*insert_iter++);
				_destruct_backward(old_end, old_size);
				_allocator.deallocate(old_end, old_size);
			}
			else 
			{
				size_type	insert_position = static_cast<size_type>(position - begin());

				_construct_at_end(*(_end - 1));
				for (iterator it = end() - 2; it != position; it--)
					*it = *(it - 1);
				_begin[insert_position] = val;
			}
			return position;
		}
		// fill (2)	
		// void insert (iterator position, size_type n, const value_type& val)
		// {

		// }
		// // range (3)	
		// template <class InputIterator>
		// 	void insert (iterator position, InputIterator first, InputIterator last);

		// erase
		// Erase elements (public member function )
		iterator erase (iterator position)
		{
			if (position + 1 != end())
			{
				for (iterator it = position; it < (end() - 1); it++)
					*it = *(it + 1);
			}
			_destruct_backward(_end, 1);
			return position;
		}

		iterator erase (iterator first, iterator last)
		{
			if (first != last)
			{
				size_type	range_size = last - first;
				for (iterator it = first; it != (end() - range_size); it++)
					*it = *(it + range_size);
				_destruct_backward(_end, range_size);
			}
			return last;
		}

		// swap
		void swap (vector& x)
		{
			data<T>	tmp;

			_swap_data(tmp, *this);
			_swap_data(*this, x);
			_swap_data(x, tmp);
		}

		friend void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			data<T>	tmp;

			x._swap_data(tmp, x);
			x._swap_data(x, y);
			x._swap_data(y, tmp);
		}

		// clear
		void clear()
		{
			_destruct_backward(_end, size());
		}

		allocator_type get_allocator() const
		{
			return (_allocator);
		}

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
		data<T, Alloc>									_old_vector;
		
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

		void	_destruct_backward(pointer new_end)
		{
			while (_end != new_end)
				_allocator.destroy(--_end);
		}

		void	_reallocate_and_copy_elements(pointer old_end, const value_type &val)
		{
			size_type	new_capacity = capacity();

			if (new_capacity == 0)
				new_capacity = 1;
			else
				new_capacity *= 2;
			_vector_allocation(new_capacity);
			_construct_backward(old_end, _old_vector.size, val);
			_destruct_backward(old_end, _old_vector.size);
			_allocator.deallocate(old_end, _old_vector.capacity);
		}

		void	_reallocate_and_copy_elements(pointer old_end, size_type new_capacity)
		{
			_vector_allocation(new_capacity);
			_begin = _end = _begin + _old_vector.size;
			_construct_backward(old_end, _old_vector.size);
			_destruct_backward(old_end, _old_vector.size);
			_allocator.deallocate(old_end, _old_vector.capacity);
		}

		void	_expand_vector(pointer old_end, size_type n, const value_type &val)
		{
			size_type	new_capacity = n;
		
			if (capacity() * 2 > n)
				new_capacity = capacity() * 2;
			_vector_allocation(new_capacity);
			_begin = _end = _begin + _old_vector.size;
			_construct_at_end(n - _old_vector.size, val);
			_construct_backward(old_end, _old_vector.size);
			_destruct_backward(old_end, _old_vector.size);
			_allocator.deallocate(old_end, _old_vector.capacity);
		}

		pointer	_iterator_to_pointer(iterator position)
		{
			difference_type	index;
			pointer			ptr;

			index = position - begin();
			ptr = _begin + index;
			return ptr;
		}

		void	_update_data(data<T, Alloc> &old_vector)
		{
			old_vector._begin = _begin;
			old_vector._end = _end;
			old_vector.capacity = capacity();
			old_vector.size = size();
		}

		template <typename D, typename U>
		void	_swap_data(D &data, U &tmp)
		{
			data._begin = tmp._begin;
			data._end = tmp._end;
			data._end_capacity = tmp._end_capacity;
			data._allocator = tmp._allocator;
		}
};
}

#endif