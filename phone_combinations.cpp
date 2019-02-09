#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void helper(
        std::unordered_map<char,std::string>& lookup,
        std::string numbers,
        std::string::size_type pos,
        std::string curr_word,
        std::vector<std::string>& results)
{
    if (pos == numbers.size()) {
        if (!curr_word.empty()) {
            results.push_back(curr_word);
        }
        return;
    }
    char curr_num = numbers[pos++];
    if (lookup.find(curr_num) != lookup.end()) {
        std::string next_letters = lookup[curr_num];
        for (const auto& letter : next_letters) {
            std::string new_word = curr_word + letter;
            helper(lookup, numbers, pos, new_word, results);
        }
    }
    return;
}

std::vector<std::string> phone_combos(
        std::unordered_map<char,std::string>& lookup,
        std::string numbers)
{
    std::vector<std::string> results;
    helper(lookup, numbers, 0, "", results);
    return results;
}

int main()
{
    std::unordered_map<char,std::string> lookup {{'0', ""},
                                                 {'1', ""},
                                                 {'2', "abc"},
                                                 {'3', "def"},
                                                 {'4', "ghi"},
                                                 {'5', "jkl"},
                                                 {'6', "mno"},
                                                 {'7', "pqrs"},
                                                 {'8', "tuv"},
                                                 {'9', "wxyz"}};
    std::string numbers = "456";
    std::vector<std::string> results = phone_combos(lookup, numbers);
    for (const auto& result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}
