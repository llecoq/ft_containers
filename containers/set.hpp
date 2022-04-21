/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:44:21 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/21 10:46:43 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

namespace ft
{

template  < class T,                        // set::key_type/value_type
			class Compare = std::less<T>,        // set::key_compare/value_compare
			class Alloc = std::allocator<T>      // set::allocator_type
			>
class set
{
	
};


}	// namespace ft


#endif