#include "ScalarConverter.hpp"

int main (int argc, char **argv){
   
   if (argc != 2){
      std::cout << "Error argc != 2" << std::endl;
      return 1;
   }
   std::string literal = argv[1];
   (void)literal;
   ScalarConverter::convert(literal);

   // int a = 10;
   // char c = 'a';

   // int*  q = (int*)&c;
   // int*  p = static_cast<int*>(&c);


   // std::cout << "The Value of q: " << q << std::endl;

   // std::cout << "The Value of p: " << p << std::endl;

   return 0;
}