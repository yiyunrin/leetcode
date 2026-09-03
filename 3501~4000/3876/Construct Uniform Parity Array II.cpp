// 造成false的條件
// nums1中有奇數，且最小的數不是奇數
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_cnt = 0, mn = nums1[0];
        for(int i = 0;i < nums1.size();i ++){
            if(nums1[i] & 1)
                odd_cnt ++;
            mn = min(mn, nums1[i]);
        }
        if(odd_cnt > 0 && (mn & 1) == 0)
            return false;
        return true;
    }
};
