class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn_idx = 0, mx_idx = 0, n = nums.size();
        // 找到最大和最小的idx
        for(int i = 1;i < n;i ++){
            if(nums[i] < nums[mn_idx])
                mn_idx = i;
            if(nums[i] > nums[mx_idx])
                mx_idx = i;
        }
        // 計算需要移除的最小數量
        int mn = min(mn_idx, mx_idx), mx = max(mn_idx, mx_idx);
        return min(mx + 1, min(n - mn, mn + 1 + n - mx));
    }
};
