class Solution
{
public:
    int binarySearch(int height, vector<pair<int, int>> &st)
    {
        int l = 0, r = st.size() - 1, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (st[mid].first > height)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        vector<vector<pair<int, int>>> nQue(heights.size());
        vector<int> ans(queries.size(), -1);
        vector<pair<int, int>> st;
        for (int i = 0; i < queries.size(); i++)
        {
            int a = queries[i][0], b = queries[i][1]; // index of Alice & Bob
            if (a > b)
                swap(a, b); // b is always bigger

            if (heights[b] > heights[a] || a == b)
            { // hb > ha
                ans[i] = b;
            }
            if (ans[i] == -1)
                nQue[b].push_back({heights[a], i}); // ha > hb
        }

        for (int q = heights.size() - 1; q >= 0; q--)
        {
            for (auto &[h, idx] : nQue[q])
            {
                int pos = binarySearch(h, st);
                if (pos != -1)
                    ans[idx] = st[pos].second;
            }
            // monodecreasing stack --> min idx height > than required   1 2 3 4 5 6 7 8
            while (!st.empty() && st.back().first <= heights[q]) // <= bcz '=' height will give better smaller idx
                st.pop_back();
            st.push_back({heights[q], q});
        }
        return ans;
    }
};