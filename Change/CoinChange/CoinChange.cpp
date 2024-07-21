#include <iostream>
#include <vector>
#include <algorithm>

int CoinChange(std::vector<int> &coins, int amount)
{
    std::vector<int> result(amount + 1, amount + 1);
    result[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (const int &coin : coins)
        {
            if (i - coin >= 0)
            {
                result[i] = std::min(result[i], result[i - coin] + 1);
            }
        }
    }
    return result[amount] > amount ? -1 : result[amount];
}

int main()
{
    std::vector<int> coins = { 1,2,5 };
    int amount = 11;

    int result = CoinChange(coins, amount);
    std::cout << result << std::endl;
}

