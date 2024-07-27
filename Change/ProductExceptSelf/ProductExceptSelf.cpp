#include <iostream>
#include <vector>

std::vector<int> ProductExceptSelf(std::vector<int> &nums)
{
    int n = nums.size();
    std::vector<int> answer(n, 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (j != i)
            {
                answer[i] = answer[i] * nums[j];
            }
        }
    }

    return answer;
}

int main()
{
    std::vector<int> nums{ -1,1,0,-3,3 };
    std::vector<int> result = ProductExceptSelf(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
}
