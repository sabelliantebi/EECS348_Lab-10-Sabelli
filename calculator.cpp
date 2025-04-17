#include "calculator.hpp"
#include <iostream>  
#include <cctype> //for isdigit
#include <cstdlib> //for std::stod

bool is_valid_double(const std::string &str) { //funct to check if the string is a valid double num
    int i = 0;  //to later use for loops
    int len = str.length();  //lenght of the string we get
    bool seen_digit = false;  //to track if there are digits
    bool seen_decimal = false;  //track to see if there was a decimal point 

    if (len == 0) return false; //if it is empty then it is not valid 

    //optional sign
    if (str[i] == '+' || str[i] == '-') {
        i++;
        if (i == len) return false; //can't just be "+" or "-"
    }

    for (; i < len; ++i) {
        char c = str[i];

        if (isdigit(c)) {
            seen_digit = true; //mark that we saw at least one digit
        } else if (c == '.') {
            if (seen_decimal) return false; //can't have two dots
            seen_decimal = true;

            //dot can't be the last character
            if (i == len - 1) return false;
        } else {
            return false; //invalid character
        }
    }

    return seen_digit; //must have at least one digit
}

//this function adds two valid double formatted strings and returns the result as string
std::string add_doubles(const std::string &a, const std::string &b) {
    //these are valid numbers already, so use stod
    double x = parse_number(a);
    double y = parse_number(b);
    double sum = x + y;

    //convert back to string with some precision
    return std::to_string(sum);
}

//this function is only called after validation, so use stod
double parse_number(const std::string &expression) {
    return std::stod(expression); //allowed only here
}