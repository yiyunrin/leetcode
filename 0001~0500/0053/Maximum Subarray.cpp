class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, mx = nums[0];
        // 按順序加總，如果小於0，就歸0繼續加
        for(int i = 0;i < nums.size();i ++){
            if(sum < 0)
                sum = 0;
            sum += nums[i];
            mx = max(sum, mx);
        }
        return mx;
    }
};
