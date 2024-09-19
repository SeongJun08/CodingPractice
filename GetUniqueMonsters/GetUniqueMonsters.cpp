#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> GetUniqueMonsters(std::vector<int> monsters) 
{
    std::unordered_map<int, int> mcount;

    // 몬스터번호, 등장횟수
    for (int monster : monsters) 
    {
        mcount[monster]++;
    }

    std::vector<int> temp;
    for (const auto &entry : mcount) 
    {
        if (entry.second == 1)  // 몬스터 등장횟수 1인거 모음
        {
            temp.push_back(entry.first);
        }
    }

    if (temp.empty()) 
    {
        return { -1 };
    }

    std::sort(temp.begin(), temp.end());

    return temp;
}

int main() 
{
    std::vector<int> monsters = { 2, 1, 3, 3 };
    std::vector<int> result = GetUniqueMonsters(monsters);

    for (int monster : result) 
    {
        std::cout << monster << " ";
    }

    std::cout << std::endl;

    std::vector<int> monsters1 = { 3,4,4,2,5,2,5,5 };
    std::vector<int> result1 = GetUniqueMonsters(monsters1);

    for (int monster1 : result1)
    {
        std::cout << monster1 << " ";
    }

    std::cout << std::endl;

    std::vector<int> monsters2 = { 3,5,3,5,7,5,7 };
    std::vector<int> result2 = GetUniqueMonsters(monsters2);

    for (int monster2 : result2)
    {
        std::cout << monster2 << " ";
    }

    return 0;
}
