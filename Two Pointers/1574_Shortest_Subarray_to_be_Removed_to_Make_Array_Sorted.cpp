class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int l = 0;
        int r = n - 1;

        // while(l + 1 < n and arr[l] <= arr[l+1] )
        //     l += 1;
        // if(l == r) return 0;
        while (r > 0 and arr[r - 1] <= arr[r])
            r -= 1;
        // int ans = min(n - l - 1, r);
        int ans = r;

        while (l < r)
        {
            while (r < n && arr[l] > arr[r])
                r += 1;
            ans = min(ans, r - l - 1);
            if (arr[l] > arr[l + 1]) // prefix
                break;
            l++;
        }

        return ans;
        // 1 2 3 4 8 2 4
        //       l   r r
        // 1 2 9 5 7 7 8 9
        //   l   r
    }
};