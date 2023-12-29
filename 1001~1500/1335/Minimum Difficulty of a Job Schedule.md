# Approach
<!-- Describe your approach to solving the problem. -->
### 變數
- n : jobDifficulty的大小
- dp : d * n 的二維vector
    - dp[i][j]表示(i + 1)天內做j個工作的最小difficulty

### 方法
- 初始dp[0][j]是前j個工作difficulty的最大值。
- 其他的dp[i][j] = min( dp[i - 1][k - 1] + max(jobDifficulty[k ~ j]))
    - dp[i][j] = (前 i 天做前 k - 1 個工作的difficulty) + (第 i + 1 天做第 k ~ j 個工作的difficulty)
    - i <= k <= j
    - 總共有 i + 1 天，做 j 個工作
    - 第 0 ~ k - 1 個工作在前 i 天做完，第 k ~ j 個工作在第 i + 1 天做完
# Complexity
- Time complexity:$$O(d * n * n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:$$O(d * n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        vector<vector<int>> dp(d, vector<int>(n, -1));
        dp[0][0] = jobDifficulty[0];

        //初始做一天的difficulty
        for(int i = 1;i < n;i ++)
            dp[0][i] = max(dp[0][i - 1], jobDifficulty[i]);

        //計算dp
        for(int i = 1;i < d;i ++){
            for(int j = i;j < n;j ++){
                int mx = jobDifficulty[j], ans = INT_MAX;
                //窮舉k
                for(int k = j;k >= i;k --){
                    mx = max(mx, jobDifficulty[k]);
                    ans = min(mx + dp[i - 1][k - 1], ans);
                }
                dp[i][j] = ans;
            }
        }
        return dp[d - 1][n - 1];
    }
};
```
