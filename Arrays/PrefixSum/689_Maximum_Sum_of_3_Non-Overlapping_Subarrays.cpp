class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        // shift by 1 to right or indexing from 1
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1]; // right shifted
        }

        // LEFT
        vector<int> leftMaxIdx(n, 0);
        int maxLeftSum = prefixSum[k] - prefixSum[0];

        for (int i = k; i < n; i++)
        {
            int curSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            if (curSum > maxLeftSum)
            {
                maxLeftSum = curSum;
                leftMaxIdx[i] = i + 1 - k;
            }
            else
            {
                leftMaxIdx[i] = leftMaxIdx[i - 1];
            }
        }

        // RIGHT
        vector<int> rightMaxIdx(n, 0);
        int maxRightSum = prefixSum[n] - prefixSum[n - k];

        for (int i = n - k; i >= 0; i--)
        {
            int curSum = prefixSum[i + k] - prefixSum[i];
            if (curSum >= maxRightSum)
            { // >= --> left most index
                maxRightSum = curSum;
                rightMaxIdx[i] = i;
            }
            else
            {
                rightMaxIdx[i] = rightMaxIdx[i + 1];
            }
        }

        vector<int> ans(3, 0);
        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; i++)
        {
            int left = leftMaxIdx[i - 1];
            int right = rightMaxIdx[i + k];

            int curSum = (prefixSum[left + k] - prefixSum[left]) +
                         (prefixSum[i + k] - prefixSum[i]) +
                         (prefixSum[right + k] - prefixSum[right]);

            if (curSum > maxSum)
            {
                maxSum = curSum;
                ans = {left, i, right};
            }
        }

        return ans;
    }
};