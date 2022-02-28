/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_vector.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:26:55 by llecoq            #+#    #+#             */
/*   Updated: 2022/02/28 19:26:42 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.hpp"
#include "utils/tester.hpp"

int	tester_vector(std::string library)
{
	if (library == "ft")
	{
		std::ofstream	output_file("tester_results/vector_ft.test");

		/*----------------------------- ITERATOR -----------------------------*/
		{
			ft::vector<int>				vec(5, 10);
			ft::vector<int>::iterator	it = vec.begin();
			ft::vector<int>::iterator	itcopy(it);
			ft::vector<int>::iterator	ittmp = it;
			if (it == itcopy)
				output_file << "it == itcopy" << std::endl;
		
			/*-------------------- MEMBER ACCESS */
			output_file << *it << std::endl;

			/*------------------------ INCREMENT */
			ittmp = ++it;
			if (ittmp != vec.begin())
				output_file << "pre incrementation OK" << std::endl;
			ittmp = itcopy++;
			if (ittmp == vec.begin() && itcopy == it)
				output_file << "post incrementation OK" << std::endl;
			// ft::vector<int>::const_iterator	constit = vec.begin();
			
			/*------------------------ DECREMENT */
			it = vec.end();
			ittmp = --it;
			if (ittmp != vec.end())
				output_file << "pre decrementation OK" << std::endl;
			itcopy = vec.end();
			ittmp = itcopy--;
			if (itcopy != vec.end() && ittmp == vec.end())
				output_file << "post decrementation OK" << std::endl;
			ft::vector<int>::iterator	ite = vec.end();
			if (it != ite)
				output_file << "it != ite" << std::endl;
			
			/*----------------------- ARITHMETIC */
			it = vec.begin() + 5;
			if (it == vec.end())
				output_file << "arithemtic operator a + n OK" << std::endl;
			it = 5 + vec.begin();
			if (it == vec.end())
				output_file << "arithemtic operator n + a OK" << std::endl;
			it = vec.end() - 5;
			if (it == vec.begin())
				output_file << "arithemtic operator a - n OK" << std::endl;
			output_file << vec.end() - ++vec.begin() << std::endl;

			/*------------ INEQUALITY RELATIONAL */
			if (vec.begin() < vec.end())
				output_file << "inequality relational < operator OK" << std::endl;
			if (vec.end() > vec.begin())
				output_file << "inequality relational > operator OK" << std::endl;
			if (vec.begin() <= vec.end() && vec.begin() <= vec.begin())
				output_file << "inequality relational <= operator OK" << std::endl;
			if (vec.end() >= vec.begin() && vec.end() >= vec.end())
				output_file << "inequality relational >= operator OK" << std::endl;
		
			/*-------------- COMPOUND ASSIGNMENT */
			if ((vec.begin() += 5) == vec.end())
				output_file << "compound assignment += OK" << std::endl;
			if ((vec.end() -= 5) == vec.begin())
				output_file << "compound assignment -= OK" << std::endl;
		}

		/*----------------------------- CAPACITY -----------------------------*/
			/*--------------------------- SIZE -------------------------------*/
		{
			ft::vector<int>			vec(5, 10);
			ft::vector<int>			empty;
			ft::vector<TestClass>	testClass;

			output_file << vec.size() << std::endl;
			output_file << empty.size() << std::endl;
			output_file << testClass.size() << std::endl;
		}
			/*------------------------- MAX_SIZE -----------------------------*/
		{
			ft::vector<int>			vec_int;
			ft::vector<char>		vec_char;
			ft::vector<TestClass>	testClass;

			output_file << vec_int.max_size() << std::endl;
			output_file << vec_char.max_size() << std::endl;
			output_file << testClass.max_size() << std::endl;
			try
			{
				ft::vector<int>	vec(-1, 10);
			}
			catch(const std::exception& e)
			{
				output_file << e.what() << std::endl;
			}
		}
			/*-------------------------- RESIZE ------------------------------*/
		{
			
		}
			/*------------------------- CAPACITY -----------------------------*/
		{
			ft::vector<int>		vec(5, 100);

			output_file << vec.capacity() << std::endl;
		}
		return (0);
	}
	else if (library == "std")
	{
		std::ofstream	output_file("tester_results/vector_std.test");

		/*----------------------------- ITERATOR -----------------------------*/
		{
			std::vector<int>				vec(5, 10);
			std::vector<int>::iterator	it = vec.begin();
			std::vector<int>::iterator	itcopy(it);
			std::vector<int>::iterator	ittmp = it;
			if (it == itcopy)
				output_file << "it == itcopy" << std::endl;
		
			/*-------------------- MEMBER ACCESS */
			output_file << *it << std::endl;

			/*------------------------ INCREMENT */
			ittmp = ++it;
			if (ittmp != vec.begin())
				output_file << "pre incrementation OK" << std::endl;
			ittmp = itcopy++;
			if (ittmp == vec.begin() && itcopy == it)
				output_file << "post incrementation OK" << std::endl;
			// std::vector<int>::const_iterator	constit = vec.begin();
			
			/*------------------------ DECREMENT */
			it = vec.end();
			ittmp = --it;
			if (ittmp != vec.end())
				output_file << "pre decrementation OK" << std::endl;
			itcopy = vec.end();
			ittmp = itcopy--;
			if (itcopy != vec.end() && ittmp == vec.end())
				output_file << "post decrementation OK" << std::endl;
			std::vector<int>::iterator	ite = vec.end();
			if (it != ite)
				output_file << "it != ite" << std::endl;
			
			/*----------------------- ARITHMETIC */
			it = vec.begin() + 5;
			if (it == vec.end())
				output_file << "arithemtic operator a + n OK" << std::endl;
			it = 5 + vec.begin();
			if (it == vec.end())
				output_file << "arithemtic operator n + a OK" << std::endl;
			it = vec.end() - 5;
			if (it == vec.begin())
				output_file << "arithemtic operator a - n OK" << std::endl;
			output_file << vec.end() - ++vec.begin() << std::endl;

			/*------------ INEQUALITY RELATIONAL */
			if (vec.begin() < vec.end())
				output_file << "inequality relational < operator OK" << std::endl;
			if (vec.end() > vec.begin())
				output_file << "inequality relational > operator OK" << std::endl;
			if (vec.begin() <= vec.end() && vec.begin() <= vec.begin())
				output_file << "inequality relational <= operator OK" << std::endl;
			if (vec.end() >= vec.begin() && vec.end() >= vec.end())
				output_file << "inequality relational >= operator OK" << std::endl;
			
			/*-------------- COMPOUND ASSIGNMENT */
			if ((vec.begin() += 5) == vec.end())
				output_file << "compound assignment += OK" << std::endl;
			if ((vec.end() -= 5) == vec.begin())
				output_file << "compound assignment -= OK" << std::endl;

		}
		/*----------------------------- CAPACITY -----------------------------*/
			/*--------------------------- SIZE -------------------------------*/
		{
			std::vector<int>		vec(5, 10);
			std::vector<int>		empty;
			std::vector<TestClass>	testClass;

			output_file << vec.size() << std::endl;
			output_file << empty.size() << std::endl;
			output_file << testClass.size() << std::endl;
		}
			/*------------------------- MAX_SIZE -----------------------------*/
		{
			std::vector<int>		vec_int;
			std::vector<char>		vec_char;
			std::vector<TestClass>	testClass;

			output_file << vec_int.max_size() << std::endl;
			output_file << vec_char.max_size() << std::endl;
			output_file << testClass.max_size() << std::endl;
			try
			{
				std::vector<int>	vec(-1, 10);
			}
			catch(const std::exception& e)
			{
				output_file << e.what() << std::endl;
			}
		}
			/*-------------------------- RESIZE ------------------------------*/
		{
			
		}
			/*------------------------- CAPACITY -----------------------------*/
		{
			std::vector<int>		vec(5, 100);

			output_file << vec.capacity() << std::endl;
		}
		return (0);
	}
	return (ERROR);
}