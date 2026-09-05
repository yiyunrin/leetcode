class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mx(n), mn(n);
        mx[0] = nums[0];
        mn[n - 1] = nums[n - 1];
        for(int i = 1;i < n;i ++){
            mx[i] = max(mx[i - 1], nums[i]);
            mn[n - i - 1] = min(mn[n - i], nums[n - i - 1]);
        }
        for(int i = 0;i < n;i ++){
            if(mx[i] - mn[i] <= k)
                return i;
        }
        return -1;
    }
};
