class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> idx;
        int n = nums.size();
        for(int i = 0;i < n;i ++){
            if(idx.empty() || nums[i] < nums[idx.top()])
                idx.push(i);
        }

        int ans = 0;
        for(int i = n - 1;i >= 0;i --){
            while(!idx.empty() && nums[idx.top()] <= nums[i]){
                ans = max(ans, i - idx.top());
                idx.pop();
            }
        }
        return ans;
    }
};
