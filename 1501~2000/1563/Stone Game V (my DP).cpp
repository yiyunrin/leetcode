class Solution {
public:
    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        // 先計算不同長度的rows的總和
        vector<vector<int>> sum(n + 1, vector<int>(n, 0));
        sum[1] = stones;
        for(int i = 2;i <= n;i ++){
            for(int j = 0;j + i <= n;j ++){
                sum[i][j] = stones[j] + sum[i - 1][j + 1];
            }
        }

        // 使用DP，每次把目前範圍切成A, B兩段
        // sum: 該段的總和
        // div: 以該段為範圍，未來可以拿到的最大分數
        // 如果 sumA<=sumB -> get sumA+divA
        // 如果 sumB<=sumA -> get sumB+divB
        vector<vector<int>> dp(n + 1, vector<int>(n, 0));
        for(int i = 2;i <= n;i ++){
            for(int j = 0;j + i - 1 < n;j ++){
                for(int k = 1;k < i;k ++){
                    int sumA = sum[k][j];
                    int sumB = sum[i - k][j + k];
                    int divA = dp[k][j];
                    int divB = dp[i - k][j + k];
                    if(sumA <= sumB)
                        dp[i][j] = max(dp[i][j], sumA + divA);
                    if(sumB <= sumA)
                        dp[i][j] = max(dp[i][j], sumB + divB);
                }
            }
        }
        return dp[n][0];
    }
};
