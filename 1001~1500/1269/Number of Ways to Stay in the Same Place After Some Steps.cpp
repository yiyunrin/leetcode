//就是dp
//然後不可能走超過steps/2+1格
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1000000007, last = min(steps / 2, arrLen - 1) + 1;
        vector<vector<int>> dp(steps + 1, vector<int>(last + 2, 0));
        dp[0][1] = 1;
        for(int i = 1;i <= steps;i ++){
            for(int j = 1;j <= last;j ++){
                dp[i][j] = dp[i - 1][j];
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
        return dp[steps][1];
    }
};
