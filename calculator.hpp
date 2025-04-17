#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>

//This function should expect that `expression` has already been
//validated and thus throw no exceptions
double parse_number(const std::string &expression);

//this checks if a given string is a valid double based on the rules
bool is_valid_double(const std::string &str);

//this adds two double numbers that are given as strings
std::string add_strings(const std::string &a, const std::string &b);

std::string add_doubles(const std::string &a, const std::string &b);  

#endif // __CALCULATOR_HPP