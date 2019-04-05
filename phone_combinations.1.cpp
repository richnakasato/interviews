#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void helper(const std::unordered_map<char,std::string>& lookup,
            const std::string& phone_num,
            size_t curr_idx,
            std::string curr_combo,
            std::vector<std::string>& results)
{
    if (curr_idx == phone_num.size()) {
        results.push_back(curr_combo);
        return;
    }
    while (lookup.find(phone_num[curr_idx]) == lookup.end())
        ++curr_idx;
    char curr_digit = phone_num[curr_idx];
    for (size_t i=0; i<lookup.at(curr_digit).size(); ++i) {
        helper(lookup, phone_num, curr_idx+1,
               curr_combo+lookup.at(curr_digit)[i], results);
    }
    return;
}

std::vector<std::string> phone_combo(std::string phone_num)
{
    std::vector<std::string> results;
    std::unordered_map<char,std::string> lookup {{'2', "ABC"},
                                                 {'3', "DEF"},
                                                 {'4', "GHI"},
                                                 {'5', "JKL"},
                                                 {'6', "MNO"},
                                                 {'7', "PQRS"},
                                                 {'8', "TUV"},
                                                 {'9', "WXYZ"}};
    helper(lookup, phone_num, 0, "", results);
    return results;
}

int main()
{
    std::string phone;
    std::cin >> phone;
    std::vector<std::string> results = phone_combo(phone);
    for (const auto& combo : results) {
        std::cout << combo << ", ";
    }
    std::cout << std::endl;
    return 0;
}
