class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(), mod = 1000000007;
        long long ans= 0;
        vector<long long> dp(n, 1);
        sort(arr.begin(), arr.end());
        for(int i = 0;i < n;i ++){
            //找所有arr[j]*arr[k] == arr[i]
            for(int j = 0;j < i;j ++){
                for(int k = 0;k < i;k ++){
                    long long tmp = (long long)arr[j] * arr[k];
                    if(tmp == arr[i])
                        dp[i] += dp[j] * dp[k];
                    if(tmp >= arr[i])
                        break;
                }
            }
            ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
};
