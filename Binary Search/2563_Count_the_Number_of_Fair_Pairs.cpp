// CPP
class Solution
{
public:
    int binSearch(vector<int> &nums, int l, int r, int target)
    {
        // largest index 'i' such that nums[i] < target
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return r;
    }
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            int low = lower - nums[i];
            int up = upper - nums[i];
            ans += (binSearch(nums, i + 1, n - 1, up + 1) -
                    binSearch(nums, i + 1, n - 1, low));
        }

        return ans;
    }
};