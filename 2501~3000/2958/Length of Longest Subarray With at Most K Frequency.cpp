class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // 用來計算每個數字出現的次數
        unordered_map<int, int> cnt;
        int l = 0, r = 0, n = nums.size(), ans = 1;
        bool good = true;
        // 使用sliding window
        // 如果目前的範圍符合good規範，就繼續加長
        // 如果不符合就縮短範圍
        while(r < n){
            if(good){
                cnt[nums[r]] ++;
                if(cnt[nums[r]] > k)
                    good = false;
                r ++;
            }
            else{
                if(cnt[nums[l]] > k)
                    good = true;
                cnt[nums[l]] --;
                l ++;
            }
            if(good)
                ans = max(ans, r - l);
        }
        return ans;
    }
};
