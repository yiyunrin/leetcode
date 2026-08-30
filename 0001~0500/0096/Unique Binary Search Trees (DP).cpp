// n個節點的總數 = 以1~n節點為root的數量總和
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i ++){
            for(int j = 0;j < i;j ++){
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
