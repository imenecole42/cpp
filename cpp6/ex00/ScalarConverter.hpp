#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <string>
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &cpy);
	public:
		~ScalarConverter();
		class BadInputException : public std::exception {
			public:
				const char* what() const throw();
		};
		//check string 
		static bool checkInt(std::string str);
		static bool checkChar(std::string str);
		static bool checkFloat(std::string str);
		static bool checkDouble(std::string str);
		static bool checkExcep(std::string str);
		//converti string
		static int convert_int(std::string str);
		static char convert_char(std::string str);
		static float convert_float(std::string str);
		static double convert_double(std::string str);
		//print message 
		static void prChar(std::string str);
		static void prInt(std::string str);
		static void prFloat(std::string str);
		static void prDouble(std::string str);
		static void prExcep(std::string str);
		//convert
		static void convert(std::string str);
};
#endif