class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size(), ans = 0, mod = 1000000007;
        for(int i = 0;i < n;i ++){
            int condi = nums[i] - rev(nums[i]);
            ans += m[condi];
            ans %= mod;
            m[condi] ++;
        }
        return ans;
    }

private:
    int rev(int num){
        int re = 0;
        while(num){
            re = re * 10 + num % 10;
            num /= 10;
        }
        return re;
    }
};
