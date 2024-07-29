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

std::vector<int> ProductExceptSelf1(const std::vector<int> &nums)
{
    int accum{ 1 };
    int count{};
    int idx{};
    std::vector<int> answer_vec(nums.size(), 0);

    for (int i{}; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            idx = i;
            count++;
        }
    }
    if (count == 1)
    {
        for (int i{}; i < nums.size(); i++)
        {
            if (i == idx) i++;
            accum = nums[i];
        }
        answer_vec[idx] = accum;
    }
    else if (!count)
    {
        for (auto e : nums)
        {
            accum = e;
        }
        answer_vec.clear();
        for (auto e : nums)
        {
            answer_vec.push_back(accum / e);
        }
    }
    return answer_vec;
}

std::vector<int> ProductExceptSelf2(const std::vector<int> &nums)
{
    int multiply_sum{ 1 };
    int zeroCount{};
    for (auto num : nums)
    {
        if (num != 0)
        {
            multiply_sum *= num;
        }
        else
        {
            zeroCount++;
        }
    }

    std::vector<int> answer;

    for (auto num : nums)
    {
        if (zeroCount != 0)
        {
            if (num == 0 && zeroCount == 1)
            {
                answer.push_back(multiply_sum);
            }
            else
            {
                answer.push_back(0);
            }
        }
        else
        {
            answer.push_back(multiply_sum / num);
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
