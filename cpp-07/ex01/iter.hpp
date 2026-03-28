#ifndef ITER_HPP 
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T_arr, typename T_func>

void iter(T_arr* array, size_t length, T_func func){
    if(!array) return;
    for (size_t i = 0; i < length; i++){
        func(array[i]);
    }
};

#endif