class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<long> ps(n + 1, 0);
        for (auto shift : shifts)
        {
            int x1 = -1, x2 = 1; // backward
            if (shift[2] == 1)
                x1 = 1, x2 = -1; // forwar d

            ps[shift[0]] += x1;
            ps[shift[1] + 1] += x2;
        }
        // for(int i = 1; i <= n; i++)
        //     ps[i] += ps[i-1];

        // for(int i = 0; i < n; i++){          // O(3N)
        //     int chg = (s[i] - 'a' + ps[i]) % 26;
        //     s[i] = 'a' + (chg + 26) % 26;
        // }

        int netShift = 0; // O(2N)
        for (int i = 0; i < n; i++)
        {
            netShift = (netShift + ps[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + netShift + 26) % 26;
        }

        return s;
    }
};