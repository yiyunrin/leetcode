class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // num, length
        unordered_map<int, int> sub;
        int ans = -1;
        for(int i = 0;i < nums.size();i ++){
            int sq = sqrt(nums[i]), length = 1;
            if(sq * sq == nums[i] && sub.find(sq) != sub.end())
                length = sub[sq] + 1;
            sub[nums[i]] = length;
            if(length >= 2)
                ans = max(ans, length);
        }
        return ans;
    }
};
