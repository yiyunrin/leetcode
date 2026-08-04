class Solution {
public:
    int jump(vector<int>& nums) {
        int mx = 0, steps = 0, now = 0, n = nums.size();
        while(now < n){
            int pre_mx = min(n - 1, mx);
            steps ++;
            while(now <= pre_mx){
                mx = max(mx, now + nums[now]);
                now ++;
            }
        }
        return steps - 1;
    }
};
