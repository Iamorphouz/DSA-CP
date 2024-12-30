class Solution
{
public:
    const int mod = 1e9 + 7;
    int count(int target, vector<int> &dp, int one, int zero)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;

        if (dp[target] != -1)
            return dp[target];

        long long sum = 0;
        sum = count(target - one, dp, one, zero) + count(target - zero, dp, one, zero);

        return dp[target] = sum % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, -1);

        int ans = 0;
        for (int len = low; len <= high; len++)
        {

            ans = (ans % mod + count(len, dp, one, zero) % mod) % mod;
        }

        return ans;
    }
};