#pragma once
#include <stdint.h>
#include <type_traits>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
/**
 * @brief Print ip address presented as integer type
 * 
 * @tparam T Integer type
 * @param val IP value
 * @return void
 */
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
/**
 * @brief Print ip address presented as container
 * 
 * @tparam T Container type
 * @param container Container
 * @return void
 */
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
/**
 * @brief Print ip address
 * 
 * @param ip IP address string
 * @return void
 */
void print_ip(const std::string &ip)
{
    std::cout << ip << std::endl;
}
