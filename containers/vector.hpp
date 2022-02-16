/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:56 by llecoq            #+#    #+#             */
/*   Updated: 2022/02/16 16:40:54 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "../utils/iterator.hpp"

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> > //        GENERIC TEMPLATE
	class vector
	{
		public:
			/*
			** ------------------------------------------------- TEMPLATE PARAMETERS
			*/
			typedef	T												value_type;
			typedef	Alloc											allocator_type;
			/*
			** -------------------------------------------------------- MEMBER TYPES
			*/
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef ft::random_access_iterator<value_type>			iterator;   // iterator a creer
			typedef ft::random_access_iterator<const value_type>	const_iterator;   // iterator a creer
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef ft::iterator_traits<iterator>::difference_type	difference_type;
			// typedef typename 										size_type;
	
	};
}

#endif