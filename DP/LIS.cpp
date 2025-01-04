#include <iostream>
#include <vector>
using namespace std;

void LIS(vector<int> &nums, int idx, int last, vector<int> curr, vector<int> &ans)
{
    if (idx == nums.size())
    {
        if (ans.size() < curr.size())
            ans = curr;
        return;
    }
    // take
    if (nums[idx] > nums[last])
    {
        curr.push_back(nums[idx]);
        LIS(nums, idx + 1, idx, curr, ans);
        curr.pop_back();
    }
    // not take
    LIS(nums, idx + 1, last, curr, ans);
}

int LISLength(vector<int> &nums, int idx, int last, vector<vector<int>> &dp)
{
    if (idx == nums.size())
    {
        return 0;
    }

    if (dp[idx][last + 1] != -1)
        return dp[idx][last + 1];

    // take
    int take = 0;
    if (last == -1 || nums[idx] > nums[last])
    {
        take = 1 + LISLength(nums, idx + 1, idx, dp);
    }
    // not take
    int ntake = 0 + LISLength(nums, idx + 1, last, dp);

    dp[idx][last + 1] = max(take, ntake);
    return dp[idx][last + 1];
}

int main()
{
    vector<int> v = {5, 0, 1, 4}, curr, ans;
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // LIS(v, 0, -1, curr, ans);
    int x = LISLength(v, 0, -1, dp);
    // for (auto x : ans)
    cout << x;
    return 0;
}