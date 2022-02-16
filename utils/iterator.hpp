/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:19:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/02/16 16:23:13 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
	template <class Category,          // iterator::iterator_category
          class T,                     // iterator::value_type
          class Distance = ptrdiff_t,  // iterator::difference_type
          class Pointer = T*,          // iterator::pointer
          class Reference = T&         // iterator::reference
          >
	class iterator
	{
		public :

	};
}

#endif