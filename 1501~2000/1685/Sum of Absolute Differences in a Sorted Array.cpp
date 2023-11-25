class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), sum = 0, pre = 0;
        for(int i = 0;i < n;i ++)
            sum += nums[i];
        vector<int> ans(n);
        for(int i = 0;i < n;i ++){
            ans[i] = i * nums[i] - pre + sum - (n - i) * nums[i];
            sum -= nums[i];
            pre += nums[i];
        }
        return ans;
    }
};
