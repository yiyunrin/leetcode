class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ele;
        int mx = INT_MIN, range = INT_MAX;
        vector<int> ans;
        for(int i = 0;i < nums.size();i ++){
            mx = max(mx, nums[i][0]);
            ele.push({nums[i][0], i});
        }
        vector<int> idx(nums.size(), 1);
        while(1){
            auto [num, list] = ele.top();
            ele.pop();
            if(mx - num < range){
                range = mx - num;
                ans = {num, mx};
            }
            if(idx[list] >= nums[list].size())
                break;
            ele.push({nums[list][idx[list]], list});
            mx = max(mx, nums[list][idx[list]]);
            idx[list] ++;
        }
        return ans;
    }
};
