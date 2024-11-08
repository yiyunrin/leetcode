class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int _xor = 0, n = nums.size(), mx = (1 << maximumBit) - 1;
        for(int i = 0;i < n;i ++)
            _xor ^= nums[i];
        vector<int> ans(n);
        for(int i = 0;i < n;i ++){
            ans[i] = _xor ^ mx;
            _xor ^= nums[n - i - 1];
        }
        return ans;
    }
};
