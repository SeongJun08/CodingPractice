#include <iostream>
#include <vector>
#include <algorithm>

int MaxProfit(const std::vector<int> &prices)
{
    if (prices.empty()) return 0; // 가격 배열이 비어있으면 이익은 0

    int min_price = prices[0]; // 첫 번째 가격을 최소 가격으로 초기화
    int max_profit = 0; // 최대 이익을 0으로 초기화

    // 가격 배열의 두 번째 요소부터 끝까지 순회
    for (size_t i = 1; i < prices.size(); ++i)
    {
        // 현재 이익을 계산하고 최대 이익을 갱신
        max_profit = std::max(max_profit, prices[i] - min_price);

        // 현재 가격을 이용해 최소 가격 갱신
        min_price = std::min(min_price, prices[i]);
    }

    return max_profit; // 최대 이익 반환
}

int main()
{
    std::vector<int> prices = { 7, 1, 5, 3, 6, 4 }; // 주어진 가격 배열

    std::cout << MaxProfit(prices) << std::endl; // 최대 이익 출력
    return 0;
}
