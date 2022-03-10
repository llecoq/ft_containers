/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_copy_assignment.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:43:44 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/10 14:49:49 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_copy_assignment()
{
	std::vector<TestClass>	vec(5, 100);
	std::vector<TestClass>	vec_2;

	ft::pushBackVec(vec_2);

	ft::displayData(vec, "vec");
	ft::displayVec(vec);
	ft::displayData(vec_2, "vec_2");
	ft::displayVec(vec_2);

	vec_2 = vec;
	ft::displayData(vec_2, "vec_2");
	ft::displayVec(vec_2);

	std::vector<TestClass>	vec_3 = vec;
}
