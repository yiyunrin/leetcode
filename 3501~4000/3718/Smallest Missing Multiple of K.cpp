class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int now = k;
        for(int i = 0;i < nums.size();i ++){
            if(nums[i] > now)
                break;
            else if(nums[i] == now)
                now += k;
        }
        return now;
    }
};
