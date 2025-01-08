class Solution
{
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int ans = 0;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans += isPrefixAndSuffix(words[i], words[j]);
            }
        }

        return ans;
    }
    bool isPrefixAndSuffix(string &str1, string &str2)
    {
        if (str1.size() <= str2.size())
        {
            if (str1 == str2.substr(0, str1.size()) && str1 == str2.substr(str2.size() - str1.size(), str1.size()))
            {
                return true;
            }
        }
        return false;
    }
};