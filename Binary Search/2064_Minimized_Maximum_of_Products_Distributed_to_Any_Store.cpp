class Solution
{
public:
    bool possibleDistribution(int n, vector<int> &quantities, int m)
    {
        for (int &p : quantities)
        {
            n -= (p + m - 1) / m; // ceil

            if (n < 0)
            {
                return false;
            }
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            // cout<<l <<" "<<r<<" "<<possibleDistribution(n, quantities, m)<<endl;
            if (possibleDistribution(n, quantities, m))
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return l;
    }
};