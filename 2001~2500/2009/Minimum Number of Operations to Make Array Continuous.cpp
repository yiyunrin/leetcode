class Solution {
public:
    int minOperations(vector<int>& nums) {
        //按大小排
        sort(nums.begin(), nums.end());
        //用sliding window看在(nums[l])到(nums[l]+n-1)間的數字有幾個
        //same是用來計算重複的數字的數量
        int l = 0, r = 0, n = nums.size(), ans = n, same = 0;
        while(l < n && r < n){
            while(r < n && nums[r] < nums[l] + n){
                if(r && nums[r] == nums[r - 1])
                    same ++;
                r ++;
            }
            //計算要把數字都改成這個範圍需要多少次
            ans = min(ans, n - (r - l) + same);
            if(l < n - 1 && nums[l] == nums[l + 1])
                same --;
            l ++;
        }
        return ans;
    }
};
