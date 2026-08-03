class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0, n = nums.size();
        // 每次更新最遠可以到哪裡
        for(int i = 0;i < n - 1;i ++){
            // 如果現在的位置，是沒辦法到的
            if(i > mx)
                return false;
            mx = max(mx, i + nums[i]);
        }
        return mx >= n - 1;
    }
};
