/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:23:40 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/11 11:47:29 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestClass.hpp"

std::ostream	&operator<<(std::ostream &output, const TestClass &rhs)
{
	output << rhs.getName() << " " << rhs.getNumber() << " i = " << rhs.getI();
	return output;
};

int TestClass::objectCount = 0;