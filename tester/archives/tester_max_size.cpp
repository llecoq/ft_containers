/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_max_size.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:17:29 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 16:42:32 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_max_size(void)
{
	ft::vector<int>			vec_int;
	ft::vector<char>			vec_char;
	ft::vector<double>			vec_double;
	ft::vector<float>			vec_float;
	ft::vector<long>			vec_long;
	ft::vector<const char>		vec_const_char;
	ft::vector<const int>		vec_const_int;
	ft::vector<TestClass>		vec_class;

	std::cout << "vec_int max_size = " << vec_int.max_size() << std::endl;
	std::cout << "vec_char max_size = " << vec_char.max_size() << std::endl;
	std::cout << "vec_double max_size = " << vec_double.max_size() << std::endl;
	std::cout << "vec_float max_size = " << vec_float.max_size() << std::endl;
	std::cout << "vec_long max_size = " << vec_long.max_size() << std::endl;
	std::cout << "vec_const char max_size = " << vec_const_char.max_size() << std::endl;
	std::cout << "vec_const int max_size = " << vec_const_int.max_size() << std::endl;
	std::cout << "vec_int TestClass = " << vec_class.max_size() << std::endl;
}