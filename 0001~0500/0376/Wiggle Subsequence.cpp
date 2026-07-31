class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n - 1;i ++)
            nums[i] = nums[i + 1] - nums[i];
        int cnt1 = 1, cnt2 = 1;
        for(int i = 0;i < n - 1;i ++){
            if((!(cnt1 & 1) && nums[i] > 0) || ((cnt1 & 1) && nums[i] < 0))
                cnt1 ++;
            if(((cnt2 & 1) && nums[i] > 0) || (!(cnt2 & 1) && nums[i] < 0))
                cnt2 ++;
        }
        return max(cnt1, cnt2);
    }
};
