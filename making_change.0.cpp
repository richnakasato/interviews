#include <cassert>
#include <vector>

int helper(int coins[], int sz, int amount, int curr_coin)
{
    if (amount == 0) return 1;
    if (amount < 0) return 0;
    int result = 0;
    for (int i=curr_coin; i<sz; ++i) {
        result += helper(coins, sz, amount-coins[i], i);
    }
    return result;
}

int make_change(int coins[], int sz, int amount)
{
    return helper(coins, sz, amount, 0);
}

int main()
{
    int coins[4] {25, 10, 5, 1};
    assert(make_change(coins, 4, 10)==4);
    return 0;
}
