/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:49:09 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/04 13:02:08 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TestClass.hpp"
#include "../containers/vector.hpp"

int		tester_vector(std::string library);
void	tester_push_back(void);
void	tester_reverse_iterator(void);
void	tester_resize(void);
void	tester_reserve(void);
void	tester_pop_back(void);
void	tester_copy_constructor(void);
void	tester_element_access(void);

#define ERROR 1

#endif