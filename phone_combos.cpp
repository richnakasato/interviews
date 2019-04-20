/*
Problem: Given two strings, one containing only digits, the second containing
         only letters, determine if the letter string is a valid interpretation
         of the digits string

Example:
         Input:  "234", "ADG"
         Output: True


--------------------------------------------------------------------------------

Problem: Given a string containing only digits, return all possible string
         combinations that are valid interpretations of the digits string

Example:
         Input:  "2"
         Output: ["a", "b", "c"]

KEYPAD:
2   ABC
3   DEF
4   GHI
5   JKL
6   MNO
7   PQRS
8   TUV
9   WXYZ

*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool valid_combo(std::string n, std::string s)
{
    if (n.empty() != s.empty()) return false;
    static const std::unordered_map<char,std::string> keypad {{'0', ""},
                                                              {'1', ""},
                                                              {'2', "ABC"},
                                                              {'3', "DEF"},
                                                              {'4', "GHI"},
                                                              {'5', "JKL"},
                                                              {'6', "MNO"},
                                                              {'7', "PQRS"},
                                                              {'8', "TUV"},
                                                              {'9', "WXYZ"}};
    size_t lhs = 0;
    size_t rhs = 0;
    while (lhs < n.size() && rhs < s.size()) {
        std::string temp = keypad.at(n[lhs]);
        if (temp.size()
            && std::find_if(temp.begin(),
                            temp.end(),
                            [&s, &rhs](char c){ return c == s[rhs]; }) != temp.end()) {
            ++lhs;
            ++rhs;
        }
        else if (!temp.size()) {
            ++lhs;
        }
    }
    return lhs == n.size() && rhs == s.size();
}


int main()
{
    assert(valid_combo("234", "ADG"));
    assert(valid_combo("1111111112", "A"));
    assert(!valid_combo("1111111112", "AA"));
    assert(valid_combo("00000001", ""));
    return 0;
}
