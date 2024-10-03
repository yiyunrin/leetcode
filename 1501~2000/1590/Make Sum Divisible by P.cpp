class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0, n = nums.size();
        for(int i = 0;i < n;i ++)
            sum = (sum + nums[i]) % p;
        unordered_map<int, int> idx;
        idx[0] = -1;
        int pre = 0, mn = n;
        for(int i = 0;i < n;i ++){
            pre = (pre + nums[i]) % p;
            int tmp = (p - sum + pre) % p;
            idx[pre] = i;
            if(idx.count(tmp))
                mn = min(mn, i - idx[tmp]);
        }
        if(mn == n)
            return -1;
        return mn;
    }
};
