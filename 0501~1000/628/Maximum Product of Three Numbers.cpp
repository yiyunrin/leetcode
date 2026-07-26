class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        // 最大的答案有兩種可能
        // 1. 三個最大的值相乘
        // 2. 兩個最小的負數乘上最大值
        return max(nums[0] * nums[1] * nums[n], nums[n] * nums[n - 1] * nums[n - 2]);
    }
};
