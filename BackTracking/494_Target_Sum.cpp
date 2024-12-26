// BRUTE
class Solution
{
public:
    int totalWays = 0;
    int findTargetSumWays(vector<int> &nums, int target)
    {
        calculate(nums, 0, 0, target);
        return totalWays;
    }

private:
    void calculate(vector<int> &nums, int idx, int sum, int target)
    {
        if (idx == nums.size())
        {
            if (sum == target)
            {
                totalWays++;
            }
        }
        else
        {
            calculate(nums, idx + 1, sum + nums[idx], target);

            calculate(nums, idx + 1, sum - nums[idx], target);
        }
    }
};
