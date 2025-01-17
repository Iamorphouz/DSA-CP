class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int ans = 0;
        for (int &x : derived)
            ans = ans ^ x;
        return 1 - ans;
    }
};