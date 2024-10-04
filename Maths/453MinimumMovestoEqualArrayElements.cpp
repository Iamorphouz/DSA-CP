// nums = [1,2,3]
//   ---> [4,4,4]
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        // Maths
        // mini Moves = m
        // sum + m (n - 1) = (minNum + m) n
        // we will inc minNum m times, that inc (n - 1) elements m times
        // m = sum - minNum * n;
        int mini = *min_element(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        return int(sum - mini * n);
    }
};