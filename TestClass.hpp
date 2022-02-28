/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:57:36 by llecoq            #+#    #+#             */
/*   Updated: 2022/01/18 13:35:50 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TestClass_HPP
# define TestClass_HPP

# include <iostream>
# include <string>

class Form;

class TestClass
{

	public:

		class	GradeTooHighException : public std::exception
		{
				virtual const char * what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
				virtual const char * what() const throw();
		};

		TestClass();
		TestClass( TestClass const & src );
		TestClass( std::string name, int grade );
		~TestClass();

		TestClass &	operator=( TestClass const & rhs );

		std::string const	getName() const;
		int					getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

	private:

		int					_grade;
		std::string const	_name;

};

std::ostream &			operator<<( std::ostream & o, TestClass const & i );

#endif /* ****************************************************** TestClass_H */