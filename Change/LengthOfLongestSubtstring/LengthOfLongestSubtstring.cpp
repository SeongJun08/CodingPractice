#include <iostream>
#include <string>

int LengthOfLongestSubtstring(std::string s)
{
    int result = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int count = 1;

        while (s[i + 1] == s[i] + 1)
        {
            i++;
            count++;
        }

        if (result < count) result = count;
    }
    return result;
}

int main()
{
    std::string s{ "abcabcabcaa" };
    std::cout << LengthOfLongestSubtstring(s) << std::endl;
}

