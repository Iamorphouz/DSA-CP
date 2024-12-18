class Solution
{
public:
    // stack
    vector<int> finalPrices_Stack(vector<int> &prices)
    {
        const int n = prices.size();
        int stack[500], top = 0;
        stack[top] = n - 1;
        vector<int> ans = prices;
        for (int i = n - 2; i >= 0; i--)
        {
            while (top >= 0 && prices[i] < prices[stack[top]])
                top--;
            if (top >= 0)
                ans[i] -= prices[stack[top]];
            stack[++top] = i;
        }
        return ans;
    }
    // loops
    vector<int> finalPrices_Loops(vector<int> &prices)
    {
        int n = prices.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] <= prices[i])
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }

        return prices;
    }
};
