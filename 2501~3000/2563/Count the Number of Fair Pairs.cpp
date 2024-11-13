class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for(int i = 0;i < n;i ++){
            int tmp = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - 
                      lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            if(tmp > 0)
                ans += tmp;
        }
        return ans;
    }
};
