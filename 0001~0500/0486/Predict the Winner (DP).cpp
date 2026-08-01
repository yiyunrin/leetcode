class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = nums;
        for(int i = 1;i < n;i ++){
            vector<int> tmp(n, 0);
            for(int j = 0;j < n - i;j ++){
                int l = j, r = j + i;
                tmp[j] = max(nums[l] - pre[l + 1], nums[r] - pre[l]);
            }
            pre = tmp;
        }
        return pre[0] >= 0;
    }
};
