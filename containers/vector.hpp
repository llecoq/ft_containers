/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:56 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 17:18:03 by llecoq           ###   ########.fr       */
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
		typedef	T													value_type;
		typedef	Alloc												allocator_type;
	
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
	*/
		//-------------------------------------------------------------- default
		explicit vector (const allocator_type& alloc = allocator_type())
		:
			_begin(NULL),
			_end(NULL),
			_end_capacity(NULL),
			_allocator(alloc)
		{}
		
		//----------------------------------------------------------------- fill
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
		:
			_begin(NULL),
			_end(NULL),
			_end_capacity(NULL),
			_allocator(alloc)
		{
			if (n > 0)
			{
				_vector_allocation(n);
				_construct_at_end(n, val);
			}					
		}

		//---------------------------------------------------------------- range
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value
			&& !std::is_floating_point<InputIterator>::value, InputIterator>::type* = 0)
		:
			_begin(NULL),
			_end(NULL),
			_end_capacity(NULL),
			_allocator(alloc)
		{
			_vector_allocation(static_cast<size_type>(last - first));
			_construct_at_end(first, last);
		};

		//----------------------------------------------------------------- copy
		vector (const vector& x)
		:
			_begin(NULL),
			_end(NULL),
			_end_capacity(NULL),
			_allocator(x._allocator)
		{
			_vector_allocation(x.size());
			_construct_at_end(x.begin(), x.end());
		}
		//------------------------------------------------------ copy assignment
		vector& operator= (const vector& x)
		{
			assign(x._begin, x._end);
			return (*this);
		}

	/*
	** -------------------------------------------------------------- DESTRUCTOR
	*/	
		~vector()
		{
			if (_begin != NULL)
			{
				_destruct_backward(_end, size());
				_allocator.deallocate(_begin, capacity());
			}
		}

	/*
	** --------------------------------------------------------------- ITERATORS
	*/    
		iterator begin() {return (iterator(_begin));}
		const_iterator begin() const {return (const_iterator(_begin));}
		reverse_iterator rbegin() {return (reverse_iterator(_end));}
		const_reverse_iterator rbegin() const {return (const_reverse_iterator(_end));}
		iterator end() {return (iterator(_end));}	
		const_iterator end() const {return (const_iterator(_end));}
		reverse_iterator rend() {return (reverse_iterator(_begin));}
		reverse_iterator rend() const {return (reverse_iterator(_begin));}
		
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
	*/
		//--------------------------------------------------------- assign range
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
			typename enable_if<!is_integral<InputIterator>::value
			&& !std::is_floating_point<InputIterator>::value, InputIterator>::type* = 0)
		{
			size_type	n = static_cast<size_type>(last - first);

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
				else
					_destruct_backward(_old_vector._begin);
			}
		}

		//---------------------------------------------------------- assign fill
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
				else
					_destruct_backward(_old_vector._begin);
			}
		}

		//------------------------------------------------------------ push back
		void push_back (const value_type& val)
		{
			if (_end != _end_capacity)
				_allocator.construct(_end++, val);
			else
			{
				_update_data(_old_vector);
				_vector_allocation(_new_capacity());
				_set_ptr(_begin + _old_vector.size + 1);
				_construct_backward(_old_vector._end, _old_vector.size, val);
				_destruct_backward(_old_vector._end, _old_vector.size);
				_allocator.deallocate(_old_vector._end, _old_vector.capacity);
			}
		}

		//------------------------------------------------------------- pop back
		void pop_back(void)
		{
			_destruct_backward(_end, 1);
		}

		//------------------------------------------------ insert single element
		iterator insert (iterator position, const value_type& val)
		{
			size_type	insert_position = static_cast<size_type>(position - begin());

			if (_end == _end_capacity)
			{
				pointer		insert_ptr = _iterator_to_pointer(position);

				_update_data(_old_vector);
				_vector_allocation(_new_capacity());
				_set_ptr(_begin + insert_position + 1);
				_construct_backward(insert_ptr, insert_position, val);
				_construct_at_end(insert_ptr, _old_vector._end);
				_destruct_backward(_old_vector._end, _old_vector.size);
				_allocator.deallocate(_old_vector._end, _old_vector.size);
				position = iterator(_begin + insert_position);
			}
			else 
			{
				_construct_at_end(1, *(_end - 1));
				_assign_backward(end(), position);
				_begin[insert_position] = val;
			}
			return position;
		}
	
		//---------------------------------------------------------- insert fill
		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type	insert_position = static_cast<size_type>(position - begin());

			if (_end + n > _end_capacity)
			{
				pointer		insert_ptr = _iterator_to_pointer(position);

				_update_data(_old_vector);
				_vector_allocation(_new_capacity(size() + n));
				_set_ptr(_begin + insert_position);
				_construct_at_end(n, val);
				_construct_backward(insert_ptr, insert_position);
				_construct_at_end(insert_ptr, _old_vector._end);
				_destruct_backward(_old_vector._end, _old_vector.size);
				_allocator.deallocate(_old_vector._end, _old_vector.size);
				position = iterator(_begin + insert_position);
			}
			else 
			{
				_construct_at_end(_end - n, _end);
				_assign_backward(end(), position, n);
				while (n-- > 0)
					_begin[insert_position++] = val;
			}
		}
		
		//--------------------------------------------------------- insert range
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
			typename enable_if<!is_integral<InputIterator>::value
			&& !std::is_floating_point<InputIterator>::value, InputIterator>::type* = 0)
		{
			size_type	insert_position = static_cast<size_type>(position - begin());
			size_type	n = static_cast<size_type>(last - first);

			if (_end + n > _end_capacity)
			{
				pointer		insert_ptr = _iterator_to_pointer(position);

				_update_data(_old_vector);
				_vector_allocation(_new_capacity(size() + n));
				_set_ptr(_begin + insert_position);
				_construct_at_end(first, last);
				_construct_backward(insert_ptr, insert_position);
				_construct_at_end(insert_ptr, _old_vector._end);
				_destruct_backward(_old_vector._end, _old_vector.size);
				_allocator.deallocate(_old_vector._end, _old_vector.size);
				position = iterator(_begin + insert_position);
			}
			else 
			{
				_construct_at_end(_end - n, _end);
				_assign_backward(end(), position, n);
				while (n-- > 0)
					_begin[insert_position++] = *(first++);
			}
		}

		//------------------------------------------------- erase single element
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

		//---------------------------------------------------------- erase range
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

		//----------------------------------------------------------------- swap
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
		
	
	/*
	** -------------------------------------------------------------- ALLOCATION
	*/
		void	_vector_allocation(size_type n)
		{
			if (n > max_size())
				throw lenghtErrorException;
			_begin = _end = _allocator.allocate(n);
			_end_capacity = _begin + n;
		}

		size_type	_new_capacity(size_type n = 0)
		{
			size_type	new_capacity = capacity();

			if (n > 0)
				return (capacity() * 2 > n ? capacity() * 2 : n);
			else
				return (new_capacity == 0 ? 1 : new_capacity * 2);
		}
	/*
	** -------------------------------------------------------- CONSTRUCT AT END
	*/
		void	_construct_at_end(size_type n, const value_type &val)
		{
			while (n-- > 0)
				_allocator.construct(_end++, val);
		}

		template <typename Input>
		void	_construct_at_end(Input begin, Input end)
		{
			while (begin != end)
				_allocator.construct(_end++, *begin++);
		}
	/*
	** ------------------------------------------------------ CONSTRUCT BACKWARD
	*/
		void	_construct_backward(pointer old_end, size_type number_of_elements,
				const value_type &val)
		{
			// _set_ptr(_begin + number_of_elements + 1);
			_allocator.construct(--_begin, val);
			while (number_of_elements-- > 0)
				_allocator.construct(--_begin, *--old_end);
		}
		
		void	_construct_backward(pointer old_end, size_type number_of_elements)
		{
			while (number_of_elements-- > 0)
				_allocator.construct(--_begin, *--old_end);
		}
	/*
	** ------------------------------------------------------- DESTRUCT BACKWARD
	*/		
		void	_destruct_backward(pointer &end, size_type size)
		{
			while (size-- > 0)
				_allocator.destroy(--end);
		}

		void	_destruct_backward(pointer new_end)
		{
			while (_end > new_end)
				_allocator.destroy(--_end);
		}
	/*
	** --------------------------------------------------------- ASSIGN BACKWARD
	*/
		void	_assign_backward(iterator begin, iterator end, size_type n = 1)
		{
			begin -= (n + 1);
			while (begin > end + n - 1)
				*(begin--) = *(begin - n);
		}
	/*
	** ------------------------------------------------------------- SET POINTER
	*/
		void	_set_ptr(pointer ptr)
		{
			_begin = _end = ptr;
		}

		pointer	_iterator_to_pointer(iterator &position)
		{
			pointer			ptr;

			ptr = _begin + (position - begin());
			return ptr;
		}
	/*
	** -------------------------------------------------------- SWAP/UPDATE DATA
	*/
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