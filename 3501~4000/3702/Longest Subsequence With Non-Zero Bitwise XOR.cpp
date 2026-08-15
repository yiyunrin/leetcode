class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int _xor = 0, zero = 0, n = nums.size();
        for(int i = 0;i < n;i ++){
            if(nums[i] == 0)
                zero ++;
            _xor ^= nums[i];
        }
        if(_xor != 0)
            return n;
        if(zero == n)
            return 0;
        return n - 1;
    }
};
