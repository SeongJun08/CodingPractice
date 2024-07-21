#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict) 
{
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[s.size()];
}

int main() {
    string s1 = "helloworld";
    vector<string> wordDict1 = { "hello", "world" };
    cout << boolalpha << wordBreak(s1, wordDict1) << endl;  // true

    string s2 = "applepenapple";
    vector<string> wordDict2 = { "apple", "pen" };
    cout << boolalpha << wordBreak(s2, wordDict2) << endl;  // true

    string s3 = "catsandog";
    vector<string> wordDict3 = { "cats", "dog", "sand", "and", "cat" };
    cout << boolalpha << wordBreak(s3, wordDict3) << endl;  // false

    return 0;
}
