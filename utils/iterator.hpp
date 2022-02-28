/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:19:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/02/28 10:51:20 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{

	struct random_access_iterator_tag {};

	/*
	** ---------------------------------------------------------------- ITERATOR
	*/

	template < class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T& >
	struct iterator
	{
		typedef T         								value_type;
		typedef Distance  								difference_type;
		typedef Pointer   								pointer;
		typedef Reference 								reference;
		typedef Category  								iterator_category;
	};

	/*
	** --------------------------------------------------------- ITERATOR_TRAITS
	*/

	template < class Iterator >
	class iterator_traits
	{
		public :

			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template < class T >
	class iterator_traits< T* >
	{
		public :

			typedef ptrdiff_t								difference_type;
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef random_access_iterator_tag				iterator_category;
	};

	template < class T >
	class iterator_traits< const T* >
	{
		public :

			typedef ptrdiff_t								difference_type;
			typedef T										value_type;
			typedef const T*								pointer;
			typedef const T&								reference;
			typedef random_access_iterator_tag				iterator_category;
	};
}

#endif