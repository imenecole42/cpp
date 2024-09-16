#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	return(*this);
}
ScalarConverter::~ScalarConverter()
{

}
bool	ScalarConverter::checkChar(std::string str) 
{
	char	c;
	if (str.length() != 1)
		return false;
	c = str[0];
	if ((c >= 32 && c < 48) || (c >= 58 && c < 127))
		return true;
	return  false;
}
bool ScalarConverter ::checkInt(std::string str)
{
	std::istringstream istr(str);
	int nb;
	//interprete la prochaine valeur en int et le stocker dans nb
	istr >> nb ;
	// verif si la chaîne a pu être interprétée comme un entier avec succès.istr.fail
	//vérifie si istr est arrivé à la fin de la chaîne
	if(!istr.fail() && istr.eof())
		return(true);
	return(false);
}
bool ScalarConverter ::checkFloat(std::string str)
{
	std::istringstream istr(str);
	float	nbr;
	char	c;
	//si la chaîne n'est pas un nombre à virgule flottante valide
	if (!(istr >> nbr)) 
		return false;
	istr >> c;
	//verifie si nbr apres virgule est un 'f'
	if (c != 'f')
		return false;
	return true;
}
bool ScalarConverter ::checkDouble(std::string str)
{
	std::istringstream iss(str);
	double	d;
	char	c;

	if (!(iss >> d) || (iss >> c))
			return false;
	return true;
}
bool	ScalarConverter::checkExcep(std::string str) 
{
	return(str == "+inf" || str == "-inf" || str == "nan"|| str == "+inff" || str == "-inff" || str == "nanf");		
}

int		ScalarConverter::convert_int(std::string str)
{
	std::istringstream istr(str);
	int	nb;
	istr >> nb;
	return (nb);
}

char	ScalarConverter::convert_char(std::string str)
{
	return (str[0]);
}

float	ScalarConverter::convert_float(std::string str)
{
	std::istringstream istr(str);
	float	f;
	istr >> f;
	return (f);
}

double	ScalarConverter::convert_double(std::string str) 
{
	std::istringstream istr(str);
	double	d;
	istr >> d;
	return (d);
}
void	ScalarConverter::prChar(std::string str) {
	char c;
	try {
		c = convert_char(str);
		std::cout << "char		: " << c << std::endl;
		std::cout << "int		: " << static_cast<int>(c) << std::endl;
		std::cout << "float		: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double		: " << static_cast<double>(c) << std::endl;
	} 
	catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}
}

void	ScalarConverter::prInt(std::string str) {
	int nbr;
	try {
		nbr = convert_int(str);
		if (std::isprint(static_cast<char>(nbr)))
			std::cout << "char		: " << static_cast<char>(nbr) << std::endl;
		else
			std::cout << "char		: non displayable" << std::endl;
		std::cout << "int		: " << nbr << std::endl;
		std::cout << "float		: " << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double		: "<< static_cast<double>(nbr) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}
}

void	ScalarConverter::prFloat(std::string str) {
	float flot;
	try {
		flot = convert_float(str);
		if (std::isprint(static_cast<char>(flot)))
			std::cout << "char		: " << static_cast<char>(flot) << std::endl;
		else
			std::cout << "char		: non displayable" << std::endl;
		std::cout << "int		: " << static_cast<int>(flot) << std::endl;
		std::cout << "float		: " << flot << "f" << std::endl;
		std::cout << "double		: " << static_cast<double>(flot) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}
}

void	ScalarConverter::prDouble(std::string str) {
	double d;
	try {
		d = convert_double(str);
		if (std::isprint(static_cast<char>(d)))
			std::cout << "char		: " << static_cast<char>(d) << std::endl;
		else
			std::cout << "char		: non displayable" << std::endl;
		std::cout << "int		: " << static_cast<int>(d) << std::endl;
		std::cout << "float		: " << static_cast<float>(d) << std::endl;
		std::cout << "double		: " << d << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}
}

void	ScalarConverter::prExcep(std::string str) {
	if (str == "nan" || str == "nanf") {
		std::cout << "char		: impossible" << std::endl;
		std::cout << "int		: impossible" << std::endl;
		std::cout << "float		: nanf" << std::endl;
		std::cout << "double		: nan" << std::endl;
	} else if (str == "+inf" || str == "+inff") {
		std::cout << "char		: impossible" << std::endl;
		std::cout << "int		: impossible" << std::endl;
		std::cout << "float		: +inff" << std::endl;
		std::cout << "double		: +inf" << std::endl;
	} else if (str == "-inf" || str == "-inf") {
		std::cout << "char		: impossible" << std::endl;
		std::cout << "int		: impossible" << std::endl;
		std::cout << "float		: -inff" << std::endl;
		std::cout << "double		: -inf" << std::endl;
	}
}
void	ScalarConverter::convert(std::string str) {
	if (checkChar(str))
	{
		prChar(str);
	} 
	else if (checkInt(str)) 
	{
		prInt(str);
	} 
	else if (checkFloat(str)) 
	{
		prFloat(str);

	} 
	else if (checkDouble(str)) 
	{
		prDouble(str);		

	} 
	else if (checkExcep(str)) 
	{
		prExcep(str);
	}
}
const char* ScalarConverter::BadInputException::what() const throw() {
	return "Bad input ! Use Brain please";
}