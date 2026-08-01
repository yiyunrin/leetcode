class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        if(dfs(nums, 0, nums.size() - 1) >= 0)
            return true;
        return false; 
    }
private:
    // Player會選擇讓自己跟敵人的分數差最多的方案
    int dfs(vector<int> &nums, int st, int ed){
        if(st == ed)
            return nums[st];
        int front = nums[st] - dfs(nums, st + 1, ed),
            tail = nums[ed] - dfs(nums, st, ed - 1);
        return max(front, tail);
    }
};
