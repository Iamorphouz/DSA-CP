#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> ans(n, 0);
        for (int i = 0, cnt = 0, totalOps = 0; i < n; i++)
        {
            ans[i] = totalOps;
            cnt += boxes[i] - '0';
            totalOps += cnt;
        }

        for (int i = n - 1, cnt = 0, totalOps = 0; i >= 0; i--)
        {
            ans[i] += totalOps;
            cnt += boxes[i] - '0';
            totalOps += cnt;
        }

        return ans;

        // for(int i = 0; i < n; i++){
        //     int cost = 0;
        //     for(int j = 0; j < n; j++){
        //         if(j != i){
        //             if(boxes[j] == '1'){
        //                 cost += abs(j - i);
        //             }
        //         }
        //     }
        //     ans[i] = cost;
        // }
        // return ans;
    }
};