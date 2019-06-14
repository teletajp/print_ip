#pragma once
#include <stdint.h>
#include <type_traits>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

template< bool B, class T = void >
using enable_if_t = typename std::enable_if<B,T>::type;

template< class T, class U >
inline constexpr bool is_same_v = std::is_same<T, U>::value;

template< class T>
inline constexpr bool is_integral_v = std::is_integral<T>::value;
/**
 * @brief Print ip address presented as integer type
 * 
 * @tparam T Integer type
 * @param val IP value
 * @return void
 */
template<typename T>
enable_if_t<is_integral_v<T>,void> print_ip(const T &val )
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
enable_if_t<is_same_v<std::vector<typename T::value_type>, T> 
|| is_same_v<std::list<typename T::value_type>, T>, void> print_ip(const T& container)
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
