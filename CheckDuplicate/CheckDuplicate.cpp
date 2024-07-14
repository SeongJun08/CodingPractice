#include <iostream>
#include <vector>
#include <algorithm>

bool CheckDuplicate(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::vector<int> nums = { 1,2,3,4,5,6 };
    bool hasDuplicate = CheckDuplicate(nums);
    std::cout << (hasDuplicate ? "중복된 요소 존재" : "중복된 요소 없음") << std::endl;

}
