/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_vector.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:26:55 by llecoq            #+#    #+#             */
/*   Updated: 2022/02/27 15:51:36 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.hpp"
#include "utils/tester.hpp"
#include "Ah.hpp"

int	tester_vector(std::string library)
{
	if (library == "ft")
	{
		std::string		output_file_name = "tester_results/vector_ft.test";
		std::ofstream	output_file(output_file_name);
		/*----------------------------- CAPACITY -----------------------------*/
			/*--------------------------- SIZE -------------------------------*/
		{
			ft::vector<int>		vec(5, 10);
			ft::vector<int>		empty;
			ft::vector<Ah>		vec_class;

			output_file << vec.size() << std::endl;
			output_file << empty.size() << std::endl;
			output_file << vec_class.size() << std::endl;
		}
			/*------------------------- MAX_SIZE -----------------------------*/
		{
			ft::vector<int>		vec_int;
			ft::vector<char>	vec_char;
			ft::vector<Ah>		vec_class;

			output_file << vec_int.max_size() << std::endl;
			output_file << vec_char.max_size() << std::endl;
			output_file << vec_class.max_size() << std::endl;
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
		std::string		output_file_name = "tester_results/vector_std.test";
		std::ofstream	output_file(output_file_name);
		/*----------------------------- CAPACITY -----------------------------*/
			/*--------------------------- SIZE -------------------------------*/
		{
			std::vector<int>		vec(5, 10);
			std::vector<int>		empty;
			std::vector<Ah>			vec_class;

			output_file << vec.size() << std::endl;
			output_file << empty.size() << std::endl;
			output_file << vec_class.size() << std::endl;
		}
			/*------------------------- MAX_SIZE -----------------------------*/
		{
			std::vector<int>		vec_int;
			std::vector<char>	vec_char;
			std::vector<Ah>		vec_class;

			output_file << vec_int.max_size() << std::endl;
			output_file << vec_char.max_size() << std::endl;
			output_file << vec_class.max_size() << std::endl;
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