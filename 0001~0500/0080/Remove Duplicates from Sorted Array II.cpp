class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int now = 2;
        for(int i = 2;i < nums.size();i ++){
            if(nums[i] != nums[now - 1] || nums[now - 1] != nums[now - 2]){
                nums[now] = nums[i];
                now += 1;
            }
        }
        return now;
    }
};
