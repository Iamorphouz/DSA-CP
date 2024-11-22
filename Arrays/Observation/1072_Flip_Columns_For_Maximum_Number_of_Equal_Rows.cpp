// cpp
class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> mp;
        // find same pattern or exact inverted pattern
        // TTF = 001 TTF = 110
        for (vector<int> &r : matrix)
        {
            string s(r.size(), 'T');
            for (int i = 1; i < r.size(); i++)
            {
                if (r[i] != r[0])
                    s[i] = 'F';
            }

            mp[s]++;
        }

        int ans = 0;
        for (auto &it : mp)
            ans = max(ans, it.second);

        return ans;
    }
};