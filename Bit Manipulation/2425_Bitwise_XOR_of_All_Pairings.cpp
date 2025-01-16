class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        if (!(m & 1) && !(n & 1))
        { // even even
            return 0;
        }
        else if ((m & 1) && (n & 1))
        { // odd // odd
            int ans = 0;
            for (int &x : nums1)
                ans ^= x;
            for (int &x : nums2)
                ans ^= x;

            return ans;
        }
        else if ((m & 1) && !(n & 1))
        { // odd // even
            int ans = 0;
            for (int &x : nums2)
                ans ^= x;
            return ans;
        }
        else
        {
            int ans = 0;
            for (int &x : nums1)
                ans ^= x;
            return ans;
        }
    }
};