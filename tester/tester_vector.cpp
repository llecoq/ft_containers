/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_vector.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:26:55 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/04 12:02:29 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector.hpp"
#include "../utils/tester.hpp"

int	tester_vector(std::string library)
{
	if (library == "ft")
	{
	// 	std::ofstream	outputFile("tester_results/vector_ft.test");

	// 	/*----------------------------- ITERATOR -----------------------------*/
	// 	{
	// 		ft::vector<int>				vec(5, 10);
	// 		ft::vector<int>::iterator	it = vec.begin();
	// 		ft::vector<int>::iterator	itcopy(it);
	// 		ft::vector<int>::iterator	ittmp = it;
	// 		if (it == itcopy)
	// 			outputFile << "it == itcopy" << std::endl;
		
	// 		/*-------------------- MEMBER ACCESS */
	// // A CHANGER EN FT AATTEEEEEENNNTIOOOONNNNNNNNNNNNNNN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// 		ft::vector<TestClass>				michel;
	// 		michel.push_back(TestClass());
	// 		ft::vector<TestClass>::iterator	iterClass = michel.begin();
			
	// 		// indirection to rvalue
	// 		outputFile << *it << std::endl;
	// 		// member pointer
	// 		outputFile << iterClass->getName() << std::endl;
	// 		// indirection
	// 		int	m = *it;
	// 		outputFile << m << std::endl;

	// 		/*------------------------ INCREMENT */
	// 		ittmp = ++it;
	// 		if (ittmp != vec.begin())
	// 			outputFile << "pre incrementation OK" << std::endl;
	// 		else
	// 			outputFile << "pre incrementation KO" << std::endl;
	// 		ittmp = itcopy++;
	// 		if (ittmp == vec.begin() && itcopy == it)
	// 			outputFile << "post incrementation OK" << std::endl;
	// 		else
	// 			outputFile << "post incrementation KO" << std::endl;
	// 		// ft::vector<int>::const_iterator	constit = vec.begin();
			
	// 		/*------------------------ DECREMENT */
	// 		it = vec.end();
	// 		ittmp = --it;
	// 		if (ittmp != vec.end())
	// 			outputFile << "pre decrementation OK" << std::endl;
	// 		else
	// 			outputFile << "pre decrementation KO" << std::endl;
	// 		itcopy = vec.end();
	// 		ittmp = itcopy--;
	// 		if (itcopy != vec.end() && ittmp == vec.end())
	// 			outputFile << "post decrementation OK" << std::endl;
	// 		else
	// 			outputFile << "post decrementation KO" << std::endl;
	// 		ft::vector<int>::iterator	ite = vec.end();
	// 		if (it != ite)
	// 			outputFile << "it != ite" << std::endl;
	// 		it = vec.begin();
	// 		outputFile << *it-- << std::endl;
	// 		outputFile << *it << std::endl;
			
	// 		/*----------------------- ARITHMETIC */
	// 		it = vec.begin() + 5;
	// 		if (it == vec.end())
	// 			outputFile << "arithemtic operator a + n OK" << std::endl;
	// 		else
	// 			outputFile << "arithemtic operator a + n KO" << std::endl;
	// 		it = 5 + vec.begin();
	// 		if (it == vec.end())
	// 			outputFile << "arithemtic operator n + a OK" << std::endl;
	// 		else
	// 			outputFile << "arithemtic operator n + a KO" << std::endl;
	// 		it = vec.end() - 5;
	// 		if (it == vec.begin())
	// 			outputFile << "arithemtic operator a - n OK" << std::endl;
	// 		else
	// 			outputFile << "arithemtic operator a - n KO" << std::endl;
	// 		outputFile << vec.end() - ++vec.begin() << std::endl;

	// 		/*------------ INEQUALITY RELATIONAL */
	// 		if (vec.begin() < vec.end())
	// 			outputFile << "inequality relational < operator OK" << std::endl;
	// 		else
	// 			outputFile << "inequality relational < operator KO" << std::endl;
	// 		if (vec.end() > vec.begin())
	// 			outputFile << "inequality relational > operator OK" << std::endl;
	// 		else
	// 			outputFile << "inequality relational > operator KO" << std::endl;
	// 		if (vec.begin() <= vec.end() && vec.begin() <= vec.begin())
	// 			outputFile << "inequality relational <= operator OK" << std::endl;
	// 		else
	// 			outputFile << "inequality relational <= operator KO" << std::endl;
	// 		if (vec.end() >= vec.begin() && vec.end() >= vec.end())
	// 			outputFile << "inequality relational >= operator OK" << std::endl;
	// 		else
	// 			outputFile << "inequality relational >= operator KO" << std::endl;
		
	// 		/*-------------- COMPOUND ASSIGNMENT */
	// 		if ((vec.begin() += 5) == vec.end())
	// 			outputFile << "compound assignment += OK" << std::endl;
	// 		else
	// 			outputFile << "compound assignment += KO" << std::endl;
	// 		if ((vec.end() -= 5) == vec.begin())
	// 			outputFile << "compound assignment -= OK" << std::endl;
	// 		else
	// 			outputFile << "compound assignment -= KO" << std::endl;

	// 		/*------------------------ SUBSCRIPT */
	// 		outputFile << it[2] << std::endl;
	// 	}

	// 	/*----------------------------- CAPACITY -----------------------------*/
	// 		/*--------------------------- SIZE -------------------------------*/
	// 	{
	// 		ft::vector<int>			vec(5, 10);
	// 		ft::vector<int>			empty;
	// 		ft::vector<TestClass>	testClass;

	// 		outputFile << vec.size() << std::endl;
	// 		outputFile << empty.size() << std::endl;
	// 		outputFile << testClass.size() << std::endl;
	// 	}
	// 		/*------------------------- MAX_SIZE -----------------------------*/
	// 	{
	// 		ft::vector<int>			vec_int;
	// 		ft::vector<char>		vec_char;
	// 		ft::vector<TestClass>	testClass;

	// 		outputFile << vec_int.max_size() << std::endl;
	// 		outputFile << vec_char.max_size() << std::endl;
	// 		outputFile << testClass.max_size() << std::endl;
	// 		try
	// 		{
	// 			ft::vector<int>	vec(-1, 10);
	// 		}
	// 		catch(const std::exception& e)
	// 		{
	// 			outputFile << e.what() << std::endl;
	// 		}
	// 	}
	// 		/*-------------------------- RESIZE ------------------------------*/
	// 	{
			
	// 	}
	// 		/*------------------------- CAPACITY -----------------------------*/
	// 	{
	// 		ft::vector<int>		vec(5, 100);

	// 		outputFile << vec.capacity() << std::endl;
	// 	}
	// 	return (0);
	}

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

// 	else if (library == "std")
// 	{
// 		std::ofstream	outputFile("tester_results/vector_std.test");

// //STD	/*----------------------------- ITERATOR -----------------------------*/
// 		{
// 			std::vector<int>					vec(5, 10);
// 			std::vector<int>::iterator			it = vec.begin();
// 			std::vector<int>::iterator			itcopy(it);
// 			std::vector<int>::iterator			ittmp = it;
// 			if (it == itcopy)
// 				outputFile << "it == itcopy" << std::endl;
		
// //STD		/*-------------------- MEMBER ACCESS */
// 			std::vector<TestClass>				michel;
// 			michel.push_back(TestClass());
// 			michel.push_back(TestClass());
// 			std::vector<TestClass>::iterator	iterClass = michel.begin();
			
// 			// indirection to rvalue
// 			outputFile << *it << std::endl;
// 			// member pointer
// 			outputFile << iterClass->getName() << std::endl;
// 			// indirection to lvalue
// 			int	m = *it;
// 			outputFile << m << std::endl;

// //STD		/*------------------------ INCREMENT */
// 			ittmp = ++it;
// 			if (ittmp != vec.begin())
// 				outputFile << "pre incrementation OK" << std::endl;
// 			ittmp = itcopy++;
// 			if (ittmp == vec.begin() && itcopy == it)
// 				outputFile << "post incrementation OK" << std::endl;
// 			// std::vector<int>::const_iterator	constit = vec.begin();
			
// //STD		/*------------------------ DECREMENT */
// 			it = vec.end();
// 			ittmp = --it;
// 			if (ittmp != vec.end())
// 				outputFile << "pre decrementation OK" << std::endl;
// 			itcopy = vec.end();
// 			ittmp = itcopy--;
// 			if (itcopy != vec.end() && ittmp == vec.end())
// 				outputFile << "post decrementation OK" << std::endl;
// 			std::vector<int>::iterator	ite = vec.end();
// 			if (it != ite)
// 				outputFile << "it != ite" << std::endl;
// 			it = vec.begin();
// 			outputFile << *it-- << std::endl;
// 			outputFile << *it << std::endl;
			
// //STD		/*----------------------- ARITHMETIC */
// 			it = vec.begin() + 5;
// 			if (it == vec.end())
// 				outputFile << "arithemtic operator a + n OK" << std::endl;
// 			it = 5 + vec.begin();
// 			if (it == vec.end())
// 				outputFile << "arithemtic operator n + a OK" << std::endl;
// 			it = vec.end() - 5;
// 			if (it == vec.begin())
// 				outputFile << "arithemtic operator a - n OK" << std::endl;
// 			outputFile << vec.end() - ++vec.begin() << std::endl;

// //STD		/*------------ INEQUALITY RELATIONAL */
// 			if (vec.begin() < vec.end())
// 				outputFile << "inequality relational < operator OK" << std::endl;
// 			if (vec.end() > vec.begin())
// 				outputFile << "inequality relational > operator OK" << std::endl;
// 			if (vec.begin() <= vec.end() && vec.begin() <= vec.begin())
// 				outputFile << "inequality relational <= operator OK" << std::endl;
// 			if (vec.end() >= vec.begin() && vec.end() >= vec.end())
// 				outputFile << "inequality relational >= operator OK" << std::endl;
			
// //STD		/*-------------- COMPOUND ASSIGNMENT */
// 			if ((vec.begin() += 5) == vec.end())
// 				outputFile << "compound assignment += OK" << std::endl;
// 			if ((vec.end() -= 5) == vec.begin())
// 				outputFile << "compound assignment -= OK" << std::endl;

// //STD		/*------------------------ SUBSCRIPT */
// 			outputFile << it[2] << std::endl;

// //STD	/*------------------------- REVERSE ITERATOR -------------------------*/
// 		{
			
// 		}

// 		}
// //STD	/*----------------------------- CAPACITY -----------------------------*/
// 			/*--------------------------- SIZE -------------------------------*/
// 		{
// 			std::vector<int>		vec(5, 10);
// 			std::vector<int>		empty;
// 			std::vector<TestClass>	testClass;

// 			outputFile << vec.size() << std::endl;
// 			outputFile << empty.size() << std::endl;
// 			outputFile << testClass.size() << std::endl;
// 		}
// //STD		/*------------------------- MAX_SIZE -----------------------------*/
// 		{
// 			std::vector<int>		vec_int;
// 			std::vector<char>		vec_char;
// 			std::vector<TestClass>	testClass;

// 			outputFile << vec_int.max_size() << std::endl;
// 			outputFile << vec_char.max_size() << std::endl;
// 			outputFile << testClass.max_size() << std::endl;
// 			try
// 			{
// 				std::vector<int>	vec(-1, 10);
// 			}
// 			catch(const std::exception& e)
// 			{
// 				outputFile << e.what() << std::endl;
// 			}
// 		}
// //STD		/*-------------------------- RESIZE ------------------------------*/
// 		{
			
// 		}
// //STD		/*------------------------- CAPACITY -----------------------------*/
// 		{
// 			std::vector<int>		vec(5, 100);

// 			outputFile << vec.capacity() << std::endl;
// 		}
// 		return (0);
// 	}
	return (ERROR);
}