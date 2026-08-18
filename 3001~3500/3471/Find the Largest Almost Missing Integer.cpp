class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> cnt(51, 0);
        int n = nums.size();
        for(int i = 0;i < n;i ++){
            cnt[nums[i]] ++;
        }
        // 如果k==n表示所有數字都只會在一個subarray出現
        // 找最大的數
        if(k == n){
            for(int i = 50;i >= 0;i --){
                if(cnt[i] > 0)
                    return i;
            }
        }
        // 如果k==1
        // 找只出現1次最大的數
        if(k == 1){
            for(int i = 50;i >= 0;i --){
                if(cnt[i] == 1)
                    return i;
            }
            return -1;
        }
        // 否則只看最左和右的數字
        if(cnt[nums[n - 1]] == 1 && cnt[nums[0]] == 1)
            return nums[n - 1] > nums[0] ? nums[n - 1] : nums[0];
        if(cnt[nums[n - 1]] == 1)
            return nums[n - 1];
        if(cnt[nums[0]] == 1)
            return nums[0];
        return -1;
    }
};
