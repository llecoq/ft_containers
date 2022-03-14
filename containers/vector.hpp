/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:56 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/14 18:17:44 by llecoq           ###   ########.fr       */
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
#include "../utils/metafunctions.hpp"

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
		{}
		
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
			_construct_at_end(x.begin(), x.end());
			// for (size_type i = 0; i < x.size(); i++)
				// _allocator.construct(_end++, x._begin[i]);
		}

		/* 															    copy (1)
		**															  assignment
		**
		*/
		vector& operator= (const vector& x)
		{
			assign(x._begin, x._end);
			(void)x;
			return (*this);
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

		void resize (size_type n, value_type val = value_type())
		{
			if (n < size())
				_destruct_backward(_end, size() - n);
			else if (n > capacity())
			{
				_update_data(_old_vector);
				_vector_allocation(_new_capacity(n));
				_set_ptr(_begin + _old_vector.size);
				_construct_at_end(n - _old_vector.size, val);
				_construct_backward(_old_vector._end, _old_vector.size);
				_destruct_backward(_old_vector._end, _old_vector.size);
				_allocator.deallocate(_old_vector._end, _old_vector.capacity);
			}
		}

		size_type capacity() const
		{
			return static_cast<size_type>(_end_capacity - _begin);
		}

		bool empty() const
		{
			return (_begin == _end);
		}

		void reserve (size_type n)
		{
			if (n > capacity())
			{
				_update_data(_old_vector);
				_vector_allocation(n);
				_set_ptr(_begin + _old_vector.size);
				_construct_backward(_old_vector._end, _old_vector.size);
				_destruct_backward(_old_vector._end, _old_vector.size);
				_allocator.deallocate(_old_vector._end, _old_vector.capacity);
			}
		}

	/*
	** ---------------------------------------------------------- ELEMENT ACCESS
	*/
		reference operator[] (size_type n)
		{
			return _begin[n];
		}

		const_reference operator[] (size_type n) const
		{
			return _begin[n];
		}

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
		
		reference front()
		{
			return *_begin;
		}

		const_reference front() const
		{
			return *_begin;
		}

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

// template <class _ForwardIterator>
// typename enable_if
// <
//     __is_forward_iterator<_ForwardIterator>::value &&
//     is_constructible<
//        _Tp,
//        typename iterator_traits<_ForwardIterator>::reference>::value,
//     void
// >::type
// vector<_Tp, _Allocator>::assign(_ForwardIterator __first, _ForwardIterator __last)

// typename enable_if
// <
//      __is_input_iterator  <_InputIterator>::value &&
//     !__is_forward_iterator<_InputIterator>::value &&
//     is_constructible<
//        _Tp,
//        typename iterator_traits<_InputIterator>::reference>::value,
//     void
// >::type
// vector<_Tp, _Allocator>::assign(_InputIterator __first, _InputIterator __last)

// template <class _InputIterator>
// typename enable_if
// <
//     __is_input_iterator<_InputIterator>::value &&
//    !__is_forward_iterator<_InputIterator>::value,
//    void
// >::type
// vector<bool, _Allocator>::assign(_InputIterator __first, _InputIterator __last)

// template <class _Allocator>
// template <class _ForwardIterator>
// typename enable_if
// <
//     __is_forward_iterator<_ForwardIterator>::value,
//    void
// >::type
// vector<bool, _Allocator>::assign(_ForwardIterator __first, _ForwardIterator __last)

		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last)
		// {
		// 	size_type	n = last - first;

		// 	_update_data(_old_vector);
		// 	if (n > capacity())
		// 	{
		// 		clear();
		// 		_allocator.deallocate(_begin, _old_vector.capacity);
		// 		_vector_allocation(n);
		// 		_construct_at_end(first, last);
		// 	}
		// 	else
		// 	{
		// 		for (size_t i = 0; i < n && i < size(); i++)
		// 			*(_old_vector._begin++) = *(first++);
		// 		if (n > size())
		// 			_construct_at_end(first, last);
		// 		_destruct_backward(_old_vector._begin);
		// 	}
		// }

		template <class InputIterator>
		void assign (typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
		// typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			size_type	n = last - first;

			_update_data(_old_vector);
			if (n > capacity())
			{
				clear();
				_allocator.deallocate(_begin, _old_vector.capacity);
				_vector_allocation(n);
				_construct_at_end(first, last);
			}
			else
			{
				for (size_t i = 0; i < n && i < size(); i++)
					*(_old_vector._begin++) = *(first++);
				if (n > size())
					_construct_at_end(first, last);
				_destruct_backward(_old_vector._begin);
			}
		}

		/*																 fill(2)
		**	In the fill version (2), the new contents are n elements, each init-
		**	-ialized to a copy of val.
		*/

		void assign (size_type n, const value_type &val)
		{
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
				_vector_allocation(_new_capacity());
				_construct_backward(_old_vector._end, _old_vector.size, val);
				_destruct_backward(_old_vector._end, _old_vector.size);
				_allocator.deallocate(_old_vector._end, _old_vector.capacity);
			}
		}

		void pop_back(void)
		{
			_destruct_backward(_end, 1);
		}

		iterator insert (iterator position, const value_type& val)
		{
			size_type	insert_position = static_cast<size_type>(position - begin());

			if (_end == _end_capacity)
			{
				pointer		insert_ptr = _iterator_to_pointer(position);

				_update_data(_old_vector);
				_vector_allocation(_new_capacity());
				_construct_backward(insert_ptr, insert_position, val);
				_construct_at_end(insert_ptr, _old_vector._end);
				_destruct_backward(_old_vector._end, _old_vector.size);
				_allocator.deallocate(_old_vector._end, _old_vector.size);
			}
			else 
			{
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

		void clear()
		{
			_destruct_backward(_end, size());
		}

		allocator_type get_allocator() const
		{
			return (_allocator);
		}


	/*
	** ---------------------------------------------------- RELATIONAL OPERATORS
	*/
		friend bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (lhs.size() == rhs.size());
		}

		friend bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (lhs.size() != rhs.size());
		}

		friend bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (lhs.size() < rhs.size());
		}

		friend bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (lhs.size() <= rhs.size());
		}

		friend bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (lhs.size() > rhs.size());
		}

		friend bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (lhs.size() >= rhs.size());
		}


	/*
	** -------------------------------------------------------------- EXCEPTIONS
	*/
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

		// void	_construct_at_end(pointer begin, pointer end)
		// {
		// 	while (begin != end)
		// 		_allocator.construct(_end++, *begin++);
		// }

		// void	_construct_at_end(iterator begin, iterator end)
		// {
		// 	while (begin != end)
		// 		_allocator.construct(_end++, *begin++);
		// }

		template <typename Input>
		void	_construct_at_end(Input begin, Input end)
		{
			while (begin != end)
				_allocator.construct(_end++, *begin++);
		}

		void	_construct_backward(pointer old_end, size_type number_of_elements, const value_type &val)
		{
			_set_ptr(_begin + number_of_elements + 1);
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

		size_type	_new_capacity(size_type n = 0)
		{
			size_type	new_capacity = capacity();

			if (n > 0)
				return (capacity() * 2 > n ? capacity() * 2 : n);
			else
				return (new_capacity == 0 ? 1 : new_capacity * 2);
		}

		// void	_expand_vector(pointer old_end, size_type n, const value_type &val)
		// {
		// 	size_type	new_capacity = n;
		
		// 	if (capacity() * 2 > n)
		// 		new_capacity = capacity() * 2;
		// 	_vector_allocation(new_capacity);
		// 	_set_ptr(_begin + _old_vector.size);
		// 	_construct_at_end(n - _old_vector.size, val);
		// 	_construct_backward(old_end, _old_vector.size);
		// 	_destruct_backward(old_end, _old_vector.size);
		// 	_allocator.deallocate(old_end, _old_vector.capacity);
		// }

		void	_set_ptr(pointer ptr)
		{
			_begin = _end = ptr;
		}

		pointer	_iterator_to_pointer(iterator position)
		{
			pointer			ptr;

			ptr = _begin + (position - begin());
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