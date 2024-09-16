
#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed( const int nbr );
		Fixed( const float nbr );
		Fixed( const Fixed & other );

		~Fixed();
		Fixed &	operator=( const Fixed & other);
		Fixed	operator+( const Fixed & other) const;
		Fixed	operator-( const Fixed & other) const;
		Fixed	operator*( const Fixed & other) const;
		Fixed	operator/( const Fixed & other) const;

		bool	operator>( const Fixed & fpn ) const;
		bool	operator<( const Fixed & fpn ) const;
		bool	operator>=( const Fixed & fpn ) const;
		bool	operator<=( const Fixed & fpn ) const;
		bool	operator==( const Fixed & fpn ) const;
		bool	operator!=( const Fixed & fpn ) const;

		Fixed &	operator++( void );
		Fixed	operator++( int );
		Fixed &	operator--( void );
		Fixed	operator--( int );

		int	getRawBits(void) const ;
		void setRawBits( int nbr);
		float	toFloat( void ) const;
		int		toInt( void ) const;

	static Fixed max(Fixed &a, Fixed &b);
	static const Fixed max(Fixed const &a, Fixed const &b);
	static Fixed min(Fixed &a, Fixed &b);
	static const Fixed min(Fixed const &a, Fixed const &b);

	private:

		int					_nbr;
		static const int	_bit = 8;
};
//ces opérateurs sont surchargés en tant que fonctions globales avec deux paramètres, cout et objet de classe définie par l'utilisateur
//On retourne un « ostream » pour permettre l'enchaînement des opérations sur la sortie standard
std::ostream & operator<<( std::ostream & o, Fixed const & other  );

#endif