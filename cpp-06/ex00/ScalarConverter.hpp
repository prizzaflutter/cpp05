#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>
#include <cstddef>

class ScalarConverter {
    private: 
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void convert(const std::string& literal);
};

#endif