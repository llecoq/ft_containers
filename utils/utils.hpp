/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:08:10 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/08 18:15:24 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "vector.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	struct data
	{
		typedef	Alloc											allocator_type;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::size_type				size_type;

		pointer													_begin;
		pointer													_end;
		size_type												_size;
	};

	template < typename T >
	void	displayVec(T vec)
	{
		typename T::iterator	it = vec.begin();

		std::cout << "Vector contains :" << std::endl;
		while (it++ != vec.end())
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

#endif