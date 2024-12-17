class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        string repeatLimitedString = "";
        vector<int> freq(26, 0);
        int i = 0;
        for (auto ch : s)
        {
            i = max(i, ch - 'a');
            freq[ch - 'a']++;
        }

        while (i >= 0)
        {
            if (!freq[i])
            {
                i--;
                continue;
            }
            if (freq[i] <= repeatLimit)
            {
                char ch = 'a' + i;
                string ss(freq[i], ch);
                freq[i] = 0;
                repeatLimitedString += ss;
                i--;
            }
            while (i >= 0 && freq[i] > repeatLimit)
            {
                freq[i] -= repeatLimit;
                char ch = 'a' + i;
                string ss(repeatLimit, ch);
                repeatLimitedString += ss;
                int j = i - 1;
                while (j >= 0 && freq[j] == 0)
                {
                    j--;
                }
                if (j >= 0)
                {
                    ch = 'a' + j;
                    freq[j]--;
                    repeatLimitedString.push_back(ch);
                }
                else
                {
                    return repeatLimitedString;
                }
            }
        }
        return repeatLimitedString;
    }
};
