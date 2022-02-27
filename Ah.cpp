#include "Ah.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ah::Ah()
{
	n = 0;
	std::cout << "Ah default constructor" << std::endl;
}

Ah::Ah(int i) : n(i)
{
	std::cout << "Ah int i constructor" << std::endl;
}

Ah::Ah( const Ah & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ah::~Ah()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ah &				Ah::operator=( Ah const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Ah const & i )
{
	o << "Value = " << i.n;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */