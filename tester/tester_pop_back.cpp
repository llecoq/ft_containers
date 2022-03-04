/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_pop_back.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:48:53 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/04 13:54:54 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_pop_back(void)
{
	std::vector<int>	vec;
	// vec.pop_back(); // std::vector non protege, segfault
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	dprintf(2, "pop back\n");
	vec.pop_back();
	dprintf(2, "pop back done\n");

	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	
	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
}