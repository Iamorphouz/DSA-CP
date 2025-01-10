class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> mp(26, 0);
        for (int i = 0; i < words2.size(); i++)
        {
            string s = words2[i];
            vector<int> tmp(26, 0);
            for (char ch : s)
                tmp[ch - 'a']++;
            for (int i = 0; i < 26; i++)
                mp[i] = max(mp[i], tmp[i]);
        }
        vector<string> ans;
        for (string s : words1)
        {
            vector<int> tmp(26, 0);
            for (char ch : s)
                tmp[ch - 'a']++;
            int flag = 1;
            for (int i = 0; i < 26; i++)
            {
                if (mp[i] && tmp[i] < mp[i])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                ans.push_back(s);
        }
        return ans;
    }
};