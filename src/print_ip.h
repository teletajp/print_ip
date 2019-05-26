#pragma once
#include <stdint.h>
#include <type_traits>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

template<typename T>
std::enable_if_t<std::is_integral<T>::value,void> print_ip(const T &val )
{
    const uint8_t *bytes = (uint8_t*)&val;
    for(int i = sizeof(T)-1; i >= 0 ; --i)
    {
        std::cout<< int(bytes[i]);
        i ? std::cout<<'.' : std::cout<<std::endl;
    }
}

template<typename T>
std::enable_if_t<std::is_same_v<std::vector<typename T::value_type>, T> 
|| std::is_same_v<std::list<typename T::value_type>, T>, void> print_ip(const T& container)
{
    for(auto it = container.begin(); it != container.end();)
    {
        std::cout<<int(*it);
        ++it;
        (it != container.end()) ? std::cout<<'.' : std::cout<<std::endl;
    }
}

template<typename T>
std::enable_if_t<std::is_same_v<std::string, T>, void> print_ip(const T& container)
{
    std::cout << container << std::endl;
}
