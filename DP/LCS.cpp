#include <iostream>
#include <vector>
#include <string>
using namespace std;

void LCS(string &s1, string &s2, int i1, int i2, string curr, string &lcs)
{
    if (i1 == s1.size() || i2 == s2.size())
    {
        if (lcs.size() < curr.size())
            lcs = curr;
        return;
    }

    // match
    if (s1[i1] == s2[i2])
    {
        curr.push_back(s1[i1]);
        LCS(s1, s2, i1 + 1, i2 + 1, curr, lcs);
        curr.pop_back();
    }
    else
    {
        LCS(s1, s2, i1, i2 + 1, curr, lcs);
        LCS(s1, s2, i1 + 1, i2, curr, lcs);
    }
    // no match
}

int LCS(string &s1, string &s2, int i1, int i2, vector<vector<int>> &dp)
{
    if (i1 == s1.size() || i2 == s2.size())
    {
        return 0;
    }

    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    // match
    int take = 0, ntake = 0;
    if (s1[i1] == s2[i2])
    {
        take = 1 + LCS(s1, s2, i1 + 1, i2 + 1, dp);
    }
    else
    {
        ntake = max(LCS(s1, s2, i1, i2 + 1, dp),
                    LCS(s1, s2, i1 + 1, i2, dp));
    }
    // no match
    dp[i1][i2] = max(take, ntake);
    return dp[i1][i2];
}
int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    string s;
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
    LCS(s1, s2, 0, 0, "", s);
    cout << s;
    cout << LCS(s1, s2, 0, 0, dp);
    return 0;
}