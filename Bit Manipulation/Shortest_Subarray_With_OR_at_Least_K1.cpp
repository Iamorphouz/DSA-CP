// CPP
class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = n + 1;
        for (int i = 0; i < n; i++)
        {
            int sub_or = 0;
            int sz = 0;
            for (int j = i; j < n; j++)
            {
                sub_or |= nums[j];
                sz++;
                if (sub_or >= k)
                    ans = min(ans, sz);
            }
        }

        return ans > n ? -1 : ans;
    }
};

#Python
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = n + 1
        for i in range(0, n):
            sub_or = 0
            sz = 0
            for j in range(i, n):
                sub_or |= nums[j]
                sz += 1
                if(sub_or >= k): 
                    ans = min(ans, sz)
                    break
                

        return -1 if ans > n else ans