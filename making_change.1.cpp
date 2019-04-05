#include <iostream>
#include <string>
#include <vector>

int helper(const std::vector<int>& coins, int amount, size_t pos)
{
    if (amount == 0) return 1;
    if (amount < 0) return 0;
    int result = 0;
    for (size_t i=pos; i<coins.size(); ++i) {
        result += helper(coins, amount-coins[i], i);
    }
    return result;
}

int making_change(const std::vector<int>& coins, int amount)
{
    return helper(coins, amount, 0);
}

int main()
{
    std::vector<int> coins {10,5,1};
    int amount;
    std::cout << "enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;;
    std::cout << making_change(coins, amount) << std::endl;
    return 0;
}
