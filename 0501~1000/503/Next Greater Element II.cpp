class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // {num, index}
        stack<pair<int, int>> st;
        int n = nums.size(), mx_idx = 0;
        vector<int> ans(n, -1);
        // 因為可以循環，所以會記錄最大值的index，第二次遍歷只需要到最大值即可
        for(int i = 0;i < n;i ++){
            while(!st.empty() && st.top().first < nums[i]){
                pair<int, int> now = st.top();
                st.pop();
                ans[now.second] = nums[i];
            }
            if(nums[i] > nums[mx_idx])
                mx_idx = i;
            st.push({nums[i], i});
        }
        for(int i = 0;i <= mx_idx;i ++){
            while(!st.empty() && st.top().first < nums[i]){
                pair<int, int> now = st.top();
                st.pop();
                ans[now.second] = nums[i];
            }
        }
        return ans;
    }
};
