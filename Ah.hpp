#ifndef AH_HPP
# define AH_HPP

# include <iostream>
# include <string>

class Ah
{

	public:

		Ah();
		Ah(int	i);
		Ah( Ah const & src );
		~Ah();

		Ah &		operator=( Ah const & rhs );

		int	n;

	private:

};

std::ostream &			operator<<( std::ostream & o, Ah const & i );

#endif /* ************************************************************** AH_H */