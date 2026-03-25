#include "ScalarConverter.hpp"

static bool isChar(const std::string &str)
{
    if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]))
    {
        return true;
    }
    return false;
}
static bool isInt(const std::string &str)
{
    if (str.empty())
        return false;
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;

    if (i == str.length())
        return false;

    for (; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}
static bool isFloat(const std::string &str)
{
    if (str.empty())
        return false;
    if (str[str.length() - 1] != 'f')
        return false;
    size_t i = 0;
    bool hasDicimal = false;
    bool hasDigits = false;

    if (str[i] == '-' || str[i] == '+')
    {
        i++;
    }

    for (; i < str.length() - 1; i++)
    {
        if (isdigit(str[i]))
        {
            hasDigits = true;
        }
        else if (str[i] == '.')
        {
            if (hasDicimal)
                return false;
            hasDicimal = true;
        }
        else
        {
            return false;
        }
    }
    return hasDigits && hasDicimal;
}
static bool isDouble(const std::string &str)
{
    if (str.empty())
        return false;

    bool hasDicimal = false;
    bool hasDigits = false;
    size_t i = 0;

    if (str[i] == '-' || str[i] == '+')
    {
        i++;
    }
    for (; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            hasDigits = true;
        }
        else if (str[i] == '.')
        {
            if (hasDicimal)
                return false;
            hasDicimal = true;
        }
        else
        {
            return false;
        }
    }
    return hasDigits && hasDicimal;
}

ScalarConverter::ScalarConverter(void)
{
    std::cout << "default constructor called" << std::endl;
};
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
    std::cout << "copy constructor called" << std::endl;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter()
{
    std::cout << "destructor called" << std::endl;
};

void ScalarConverter::convert(const std::string &literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "nanf" || literal == "-inff" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (literal == "nan" || literal == "+inf" || literal == "-inf")
        {
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
        else
        {
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        }
        return;
    }

    if (isChar(literal))
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (isInt(literal))
    {
        double d = std::strtod(literal.c_str(), NULL);
        std::cout << "char: ";
        if (d < 0 || d > 127)
            std::cout << "impossible\n";
        else if (!isprint(static_cast<int>(d)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(d) << "'\n";
        std::cout << "int: ";
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        {
            std::cout << "impossible\n";
        }
        else
        {
            std::cout << static_cast<int>(d) << "\n";
        }
        std::cout << "float: " << static_cast<float>(d) << ".0f\n";
        std::cout << "double: " << d << ".0\n";
    }
    else if (isFloat(literal) || isDouble(literal))
    {
        double d = std::strtod(literal.c_str(), NULL);
        std::cout << "char: ";
        if (d < 0 || d > 127)
            std::cout << "impossible\n";
        else if (!isprint(static_cast<int>(d)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(d) << "'\n";
        std::cout << "int: ";
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        {
            std::cout << "impossible\n";
        }
        else
        {
            std::cout << static_cast<int>(d) << "\n";
        }
        std::cout << "float: ";
        float f
         = static_cast<float>(d);
        if (f - static_cast<int>(f) == 0)
            std::cout << f << ".0f\n";
        else
            std::cout << f << "f\n";
        std::cout << "double: ";
        if (d - static_cast<int>(d) == 0)
            std::cout << d << ".0\n";
        else
            std::cout << d << "\n";
    }
    else
    {
        std::cout << "Error: Unknown literal type." << std::endl;
    }
}