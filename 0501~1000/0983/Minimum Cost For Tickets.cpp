class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days[days.size() - 1], now = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 1;i <= n;i ++){
            if(i == days[now]){
                int tmp = costs[0] + dp[i - 1];
                tmp = min(tmp, costs[1] + dp[max(0, i - 7)]);
                tmp = min(tmp, costs[2] + dp[max(0, i - 30)]);
                dp[i] = tmp;
                now ++;
            }
            else
                dp[i] = dp[i - 1];
        }
        return dp[n];
    }
};
