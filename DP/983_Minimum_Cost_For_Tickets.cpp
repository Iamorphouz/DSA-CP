/*
def solve(i:int, days: List[int], costs: List[int], dp: List[int]) -> int:
    n = len(days)
    if i >= n:
        return 0

    if dp[i] != -1:
        return dp[i]

    cost_1day = costs[0] + solve(i + 1, days, costs, dp)

    j = i
    while j < n and days[j] < days[i] + 7:
        j += 1
    cost_7day = costs[1] + solve(j, days, costs, dp)


    j = i
    while j < n and days[j] < days[i] + 30:
        j += 1
    cost_30day = costs[2] + solve(j, days, costs, dp)

    dp[i] = min(cost_1day, cost_7day, cost_30day)
    return dp[i]

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [-1] * 366
        return solve(0, days, costs, dp)
*/