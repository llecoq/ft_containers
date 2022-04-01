/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_copy_assignment.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:43:44 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/01 14:23:02 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_copy_assignment()
{
	ft::vector<TestClass>	vec(5, 100);
	ft::vector<TestClass>	vec_2;

	ut::pushBackVec(vec_2);

	ut::displayData(vec, "vec");
	ut::displayVec(vec);
	ut::displayData(vec_2, "vec_2");
	ut::displayVec(vec_2);

	vec_2 = vec;
	ut::displayData(vec_2, "vec_2");
	ut::displayVec(vec_2);

	ft::vector<TestClass>	vec_3 = vec;
	ut::displayData(vec_3, "vec_3");
	ut::displayVec(vec_3);
}
