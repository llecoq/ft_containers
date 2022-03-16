/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:49:09 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/16 16:45:57 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>

# include "TestClass.hpp"
# include "metafunctions.hpp"
# include "../containers/vector.hpp"
# include "../containers/stack.hpp"

int		tester_vector_ft();
int		tester_vector_std();
int		tester_pair_ft();
int		tester_pair_std();
int		tester_stack_ft();
int		tester_stack_std();

#define ERROR 1
#define SUCCESS 0

#endif