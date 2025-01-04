class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.size();
        vector<int> firstIdx(26, -1);
        vector<int> lastIdx(26, n);
        for (int i = 0; i < n; i++)
        {
            if (firstIdx[s[i] - 'a'] == -1)
                firstIdx[s[i] - 'a'] = i;
            lastIdx[s[i] - 'a'] = i;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {                                             // O(26) * O(N)
            if (firstIdx[i] == -1 || lastIdx[i] == n) // 0  // 1
                continue;

            unordered_set<char> st;
            // cout<<firstIdx[i] << " " << lastIdx[i]<<endl;
            for (int it = firstIdx[i] + 1; it < lastIdx[i]; it++)
            { // O(N)
                st.insert(s[it]);
            }

            cnt += st.size();
        }

        return cnt;
    }
};