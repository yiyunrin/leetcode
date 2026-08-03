class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // 先建選1~3個的總和
        vector<vector<int>> sum(3, vector<int>(n, 0));
        sum[0] = stoneValue;
        for(int i = 1;i < 3;i ++){
            for(int j = 0;j + i < n;j ++){
                sum[i][j] = stoneValue[j] + sum[i - 1][j + 1];
            }
        }
        //             ( one[i] - dp[i + 1]
        // dp[i] = max ( two[i] - dp[i + 2]
        //             ( three[i] - dp[i + 3]
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;
        for(int i = n - 1;i >= 0;i --){
            for(int j = 0;j < 3 && i + j < n;j ++){
                dp[i] = max(dp[i], sum[j][i] - dp[i + j + 1]);
            }
        }
        if(dp[0] > 0)
            return "Alice";
        else if(dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};
