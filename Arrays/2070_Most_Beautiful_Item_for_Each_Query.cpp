// CPP
class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        int maxi = INT_MAX;

        sort(items.begin(), items.end());

        vector<vector<int>> res = {{0, 0, maxi}};

        for (auto &item : items)
        {
            int price = item[0];
            int beauty = item[1];
            if (beauty > res.back()[1])
            {
                if (price == res.back()[0])
                {
                    res.back()[1] = beauty;
                }
                else
                {
                    res.back()[2] = price;
                    res.push_back({price, beauty, maxi});
                }
            }
        }

        vector<int> ans;

        for (int q : queries)
        {
            for (int i = res.size() - 1; i >= 0; i--)
            {
                if (res[i][0] <= q)
                {
                    ans.push_back(res[i][1]);
                    break;
                }
            }
        }

        return ans;
    }
};

// Python
class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        
        maxi = float('inf')
        res = [[0, 0, maxi]] # minprice, beauty, maxprice

        items.sort(key = lambda x: x[0])

        for price, beauty in items:
            
            if beauty > res[-1][1]:
                if price == res[-1][0]:
                    res[-1][1] = beauty
                else:
                    res[-1][2] = price
                    res.append([price, beauty, maxi])

        ans = []

        for q in queries:
            for i in range(len(res) - 1, -1, -1):
                if res[i][0] <= q:
                    ans.append(res[i][1])
                    break
        
        return ans