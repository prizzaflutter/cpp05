#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class MyCustomException : public std::exception {
    public : 
        virtual const char* what() const throw (){
            return "Error: Value not found in container!";
        }
};

template <typename T>

typename T::iterator easyfind(T& c, int v){
    typename T::iterator it = std::find(c.begin(), c.end(), v);

    if (it == c.end()){
        throw MyCustomException();
    }
    return it;
}

#endif