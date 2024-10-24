class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        ans = 0, mx = 0, n = nums.size();
        for(int i = 0;i < n;i ++)
            mx |= nums[i];
        dfs(0, nums, 0);
        return ans;
    }
private:
    int ans, mx, n;
    void dfs(int idx, vector<int>& nums, int sum){
        if(idx >= n)
            return;
        dfs(idx + 1, nums, sum);
        sum |= nums[idx];
        if(sum == mx)
            ans ++;
        dfs(idx + 1, nums, sum);
    }
};
