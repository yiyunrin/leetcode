class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int  n = nums.size(), sum = nums[0];
        int i = 1;
        // 先找出prefix sum
        while(i < n && nums[i] == nums[i - 1] + 1){
            sum += nums[i];
            i ++;
        }
        // 再找答案
        sort(nums.begin(), nums.end());
        for(int j = 1;j < n;j ++){
            if(nums[j] > sum && nums[j] != nums[j - 1] + 1 && nums[j] != nums[j - 1]){
                return max(nums[j - 1] + 1, sum);
            }
        }
        return max(nums[n - 1] + 1, sum);
    }
};
