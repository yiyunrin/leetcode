class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size(), n = obs[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if(obs[0][0] != 1)
            dp[0][0] = 1;
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(obs[i][j] == 1)
                    continue;
                if(i > 0)
                    dp[i][j] += dp[i - 1][j];
                if(j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
