/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:19:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/01 15:44:23 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{

	struct random_access_iterator_tag {};

/*
** -------------------------------------------------------------------- ITERATOR
*/
	template < class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T& >
	struct iterator
	{
		typedef T         									value_type;
		typedef Distance  									difference_type;
		typedef Pointer   									pointer;
		typedef Reference 									reference;
		typedef Category  									iterator_category;
	};


/*
** ------------------------------------------------------------- ITERATOR_TRAITS
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


/*
** ------------------------------------------------------------ REVERSE ITERATOR
*/
	// template <class Iterator>
	// class reverse_iterator
	// {
	// 	public :

	// 		typedef typename iterator_type											Iterator;
	// 		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	// 		typedef typename iterator_traits<Iterator>::value_type			value_type;
	// 		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	// 		typedef typename iterator_traits<Iterator>::pointer				pointer;
	// 		typedef typename iterator_traits<Iterator>::reference			reference;

	// 	/*------------------------- MEMBER FUNCTIONS -------------------------*/
	// 	// default (1)
	// 		reverse_iterator(){}

	// 	// initialization (2)	
	// 		explicit reverse_iterator (iterator_type it);

	// 	// copy (3)	
	// 		template <class Iter>
	// 		reverse_iterator (const reverse_iterator<Iter>& rev_it);

	// };
}

#endif