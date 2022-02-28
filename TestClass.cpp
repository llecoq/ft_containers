/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:16:44 by llecoq            #+#    #+#             */
/*   Updated: 2022/01/13 14:43:37 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestClass.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

TestClass::TestClass() : _grade(150), _name("Michel")
{
	std::cout << "TESTCLASS DEFAULT CONSTRUCTOR" << std::endl;
}

TestClass::TestClass( const TestClass & src ) : _name("Michel")
{
	std::cout << "TESTCLASS COPY CONSTRUCTOR" << std::endl;

	_grade = src._grade;
}

TestClass::TestClass( std::string name, int grade ) : _grade(grade), _name(name)
{
	std::cout << "TESTCLASS STRING CONSTRUCTOR" << std::endl;

	if (grade > 150)
	{
		std::cerr << name << "'s grade is " << grade << " " ;
		throw TestClass::GradeTooLowException();
	}
	else if (grade < 1)
	{
		std::cerr << name << "'s grade = " << grade << " " ;
		throw TestClass::GradeTooHighException();
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

TestClass::~TestClass()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

TestClass &				TestClass::operator=( TestClass const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, TestClass const & i )
{
	o << i.getName() << ", TestClass grade " << i.getGrade() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	TestClass::incrementGrade()
{
	std::cerr << "* try to increment grade *" << std::endl;
	if (_grade <= 1)
	{
		std::cerr << "Cannot increment grade !!! ";
		throw (TestClass::GradeTooHighException());
	}
	else 
		_grade--;
}

void	TestClass::decrementGrade()
{
	std::cerr << "* try to decrement grade *" << std::endl;
	if (_grade >= 150)
	{
		std::cerr << "Cannot decrement grade !!! ";
		throw (TestClass::GradeTooLowException());
	}
	else
		_grade++;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	TestClass::getGrade( void ) const
{
	return (_grade);
}

std::string const	TestClass::getName( void ) const
{
	return (_name);
}

/*
** --------------------------------- EXCEPTION ---------------------------------
*/

const char *	TestClass::GradeTooHighException::what() const throw()
{
	return ("grade is too high.");
}

const char *	TestClass::GradeTooLowException::what() const throw()
{
	return ("grade is too low.");
}

/* ************************************************************************** */