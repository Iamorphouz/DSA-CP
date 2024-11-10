// CPP
class Solution
{
public:
    void update_bits(vector<int> &bits, int x, int change)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((x >> i) & 1)
                bits[i] += change;
        }
    }

    int bitsToNum(vector<int> &bits)
    {
        int num = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i])
                num = num | (1 << i);
        }
        return num;
    }

    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int i = 0, n = nums.size();
        int ans = n + 1;
        vector<int> bits(32, 0);

        for (int j = 0; j < n; j++)
        {
            update_bits(bits, nums[j], 1);
            while (i <= j && bitsToNum(bits) >= k)
            {
                ans = min(ans, j - i + 1);
                update_bits(bits, nums[i], -1);
                i++;
            }
        }

        return ans > n ? -1 : ans;
    }
};

#Python
class Solution:
    def update_bits(self, bits: List[int], x:int, change:int):
        for i in range(32):
            if (x >> i) & 1:
                bits[i] += change

    def bits_to_num(self, bits: List[int]) -> int:
        num = 0
        for i in range(32):
            if bits[i]:
                num |= 1 << i
        return num

    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        bits = [0] * 32
        i = 0
        ans = n + 1
        for j in range(n):
            self.update_bits(bits, nums[j], 1)
            
            while i <= j and self.bits_to_num(bits) >= k:

                ans = min(ans, j-i+1)
                self.update_bits(bits, nums[i], -1)
                i += 1

        return -1 if ans > n else ans