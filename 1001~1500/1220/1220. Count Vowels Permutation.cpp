class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(5, vector<int>(n));
        int mod = 1000000007;
        for(int i = 0;i < 5;i ++)
            dp[i][0] = 1;
        for(int i = 1;i < n;i ++){
            dp[0][i] = ((dp[1][i - 1] + dp[2][i - 1]) % mod + dp[4][i - 1]) % mod;
            dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % mod;
            dp[2][i] = (dp[1][i - 1] + dp[3][i - 1]) % mod;
            dp[3][i] = dp[2][i - 1] % mod;
            dp[4][i] = (dp[2][i - 1] + dp[3][i - 1]) % mod;
        }
        int ans = 0;
        for(int i = 0;i < 5;i ++)
            ans = (ans + dp[i][n - 1]) % mod;
        return ans;
    }
};
