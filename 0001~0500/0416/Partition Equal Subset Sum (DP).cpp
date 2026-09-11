class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0;i < n;i ++)
            sum += nums[i];
        if(sum & 1)
            return false;
        int half = sum / 2;
        vector<bool> dp(half + 1, false);
        dp[0] = true;
        for(int i = 0;i < n;i ++){
            vector<bool> now = dp;
            for(int j = 0;j <= half;j ++){
                int pre = j - nums[i];
                if(pre >= 0 && dp[pre])
                    now[j] = true;
            }
            dp = now;
        }
        return dp[half];
    }
};
